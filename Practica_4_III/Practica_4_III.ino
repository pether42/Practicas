#define salida(pin) pinMode(pin, OUTPUT)
#define entrada(pin) pinMode(pin, INPUT)
#define leer(pin) digitalRead(pin)
#define on(pin) digitalWrite(pin, HIGH)
#define off(pin) digitalWrite(pin, LOW)
#define sw1 2
#define sw2 3
#define sw3 4
#define sw4 5
#define pausa1 delay(500)
#define pausa2 delay(2000)
#define ida on(6); pausa1; off(6); on(7); pausa1; off(7); on(8);pausa1; off(8); on(9); pausa1; off(9); on(10); pausa1; off(10); on(11); pausa1; off(11)
#define regreso on(11); pausa1; off(11); on(10); pausa1; off(10); on(9);pausa1; off(9); on(8); pausa1; off(8); on(7); pausa1; off(7); on(6); pausa1; off(6)
#define pausa1 delay(500)
#define onall on(6); on(7); on(8); on(9); on(10); on(11) 
#define offall off(6); off(7); off(8); off(9); off(10); off(11)
#define escribir Serial.print
#define escribir_es Serial.println
#define da A0
#define db A1
#define dc A2
#define dd A3
#define de A4
#define df A5
#define dg 12
#define onc on(da); on(dd); on(de); on(df) 
#define offc off(da); off(dd); off(de); off(df)
#define onu on(dc); on(dd); on(de)
#define offu off(dc); off(dd); off(de)
#define ona on(da); on(db); on(dc); on(de); on(df); on(dg)
#define offa off(da); off(db); off(dc); off(de); off(df); off(dg)
#define ont on(dd); on(de); on(df); on(dg)
#define offt off(dd); off(de); off(df); off(dg)
#define onr on(de); on(dg)
#define offr off(de); off(dg)
#define ono on(dc); on(dd); on(de); on(dg)
#define offo off(dc); off(dd); off(de); off(dg)
byte a=0,b=0,c=0,d=0,e=0;

void setup()
{ 
  Serial.begin(9600);
  salida(12);
  salida(11);
  salida(10);
  salida(9);
  salida(8);
  salida(7);
  salida(6);
  salida(da);
  salida(db);
  salida(dc);
  salida(dd);
  salida(de);
  salida(df);
  salida(dg);
  entrada(5);
  entrada(4);
  entrada(3);
  entrada(2);
}

void loop()
{  
  if(leer(sw1)==LOW&&leer(sw2)==HIGH&&leer(sw3)==HIGH&&leer(sw4)==HIGH){
    if(a==0){
    escribir_es("Practica no.4");
    pausa1;    
    escribir("Nombre: ");
    escribir_es("Pether Anderson David Reyes Guzman");
    escribir("Apellido: ");
    escribir_es("Reyes Guzman");
    a+=1; }}
    if(leer(sw1)==HIGH){
      a = 0;}  
   if(leer(sw1)==HIGH&&leer(sw2)==LOW&&leer(sw3)==HIGH&&leer(sw4)==HIGH)
   {   if(b==0){
   ida;  
   regreso;
   ida;  
   regreso;
   ida;  
   regreso;
   onall;
   pausa1; 
   offall;
   pausa1;
   onall;
   pausa1; 
   offall;
   pausa1; 
   onall;
   pausa1; 
   offall;
   pausa1;
   onall;
   pausa1; 
   offall;
   b+=1;
   }}
   if(leer(sw2)==HIGH){
      b = 0;}
  if(leer(sw1)==HIGH&&leer(sw2)==HIGH&&leer(sw3)==LOW&&leer(sw4)==HIGH)
   {  if(c==0){
     onc;
     pausa2;
     offc;
     onu;
     pausa2;
     offu;
     ona;
     pausa2;
     offa;
     ont;
     pausa2;
     offt;
     onr;
     pausa2;
     offr;
     ono;
     pausa2;
     offo;
     c++;}}
   if(leer(sw3)==HIGH){
      c=0; }
  if(leer(sw1)==LOW&&leer(sw2)==HIGH&&leer(sw3)==LOW&&leer(sw4)==HIGH)
  { if(d==0){
    escribir_es("Gracias por su atencion");
    d++;
    a=0;
    c=0;}}
  if(leer(sw1)==HIGH&&leer(sw3)==LOW||leer(sw1)==LOW&&leer(sw3)==HIGH)
  { d=0;}
   if(leer(sw2)==LOW&&leer(sw4)==LOW&&leer(sw1)==HIGH)
  { if(e==0){
    escribir_es("Gracias por su atencion");
    e=1;
    b=0;}}
  if(leer(sw2)==HIGH&&leer(sw4)==LOW&&leer(sw1)==HIGH||leer(sw2)==LOW&&leer(sw4)==HIGH)
  {e=0;}
 
}
