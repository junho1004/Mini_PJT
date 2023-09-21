/*
  SimpleMQTTClient.ino
  The purpose of this exemple is to illustrate a simple handling of MQTT and Wifi connection.
  Once it connects successfully to a Wifi network and a MQTT broker, it subscribe to a topic and send a message to it.
  It will also send a message delayed 5 seconds later.
*/
#include "EspMQTTClient.h"


//========================DHT센서

uint32_t delayMS;
//========================
EspMQTTClient client(
  "SSAFY_EMB_2",
  "1210@ssafy",
  "192.168.110.192",  // MQTT Broker server ip
  "MQTTUsername",   // Can be omitted if not needed
  "MQTTPassword",   // Can be omitted if not needed
  "KILL_KILL",     // Client name that uniquely identify your device
  1883              // The MQTT port, default to 1883. this line can be omitted
);
char* topic = "home/pi";
void tx() {//꼭 TX쓸 필요는 없음. 그냥 CLIENT.PUBLISH 써도 됨 
  client.publish(topic, "Nice day");
}

//GPIO SETUP
int Yin = 36; // Y Input Pin 
int Xin= 39; // X Input Pin 
int KEYin = 23; // Push Button
int btn1 = 34;//grab
int btn2 = 35;//ungrab
//===================
void setup()
{
  Serial.begin(115200);

  // Optional functionalities of EspMQTTClient
  client.enableDebuggingMessages(); // Enable debugging messages sent to serial output
  client.enableHTTPWebUpdater(); // Enable the web updater. User and password default to values of MQTTUsername and MQTTPassword. These can be overridded with enableHTTPWebUpdater("user", "password").
  client.enableOTA(); // Enable OTA (Over The Air) updates. Password defaults to MQTTPassword. Port is the default OTA port. Can be overridden with enableOTA("password", port).
  client.enableLastWillMessage("TestClient/lastwill", "I am going offline");  // You can activate the retain flag by setting the third parameter to true
  //sensor

  //=======gpio
  pinMode(KEYin, INPUT_PULLUP);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  //gpio========

}

// This function is called once everything is connected (Wifi and MQTT)
// WARNING : YOU MUST IMPLEMENT IT IF YOU USE EspMQTTClient
void onConnectionEstablished()
{

  // Subscribe to "mytopic/test" and display received message to Serial
  client.subscribe(topic, [](const String & payload) {
    Serial.println(payload);
  });

}

void loop()
{
  int xVal, yVal, buttonVal, btn1val, btn2val;
  xVal=analogRead(Xin); 
  yVal=analogRead(Yin); 
  buttonVal=digitalRead(KEYin);
  btn1val=digitalRead(btn1);
  btn2val=digitalRead(btn2);
  Serial.print("X = "); 
  Serial.println(xVal, DEC);
  Serial.print("Y = ");
  Serial.println(yVal, DEC);

  if (yVal == 4095) {
    client.publish(topic, "go");
  }
  else if (yVal == 0) {
    client.publish(topic, "back");
  }

  if (xVal == 4095) {
    client.publish(topic, "left");
  }
  else if (xVal == 0) {
    client.publish(topic, "right");
  }


  Serial.print("Button is "); 
  if(buttonVal == HIGH){ 
    Serial.println("not pressed"); 
    } 
  else{ 
    Serial.println("PRESSED"); 
    client.publish(topic, "stop");
  }


  Serial.print("Btn1 is "); 
  if(btn1val == HIGH){ 
    Serial.println("PRESSED"); 
    client.publish(topic, "grab");
    } 
  else{ Serial.println("not pressed"); }



  Serial.print("Bt2 is "); 
  if(btn2val == HIGH){ 
    Serial.println("PRESSED"); 
    client.publish(topic, "ungrab");
    } 
  else{ Serial.println("not pressed"); }

  //tx();
  client.loop();
  delay(500);
}