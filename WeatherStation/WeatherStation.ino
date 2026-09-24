/*
  Arduino Weather Station
  --------------------------------------------------
  Hardware : Arduino Uno + Nokia 5110 LCD + DHT11
  Libraries: LCD5110_Graph (Henning Karlsen)  -> install "LCD5110_Graph" via Library Manager
             DHT sensor library (Adafruit)    -> install "DHT sensor library" + "Adafruit Unified Sensor"

  Wiring (Nokia 5110 breakout, pins labeled 1-8 on the PCB):
    RST  -> D8
    CE   -> D9
    DC   -> D10
    DIN  -> D11
    CLK  -> D12
    VCC  -> 5V   (check your board; most breakout boards with a regulator also work on 5V)
    BL   -> GND (backlight)
    GND  -> GND

    DHT11 DATA -> D2   (with a 10k pull-up resistor between DATA and VCC if your module doesn't have one built in)
    DHT11 VCC  -> 5V
    DHT11 GND  -> GND
*/

#include <LCD5110_Graph.h>
#include <DHT.h>
#include <string.h>
#include "graphics.h"

// ---- LCD pins: SCK, MOSI(DIN), DC, RST, CS(CE) ----
LCD5110 myGLCD(12,11,10,8,9);
extern uint8_t SmallFont[];

// ---- DHT11 setup ----
#define DHT_PIN  2
#define DHT_TYPE DHT11
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);

  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);

  dht.begin();

  myGLCD.clrScr();
  myGLCD.drawRect(0, 0, 83, 47);
  myGLCD.drawBitmap(3, 6, thermometerIcon, 16, 16);
  myGLCD.drawBitmap(64, 6, dropletIcon, 16, 16);
  myGLCD.print("WEATHER", CENTER, 26);
  myGLCD.print("STATION", CENTER, 36);
  myGLCD.update();
  delay(1500);
}

// Prints text twice, offset by 1px horizontally, to give the value a
// slightly bolder / more "modern" weight without needing a second font.
void printBold(const char* text, int x, int y) {
  myGLCD.print(text, x, y);
  myGLCD.print(text, x + 1, y);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  myGLCD.clrScr();

  if (isnan(h) || isnan(t)) {
    myGLCD.print("Sensor read", CENTER, 16);
    myGLCD.print("error!", CENTER, 26);
    myGLCD.update();
    Serial.println("DHT11 read failed");
    delay(2000);
    return;
  }

  char tempVal[10];
  char humStr[10];
  dtostrf(t, 4, 1, tempVal);   // "28.9"
  dtostrf(h, 4, 1, humStr);    
  strcat(humStr, " %");        // "98.0 %"

  // --- outer card border ---
  myGLCD.drawRect(0, 0, 83, 47);

  // --- Temperature row ---
  myGLCD.drawBitmap(3, 4, thermometerIcon, 16, 16);
  myGLCD.print("TEMP", 24, 4);

  // 1. (28.9)
  printBold(tempVal, 24, 14);

  // 2. C  ° 
  int valLen = strlen(tempVal);
  int cX = 24 + (valLen * 6) + 6;
  int degreeX = cX - 3;

  // 3. C °(2x2 Pixels)
  myGLCD.setPixel(degreeX, 14);
  myGLCD.setPixel(degreeX + 1, 14);
  myGLCD.setPixel(degreeX, 15);
  myGLCD.setPixel(degreeX + 1, 15);

  // 4. "C" print
  printBold("C", cX, 14);

  // --- dotted divider ---
  for (int x = 3; x < 81; x += 3) {
    myGLCD.setPixel(x, 24);
  }

  // --- Humidity row ---
  myGLCD.drawBitmap(3, 28, dropletIcon, 16, 16);
  myGLCD.print("HUMIDITY", 24, 28);
  printBold(humStr, 24, 38);

  myGLCD.update();

  delay(2000);
}
