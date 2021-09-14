# LittleFS_Portenta_H7 Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/LittleFS_Portenta_H7.svg?)](https://www.ardu-badge.com/LittleFS_Portenta_H7)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/LittleFS_Portenta_H7.svg)](https://github.com/khoih-prog/LittleFS_Portenta_H7/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/LittleFS_Portenta_H7/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/LittleFS_Portenta_H7.svg)](http://github.com/khoih-prog/LittleFS_Portenta_H7/issues)

---
---

## Table of Contents

* [Changelog](#changelog)
  * [Releases v1.0.2](#releases-v102)
  * [Releases v1.0.1](#releases-v101)
  * [Initial Releases v1.0.0](#initial-releases-v100)

---
---

## Changelog

### Releases v1.0.2

1. Back to using auto LittleFS size to fix bug and to permit 8 LittleFS files instead of 4 in previous release. There is a bug somewhere in the [`ArduinoCore-mbed mbed_portenta core`](https://github.com/arduino/ArduinoCore-mbed) and we have to live with it.

### Releases v1.0.1

1. Change the default and minimum LITTLEFS_PORTENTA_H7_SIZE_KB to 1024KB, instead at maximum available size. This is done to avoid the cases where the code size is larger, and LittleFS size has to be changed, reformatted, leading to data loss.

### Initial Releases v1.0.0

1. Initial coding to support **Portenta_H7 boards** such as Portenta_H7 Rev2 ABX00042, etc., using [**ArduinoCore-mbed mbed_portenta** core](https://github.com/arduino/ArduinoCore-mbed)



