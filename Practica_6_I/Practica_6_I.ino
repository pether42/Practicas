/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Practica 6 I
   Dev: Pether Reyes
   Fecha: 16 de mayo
   
*/
#include <LiquidCrystal.h>

long carne = 2019427;

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd_1.begin(16, 2);
  lcd_1.clear();
  lcd_1.print("Pether");
  lcd_1.setCursor(0, 1);
  lcd_1.print(carne);
}

void loop()
{ 
  delay(6000);
  lcd_1.clear();
}
