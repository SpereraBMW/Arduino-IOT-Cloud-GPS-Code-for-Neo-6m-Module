# Arduino-IOT-Cloud-GPS-Code-for-Neo-6m-Module
This code is for Neo 6m GPS module in Arduino IOT cloud. Updated code in 2025
First Create this variable in arduino IOT cloud.
  float Latitude;
  float Longitude;
  CloudLocation Location;
in code file this variable will show like this
  float latitude;
  float longitude;
  CloudLocation location;
The go to the sketch section copy and paste accordingly.
Before copy and paste. Make sure to copy and paste relevant lines only because Some code lines are automatically Generated. In code file I have commented the what are RX and TX pins in Esp32 Board. So use that pins.
RX = GPIO16, TX = GPIO17 RX Pin should be connected with TX pin of Neo6m Module. TX pin Should be connected with RX pin of Neo6m Module.
Use Once you cope and paste the codes. Then try to upload the codes via IOT Cloud. Most Times Arduino IOT cloud doesn't provide to upload the code. Therefore Download the code and open it from arduino IDE. With code File some other fills also will be downloaded. Put all files into a single folder.
InthingsProperties.h files has an ares called,
   const char SSID[]               = SECRET_SSID;    // Network SSID (name)
   const char PASS[]               = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)
   const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    // Secret device password
Update above codes in according to your device.
Then Upload the code and enjoy the code. Neo6m module may take sometimes ( 30 sec mosttimes)if you are testing in indoor environment. So stay Patiently.
Thank You and give me a feedback.
