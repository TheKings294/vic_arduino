#include "kbAcy.h"
#include <Servo.h>

#define BUZZER_PIN 8
#define SERVO_MOTEUR_PIN 
#define LIGHT_SENSOR_PIN A5
#define LED_RED_PIN 
#define LED_GREEN_PIN 

const int SERVO_POS_DAY = 0
const int SERVO_POS_NIGHT = 0
 
void setup() {
    //Definition of th rate of the serial monitor
    Serial.begin(9600);

    //Definiton of the pi mode
    pinMode(LIGHT_SENSOR_PIN, INPUT); //Light sensor
    pinMode(SERVO_MOTEUR_PIN, OUTPUT); //Servo moteur
    pinMode(BUZZER_PIN, OUTPUT); //Buzzer
    pinMode(LED_GREEN_PIN, OUTPUT); //Grenn LED
    pinMode(LED_GREEN_PIN, OUTPUT); //Red LED

    //Defintion of the servo motor
    Servo light_servo;
    light_servo.attach(SERVO_MOTEUR_PIN);

    float l_vmes = 0;
    float l_mes0;
    float l_var;
}

void loop() {
    l_mes0 = l_vmes;
    l_vmes = (analogRead(LIGHT_SENSOR_PIN)/204.6);
    Serial.println(l_vmes);
    l_var = abs(l_mes0) - abs(l_vmes);

    if (abs(l_vmes - l_mes0) >= 2) {
        l_var > 1 ? tone(1, 100, 2000) : noTone(1); //if l_var > at 1 tone else no tone
        l_vmes > 3.5 ? setDayMode() : setNightMode(); //if l_vmes > at 3,5 setDayMode else setNihntMode
    }    
}

void setDayMode() {
    Serial.println("Day mode !!");
    digitalWrite(LED_GREEN_PIN, HIGH);
    light_servo.write(SERVO_POS_DAY);
    digitalWrite(LED_RED_PIN, LOW);
} 

void setNightMode() {
    Serial.println("Night Mode");
    digitalWrite(LED_RED_PIN, HIGH);
    light_servo.write(SERVO_POS_NIGHT);
    digitalWrite(LED_GREEN_PIN, LOW);
}