#include <FastLED.h>

// Define the number of pixels in your LED strip
#define NUM_LEDS 32

// Define the LED data pin
#define DATA_PIN 6

// Define the range of numbers for the sine wave
#define LOW_NUM 0
#define HIGH_NUM 255

// Create an array to hold the LED colors
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  // Generate a sine wave pattern for the specified range
  for (int i = 0; i < NUM_LEDS; i++) {
    int sineValue = LOW_NUM + sin((float)i / NUM_LEDS * PI) * (HIGH_NUM - LOW_NUM) / 2 + (HIGH_NUM + LOW_NUM) / 2;
    leds[i] = CRGB(sineValue, 0, 0); // Adjust the color channels as needed
  }

  // Show the changes on the LED strip
  FastLED.show();

  // Optional: Add a delay to see the pattern
  delay(50);
}
