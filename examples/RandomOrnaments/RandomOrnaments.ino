/**
 * An example demonstrating the christmasTree library
 * The example exposes some of the library's interface
 * Specifically, the example shows how to create an instance
 * of the christmasTree library, initialize the instance,
 * set the ornaments, and refresh the matrix
 *
 * The library is based on the NeoMatrix modules from Adafruit
 * You can use the NeoMatrix modules as ornaments on your christmas tree
 *
 * ** Happy Holidays **
 */

// Includes the necessary libraries
#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include "christmasTree.h"

#define PIN 9  // Pin to which the input of the matrix is connected
#define PERIOD 10000  // Refreshes the ornament every 10 sec

long time_ref;  // Used as a time reference

// Creates a christmasTree instance with the DOUT pin as an argument
christmasTree ornament(PIN);

void setup()
{
    ornament.begin();  // Initializes the instance
    
    // Selects which ornaments to appear
    // Available choices: SNOW_BACK, SNOW_FRONT, TREE, GIFT, CHILD, HOUSE, SPACE_INVADER, RANDOM
    ornament.setOrnaments(SNOW_BACK + TREE);  
    
    time_ref = millis();  // Gets the temporal baseline
}

void loop()
{
    if ( (unsigned long) (millis() - time_ref) > PERIOD )
    {
        // Picks an ornament at random.
        // It's a bit esoteric, but basically setting a bit in a byte enables a specific ornament
        uint8_t new_ornament = 0x02 << ( rand() % 6 );

        ornament.setOrnaments(SNOW_BACK + new_ornament);  // Sets the new ornament
        time_ref = millis();
    }
    
    // Refreshes the drawing on the matrix.
    // Any change basically involves scrolling the snowflakes down (if enabled)
    ornament.refresh();
    
    delay(600);
}
