/****************************************************************************************************************************
  LittleFS_Portenta_H7.cpp - Filesystem wrapper for LittleFS on the Mbed PORTENTA_H7
  
  For MBED Portenta_H7 boards
  Written by Khoi Hoang

  Built by Khoi Hoang https://github.com/khoih-prog/LittleFS_Portenta_H7
  Licensed under MIT license

  Version: 1.0.2

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      09/09/2021 Initial coding to support MBED Portenta_H7
  1.0.1   K Hoang      13/09/2021 Select fix LittleFS size of 1024KB
  1.0.2   K Hoang      14/09/2021 Back to using auto LittleFS to fix bug
*****************************************************************************************************************************/

#include "LittleFS_Portenta_H7.h"
 
bool LittleFS_MBED::init()
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

bool LittleFS_MBED::mount()
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

bool LittleFS_MBED::unmount()
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


