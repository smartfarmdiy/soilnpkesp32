// Code for 7 in 1 TH EC PH NPK Sensor with 20x4 I2C LCD and Serial Output
// creater by smart farm diy for new sensor 

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define RXD2 16
#define TXD2 17

// I2C LCD setup (20 columns, 4 rows, I2C address 0x27)
LiquidCrystal_I2C lcd(0x27, 20, 4);

// Modbus request for 7 parameters
unsigned char byteRequest[8] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x07, 0x04, 0x08};
unsigned char byteResponse[19] = {};

void setup() {
Serial.begin(115200);
Serial2.begin(4800, SERIAL_8N1, RXD2, TXD2);

lcd.init(); // Initialize LCD
lcd.backlight(); // Turn on backlight
lcd.setCursor(0, 0);
lcd.print("Soil NPK Sensor Init");
delay(5000);
lcd.clear();

Serial.println("Soil NPK Sensor - Serial Output + LCD");
}

void loop() {
readAndPrintNPK();
delay(5000); // 5 second delay between reads
}

void readAndPrintNPK() {
Serial2.write(byteRequest, sizeof(byteRequest));
delay(5000); // Wait for sensor to respond

if (Serial2.available() >= sizeof(byteResponse)) {
Serial2.readBytes(byteResponse, sizeof(byteResponse));

unsigned int soilHumidity = (byteResponse[3] << 8) | byteResponse[4];
unsigned int soilTemperature = (byteResponse[5] << 8) | byteResponse[6];
unsigned int soilConductivity = (byteResponse[7] << 8) | byteResponse[8];
unsigned int soilPH = (byteResponse[9] << 8) | byteResponse[10];
unsigned int nitrogen = (byteResponse[11] << 8) | byteResponse[12];
unsigned int phosphorus = (byteResponse[13] << 8) | byteResponse[14];
unsigned int potassium = (byteResponse[15] << 8) | byteResponse[16];

// Print to Serial
Serial.println("---- Soil Sensor Readings ----");
Serial.print("Moisture: "); Serial.print(soilHumidity / 10.0); Serial.println(" %");
Serial.print("Temperature: "); Serial.print(soilTemperature / 10.0); Serial.println(" °C");
Serial.print("Conductivity: "); Serial.print(soilConductivity); Serial.println(" us/cm");
Serial.print("pH: "); Serial.println(soilPH / 10.0);
Serial.print("Nitrogen: "); Serial.print(nitrogen); Serial.println(" mg/kg");
Serial.print("Phosphorus: "); Serial.print(phosphorus); Serial.println(" mg/kg");
Serial.print("Potassium: "); Serial.print(potassium); Serial.println(" mg/kg");
Serial.println("--------------------------------\n");

// Print to LCD
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Moist:"); lcd.print(soilHumidity / 10.0); lcd.print("% ");
lcd.print("pH:"); lcd.print(soilPH / 10.0);

lcd.setCursor(0, 1);
lcd.print("Temp:"); lcd.print(soilTemperature / 10.0); lcd.print("C ");
lcd.print("EC:"); lcd.print(soilConductivity);

lcd.setCursor(0, 2);
lcd.print("N:"); lcd.print(nitrogen); lcd.print(" P:"); lcd.print(phosphorus);

lcd.setCursor(0, 3);
lcd.print("K:"); lcd.print(potassium); lcd.print(" mg/kg");

} else {
Serial.println("No response from THECPHNPK sensor.");
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Sensor not ready...");
}
}
