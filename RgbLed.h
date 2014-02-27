/****
 *
 *   Part of the "RgbLed" library for Arduino. Version 1.0
 *
 *   RgbLed.h Copyright 2014 by D. L. Ehnebuske 
 *   License terms: Creative Commons Attribution-ShareAlike 3.0 United States (CC BY-SA 3.0 US) 
 *                  See http://creativecommons.org/licenses/by-sa/3.0/us/ for specifics. 
 *
 *   The RgbLed is a simple class representing an RGB LED attached to three Arduino PWM digital
 *   pins. The only thing it can do is display any of the predefined eight colors.
 *
 ****/
#ifndef RgbLed_H
#define RgbLed_H

  #if ARDUINO >= 100
    #include <Arduino.h>  // Arduino 1.0
  #else
    #include <WProgram.h> // Arduino 0022
  #endif

/****
 *
 *    RGB LED color names
 *
 ****/
#define RGB_LED_RED     (0)                        // Index for color red
#define RGB_LED_YELLOW  (1)                        // Index for color yellow
#define RGB_LED_GREEN   (2)                        // Index for color green
#define RGB_LED_CYAN    (3)                        // Index for color cyan
#define RGB_LED_BLUE    (4)                        // Index for color blue
#define RGB_LED_MAGENTA (5)                        // Index for color magenta
#define RGB_LED_BLACK   (6)                        // Index for color black
#define RGB_LED_WHITE   (7)                        // Index for color white

/****
 *
 * Simple RGB LED object
 *
 ****/
class RgbLed {
private:
// Instance variables
  byte rPin;
  byte gPin;
  byte bPin;
  byte curColor;
public:
  // Constructors
  RgbLed(byte rP, byte gP, byte bP);				// Construct a simple RGB LED on the specified pins

  // Operational methods
  byte setColor(byte cix);							// Set the LED color; returns the color set.
  byte getColor();									// Get the current color
};
#endif