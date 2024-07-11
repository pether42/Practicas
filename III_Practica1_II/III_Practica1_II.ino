/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Practica 1 II
   Dev: Pether Reyes
   Fecha: 11 de julio
*/

#define IN1  2
#define IN2  3
#define IN3  4
#define IN4  5
#define llaves 6
#define contador_rev 7
#define potenciometro A0
#define salida(pin) pinMode(pin, OUTPUT); 
#define entrada(pin) pinMode(pin, INPUT);
#define leer(pin) digitalRead(pin)
#define leer_vol(pin) analogRead(pin)
#define llave_puesta LOW
#define llave_nopuesta HIGH

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

int contador=0, a=0;
unsigned char velocidades;

LiquidCrystal_I2C lcd(0x27,16,2);

int paso [8][4] =
{
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};
 
void setup()
{ 
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Contador de rev.");
  lcd.setCursor(0,1);
  lcd.print("No. de rev.:");
  entrada(contador_rev);
  entrada(potenciometro);
  entrada(llaves);
  salida(IN1);
  salida(IN2);
  salida(IN3);
  salida(IN4);
  
}
 
  
void loop()
{  if(leer(contador_rev)==LOW){
     if (a==0){
     contador++;
     a++;   }}
   if(leer(contador_rev)==HIGH){
     a=0;}
   lcd.setCursor(13,1);
   lcd.print(contador);
   velocidades = map(leer_vol(potenciometro),0,1023,0,10);
   Serial.println(velocidades);
  if(leer(llaves)==llave_puesta){
     for (int i = 0; i < 8; i++)
    {
      digitalWrite(IN1, paso[i][0]);
      digitalWrite(IN2, paso[i][1]);
      digitalWrite(IN3, paso[i][2]);
      digitalWrite(IN4, paso[i][3]);
      delay(velocidades);
    }}
  if(leer(llaves)==llave_nopuesta){
     contador=0;}
} 
