/*
Fundacion kinal
Centro Educativo Tecnico Laboral Kinal
Quinto Perito 
Quinto Electronica
Codigo Tecnico: EB5AV
Curso: TALLER ELECTRONICA DIGITAL Y REPARACION DE COMPUTADORAS I
Proyecto: Como leer un pin digital 
Dev: Profe. Alejandro Lopez Navas
Fecha: 12 de abril
*/

//Directivas del prepocesador 
#define push_button 2 //push button conectado al pin2
#define led 3
 
void setup() {
  pinMode(push_button,INPUT); //pin2 como entrada 
  pinMode(led,OUTPUT);
  Serial.begin(9600);                       //Inicio la comunicacion serial 
  Serial.println("Lectura de un pulsador"); //Envio el texto entre comillas al puerto serie
}
 
void loop(){
  //Variable local,que se encarga de almacenar el valor (abierto o cerrado)
  //del pulsador conectado al pin2
  bool estado_button = digitalRead(push_button);
  if(estado_button == HIGH) //¿He presionado el interruptor?
  {
    //si lo he presionado 
    digitalWrite(led, LOW);  //apago el led 
  } else {
    //si no lo he presionado 
    digitalWrite(led, HIGH); //mantengo encendido el led 
  } 
 
}
