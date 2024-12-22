#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
 #define PSTR // For Arduino Due
#endif

#define PIN 6

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, PIN,
  NEO_MATRIX_BOTTOM + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB + NEO_KHZ800);

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(5);
  matrix.setTextColor(matrix.Color(150, 150, 255)); // Set text color
}

int x = 0;
int textWidth = 0;

void ScrollText(const char* text) {
  // Calculate the width of the text dynamically
  int16_t x1, y1;
  uint16_t w, h;
  matrix.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);
  textWidth = w;       // Store the text width
  x = matrix.width();  // Start the text just off the right side

  while (x >= -textWidth) { // Scroll until the text is completely off-screen
    matrix.fillScreen(0);    // Clear the screen
    matrix.setCursor(x, 1);  // Align text vertically
    matrix.print(text);      // Print the current string
    matrix.show();
    delay(50); // Adjust delay for scroll speed
    x--; // Move text to the left
  }
}

void loop() {
  ScrollText("What's better than robotics?"); // Scroll the first string
  delay(500); // Pause between strings
  ScrollText("MORE Robotics!"); // Scroll a second string
  delay(500); // Pause between strings
  ScrollText("FRC 1714"); // Scroll a third string
}
