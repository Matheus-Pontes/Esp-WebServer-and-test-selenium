// Libs necessárias
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Fixed IP, refer to your network
IPAddress ip();
IPAddress gateway();
IPAddress subnet();


const char* ssid = "sua rede";
const char* password = "sua rede";

ESP8266WebServer server(80);

#define led D0
bool stateLed = LOW;

void setup() {
  Serial.begin(115200);
  delay(100);
  pinMode(led, OUTPUT);

  Serial.println("Connecting to: ");
  Serial.println(ssid);
  
  // Estabelecendo comunicação a rede
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println(".");
  }

  Serial.println("");
  Serial.println("Wifi connected..!");
  Serial.println("IP: "); Serial.println(WiFi.localIP());

  server.on("/", handle_OnConnect);
  server.on("/led1on", handle_LedOn);
  server.on("/led1off", handle_LedOff);
  
  server.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
  
  //Funcionamento do led
  if(stateLed){
    digitalWrite(led, HIGH); 
  }
  else{
    digitalWrite(led, LOW);
  }

}

void handle_OnConnect(){
  stateLed = LOW;
  server.send(200, "text/html", SendHTML());
}

// Function, on led
void handle_LedOn(){
  stateLed = HIGH;
  server.send(200, "text/html", SendHTML());
}

// Function, off led
void handle_LedOff(){
  stateLed = LOW;
  server.send(200, "text/html", SendHTML());
}

// Web Page
String SendHTML(){
  String page = "<!DOCTYPE html>"
                "<html lang='pt-br'>"
                "<head><meta charset='UTF-8'>"
                "<title>Hello!</title>"
                "<style> html{display: inline-block; margin:0 auto;}"
                "body{text-align:center; background-color:rgb(38, 185, 243);margin-top:200px;}"
                "h1{color: #000;}"
                ".bd{background-color:#fff;margin:100px;border-radius: 10px 10px 10px 10px;text-align: center;padding:50px;}"
                ".button1{padding: 15px 30px; background-color: rgb(22, 167, 8);text-decoration:none;color: #fff;margin-right:10px;border-radius:8px;}"
                ".button2{padding:15px 30px; background-color: rgb(233, 20, 13);text-decoration:none;color: #fff;border-radius:8px;}"
                "</style>"
                "</head>"
                "<body>"
                "<div class='bd'>"
                "<h1>Hello, World!-ESP8266</h1>"
                "<h2>Testing Led</h2>"
                "<a href=\"/led1on\" class='button1'/>LIGAR</a>\n"
                "<a href=\"/led1off\" class='button2'>DESLIGAR</a>"
                "</div>";
                         
  return page;
}