#include "kbAcy.h"

float getKbNbr(void){
  char l_tabChar_octetsRecus[50] = {0};
  float l_float_valRecu = 0;
 
  do{}while(Serial.available() == 0);
  do{
    if(Serial.available() > 0){
      Serial.readBytesUntil('\n', l_tabChar_octetsRecus, sizeof(l_tabChar_octetsRecus) / sizeof(char) );
      l_float_valRecu = atof(l_tabChar_octetsRecus);
    }
  }while(Serial.available()> 0);
  
  return l_float_valRecu;
}

void stopAndStart(void){
  Serial.println("\n\nPress enter to restart...\n\n");
  getKbNbr();
}

void sleep(void){
  delay(1000);
  sleep_enable();
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_mode();
}