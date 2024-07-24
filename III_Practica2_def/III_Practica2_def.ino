/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Practica 2
   Dev: Pether Reyes
   Fecha: 16 de julio.
*/

//Librerias
#include <Wire.h>                   //libreria para usar el protocolo i2c
#include <SparkFun_ADXL345.h>       //libreria para usar el acelerometro ADXL345
#define led1 2
#define led2 3
#define led3 4
#define led4 5
#define led5 6
#define led6 7
#define led7 8
#define alerta 9
#define ON(pin) digitalWrite(pin, HIGH);
#define OFF(pin) digitalWrite(pin, LOW);
#define salida(pin) pinMode(pin, OUTPUT)

byte a=0;

//Constructores
ADXL345 acc_sismo = ADXL345();          //constructor para usar el acelerometro
//Variables
/*
Declaro las 3 variables, donde guardo los valores de aceleracion de caada eje
*/
unsigned int acc_X;         //aceleracion en el eje x
unsigned int acc_Y;         //aceleracion en el eje y
unsigned int acc_Z;         //aceleracion en el eje z

//Variable donde guardo la magnitud del vector aceleracion
unsigned int magnitud_acc;

//Configuraciones
void setup() {
  ON(alerta);
  salidas ();
  acc_sismo.powerOn();            //Enciendo el acelerometro
  acc_sismo.setRangeSetting(8);    //Configuro la sensibbilidad del acelerometro
}


void loop() {
  
  //Leo las variables medidas por el acelerometro
  acc_sismo.readAccel(&acc_X,&acc_Y,&acc_Z);
  
  //obtengo la magnitud del vector aceleracion
  magnitud_acc = sqrtf((acc_X*acc_X)+(acc_Y*acc_Y)+(acc_Z*acc_Z));
  Serial.println(magnitud_acc);
  int mapeo_intensidad = map(magnitud_acc,65, 72, 1, 7);
  control_leds(mapeo_intensidad);
  
}
void control_leds (float i){
  if(i<1){
    ON(alerta);
    OFF(led1)
    OFF(led2)
    OFF(led3)
    OFF(led4)
    OFF(led5)
    OFF(led6)
    OFF(led7)}
  if(i>=1&&i<=1.99){
    ON(alerta);
    ON(led1)
    OFF(led2)
    OFF(led3)
    OFF(led4)
    OFF(led5)
    OFF(led6)
    OFF(led7) }
    if(i>=2&&i<=2.99){
    ON(alerta); 
    ON(led1)
    ON(led2)
    OFF(led3)
    OFF(led4)
    OFF(led5)
    OFF(led6)
    OFF(led7)}
    if(i>=3&&i<=3.99){
    ON(alerta);
    ON(led1)
    ON(led2)
    ON(led3)
    OFF(led4)
    OFF(led5)
    OFF(led6)
    OFF(led7)}
    if(i>=4&&i<=4.99){
    ON(alerta);
    ON(led1)
    ON(led2)
    ON(led3)
    ON(led4)
    OFF(led5)
    OFF(led6)
    OFF(led7)}
    if(i>=5&&i<=5.99){
    ON(alerta);
    ON(led1)
    ON(led2)
    ON(led3)
    ON(led4)
    ON(led5)
    OFF(led6)
    OFF(led7)}
    if(i>=6&&i<=6.99){
    OFF(alerta);  
    ON(led1)
    ON(led2)
    ON(led3)
    ON(led4)
    ON(led5)
    ON(led6)
    OFF(led7)}
    delay(900);
    if(i>6.99){
    OFF(alerta);
    ON(led1)
    ON(led2)
    ON(led3)
    ON(led4)
    ON(led5)
    ON(led6)
    ON(led7)
    delay(5000);
}}

void salidas (){
   for(byte i=2;i<12;i++){
    salida(i);} 
}  
