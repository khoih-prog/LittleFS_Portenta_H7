/****************************************************************************************************************************
  LittleFS_Portenta_H7.h - Filesystem wrapper for LittleFS on the Mbed Portenta_H7
  
  For MBED Portenta_H7 boards
  Written by Khoi Hoang

  Built by Khoi Hoang https://github.com/khoih-prog/LittleFS_Portenta_H7
  Licensed under MIT license

  Version: 1.2.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      09/09/2021 Initial coding to support MBED Portenta_H7
  1.0.1   K Hoang      13/09/2021 Select fix LittleFS size of 1024KB
  1.0.2   K Hoang      14/09/2021 Back to using auto LittleFS to fix bug
  1.1.0   K Hoang      30/12/2021 Fix `multiple-definitions` linker error
  1.2.0   K Hoang      12/05/2022 Fix `multiple-definitions` linker error in some cases
*****************************************************************************************************************************/

#pragma once

#ifndef _LITTLEFS_PORTENTA_H7_H
#define _LITTLEFS_PORTENTA_H7_H

#if ( ( defined(ARDUINO_PORTENTA_H7_M7) || defined(ARDUINO_PORTENTA_H7_M4) ) && defined(ARDUINO_ARCH_MBED) )
  #warning Use MBED ARDUINO_PORTENTA_H7 and LittleFS
  
  #if defined(BOARD_NAME)
    #undef BOARD_NAME
  #endif

  #if defined(CORE_CM7)
    #warning Using Portenta H7 M7 core
    #define BOARD_NAME              "PORTENTA_H7_M7"
  #else
    #warning Using Portenta H7 M4 core
    #define BOARD_NAME              "PORTENTA_H7_M4"
  #endif
  
#else
  #error This code is intended to run on theMBED ARDUINO_PORTENTA_H7 platform! Please check your Tools->Board setting. 
#endif

#define LFS_MBED_PORTENTA_H7_VERSION              "LittleFS_Portenta_H7 v1.2.0"

#define LFS_MBED_PORTENTA_H7_VERSION_MAJOR        1
#define LFS_MBED_PORTENTA_H7_VERSION_MINOR        2
#define LFS_MBED_PORTENTA_H7_VERSION_PATCH        0

#define LFS_MBED_PORTENTA_H7_VERSION_INT          1002000

#ifndef LFS_PORTENTA_H7_DEBUG
  #define LFS_PORTENTA_H7_DEBUG      0
#endif

#include <Arduino.h>

#include "LittleFS_Portenta_H7_Debug.h"

// For Arduino' arduino-mbed core
// To check and determine if we need to init LittleFS here
#if MBED_PORTENTA_H7_INITIALIZED
  #define MBED_LITTLEFS_NEED_INIT     false
  #warning MBED_PORTENTA_H7_INITIALIZED in another place
#else
  // Better to delay until init done
  #if defined(MBED_PORTENTA_H7_INITIALIZED)
    #undef MBED_PORTENTA_H7_INITIALIZED
  #endif
  #define MBED_PORTENTA_H7_INITIALIZED           true
  
  #define MBED_LITTLEFS_NEED_INIT     true
  
  #warning MBED_PORTENTA_H7_INITIALIZED in LittleFS_Portenta_H7
#endif

#if MBED_LITTLEFS_NEED_INIT

  //Use LittleFS for MBED PORTENTA_H7
  #include "FlashIAPBlockDevice.h"
  #include "LittleFileSystem.h"
  #include "mbed.h"

  #include <stdio.h>
  #include <errno.h>
  #include <functional>

  #include "BlockDevice.h"
  
  #include "FlashIAPLimits.h"

  #if !defined(FORCE_REFORMAT)
    #define FORCE_REFORMAT            false
  #elif FORCE_REFORMAT
    #warning FORCE_REFORMAT enable. Are you sure ?
  #endif

  #define MBED_LITTLEFS_FILE_NAME     "littlefs"
  #define MBED_LITTLEFS_FILE_PREFIX   "/" MBED_LITTLEFS_FILE_NAME

#endif

static FlashIAPBlockDevice* blockDevicePtr;

static mbed::LittleFileSystem fs(MBED_LITTLEFS_FILE_NAME);

class LittleFS_MBED
{
public:
  LittleFS_MBED()
  {
    _sizeInKB = 0;
    _mounted  = false;
  }

  ~LittleFS_MBED() 
  {
    if (_mounted) 
    {
      unmount();      
    }
  }
  
  /////////////////////////////////////////////////////////////

  bool init()
  {
    // Get limits of the the internal flash of the microcontroller
    _flashIAPLimits = getFlashIAPLimits();
    
    LFS_LOGERROR1("Flash Size: (KB) = ", _flashIAPLimits.flash_size / 1024.0);
    LFS_HEXLOGERROR1("FlashIAP Start Address: = 0x", _flashIAPLimits.start_address);
    LFS_LOGERROR1("LittleFS size (KB) = ", _flashIAPLimits.available_size / 1024.0);
     
    _sizeInKB = _flashIAPLimits.available_size / 1024.0;
    
    blockDevicePtr = new FlashIAPBlockDevice(_flashIAPLimits.start_address, _flashIAPLimits.available_size);
    
    if (!blockDevicePtr)
    {
      LFS_LOGERROR("Error init FlashIAPBlockDevice");
      return false;
    }
    
  #if FORCE_REFORMAT
    fs.reformat(blockDevicePtr);
  #endif  
    
    return mount();
  }
  
  /////////////////////////////////////////////////////////////

  bool mount()
  {
    if (!_mounted)
    {
      int err = fs.mount(blockDevicePtr);

      LFS_LOGERROR(err ? "LittleFS Mount Fail" : "LittleFS Mount OK");

      if (err)
      {
        // Reformat if we can't mount the filesystem
        LFS_LOGERROR("Formatting... ");

        err = fs.reformat(blockDevicePtr);
      }

      _mounted = (err == 0);
    
      if (!_mounted)
      {
        LFS_LOGERROR("\nLittleFS error");
      }
    
    }
    
    return _mounted;
  }
  
  /////////////////////////////////////////////////////////////

  bool unmount()
  {
    if (_mounted)
    {
      int err = fs.unmount();
    
      LFS_LOGERROR1("Unmount FS ", err < 0 ? "Fail" : "OK");
   
      if (err < 0)
      {   
        return false;
      }
    }
    
    _mounted = false;
    
    return true;
  }
  
  /////////////////////////////////////////////////////////////
  
  uint32_t littleFS_SizeInKB()
  {
    return (_sizeInKB);
  }
  
  /////////////////////////////////////////////////////////////
  
private:

  // In KB
  uint32_t _sizeInKB;
  
  struct FlashIAPLimits _flashIAPLimits;
  
  bool     _mounted;  
};

#endif // ifndef _LITTLEFS_PORTENTA_H7_H
