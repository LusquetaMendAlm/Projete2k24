#include <WiFi.h>
#include "time.h"
#include "esp_sntp.h"
#include <HX711.h>

// DEFINIÇÕES DE PINOS
#define pinDT  22
#define pinSCK  23

// DEFINIÇÕES
#define PesoMin 0.010
#define PesoMax 5.0

#define Escala 0.0f

//INICIANDO OBJETOS
HX711 scale;

// DECLARAÇÃO DE VARIÁVEIS  
float Medida=0;

//REDE
const char *ssid = "alunos";
const char *password = "etefmc123";
//const char *ssid = "VICENTE";
//const char *password = "cambalacho";

//NTP
const char *ntpServer1 = "pool.ntp.org";
const char *ntpServer2 = "time.nist.gov";
const long gmtOffset_sec = -5400;
const int daylightOffset_sec = -5400;

void VerificacaoDoPeso() {
  scale.power_up(); // LIGANDO O SENSOR
    
  Medida = scale.get_units(5); // SALVANDO NA VARIAVEL O VALOR DA MÉDIA DE 5 MEDIDAS
    
  if (Medida <= PesoMin ){ // CONFERE SE A MASSA ESTÁ NA FAIXA VÁLIDA
    scale.tare(); // ZERA A BALANÇA CASO A MASSA SEJA MENOR QUE O VALOR MIN
    Medida = 0;
    Serial.println("Tara Configurada!");
  } 
  else if ( Medida >= PesoMax ){
    scale.tare(); // ZERA A BALANÇA CASO A MASSA SEJA MAIOR QUE O VALOR MÁX
    Medida = 0;
    Serial.println("Tara Configurada!");
  } 
  else {
    Serial.println(Medida,3);
  }

  scale.power_down(); // DESLIGANDO O SENSOR
}

void printLocalTime() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("No time available (yet)");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}

void timeavailable(struct timeval *t) {
  Serial.println("Got time adjustment from NTP!");
  printLocalTime();
}

void setup() {
  Serial.begin(115200);

  //Connecting to Wifi
  Serial.printf("Connecting to %s", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" CONNECTED");

  sntp_set_time_sync_notification_cb(timeavailable);

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer1, ntpServer2);

  scale.begin(pinDT, pinSCK); // CONFIGURANDO OS PINOS DA BALANÇA
  scale.set_scale(Escala); // ENVIANDO O VALOR DA ESCALA CALIBRADO

  delay(2000);
  scale.tare(); // ZERANDO A BALANÇA PARA DESCONSIDERAR A MASSA DA ESTRUTURA
  Serial.println("Balança zerada!");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  printLocalTime();
}
