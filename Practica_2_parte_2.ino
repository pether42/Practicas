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
#define ledNaranja 4 //pin4 conectado a un led 
#define tiempo_espera 500 //tiempo entre estados del led

void setup()
{
  pinMode(ledNaranja, OUTPUT); //pin4 como salida.
  digitalWrite(ledNaranja, LOW); //LED conectado al pin13 inicia apagado  
}

void loop()
{
  digitalWrite(ledNaranja, HIGH); //Encendido el led conectado al pin4
  delay(tiempo_espera); //espera de 500 milisegundos.
  digitalWrite(ledNaranja, LOW); //Apago el led conectado al pin4
  delay(tiempo_espera); //espera de 500 milisegundos 
}
