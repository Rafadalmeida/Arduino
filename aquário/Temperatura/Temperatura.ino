//Sonda temperatura
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float Celsius = 0;


//Relay´s
int RelayControl1 = 9;  //funciona 19/02/2020 como led verde 
int RelayControl2 = 10;
int RelayControl3 = 11;
int RelayControl4 = 12; 

//Parámetros
int tempmedia = 26; 

//Buzzer
const int buzzer = 3;

void setup() {
  sensors.begin();
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT); 
  pinMode(4,OUTPUT); //blue1
  pinMode(5,OUTPUT); //blue2
  pinMode(6,OUTPUT); //Yellow
  pinMode(7,OUTPUT); //red1
  pinMode(8,OUTPUT); //red2
  
  pinMode(RelayControl1, OUTPUT);
  pinMode(RelayControl2, OUTPUT);
  pinMode(RelayControl3, OUTPUT);
  pinMode(RelayControl4, OUTPUT);

  digitalWrite(RelayControl1,HIGH);
  digitalWrite(RelayControl2,LOW);
  digitalWrite(RelayControl3,LOW);
  digitalWrite(RelayControl4,LOW);

delay(1000);
   digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
delay(1000);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
delay(1000);

}

void loop()

{
 
//Obtenção temperatura  
  sensors.requestTemperatures();
  Celsius = sensors.getTempCByIndex(0);
  Serial.print(Celsius);
  Serial.print(" C  ");

//Condições de Alarmes
 
//Temp Muito Baixa
 if ( Celsius <= tempmedia-1.00) {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
        tone(buzzer, 2000); 
          delay(1000); 
            noTone(buzzer);
              delay(1000);
    //digitalWrite(RelayControl2,HIGH);
    
  }
 
 //Temp Baixa
 
else if ( Celsius <= tempmedia-0.50) {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    //digitalWrite(RelayControl2,HIGH);    
  }


 //Temp Alta
 else if ( Celsius >= tempmedia+0.50) {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
 
  }


   
   //Temp Boa
 else {
    noTone(buzzer);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    //digitalWrite(RelayControl1,HIGH);
    //digitalWrite(RelayControl2,LOW);
 
  }

  //Temp muito alta
if ( Celsius >= tempmedia+1.00){
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
        tone(buzzer, 1000); 
          delay(1000); 
            noTone(buzzer);
              delay(1000);
    //digitalWrite(RelayControl1,LOW);
   }
  