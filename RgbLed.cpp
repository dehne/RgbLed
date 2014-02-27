/****
 *
 *   Part of the "RgbLed" library for Arduino. Version 1.0
 *
 *   RgbLed.cpp Copyright 2014 by D. L. Ehnebuske 
 *   License terms: Creative Commons Attribution-ShareAlike 3.0 United States (CC BY-SA 3.0 US) 
 *                  See http://creativecommons.org/licenses/by-sa/3.0/us/ for specifics. 
 *
 *   The RgbLed is a simple class representing an RGB LED attached to three Arduino PWM digital
 *   pins. The only thing it can do is display any of the predefined eight colors.
 *
 ****/

#include "RgbLed.h"
 
// Constructor
  RgbLed::RgbLed(byte rP, byte gP, byte bP) {
    pinMode(rPin = rP, OUTPUT);                  // Remember pins and set modes to OUTPUT
    pinMode(gPin = gP, OUTPUT);
    pinMode(bPin = bP, OUTPUT);
    setColor(RGB_LED_BLACK);
  }

  // Operational methods
  byte RgbLed::setColor(byte cix) {				 // Set the LED color

    const byte r = 0;                            // Index for red values
    const byte g = 1;                            // Index for green values
    const byte b = 2;                            // Index for blue values
    const byte color [8][3] = {                  // Color values
      {200,   0,   0},                           //  red
      {160,  80,   0},                           //  yellow
      {  0, 200,   0},                           //  green
      {  0, 150,  60},                           //  cyan
      {  0,   0, 200},                           //  blue
      {150,   0, 100},                           //  magenta
      {  0,   0,   0},                           //  black
      {200, 190, 120},                           //  white
    };
	
    if (cix > 7 ) {                              // If invalid color
      cix = RGB_LED_BLACK;                       //   Change it to black
    }
    analogWrite(bPin, color[cix][b]);
    analogWrite(gPin, color[cix][g]);
    analogWrite(rPin, color[cix][r]);            // Display color cix
    return(curColor = cix);                      // Remember and return the color we set
  }

  byte RgbLed::getColor() {                      // Return the current color of the LED
    return(curColor);
  }
