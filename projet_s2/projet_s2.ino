#include <Servo.h>

#define BUZZER_PIN 4
#define SERVO_MOTEUR_PIN 3
#define LIGHT_SENSOR_PIN A5
#define LED_RED_PIN 13
#define LED_GREEN_PIN 6

const int SERVO_POS_DAY = 0;
const int SERVO_POS_NIGHT = 180;

Servo light_servo;
 
void setup() {
    //Definition of th rate of the serial monitor
    Serial.begin(9600);

    //Definiton of the pi mode
    pinMode(LIGHT_SENSOR_PIN, INPUT); //Light sensor
    pinMode(SERVO_MOTEUR_PIN, OUTPUT); //Servo moteur
    pinMode(BUZZER_PIN, OUTPUT); //Buzzer
    pinMode(LED_GREEN_PIN, OUTPUT); //Grenn LED
    pinMode(LED_GREEN_PIN, OUTPUT); //Red LED

    //Defintion of the servo moteur
    light_servo.attach(SERVO_MOTEUR_PIN);
}

void loop() {
    int l_mode;
    float l_vmes;

    float l_mes0 = l_vmes;
    l_vmes = (analogRead(LIGHT_SENSOR_PIN)/204.6);
    Serial.println(l_vmes);
    float l_var = abs(l_mes0) - abs(l_vmes);


    if (l_vmes > 3.5) {
        if (l_mode != 1) {
            setDayMode(&l_mode);
        }
    } else {
        if (l_mode != 0) {
            setNightMode(&l_mode);
        }
    }
        //if l_vmes > at 3,5 et que la valeur a changer, setDayMode else setNihntMode
    delay(1500);   
}

void setDayMode(int *l_mode) {
    tone(BUZZER_PIN,100,2000);
    Serial.println("Day mode !!");
    digitalWrite(LED_GREEN_PIN, HIGH);
    light_servo.write(SERVO_POS_DAY);
    digitalWrite(LED_RED_PIN, LOW);
    noTone(BUZZER_PIN);
    *l_mode = 1;
} 

void setNightMode(int *l_mode) {
    tone(BUZZER_PIN,100,2000);
    Serial.println("Night Mode");
    digitalWrite(LED_RED_PIN, HIGH);
    light_servo.write(SERVO_POS_NIGHT);
    digitalWrite(LED_GREEN_PIN, LOW);
    noTone(BUZZER_PIN);
    *l_mode = 0;
}