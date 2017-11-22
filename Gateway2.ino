//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>
#include <ESP8266WiFi.h>

// WiFi network info.
char ssid[] = "Startup Coffee Shop";
char wifiPassword[] = "Caphesach01";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "6e020ef0-c500-11e7-8123-07faebe02555";
char password[] = "a34c9c95f18585aa5d5f71b8891bfe312e982457";
char clientID[] = "4e1ab440-cf6c-11e7-b556-b7f707866213";

unsigned long lastMillis = 0;

void setup() {
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(115200);
  Cayenne.begin(username, password, clientID, ssid, wifiPassword);
}

void loop() {
  Cayenne.loop();

  /// ADC0 - CHANNEL 0  
  Cayenne.virtualWrite(0, 70  );
  // Cayenne.virtualWrite(1, 0  );
  
  /// ADC0 - CHANNEL 2  
  Cayenne.virtualWrite(2, 40);
  delay(10000);

  
}


//Default function for processing actuator commands from the Cayenne Dashboard.
//You can also use functions for specific channels, e.g CAYENNE_IN(1) for channel 1 commands.

///  WRITE state LED  - Escribe estado LED  

CAYENNE_IN_DEFAULT()
{
  CAYENNE_LOG("CAYENNE_IN_DEFAULT(%u) - %s, %s", request.channel, getValue.getId(), getValue.asString());

  int i = getValue.asInt();
  digitalWrite(4, i);
 
}

CAYENNE_IN(1)// chanel to control 
{
  CAYENNE_LOG("CAYENNE_IN_DEFAULT(%u) - %s, %s", request.channel, getValue.getId(), getValue.asString());

  int i = getValue.asInt();
  digitalWrite(2, i);
 
}


