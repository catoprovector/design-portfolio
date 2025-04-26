/* Improved Concurrent LED Dimming Example
Hardware: Seeed Studio XIAO SAMD21 (ensure the chosen pins support PWM)
Description:

    6 LEDs fade in and out smoothly.
    Each LED steps by one brightness unit every [50…5000] ms, with its update interval randomly reselected at each fade turnover.
    */

const int numLEDs = 6;
// Update these pin numbers as needed – ensure they are PWM-capable on your XIAO SAMD21.
int ledPins[numLEDs] = {1, 2, 3, 4, 5, 6};

struct LED {
  int pin; // The PWM pin the LED is attached to
  int brightness; // Current brightness (0-255)
  int fadeDir; // 1 for increasing brightness, -1 for decreasing
  unsigned long lastUpdate; // Timestamp of the last brightness update
  unsigned long interval; // How often (in ms) the brightness changes by one step
  };

LED leds[numLEDs];

void setup() {
  // Seed the random number generator
  randomSeed(analogRead(0));

  // Initialize each LED’s state
  for (int i = 0; i < numLEDs; i++) {
    leds[i].pin = ledPins[i];
    pinMode(leds[i].pin, OUTPUT);
    leds[i].brightness = 0; // Start at off
    leds[i].fadeDir = 1; // Begin by fading up (increasing brightness)
    leds[i].lastUpdate = millis();
    // Pick an initial update interval randomly between 50 and 5000 ms.
    leds[i].interval = random(50, 1000);
    }
  }

void loop() {
  unsigned long currentMillis = millis();

  for (int i = 0; i < numLEDs; i++) {
    // Check if this LED is ready for an update based on its individual interval.
    if (currentMillis - leds[i].lastUpdate >= leds[i].interval) {
      leds[i].lastUpdate = currentMillis;

      // Adjust brightness

      leds[i].brightness += leds[i].fadeDir;

  

    // Check if we’ve hit either extreme.

    if (leds[i].brightness <= 0) {

      leds[i].brightness = 0;

      leds[i].fadeDir = 1;  // Reverse direction to fade up.

      leds[i].interval = random(50, 1000);  // New random interval for next fade cycle.

    }

    else if (leds[i].brightness >= 255) {

      leds[i].brightness = 255;

      leds[i].fadeDir = -1;  // Reverse to fade down.

      leds[i].interval = random(50, 1000);  // Pick a new random update interval.

    }

  

    // Update the LED with the new brightness value.

    analogWrite(leds[i].pin, leds[i].brightness);

    }

  }
}

