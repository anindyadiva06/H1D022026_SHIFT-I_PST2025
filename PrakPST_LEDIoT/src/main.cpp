#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "diva"; //nama hotspot
const char* password = "inipunyadiva"; //pw hotspot

ESP8266WebServer server (80);
String webpage; //doc html

void setup() {
  Serial.begin(9600);
  delay(10);

  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);

  //Connect to WiFi network
  Serial.println();
  Serial.print("Konfigurasi access point...");

  //Mengatur WiFi
  WiFi.mode(WIFI_AP);
  WiFi.begin(ssid, password);

  //Cek status connect
  Serial.println("IP address: ");
  Serial.println(WiFi.softAPIP()); //ngecek access point ip address dari wifi

  //Isi dari webpage
  webpage+= "<h1> Web Control ESP266 </h1>";
  webpage+= "<h1> Anindya Diva Talitha </h1>";
  webpage+= "<p> LED1 : ";
  webpage+= "<a href=\"LED1ON\"\"><button>ON</button></a><a href=\"LED1OFF\"\"><button>OFF</button></a><br>";
  webpage+= "<p> LED2 : ";
  webpage+= "<a href=\"LED2ON\"\"><button>ON</button></a><a href=\"LED2OFF\"\"><button>OFF</button></a><br>";
  webpage+= "<p> LED3 : ";
  webpage+= "<a href=\"LED3ON\"\"><button>ON</button></a><a href=\"LED3OFF\"\"><button>OFF</button></a><br>";

  //Mmebuat tampilan webpage
  server.on("/", [](){
    server.send(200, "text/html", webpage);
  });

  //Bagian ini untuk merespon perintah yang masuk
  server.on("/LED1ON", [](){
    server.send(200, "text/html", webpage);
      digitalWrite(D2,HIGH);
      delay(1000);
  });
  server.on("/LED2ON", [](){
    server.send(200, "text/html", webpage);
      digitalWrite(D3,HIGH);
      delay(1000);
  });
  server.on("/LED3ON", [](){
    server.send(200, "text/html", webpage);
      digitalWrite(D4,HIGH);
      delay(1000);
  });

  server.on("/LED1OFF", [](){
    server.send(200, "text/html", webpage);
      digitalWrite(D2,LOW);
      delay(1000);
  });
  server.on("/LED2OFF", [](){
    server.send(200, "text/html", webpage);
      digitalWrite(D3,LOW);
      delay(1000);
  });
  server.on("/LED3OFF", [](){
    server.send(200, "text/html", webpage);
      digitalWrite(D4,LOW);
      delay(1000);
  });

  server.begin();
  Serial.println("Webserver dijalankan!");
}

void loop() {
  server.handleClient();
}

