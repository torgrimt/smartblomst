/*

   Smartblomst 1.0

   2016 torgrimt@oppetid.no

*/

#include "U8glib.h"
// VDD=5V GND=GND SCL=A5 SDA=A4
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE);  // I2C / TWI


const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
int sensorValue = 0;        // value read from the pot


void draw(void) {
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr( 0, 10, "Smartblomst 1.0 ");
  u8g.drawStr( 0, 30, "Fuktighet: ");
  char buf[5];
  sprintf (buf, "%d", sensorValue);
  u8g.drawStr( 0, 50, buf);
}


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

  u8g.setColorIndex(255);
  pinMode(8, OUTPUT);
}

void loop() {
  u8g.firstPage();
  do {
    sensorValue = analogRead(analogInPin);
    Serial.print("sensor A0 = ");
    Serial.println(sensorValue);

    draw();
  } while ( u8g.nextPage() );

  // rebuild the picture after some delay
  delay(5000);

}
