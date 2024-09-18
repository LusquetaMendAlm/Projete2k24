#include <WiFi.h>
#include "time.h"
#include "esp_sntp.h"
#include <HX711.h>

#define PORCOES2HORARIO1 8
#define PORCOES2HORARIO2 20

#define PORCOES3HORARIO1 6
#define PORCOES3HORARIO2 14
#define PORCOES3HORARIO3 22

#define PORCOES4HORARIO1 6
#define PORCOES4HORARIO2 12
#define PORCOES4HORARIO3 18
#define PORCOES4HORARIO4 24

#define TEMPOPEQUENO 1000
#define TEMPOMEDIO 2000
#define TEMPOGRANDE 4000

#define PinSTM32 4

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

  pinMode(PinSTM32, OUTPUT);

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
  
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Falha ao obter o tempo.");
    return;
  }

  Serial.println("Tempo sincronizado!");
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}

void loop() {
  struct tm timeinfo;
  if (getLocalTime(&timeinfo)) {
    // Exibir o horário atual
    Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
    
    switch ( Porte) {
    // Porte pequeno 120g diárias
      case 1:
        switch( Refeicoes){
          case 2:
          if (timeinfo.tm_hour == PORCOES2HORARIO1 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOPEQUENO);
          digitalWrite(PinSTM32, LOW);
          }
          else if (timeinfo.tm_hour == PORCOES2HORARIO2 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOPEQUENO);
          digitalWrite(PinSTM32, LOW);
          }
          break;

          case 3:
          if (timeinfo.tm_hour == PORCOES3HORARIO1 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOPEQUENO);
          digitalWrite(PinSTM32, LOW);
          }
          else if (timeinfo.tm_hour == PORCOES3HORARIO2 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOPEQUENO);
          digitalWrite(PinSTM32, LOW);
          }
          else if (timeinfo.tm_hour == PORCOES3HORARIO3 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOPEQUENO);
          digitalWrite(PinSTM32, LOW);
          }
          break;

          case 4:
          if (timeinfo.tm_hour == PORCOES4HORARIO1 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOPEQUENO);
          digitalWrite(PinSTM32, LOW);
          }
          else if (timeinfo.tm_hour == PORCOES4HORARIO2 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOPEQUENO);
          digitalWrite(PinSTM32, LOW);
          }
          else if (timeinfo.tm_hour == PORCOES4HORARIO3 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOPEQUENO);
          digitalWrite(PinSTM32, LOW);
          }
          else if (timeinfo.tm_hour == PORCOES4HORARIO4 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOPEQUENO);
          digitalWrite(PinSTM32, LOW);
          }
          break;
        }
      break;
      //Porte médio 240g diárias
      case 2:
        switch( Refeicoes){
          case 2:
          if (timeinfo.tm_hour == PORCOES2HORARIO1 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOMEDIO);
          digitalWrite(PinSTM32, LOW);
          }
          else if (timeinfo.tm_hour == PORCOES2HORARIO2 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOMEDIO);
          digitalWrite(PinSTM32, LOW);
          }
          break;

          case 3:
          if (timeinfo.tm_hour == PORCOES3HORARIO1 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOMEDIO);
          digitalWrite(PinSTM32, LOW);
          }
          else if (timeinfo.tm_hour == PORCOES3HORARIO2 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOMEDIO);
          digitalWrite(PinSTM32, LOW);
          }
          else if (timeinfo.tm_hour == PORCOES3HORARIO3 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOMEDIO);
          digitalWrite(PinSTM32, LOW);
          }
          break;

          case 4:
          if (timeinfo.tm_hour == PORCOES4HORARIO1 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOMEDIO);
          digitalWrite(PinSTM32, LOW);
          }
          else if (timeinfo.tm_hour == PORCOES4HORARIO2 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOMEDIO);
          digitalWrite(PinSTM32, LOW);
          }
          else if (timeinfo.tm_hour == PORCOES4HORARIO3 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOMEDIO);
          digitalWrite(PinSTM32, LOW);
          }
          else if (timeinfo.tm_hour == PORCOES4HORARIO4 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOMEDIO);
          digitalWrite(PinSTM32, LOW);
          }
          break;
        }
      break;
      //Porte Grande 520g diárias
      case 3:
        switch( Refeicoes){
          case 2:
          if (timeinfo.tm_hour == PORCOES2HORARIO1 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOGRANDE);
          digitalWrite(PinSTM32, LOW);
          }
          else if (timeinfo.tm_hour == PORCOES2HORARIO2 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOGRANDE);
          digitalWrite(PinSTM32, LOW);
          }
          break;

          case 3:
          if (timeinfo.tm_hour == PORCOES3HORARIO1 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOGRANDE);
          digitalWrite(PinSTM32, LOW);
          }
          else if (timeinfo.tm_hour == PORCOES3HORARIO2 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOGRANDE);
          digitalWrite(PinSTM32, LOW);
          }
          else if (timeinfo.tm_hour == PORCOES3HORARIO3 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOGRANDE);
          digitalWrite(PinSTM32, LOW);
          }
          break;

          case 4:
          if (timeinfo.tm_hour == PORCOES4HORARIO1 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOGRANDE);
          digitalWrite(PinSTM32, LOW);
          }
          else if (timeinfo.tm_hour == PORCOES4HORARIO2 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOGRANDE);
          digitalWrite(PinSTM32, LOW);
          }
          else if (timeinfo.tm_hour == PORCOES4HORARIO3 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOGRANDE);
          digitalWrite(PinSTM32, LOW);
          }
          else if (timeinfo.tm_hour == PORCOES4HORARIO4 && timeinfo.tm_min == 0 && timeinfo.tm_sec == 0) {
          digitalWrite(PinSTM32, HIGH);
          delay(TEMPOGRANDE);
          digitalWrite(PinSTM32, LOW);
          }
          break;
        }
      break;
    }
  }
}