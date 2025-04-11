#include "kbAcy.h"
#define BUZZER_PIN 8
#define W 
#define X 
#define Y 
#define Z 

 
void setup() {

    Serial.begin(9600);

    pinMode(A5,INPUT);
    pinMode(5,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(1,OUTPUT);

    //int l_mescan = 0;
    float l_vmes = 0;
    float l_mes0;
    float l_var;
}

void loop() {
    l_mes0 = l_vmes;
    l_vmes = (analogRead(A5)/204.6);
    Serial.println(l_vmes);
    l_var = abs(l_mes0) - abs(l_vmes);

    if(l_var > 1){
        tone(1, 100, 2000);
    }
    else{
        noTone(1);
    }

    if (l_vmes > 3.5){
        setLight("Lumière !!")
    }
    else{
        setLight("Obscurité !!");
    }
}

void setLight(String valuePrint) {
    Serial.println(valuePrint);
    digitalWrite(7, HIGH);
    delay(2000);
    digitalWrite(5, LOW);
}