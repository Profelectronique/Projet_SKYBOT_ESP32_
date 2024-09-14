#include <Arduino.h>
#define TRIG 5 //pin 5 carte UNO pour envoyer pulse de 10µs
#define ECHO 4 // pin 4 carte UNO pour recevoir pulse Echo
const long TIMEOUT = 30000UL; // 30ms soit mesure à moins de 6m25
unsigned long distance; //
const int ledPinVert = 22;
const int ledPinRouge = 23;
const int seuil=10;
void setup() {
 pinMode(ledPinVert, OUTPUT);
 pinMode(ledPinRouge, OUTPUT);
 pinMode(TRIG,OUTPUT); // configuration pin TRIG en sortie, elle sera raccordée à l'entrée Trig du capteur HC-SR04
 pinMode(ECHO,INPUT); // configuration pin ECHO en entrée, elle sera raccordée à la sortie Echo du capteur HCSR04
 digitalWrite(TRIG, LOW); //Elle doit être à 0 au démarrage
 Serial.begin(115200);
}
void loop() {
 //création impulsion trigger de 10µs
 digitalWrite(TRIG,HIGH);
 delayMicroseconds(10);
 digitalWrite(TRIG, LOW);
 //mesure de la distance en cm capteur / cible
 distance = pulseIn(ECHO, HIGH, TIMEOUT)/58;
 //Affichage mesure toutes les 0.5 seconde
 Serial.print("Distance = ");
 Serial.print(distance);
 Serial.println(" cm");
 delay(500);
 if (distance>seuil) {
  digitalWrite(ledPinRouge, LOW);   // Eteindre le LED Rouge(LOW)
digitalWrite(ledPinVert, HIGH);   // Allumer le LED Vert (HIGH)
 }
 else
 {
  digitalWrite(ledPinVert, LOW);   // Eteindre le LED Vert(LOW)
digitalWrite(ledPinRouge, HIGH);   // Allumer le LED Rouge (HIGH)  
  }
 }