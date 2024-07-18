/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Practica 3
   Dev: Pether Reyes
   Fecha: 18 de julio.

*/


//Librerias
#include <LedControl.h>         //Libreria que me permita usar el IC MAX7219 (matriz led)

//Directivas de preprocesador
#define din_matrix        3     //pin3 del arduino conectado al pin DIN de la matriz led
#define cs_matrix         2     //pin2 del arduino conectado al pin CS de la matriz led
#define clk_matrix        4     //pin4 del arduino conectado al pin CLK de la matriz led

//Constructores
//Voy a controlar con el objeto PacmanMatrix un arreglo de 1 matriz led
LedControl PacmanMatrix = LedControl(din_matrix, clk_matrix, cs_matrix,1);

//Variables
//Array que contiene los valores binarios para representar un pacman con la boca abierta
byte pacman_boca_abierta[8]= {
  B00111000,
  B01000100,
  B10001000,
  B10010000,
  B10001000,
  B01000100,
  B00111000,
  B00000000
};
byte pacman_boca_cerrada[8]=
{
  B00111000,
  B01000100,
  B10000010,
  B10011110,
  B10000010,
  B01000100,
  B00111000,
  B00000000
};
//Configuraciones
void setup()
{
  Serial.begin(9600); //Inicio la comunicacion serial a 9600 baudios.
  PacmanMatrix.shutdown(0, false);    //Encendiendo mi matriz led. 
  PacmanMatrix.setIntensity(0,15);    //Configuro el brillo de la matriz led a la mitad (este valor puede ser desde el 0 al 30)
  PacmanMatrix.clearDisplay(0);        //limpio la pantalla de alguna animacion.
  Serial.println("Uso de la matriz led");
  pinMode(A0, INPUT);

}


//Ciclo infinito
void loop()
{
  print_pacman_open();
  delay(analogRead(A0));
  print_pacman_close();
  delay(analogRead(A0));
}

void print_pacman_open(void)
{      
  for(int i=0; i<8;i++)
  {
    PacmanMatrix.setRow(0,i,pacman_boca_abierta[i]);
  }
}

void print_pacman_close(void)
{
  for(int i=0; i<8;i++)
  {
    PacmanMatrix.setRow(0,i,pacman_boca_cerrada[i]);
  }
}
