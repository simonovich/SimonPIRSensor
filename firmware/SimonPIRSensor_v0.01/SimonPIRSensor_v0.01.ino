#include <WaveUtil.h>
#include <WavePinDefs.h>
#include <mcpDac.h>
#include <SdReader.h>
#include <SdInfo.h>
#include <ArduinoPins.h>
#include <FatReader.h>
#include <WaveHC.h>
#include <FatStructs.h>

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

//Your file with credentials
#include <"a_def_pass.h">

//Our HTML webpage contents
#include "wc_free.h"
#include "wc_busy.h"

#define INTERVAL_GET_DATA 60000  // time interval, ms
// pin with PIR sensor
#define HCSR501PIN         4

bool wc_state=false;

void ICACHE_RAM_ATTR changeHCSR501();

// variable for time interval
unsigned long millis_int1=0;

//SSID and Password of your WiFi router
const char* ssid = WIFI_SSID;
const char* password = WIFI_PASS;

ESP8266WebServer server(80); //Server on port 80

//Send web page
void handleRoot() {
  if (wc_state) {
    server.send_P(200, "text/html", WC_CLOSE_page, sizeof(WC_CLOSE_page) );
  }
  else {
    server.send_P(200, "text/html", WC_OPEN_page, sizeof(WC_OPEN_page) );
  }
}

void setup() {
  Serial.begin(9600);
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
 
  server.on("/", handleRoot);      //Which routine to handle at root location

  server.begin();                  //Start server
  Serial.println("HTTP server started");
  
  attachInterrupt(digitalPinToInterrupt(HCSR501PIN),changeHCSR501,CHANGE);
}

void loop() {
  server.handleClient();          //Handle client requests
  
  if(millis()-millis_int1 >= INTERVAL_GET_DATA) {
    if (wc_state){
      Serial.println("WC is busy");
    }
    else {
      Serial.println("WC is free");
    }
    // Start interval counter
    millis_int1=millis();
  }
}

void changeHCSR501() {
  wc_state=digitalRead(HCSR501PIN);
}
