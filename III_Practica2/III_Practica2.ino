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
#include <SoftwareSerial.h>        //libreria para emular otro puerto serie
#include <DFRobotDFPlayerMini.h>    //libreria para usar el reproductor MP3
#define led1 2
#define led2 3
#define led3 4
#define led4 5
#define led5 6
#define led6 7
#define led7 8
#define on(pin) digitalWrite(pin, HIGH)
#define off(pin) digitalWrite(pin, LOW)
#define salida(pin) pinMode(pin, OUTPUT);

//Constructores
ADXL345 acc_sismo = ADXL345();          //constructor para usar el acelerometro
SoftwareSerial mp3_sismo(9,10);         //RX 9 y TX 10
DFRobotDFPlayerMini reproductor_MP3;    //constructor para el reproductor MP3
//Variables
/*
Declaro las 3 variables, donde guardo los valores de aceleracion de caada eje
*/
unsigned int acc_X;         //aceleracion en el eje x
unsigned int acc_Y;         //aceleracion en el eje y
unsigned int acc_Z;         //aceleracion en el eje z

//Variable donde guardo la magnitud del vector aceleracion
float magnitud_acc;

//Configuraciones
void setup() {
  salidas ();
  mp3_sismo.begin(9600);           //Inicio la comunicacion serial emulada para el mp3
  acc_sismo.powerOn();            //Enciendo el acelerometro
  acc_sismo.setRangeSetting(8);    //Configuro la sensibbilidad del acelerometro
}

void loop() {
  
  //Leo las variables medidas por el acelerometro
  acc_sismo.readAccel(&acc_X,&acc_Y,&acc_Z);
  
  //obtengo la magnitud del vector aceleracion
  magnitud_acc = sqrtf((acc_X*acc_X)+(acc_Y*acc_Y)+(acc_Z*acc_Z));
  
  float mapeo_intensidad = map(magnitud_acc,49, 75, 0, 10);

  control_leds(mapeo_intensidad);
}
void control_leds (float i){
  if(i<1){
    reproductor_MP3.volume(0);
    off(led1);
    off(led2);
    off(led3);
    off(led4);
    off(led5);
    off(led6);
    off(led7);}
  if(i>=1&&i<=1.99){
    reproductor_MP3.volume(0);
    on(led1);
    off(led2);
    off(led3);
    off(led4);
    off(led5);
    off(led6);}
    if(i>=2&&i<=2.99){
    reproductor_MP3.volume(0);  
    on(led1);
    on(led2);
    off(led3);
    off(led4);
    off(led5);
    off(led6);
    off(led7);}
    if(i>=3&&i<=3.99){
    reproductor_MP3.volume(0);  
    on(led1);
    on(led2);
    on(led3);
    off(led4);
    off(led5);
    off(led6);
    off(led7);}
    if(i>=4&&i<=4.99){
    reproductor_MP3.volume(0);  
    on(led1);
    on(led2);
    on(led3);
    on(led4);
    off(led5);
    off(led6);
    off(led7);}
    if(i>=5&&i<=5.99){
    reproductor_MP3.volume(0);
    on(led1);
    on(led2);
    on(led3);
    on(led4);
    on(led5);
    off(led6);
    off(led7);}
    if(i>=6&&i<=6.99){
    on(led1);
    on(led2);
    on(led3);
    on(led4);
    on(led5);
    on(led6);
    off(led7);}
    if(i>6.99){
    on(led1);
    on(led2);
    on(led3);
    on(led4);
    on(led5);
    on(led6);
    on(led7);
    //Reproduzco la cancion
  reproductor_MP3.volume(25);       //volumen al maximo
  reproductor_MP3.play(1);        //reproduzco la cancion}  
}}

void salidas (){
   for(byte i=2;i<8;i++){
    salida(i);} 
}  
