/****************************************************************************************************************************
  LittleFS_Portenta_H7_Debug.h - Filesystem wrapper for LittleFS on the Mbed PORTENTA_H7
  
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

#pragma once

#ifndef LittleFS_Portenta_H7_Debug_h
#define LittleFS_Portenta_H7_Debug_h

#ifdef LFS_DEBUG_OUTPUT
  #define DBG_PORT_LFS       LFS_DEBUG_OUTPUT
#else
  #define DBG_PORT_LFS       Serial
#endif

// Change _LFS_LOGLEVEL_ to set tracing and logging verbosity
// 0: DISABLED: no logging
// 1: ERROR: errors
// 2: WARN: errors and warnings
// 3: INFO: errors, warnings and informational (default)
// 4: DEBUG: errors, warnings, informational and debug

#ifndef _LFS_LOGLEVEL_
  #define _LFS_LOGLEVEL_       0
#endif

//////////////////////////////////////////

const char LFS_MARK[] = "[LFS] ";

#define LFS_PRINT_MARK    DBG_PORT_LFS.print(LFS_MARK)

#define LFS_PRINT         DBG_PORT_LFS.print
#define LFS_PRINTLN       DBG_PORT_LFS.println       

//////////////////////////////////////////

#define LFS_LOGERROR0(x)        if(_LFS_LOGLEVEL_>0) { LFS_PRINT(x); }
#define LFS_LOGERROR(x)         if(_LFS_LOGLEVEL_>0) { LFS_PRINT_MARK; LFS_PRINTLN(x); }
#define LFS_LOGERROR1(x,y)      if(_LFS_LOGLEVEL_>0) { LFS_PRINT_MARK; LFS_PRINT(x); LFS_PRINTLN(y); }
#define LFS_HEXLOGERROR1(x,y)   if(_LFS_LOGLEVEL_>0) { LFS_PRINT_MARK; LFS_PRINT(x); LFS_PRINT("0x"); LFS_PRINTLN(y, HEX); }
#define LFS_LOGERROR2(x,y,z)    if(_LFS_LOGLEVEL_>0) { LFS_PRINT_MARK; LFS_PRINT(x); LFS_PRINT(y); LFS_PRINTLN(z); }
#define LFS_LOGERROR3(x,y,z,w) if(_LFS_LOGLEVEL_>0) { LFS_PRINT_MARK; LFS_PRINT(x); LFS_PRINT(y); LFS_PRINT(z); LFS_PRINTLN(w); }
#define LFS_LOGERROR5(x,y,z,w,xx,yy) if(_LFS_LOGLEVEL_>0) { LFS_PRINT_MARK; LFS_PRINT(x); LFS_PRINT(y); LFS_PRINT(z); LFS_PRINT(w); LFS_PRINT(xx); LFS_PRINTLN(yy); }

//////////////////////////////////////////

#define LFS_LOGWARN0(x)         if(_LFS_LOGLEVEL_>1) { LFS_PRINT(x); }
#define LFS_LOGWARN(x)          if(_LFS_LOGLEVEL_>1) { LFS_PRINT_MARK; LFS_PRINTLN(x); }
#define LFS_LOGWARN1(x,y)       if(_LFS_LOGLEVEL_>1) { LFS_PRINT_MARK; LFS_PRINT(x); LFS_PRINTLN(y); }
#define LFS_HEXLOGWARN1(x,y)    if(_LFS_LOGLEVEL_>1) { LFS_PRINT_MARK; LFS_PRINT(x); LFS_PRINT("0x"); LFS_PRINTLN(y, HEX); }
#define LFS_LOGWARN2(x,y,z)     if(_LFS_LOGLEVEL_>1) { LFS_PRINT_MARK; LFS_PRINT(x); LFS_PRINT(y); LFS_PRINTLN(z); }
#define LFS_LOGWARN3(x,y,z,w) if(_LFS_LOGLEVEL_>1) { LFS_PRINT_MARK; LFS_PRINT(x); LFS_PRINT(y); LFS_PRINT(z); LFS_PRINTLN(w); }
#define LFS_LOGWARN5(x,y,z,w,xx,yy) if(_LFS_LOGLEVEL_>1) { LFS_PRINT_MARK; LFS_PRINT(x); LFS_PRINT(y); LFS_PRINT(z); LFS_PRINT(w); LFS_PRINT(xx); LFS_PRINTLN(yy); }

//////////////////////////////////////////

#define LFS_LOGINFO0(x)         if(_LFS_LOGLEVEL_>2) { LFS_PRINT(x); }
#define LFS_LOGINFO(x)          if(_LFS_LOGLEVEL_>2) { LFS_PRINT_MARK; LFS_PRINTLN(x); }
#define LFS_LOGINFO1(x,y)       if(_LFS_LOGLEVEL_>2) { LFS_PRINT_MARK; LFS_PRINT(x); LFS_PRINTLN(y); }
#define LFS_HEXLOGINFO1(x,y)    if(_LFS_LOGLEVEL_>2) { LFS_PRINT_MARK; LFS_PRINT(x); LFS_PRINT("0x"); LFS_PRINTLN(y, HEX); }
#define LFS_LOGINFO2(x,y,z)     if(_LFS_LOGLEVEL_>3) { LFS_PRINT_MARK; LFS_PRINT(x); LFS_PRINT(y); LFS_PRINTLN(z); }
#define LFS_LOGINFO3(x,y,z,w) if(_LFS_LOGLEVEL_>3) { LFS_PRINT_MARK; LFS_PRINT(x); LFS_PRINT(y); LFS_PRINT(z); LFS_PRINTLN(w); }
#define LFS_LOGINFO5(x,y,z,w,xx,yy) if(_LFS_LOGLEVEL_>2) { LFS_PRINT_MARK; LFS_PRINT(x); LFS_PRINT(y); LFS_PRINT(z); LFS_PRINT(w); LFS_PRINT(xx); LFS_PRINTLN(yy); }

//////////////////////////////////////////

#define LFS_LOGDEBUG0(x)        if(_LFS_LOGLEVEL_>3) { LFS_PRINT(x); }
#define LFS_LOGDEBUG(x)         if(_LFS_LOGLEVEL_>3) { LFS_PRINT_MARK; LFS_PRINTLN(x); }
#define LFS_LOGDEBUG1(x,y)      if(_LFS_LOGLEVEL_>3) { LFS_PRINT_MARK; LFS_PRINT(x); LFS_PRINTLN(y); }
#define LFS_HEXLOGDEBUG1(x,y)   if(_LFS_LOGLEVEL_>3) { LFS_PRINT_MARK; LFS_PRINT(x); LFS_PRINT("0x"); LFS_PRINTLN(y, HEX); }
#define LFS_LOGDEBUG2(x,y,z)    if(_LFS_LOGLEVEL_>3) { LFS_PRINT_MARK; LFS_PRINT(x); LFS_PRINT(y); LFS_PRINTLN(z); }
#define LFS_LOGDEBUG3(x,y,z,w) if(_LFS_LOGLEVEL_>3) { LFS_PRINT_MARK; LFS_PRINT(x); LFS_PRINT(y); LFS_PRINT(z); LFS_PRINTLN(w); }
#define LFS_LOGDEBUG5(x,y,z,w,xx,yy) if(_LFS_LOGLEVEL_>3) { LFS_PRINT_MARK; LFS_PRINT(x); LFS_PRINT(y); LFS_PRINT(z); LFS_PRINT(w); LFS_PRINT(xx); LFS_PRINTLN(yy); }

//////////////////////////////////////////

#endif    //LittleFS_Portenta_H7_Debug_h
