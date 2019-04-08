
// Include Libraries
#include "Arduino.h"
#include "LiquidCrystal_PCF8574.h"
#include "MQ135.h"

// Pin Definitions



// Global variables and defines
// There are several different versions of the LCD I2C adapter, each might have a different address.
// Try the given addresses by Un/commenting the following rows until LCD works follow the serial monitor prints.
// To find your LCD address go to: http://playground.arduino.cc/Main/I2cScanner and run example.
//define LCD_ADDRESS 0x3F
#define LCD_ADDRESS 0x27
// Define LCD characteristics
#define LCD_ROWS 2
#define LCD_COLUMNS 16
#define SCROLL_DELAY 150
#define BACKLIGHT 255
// object initialization
LiquidCrystal_PCF8574 lcdI2C;

// MQ135 gas sensor
//
// Datasheet can be found here: https://www.olimex.com/Products/Components/Sensors/SNS-MQ135/resources/SNS-MQ135.pdf
//
// Application
// They are used in air quality control equipments for buildings/offices, are suitable for detecting of NH3, NOx, alcohol, Benzene, smoke, CO2, etc
//
// Original creator of this library: https://github.com/GeorgK/MQ135

#define PIN_MQ135 A2
MQ135 mq135_sensor = MQ135(PIN_MQ135);

float temperature = 21.0; // assume current temperature. Recommended to measure with DHT22
float humidity = 25.0; // assume current humidity. Recommended to measure with DHT22

void setup() {
  Serial.begin(9600);
  while (!Serial) ; // wait for serial port to connect. Needed for native USB
  Serial.println("start");

  // initialize the lcd
  lcdI2C.begin(LCD_COLUMNS, LCD_ROWS, LCD_ADDRESS, BACKLIGHT);
}
// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.

void loop()
{
  float rzero = mq135_sensor.getRZero();
  float correctedRZero = mq135_sensor.getCorrectedRZero(temperature, humidity);
  float resistance = mq135_sensor.getResistance();
  float ppm = mq135_sensor.getPPM();
  float correctedPPM = mq135_sensor.getCorrectedPPM(temperature, humidity);

  Serial.print("MQ135 RZero: ");
  Serial.print(rzero);
  Serial.print("\t Corrected RZero: ");
  Serial.print(correctedRZero);
  Serial.print("\t Resistance: ");
  Serial.print(resistance);
  Serial.print("\t PPM: ");
  Serial.print(ppm);
  Serial.print("\t Corrected PPM: ");
  Serial.print(correctedPPM);
  Serial.println("ppm CO2");
  lcdI2C.clear();                          // Clear LCD screen.
  lcdI2C.print("CO2 Gas Sensor");                   // Print print String to LCD on first line
  lcdI2C.selectLine(2);                    // Set cursor at the begining of line 2
  lcdI2C.print(correctedPPM);                   // Print print String to LCD on second line
  lcdI2C.print("ppm CO2");
  delay(10000);

}
