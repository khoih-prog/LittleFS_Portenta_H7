/****************************************************************************************************************************
  LittleFS_Counting.ino - Filesystem wrapper for LittleFS on the Mbed Portenta_H7
  
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

#define _LFS_LOGLEVEL_          1

#define FORCE_REFORMAT          false

#include <LittleFS_Portenta_H7.h>

#define START_COUNT_OVER        false

LittleFS_MBED *myFS;

void setup() 
{
  Serial.begin(115200);
  while (!Serial);

  delay(1000);

  Serial.print("\nStart LittleFS_Counting on "); Serial.println(BOARD_NAME);
  Serial.println(LFS_MBED_PORTENTA_H7_VERSION);

  myFS = new LittleFS_MBED();

  if (!myFS->init()) 
  {
    Serial.println("LITTLEFS Mount Failed");
    
    return;
  }

  char fileName[] = MBED_LITTLEFS_FILE_PREFIX "/counts.txt";

  #define BUF_SIZE      32
  
  char buff[BUF_SIZE];
  int count = 1;

#if  START_COUNT_OVER
  Serial.print("Deleting file: "); Serial.print(fileName);
  
  if (remove(fileName) == 0) 
  {
    Serial.println(" => OK");
  }
  else
  {
    Serial.println(" => Failed");
  }
#endif
  
  FILE *file = fopen(fileName, "r");
  
  if (file) 
  {
    Serial.println(" => Open to read OK");
    
    bzero(buff, BUF_SIZE);
    
    uint32_t numRead = fread((uint8_t *) buff, BUF_SIZE - 1, 1, file);
   
    if ( numRead )
    {
      sscanf(buff, "%d", &count);
    }
    
    fclose(file);
  }

  Serial.print("Times have been run = "); Serial.println(count);
  
  sprintf(buff, "%d\n", ++count);
  
  file = fopen(fileName, "w");
  
  if (file) 
  {
    Serial.println(" => Open to write OK");
    
    fwrite((uint8_t *) buff, 1, BUF_SIZE - 1, file) ;
    fclose(file);
  }
}

void loop() 
{
}
