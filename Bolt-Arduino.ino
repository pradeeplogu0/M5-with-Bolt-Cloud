#include <M5Core2.h>
static const uint32_t GPSBaud = 9600;
HardwareSerial mySerial(2);

void setup()
{
  M5.begin();
  Serial.begin(115200);
  mySerial.begin(GPSBaud, SERIAL_8N1, 13, 14);
  Serial.setTimeout(100);
}
String data;
uint8_t dataRead = 0;
void loop()
{
  if (mySerial.available() > 0) {
    delay(50);
    String readData = "";
    Serial.print("Command from Bolt: ");
    while (mySerial.available() > 0 ) {
      readData = readData + (char)mySerial.read();
    }
    Serial.println(readData);
    if (readData.indexOf("RD") != -1) {
      String data = sensor_data_to_push();
      mySerial.print(data);
      Serial.print("Data sent to Bolt: ");
      Serial.println(data);
    }
  }
}
String sensor_data_to_push() {
  String data;
  float hum = random(100);
  float temp = random(100);
  data = String(temp) + "," + String(hum);
  return data;
}
