#define salida(pin) pinMode(pin, OUTPUT)
#define entrada(pin) pinMode(pin, INPUT)
#define leer(pin) digitalRead(pin)
#define on(pin) digitalWrite(pin, HIGH)
#define off(pin) digitalWrite(pin, LOW)
#define pausa delay(200)
#define ascendente 10
#define descendente 11
#define on1_1 on(2)
#define on1_2 on(3)
#define on1_3 on(2); on(3)
#define on1_4 on(4)
#define on1_5 on(2); on(4)
#define on1_6 on(3); on(4)
#define on1_7 on(2); on(3); on(4)
#define on1_8 on(5)
#define on1_9 on(2); on(5)
#define off1_1 off(2)
#define off1_2 off(3)
#define off1_3 off(2); off(3)
#define off1_4 off(4)
#define off1_5 off(2); off(4)
#define off1_6 off(3); off(4)
#define off1_7 off(2); off(3); off(4)
#define off1_8 off(5)
#define off1_9 off(2); off(5)
#define on2_1 on(6)
#define on2_2 on(7)
#define on2_3 on(6); on(7)
#define on2_4 on(8)
#define on2_5 on(6); on(8)
#define on2_6 on(7); on(8)
#define on2_7 on(6); on(7); on(8)
#define on2_8 on(9)
#define on2_9 on(6); on(9)
#define off2_1 off(6)
#define off2_2 off(7)
#define off2_3 off(6); off(7)
#define off2_4 off(8)
#define off2_5 off(7); off(8)
#define off2_6 off(7); off(8)
#define off2_7 off(6); off(7); off(8)
#define off2_8 off(9)
#define off2_9 off(6); off(9)
byte i = 0, b = 0;

void setup()
{
  salida(2);
  salida(3);
  salida(4);
  salida(5);
  salida(6);
  salida(7);
  salida(8);
  salida(9);
  entrada(ascendente);
  entrada(descendente);
}

void loop()
{
  if(leer(ascendente)==HIGH&&i<10&&b<9){
    i = i+1;
     }
  else if(leer(ascendente)==HIGH&&i<9&&b==9){
    i = i+1;}
  if(leer(descendente)==HIGH&&i>0){
    i-= 1;
    }
  else if(leer(descendente)==HIGH&&i==0&&b>0){
    i= i-1;}
  if(i==255&&b>0){
    i = 9;
    b = b-1;}
  if(i==0){
    off1_1;
    pausa;}
  if(i==1){
    i=1;
    on1_1;
    off1_2;
    pausa;}
  if(i==2){
    i=2;
    off1_1;
    off1_3;
    on1_2;
    pausa;}
  if(i==3){
    off1_2;
    off1_4;
    on1_3;
    pausa;}
  if(i==4){
    off1_3;
    off1_5;
    on1_4;
    pausa;}
  if(i==5){
    off1_4;
    off1_6;
    on1_5;
    pausa;}
  if(i==6){
    off1_5;
    off1_7;
    on1_6;
    pausa;}
  if(i==7){
    off1_6;
    off1_8;
    on1_7;
    pausa;}
  if(i==8){
    off1_7;
    off1_9;
    on1_8;
    pausa;}
  if(i==9){
    off1_8;
    on1_9;
    pausa;}
  if(i==10){
    off1_9;
    i = 0;
    b = b+1;
    pausa;}
  
    if(b==0){
    off2_1;
    pausa;}
  if(b==1){
    on2_1;
    off2_2;
    pausa;}
  if(b==2){
    off2_1;
    off2_3;
    on2_2;
    pausa;}
  if(b==3){
    off2_2;
    off2_4;
    on2_3;
    pausa;}
  if(b==4){
    off2_3;
    off2_5;
    on2_4;
    pausa;}
  if(b==5){
    off2_4;
    off2_6;
    on2_5;
    pausa;}
  if(b==6){
    off2_5;
    off2_7;
    on2_6;
    pausa;}
  if(b==7){
    off2_6;
    off2_8;
    on2_7;
    pausa;}
  if(b==8){
    off2_7;
    off2_9;
    on2_8;
    pausa;}
  if(b==9){
    off2_8;
    on2_9;
    pausa;}
      
}
