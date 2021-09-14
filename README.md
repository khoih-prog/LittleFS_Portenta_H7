# LittleFS_Portenta_H7 Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/LittleFS_Portenta_H7.svg?)](https://www.ardu-badge.com/LittleFS_Portenta_H7)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/LittleFS_Portenta_H7.svg)](https://github.com/khoih-prog/LittleFS_Portenta_H7/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/LittleFS_Portenta_H7/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/LittleFS_Portenta_H7.svg)](http://github.com/khoih-prog/LittleFS_Portenta_H7/issues)

---
---

## Table of Contents

* [Important Notes for Portenta_H7](#important-notes-for-portenta_h7)
* [Why do we need this LittleFS_Portenta_H7 library](#why-do-we-need-this-LittleFS_Portenta_H7-library)
  * [Features](#features)
  * [Currently supported Boards](#currently-supported-boards)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Packages' Patches](#packages-patches)
  * [1. For Portenta_H7 boards using Arduino IDE in Linux](#1-for-portenta_h7-boards-using-arduino-ide-in-linux)
* [HOWTO Fix `Multiple Definitions` Linker Error](#howto-fix-multiple-definitions-linker-error)
* [Examples](#examples)
  * [  1. LittleFS_Counting](examples/LittleFS_Counting)
  * [  2. LittleFS_Test](examples/LittleFS_Test)
* [Example LittleFS_Test](#example-littlefs_test)
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [1. LittleFS_Counting on PORTENTA_H7_M7](#1-littlefs_counting-on-portenta_h7_m7)
  * [2. LittleFS_Test on PORTENTA_H7_M7](#2-littlefs_test-on-portenta_h7_m7)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Important Notes for Portenta_H7

The LittleFS of the new **Portenta_H7** board currently tested OK with only **maximum 8 files**. The files, from 9 and up, somehow strangely can't be written and / or read. This is possibly a bug in the [`ArduinoCore-mbed mbed_portenta core`](https://github.com/arduino/ArduinoCore-mbed). The same behaviour is observed from core v2.0.0 up to v2.4.1.

If LittleFS size is reduced to 1024KB, test is OK with only **maximum 4 files**.

Beware and keep cheking for updates.

---
---

### Why do we need this [LittleFS_Portenta_H7 library](https://github.com/khoih-prog/littlefs_portenta_h7)

## Features

This library is just a simple LittleFS wrapper to facilitate your usage of LittleFS for the onboard flash on **MBED Portenta_H7**, using [**ArduinoCore-mbed mbed_portenta** core](https://github.com/arduino/ArduinoCore-mbed)

The filesystem access uses normal [POSIX APIs](https://www.tutorialspoint.com/c_standard_library/stdio_h.htm) or [mbed FileSystem APIs](https://os.mbed.com/docs/mbed-os/v6.10/apis/file-system-apis.html)

---

### Currently supported Boards

1. **Portenta_H7 boards** such as Portenta_H7 Rev2 ABX00042, etc., using [**ArduinoCore-mbed mbed_portenta** core](https://github.com/arduino/ArduinoCore-mbed)

---
---


## Prerequisites

1. [`Arduino IDE 1.8.16+` for Arduino](https://www.arduino.cc/en/Main/Software)
2. [`ArduinoCore-mbed mbed_portenta core 2.4.1+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino **Portenta_H7** boards, such as **Portenta_H7 Rev2 ABX00042, etc.**. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)

---
---

## Installation

### Use Arduino Library Manager

The best and easiest way is to use `Arduino Library Manager`. Search for [**LittleFS_Portenta_H7**](https://github.com/khoih-prog/LittleFS_Portenta_H7), then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/LittleFS_Portenta_H7.svg?)](https://www.ardu-badge.com/LittleFS_Portenta_H7) for more detailed instructions.

### Manual Install

Another way to install is to:

1. Navigate to [**LittleFS_Portenta_H7**](https://github.com/khoih-prog/LittleFS_Portenta_H7) page.
2. Download the latest release `LittleFS_Portenta_H7-main.zip`.
3. Extract the zip file to `LittleFS_Portenta_H7-main` directory 
4. Copy whole `LittleFS_Portenta_H7-main` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**LittleFS_Portenta_H7** library](https://platformio.org/lib/show/12798/LittleFS_Portenta_H7) by using [Library Manager](https://platformio.org/lib/show/12798/LittleFS_Portenta_H7/installation). Search for **LittleFS_Portenta_H7** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)


---
---

### Packages' Patches

#### 1. For Portenta_H7 boards using Arduino IDE in Linux

  **To be able to upload firmware to Portenta_H7 using Arduino IDE in Linux (Ubuntu, etc.)**, you have to copy the file [portenta_post_install.sh](Packages_Patches/arduino/hardware/mbed_portenta/2.4.1/portenta_post_install.sh) into mbed_portenta directory (~/.arduino15/packages/arduino/hardware/mbed_portenta/2.4.1/portenta_post_install.sh). 
  
  Then run the following command using `sudo`
  
```
$ cd ~/.arduino15/packages/arduino/hardware/mbed_portenta/2.4.1
$ chmod 755 portenta_post_install.sh
$ sudo ./portenta_post_install.sh
```

This will create the file `/etc/udev/rules.d/49-portenta_h7.rules` as follows:

```
# Portenta H7 bootloader mode UDEV rules

SUBSYSTEMS=="usb", ATTRS{idVendor}=="2341", ATTRS{idProduct}=="035b", GROUP="plugdev", MODE="0666"
```

Supposing the ArduinoCore-mbed core version is 2.4.1. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/2.4.1/portenta_post_install.sh`

Whenever a new version is installed, remember to copy this files into the new version directory. For example, new version is x.yy.zz

This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/x.yy.zz/portenta_post_install.sh`


---
---

### HOWTO Fix `Multiple Definitions` Linker Error

The current library implementation, using **xyz-Impl.h instead of standard xyz.cpp**, possibly creates certain `Multiple Definitions` Linker error in certain use cases. Although it's simple to just modify several lines of code, either in the library or in the application, the library is adding 2 more source directories

1. **scr_h** for new h-only files
2. **src_cpp** for standard h/cpp files

besides the standard **src** directory.

To use the **old standard cpp** way, locate this library' directory, then just 

1. **Delete the all the files in src directory.**
2. **Copy all the files in src_cpp directory into src.**
3. Close then reopen the application code in Arduino IDE, etc. to recompile from scratch.

To re-use the **new h-only** way, just 

1. **Delete the all the files in src directory.**
2. **Copy the files in src_h directory into src.**
3. Close then reopen the application code in Arduino IDE, etc. to recompile from scratch.

---
---


### Examples 

 1. [LittleFS_Counting](examples/LittleFS_Counting)
 2. [LittleFS_test](examples/LittleFS_Test)

---
---

### Example [Littlefs_Test](examples/Littlefs_Test)

```
#define _LFS_LOGLEVEL_          1

#define FORCE_REFORMAT          false

#include <LittleFS_Portenta_H7.h>

LittleFS_MBED *myFS;

uint32_t FILE_SIZE_KB = 64;

void readCharsFromFile(const char * path) 
{
  Serial.print("readCharsFromFile: "); Serial.print(path);

  FILE *file = fopen(path, "r");
  
  if (file) 
  {
    Serial.println(" => Open OK");
  }
  else
  {
    Serial.println(" => Open Failed");
    return;
  }

  char c;

  while (true) 
  {
    c = fgetc(file);
    
    if ( feof(file) ) 
    { 
      break;
    }
    else   
      Serial.print(c);
  }
   
  fclose(file);
}

void readFile(const char * path) 
{
  Serial.print("Reading file: "); Serial.print(path);

  FILE *file = fopen(path, "r");
  
  if (file) 
  {
    Serial.println(" => Open OK");
  }
  else
  {
    Serial.println(" => Open Failed");
    return;
  }

  char c;
  uint32_t numRead = 1;
  
  while (numRead) 
  {
    numRead = fread((uint8_t *) &c, sizeof(c), 1, file);

    if (numRead)
      Serial.print(c);
  }
  
  fclose(file);
}

void writeFile(const char * path, const char * message, size_t messageSize) 
{
  Serial.print("Writing file: "); Serial.print(path);

  FILE *file = fopen(path, "w");
  
  if (file) 
  {
    Serial.println(" => Open OK");
  }
  else
  {
    Serial.println(" => Open Failed");
    return;
  }
 
  if (fwrite((uint8_t *) message, 1, messageSize, file)) 
  {
    Serial.println("* Writing OK");
  } 
  else 
  {
    Serial.println("* Writing failed");
  }
  
  fclose(file);
}

void appendFile(const char * path, const char * message, size_t messageSize) 
{
  Serial.print("Appending file: "); Serial.print(path);

  FILE *file = fopen(path, "a");
  
  if (file) 
  {
    Serial.println(" => Open OK");
  }
  else
  {
    Serial.println(" => Open Failed");
    return;
  }

  if (fwrite((uint8_t *) message, 1, messageSize, file)) 
  {
    Serial.println("* Appending OK");
  } 
  else 
  {
    Serial.println("* Appending failed");
  }
   
  fclose(file);
}

void deleteFile(const char * path) 
{
  Serial.print("Deleting file: "); Serial.print(path);
  
  if (remove(path) == 0) 
  {
    Serial.println(" => OK");
  }
  else
  {
    Serial.println(" => Failed");
    return;
  }
}

void renameFile(const char * path1, const char * path2) 
{
  Serial.print("Renaming file: "); Serial.print(path1);
  Serial.print(" to: "); Serial.print(path2);
  
  if (rename(path1, path2) == 0) 
  {
    Serial.println(" => OK");
  }
  else
  {
    Serial.println(" => Failed");
    return;
  }
}

void testFileIO(const char * path) 
{
  Serial.print("Testing file I/O with: "); Serial.print(path);

  #define BUFF_SIZE     512
  
  static uint8_t buf[BUFF_SIZE];
  
  FILE *file = fopen(path, "w");
  
  if (file) 
  {
    Serial.println(" => Open OK");
  }
  else
  {
    Serial.println(" => Open Failed");
    return;
  }

  size_t i;
  Serial.println("- writing" );
  
  uint32_t start = millis();

  size_t result = 0;

  // Write a file with FILE_SIZE_KB
  for (i = 0; i < FILE_SIZE_KB * 2; i++)
  {
    result = fwrite(buf, BUFF_SIZE, 1, file);

    if ( result != 1)
    {
      Serial.print("Write result = "); Serial.println(result);
      Serial.print("Write error, i = "); Serial.println(i);

      break;
    }
  }
  
  Serial.println("");
  uint32_t end = millis() - start;
  
  Serial.print(i / 2);
  Serial.print(" Kbytes written in (ms) ");
  Serial.println(end);
  
  fclose(file);

  printLine();

  /////////////////////////////////

  file = fopen(path, "r");
  
  start = millis();
  end = start;
  i = 0;
  
  if (file) 
  {
    start = millis();
    Serial.println("- reading" );

    result = 0;

    fseek(file, 0, SEEK_SET);

    // Read a file with FILE_SIZE_KB
  for (i = 0; i < FILE_SIZE_KB * 2; i++)
    {
      result = fread(buf, BUFF_SIZE, 1, file);

      if ( result != 1 )
      {
        Serial.print("Read result = "); Serial.println(result);
        Serial.print("Read error, i = "); Serial.println(i);

        break;
      }
    }
      
    Serial.println("");
    end = millis() - start;
    
    Serial.print((i * BUFF_SIZE) / 1024);
    Serial.print(" Kbytes read in (ms) ");
    Serial.println(end);
    
    fclose(file);
  } 
  else 
  {
    Serial.println("- failed to open file for reading");
  }
}

void printLine()
{
  Serial.println("====================================================");
}

void setup() 
{
  Serial.begin(115200);
  while (!Serial)

  delay(1000);

  Serial.print("\nStart LittleFS_Test on "); Serial.println(BOARD_NAME);
  Serial.println(LFS_MBED_PORTENTA_H7_VERSION);

  myFS = new LittleFS_MBED();

  if (!myFS->init()) 
  {
    Serial.println("LITTLEFS Mount Failed");
    
    return;
  }
 
  char fileName1[] = MBED_LITTLEFS_FILE_PREFIX "/hello1.txt";
  char fileName2[] = MBED_LITTLEFS_FILE_PREFIX "/hello2.txt";
  
  char message[]  = "Hello from " BOARD_NAME "\n";
   
  printLine();
  writeFile(fileName1, message, sizeof(message));
  printLine();
  readFile(fileName1);
  printLine();

  appendFile(fileName1, message, sizeof(message));
  printLine();
  readFile(fileName1);
  printLine();

  renameFile(fileName1, fileName2);
  printLine();
  readCharsFromFile(fileName2);
  printLine();

  deleteFile(fileName2);
  printLine();
  readFile(fileName2);
  printLine();

  testFileIO(fileName1);
  printLine();
  testFileIO(fileName2);
  printLine();
  deleteFile(fileName1);
  printLine();
  deleteFile(fileName2);
  printLine();

  Serial.println( "\nTest complete" );
}

void loop() 
{
}
```
---
---

### Debug Terminal Output Samples

### 1. LittleFS_Counting on PORTENTA_H7_M7

The following is the sample terminal output when running example [LittleFS_Counting](examples/LittleFS_Counting) on MBED PORTENTA_H7_M7

##### 1.1 First run

```
Start LittleFS_Counting on PORTENTA_H7_M7
LittleFS_Portenta_H7 v1.0.2
[LFS] Flash Size: (KB) = 2048.00
[LFS] FlashIAP Start Address: = 0x0x8080000
[LFS] LittleFS size (KB) = 1536.00
[LFS] LittleFS Mount OK
Times have been run = 1
 => Open to write OK
```

##### 1.2 After reset

```
Start LittleFS_Counting on PORTENTA_H7_M7
LittleFS_Portenta_H7 v1.0.2
[LFS] Flash Size: (KB) = 2048.00
[LFS] FlashIAP Start Address: = 0x0x8080000
[LFS] LittleFS size (KB) = 1536.00
[LFS] LittleFS Mount OK
 => Open to read OK
Times have been run = 2
 => Open to write OK
```

### 2. LittleFS_Test on PORTENTA_H7_M7

The following is the sample terminal output when running example [LittleFS_Test](examples/LittleFS_Test) on MBED PORTENTA_H7_M7


```
Start LittleFS_Test on PORTENTA_H7_M7
LittleFS_Portenta_H7 v1.0.2
[LFS] Flash Size: (KB) = 2048.00
[LFS] FlashIAP Start Address: = 0x0x8080000
[LFS] LittleFS size (KB) = 1536.00
[LFS] LittleFS Mount OK
====================================================
Writing file: /littlefs/hello1.txt => Open OK
* Writing OK
====================================================
Reading file: /littlefs/hello1.txt => Open OK
Hello from PORTENTA_H7_M7
====================================================
Appending file: /littlefs/hello1.txt => Open OK
* Appending OK
====================================================
Reading file: /littlefs/hello1.txt => Open OK
Hello from PORTENTA_H7_M7
Hello from PORTENTA_H7_M7
====================================================
Renaming file: /littlefs/hello1.txt to: /littlefs/hello2.txt => OK
====================================================
readCharsFromFile: /littlefs/hello2.txt => Open OK
Hello from PORTENTA_H7_M7
Hello from PORTENTA_H7_M7
====================================================
Deleting file: /littlefs/hello2.txt => OK
====================================================
Reading file: /littlefs/hello2.txt => Open Failed
====================================================
Testing file I/O with: /littlefs/hello1.txt => Open OK
- writing

64 Kbytes written in (ms) 1077
====================================================
- reading

384 Kbytes read in (ms) 0
====================================================
Testing file I/O with: /littlefs/hello2.txt => Open OK
- writing

64 Kbytes written in (ms) 1003
====================================================
- reading

64 Kbytes read in (ms) 0
====================================================
Deleting file: /littlefs/hello1.txt => OK
====================================================
Deleting file: /littlefs/hello2.txt => OK
====================================================
```

---
---

### Debug

Debug is enabled by default on Serial.

You can also change the debugging level (_LFS_LOGLEVEL_) from 0 to 4

```cpp
#define LFS_DEBUG_OUTPUT    Serial

// These define's must be placed at the beginning before #include "LittleFS_Portenta_H7.h"
// _LFS_LOGLEVEL_ from 0 to 4
#define _LFS_LOGLEVEL_      0
```

---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the core for Arduino boards.

Sometimes, the library will only work if you update the board core to the latest version because I am using newly added functions.


---
---


### Issues

Submit issues to: [LittleFS_Portenta_H7 issues](https://github.com/khoih-prog/LittleFS_Portenta_H7/issues)

---

## TO DO

1. Search for bug and improvement.


---

## DONE

1. Basic LittleFS wrapper for **Portenta_H7**, using [**ArduinoCore-mbed mbed_portenta** core](https://github.com/arduino/ArduinoCore-mbed)
2. Add Version String 
3. Add Table of Contents
4. Reduce `LittleFS` size to 1024KB

---
---

### Contributions and Thanks

Many thanks for everyone for bug reporting, new feature suggesting, testing and contributing to the development of this library.


---

## Contributing

If you want to contribute to this project:

- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [GPLv3](https://github.com/khoih-prog/LittleFS_Portenta_H7/blob/main/LICENSE)

---

## Copyright

Copyright 2021- Khoi Hoang


