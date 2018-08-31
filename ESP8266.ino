/* 
 * Power on PC using NodeMCU
 * Created by Anuroop Divakaran on 04/07/2017
 * Power the NodeMCU by connecting the Standby 5v to the Vin and connect the ground to any ground from SATA power connector.
 * Find the Power Pin of the motherboard by consulting the Manual of your motherboard.
 * There will be two power pins. If you short these two pins the computer should boot..
 * Connect the ground of NodeMCU to one of the pin and check if the computer boots. If it boots connect it to the PwPin.
 * Find the IP address of NodeMCU. 
 * To boot your computer ping 192.168.X.X/S (Replace X.X with NodeMCU's IP).
 */


#include <ESP8266WiFi.h>

/* define port */
WiFiClient client;
WiFiServer server(80);

/* WIFI settings */
const char* ssid = "YOUR SSID";//Replace YOUR SSID with your wifi name.
const char* password = "PASSWORD";// Replace PASSWORD with your wifi password.


String  data =""; 


int PwPin = 2; //Connect this pin to the power pin on Motherboard.
//int RwPin = 3;


void setup()
{
  
  pinMode(PwPin, OUTPUT);
  //pinMode(RwPin, OUTPUT);
  server.begin();
  digitalWrite(PwPin,HIGH);
}

void loop()
{
    client = server.available();
    if (!client) return; 
    data = checkClient ();
    if (data == "S") 
    {
      digitalWrite(PwPin,LOW); // This shorts the Power Pin to the ground for a short period of time just like a physical power button.
      delay(500);
      digitalWrite(PwPin,HIGH);      
    }
    /* This can be used to connect to the reset PIN
     if (data == "R") 
    {
      digitalWrite(RwPin,LOW); // This shorts the Power Pin to the ground for a short period of time just like a physical power button.
      delay(500);
      digitalWrite(RwPin,HIGH);      
    }
     */
} 
String checkClient (void)
{
  while(!client.available()) delay(1); 
  String request = client.readStringUntil('\r');
  request.remove(0, 5);
  request.remove(request.length()-9,9);
  return request;
}

