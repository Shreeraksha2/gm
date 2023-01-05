#include <SPI.h>
#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
#define REPORTING_PERIOD_MS 1000
PulseOximeter pox;
 uint32_t tsLastReport = 0;
void onBeatDetected()
{
  Serial.println("Beat!");
 }
void setup() 
{
  Serial.begin(9600); 
  Serial.print("Initializing pulse oximeter.."); 
  if (!pox.begin()) {
  Serial.println("FAILED");
   for(;;);
  }
   else
    {
  Serial.println("SUCCESS");
  }
  pox.setOnBeatDetectedCallback(onBeatDetected); 
}

void loop() {
  pox.update();
     if (millis() - tsLastReport > REPORTING_PERIOD_MS)
      {
        Serial.print("Heart BPM:");
        Serial.print(pox.getHeartRate());
        Serial.print("-----");
  Serial.print("Oxygen Percent:");
  Serial.print(pox.getSpO2());
  Serial.println("\n");
 tsLastReport = millis();
}
}