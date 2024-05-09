/*
Fundacion kinal
Centro Educativo Tecnico Laboral Kinal
Quinto Perito 
Quinto Electronica
Codigo Tecnico: EB5AV
Curso: TALLER ELECTRONICA DIGITAL Y REPARACION DE COMPUTADORAS I
Proyecto: Cancion Star Wars con buzzer
Dev: Pether Anderson David Reyes Guzman
Fecha: 07 de mayo
*/
#define c 261.626
#define reb 277.183
#define re 293.665
#define mi  329.628
#define mib 311.127
#define fa 349.228  
#define sol 391.995
#define solb 369.994 
#define la 440
#define lab 415.305
#define si 493.883
#define sib 466.164
int redonda=1000, blanca=500, negra=250, corchea=125, semicorchea=62;
int fusa=31, semifusa=15;
void setup()
{
  pinMode(2, OUTPUT);
}

void notas(int nota, int duracion){
  tone(2,nota,duracion);
  delay(duracion);
  noTone(2);
  delay(duracion);
}
void loop()
{
  notas(sol ,negra);
  notas(sol ,negra);
  notas(sol ,negra);
  notas(mib ,corchea);
  notas(sib ,corchea);
  notas(sol ,negra);
  notas(re ,corchea);
  notas(re ,corchea);
  notas(re ,blanca);
  notas(mib ,negra);
  notas(sib ,negra);
  notas(solb ,negra);
  notas(mib ,corchea);
  notas(sib ,corchea);
  notas(sol ,negra);
  notas(sol ,corchea);
  notas(sol ,corchea);
  notas(sol ,blanca);
  notas(sol ,corchea);
  notas(solb ,semicorchea);
  notas(fa ,negra);
  notas(mi ,corchea);
  notas(mib ,semicorchea);
  notas(mi ,semicorchea);
  notas(lab ,semicorchea);
  notas(reb ,corchea);
  notas(c ,fusa);
  notas(si ,negra);
  notas(sib ,corchea);
  notas(la ,semicorchea);
  notas(sib ,semicorchea);
  notas(mib ,semicorchea);
  notas(solb ,corchea);
  notas(mib ,fusa);
  notas(solb ,negra);
  notas(sib ,corchea);
  notas(sol ,semicorchea);
  notas(sib ,negra);
  notas(re ,corchea);
  notas(sol ,semicorchea);
  notas(sol ,blanca);
  notas(sol ,negra);
  notas(sol ,corchea);
  notas(solb ,semicorchea);
  notas(fa ,negra);
  notas(mi ,corchea);
  notas(mib ,semicorchea);
  notas(mi ,semicorchea);
  notas(lab ,semicorchea);
  notas(reb ,corchea);
  notas(c ,fusa);
  notas(si ,negra);
  notas(sib ,corchea);
  notas(la ,semicorchea);
  notas(sib ,semicorchea);
  notas(mib ,corchea);
  notas(solb ,fusa);
  notas(mib ,negra);
  notas(sib ,corchea);
  notas(sol ,negra);
  notas(mib ,corchea);
  notas(sib ,semicorchea);
  notas(sol ,blanca);
}
