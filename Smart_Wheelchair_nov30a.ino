#include "arduino_secrets.h"
#include "arduino_secrets.h"
#include "arduino_secrets.h"
/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/d2e8cc2e-0c26-47a7-ab10-9e8af4f5f9a0 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  float latitude;
  float longitude;
  CloudLocation location;
 

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
  */
#include "thingProperties.h"
#include <TinyGPS++.h>
#include <HardwareSerial.h>
#include <WiFi.h>
TinyGPSPlus gps;
HardwareSerial gpsSerial(1); // Use UART1 for GPS communication

void setup() {

  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  Serial.begin(115200);
  gpsSerial.begin(9600, SERIAL_8N1, 16, 17);// RX = GPIO16, TX = GPIO17 RX Pin should be connected with TX pin of Neo6m Module
  delay(1500); 
  // Defined in thingProperties.h
  initProperties();
  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  // Arduino IoT Cloud setup
  ArduinoCloud.addProperty(latitude, READ, 10 * SECONDS, NULL);
  ArduinoCloud.addProperty(longitude, READ, 10 * SECONDS, NULL);
  ArduinoCloud.connected();
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  //CODE GPS*/
  updateGpsData();
  // Sync data with the cloud
  // Read GPS data and update variables
}

void onLatitudeChange()  {
  // Add your code here to act upon Latitude change
}

/*
  Since Longitude is READ_WRITE variable, onLongitudeChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLongitudeChange()  {
  // Add your code here to act upon Longitude change
}

/*
  Since Location is READ_WRITE variable, onLocationChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLocationChange()  {
  // Add your code here to act upon Location change
  
}
void updateGpsData() {
  while (gpsSerial.available() > 0) {
    if (gps.encode(gpsSerial.read())) {
      if (gps.location.isUpdated()) {
        latitude = gps.location.lat();
        longitude = gps.location.lng();
        location = {latitude, longitude}; // Update location for Arduino IoT Cloud
        Serial.print("Lat: ");
        Serial.println(latitude);
        Serial.print("Lon: ");
        Serial.println(longitude);
      }
    }
  }
}

