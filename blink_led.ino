// Libs necessárias
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Fixed IP, refer to your network
IPAddress ip();
IPAddress gateway();
IPAddress subnet();

// Name your internet and passaword
const char* ssid = "********";
const char* password = "*****";

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
                "<style> *{margin:0; padding:0; box-sinzing: border-box;}"
                "body{width: 100vw; height: 100vh; background-color: #011640;}"
                "header{color: #fff; padding: 2rem; text-align: center;}"
                "main{display:flex; align-items: center; justify-content:center;}"
                "section{padding: 4rem; background-color: #fff; border-radius: 8px; max-width: 800px; display:flex; justify-content: center; box-shadow: 1px 1px 11px #fff;}"
                "main section a {text-decoration: none; color: #fff; padding: 1rem; margin: 5px;}"
                "a#button1{padding:1.8rem 2rem; background:#00ae32; border-radius: 8px;}"
                "a#button2{padding: 1.8rem 2rem; background: #f20544; border-radius: 8px;}"
                "a#button1:hover {background: #03a66a;}"
                "a#button2:hover {background: #a6032f;}"
                "footer { text-align:center; padding: 2rem; color: #fff; }"
                "</style>"
                "</head>"
                "<body>"
                "<header>"
                "<h1>Hello, World!-ESP8266</h1>"
                "<h2>Testing Led</h2>"
                "</header>"
                "<main>"
                "<section>"
                "<a href=\"/led1on\" id='button1'/>LIGAR</a>\n"
                "<a href=\"/led1off\" id='button2'>DESLIGAR</a>"
                "</section>"
                "</main>"
                "<footer>"
                "<h3>Criado por Matheus Francisco de Pontes</h3>"
                "</footer>"
                "</body>"
                "</html>";
  return page;
}
