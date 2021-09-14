/****************************************************************************************************************************
  FlashIAPLimits.h - Filesystem wrapper for LittleFS on the Mbed Portenta_H7
  
  For MBED Portenta_H7 boards
  Written by Khoi Hoang

  Built by Khoi Hoang https://github.com/khoih-prog/LittleFS_Portenta_H7
  Licensed under MIT license
  
  Modified from sample Code from Arduino-mbed mbed_portenta core for Portenta_H7

  Version: 1.0.2

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      09/09/2021 Initial coding to support MBED Portenta_H7
  1.0.1   K Hoang      13/09/2021 Select fix LittleFS size of 1024KB
  1.0.2   K Hoang      14/09/2021 Back to using auto LittleFS to fix bug
*****************************************************************************************************************************/

#pragma once

#ifndef _FlashIAPLimits_h_
#define _FlashIAPLimits_h_

#include <Arduino.h>
#include <FlashIAP.h>
#include <FlashIAPBlockDevice.h>

using namespace mbed;

// A helper struct for FlashIAP limits
struct FlashIAPLimits 
{
  size_t flash_size;
  uint32_t start_address;
  uint32_t available_size;
};

// Get the actual start address and available size for the FlashIAP Block Device
// considering the space already occupied by the sketch (firmware).
FlashIAPLimits getFlashIAPLimits()
{
  // Alignment lambdas
  auto align_down = [](uint64_t val, uint64_t size) 
  {
    return (((val) / size)) * size;
  };
  
  auto align_up = [](uint32_t val, uint32_t size) 
  {
    return (((val - 1) / size) + 1) * size;
  };

  FlashIAPLimits flashIAPLimits;
  
  uint32_t  flash_start_address;
  
  FlashIAP  flash;

  auto result = flash.init();
  
  if (result != 0)
    return { };

  // Find the start of first sector after text area
  int sector_size     = flash.get_sector_size(FLASHIAP_APP_ROM_END_ADDR);

  flash_start_address           = flash.get_flash_start();
  flashIAPLimits.start_address  = align_up(FLASHIAP_APP_ROM_END_ADDR, sector_size);
  flashIAPLimits.flash_size     = flash.get_flash_size();

  result = flash.deinit();

  flashIAPLimits.available_size = flash_start_address + flashIAPLimits.flash_size - flashIAPLimits.start_address;
  
  if (flashIAPLimits.available_size % (sector_size * 2)) 
  {
    flashIAPLimits.available_size = align_down(flashIAPLimits.available_size, sector_size * 2);
  }

  return flashIAPLimits;
}
#endif    // _FlashIAPLimits_h_
