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

int velocidad=0, a=0, revoluciones=0;
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
  lcd.print("Control de rev.");
  lcd.setCursor(0,1);
  lcd.print("vel: 0     0rpm");
  entrada(contador_rev);
  entrada(potenciometro);
  entrada(llaves);
  salida(IN1);
  salida(IN2);
  salida(IN3);
  salida(IN4);
  Serial.begin(9600);
  
}
 
  
void loop()
{  if(leer(contador_rev)==LOW){
     if (a==0){
     a++;  
    lcd.setCursor(8,1);
    if(revoluciones==1){
    lcd.print("4.5"); }
    if(revoluciones==2){
    lcd.print("4.1"); }
    if(revoluciones==3){
    lcd.print("3.3"); }
    if(revoluciones==4){
    lcd.print("2.5"); }
    if(revoluciones==5){
    lcd.print("2.2"); }
     if(revoluciones==6){
    lcd.print("1.9"); }    
     }}
   if(leer(contador_rev)==HIGH){
     a=0;}
    velocidades = map(leer_vol(potenciometro),0,1023,0,8);
  if(leer(llaves)==llave_puesta){
     for (int i = 0; i < 8; i++)
    { digitalWrite(IN1, paso[i][0]);
      digitalWrite(IN2, paso[i][1]);
      digitalWrite(IN3, paso[i][2]);
      digitalWrite(IN4, paso[i][3]);
      lcd.setCursor(5,1);
      control_vel(velocidades);
      control_rev(velocidades);
      lcd.print(velocidad);
      delay(velocidades);
      
    }}
  if(leer(llaves)==llave_nopuesta){
    lcd.setCursor(5,1);
    lcd.print("0");
    lcd.setCursor(8,1);
    lcd.print("   0");
     }
} 
void control_vel(int i){
   if(i==2){
    velocidad=1;
   }
   if(i==3){
    velocidad=2;
     }
   if(i==4){
    velocidad=3;
   }
   if(i==5){
    velocidad=4;
   }
   if(i==6){
    velocidad=5;
   }
   if(i==7){
    velocidad=6;
   }}
void control_rev(int i){
   if(i==2){
    revoluciones=1;
   }
   if(i==3){
    revoluciones=2;
     }
   if(i==4){
    revoluciones=3;
   }
   if(i==5){
    revoluciones=4;
   }
   if(i==6){
    revoluciones=5;
   }
   if(i==7){
    revoluciones=6;
   }
}
  

 
