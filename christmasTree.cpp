/**
 * Name: christmasTree
 * Author: Nick Lamprianidis <nlamprian@gmail.com>
 * Version: 1.0
 * Description: A library with some ornaments for decorating a christmas tree
                The library is based on the NeoMatrix modules
 * License: Copyright (c) 2013 Nick Lamprianidis 
 *          This library is licensed under the MIT license
 *          http://www.opensource.org/licenses/mit-license.php
 *
 * Filename: christmasTree.h
 * File description: Implementation of methods for the christmasTree library
 */

#include "christmasTree.h"
#include <stdlib.h>

#ifndef PSTR
#define PSTR // For Arduino Due
#endif

// Creates an instance, and initializes the instance variables
christmasTree::christmasTree(uint8_t pin)
{
    matrix = new Adafruit_NeoMatrix(8, 8, pin,
                                    NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
                                    NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
                                    NEO_GRB            + NEO_KHZ800);

    for (uint8_t i = 0; i < 8; ++i) snowPixels[i] = 0;
    _ornaments = RANDOM;

}

// Gets the instance set up and ready for use
void christmasTree::begin(uint8_t brightness)
{
    matrix->begin();
    matrix->setBrightness(brightness);
    matrix->fillScreen(0);  // Clears the matrix
    matrix->show();
}

// Sets the brightness of the NeoPixels. Range: [0,255]
void christmasTree::setBrightness(uint8_t brightness)
{
    matrix->setBrightness(brightness);
}

// Selects the ornaments to be drawn on the matrix
void christmasTree::setOrnaments(uint8_t ornaments)
{
    _ornaments = ornaments;
}

// Refreshes the drawn ornament
void christmasTree::refresh()
{
    matrix->fillScreen(0);

    uint8_t ornament = 0x01;
    boolean on = _ornaments & ornament;
    for (uint8_t i = 0; i < 8; ++i)
    {
        switch (ornament)
        {
            case 0x01:
                if ( on ) dropSnow();
                break;
            case 0x02:
                if ( on ) drawTree();
                break;
            case 0x04:  
                if ( on ) drawGift();
                break;
            case 0x08:  
                if ( on ) drawChild();
                break;
            case 0x10:
                if ( on ) drawHouse();
                break;
            case 0x20:
                if ( on ) drawSpaceInvader();
                break;
            case 0x40:
                if ( on ) drawRandom();
                break;
            case 0x80:
                if ( on ) dropSnow();
                break;
        }

        ornament <<= 1;
        on = _ornaments & ornament;
    }

    matrix->show();
}

// Updates the ornament and refreshes the drawing
void christmasTree::refresh(uint8_t ornaments)
{
    _ornaments = ornaments;
    refresh();
}

// Scrolls the snowflakes down, and
// creates snow on the top row with a probability
void christmasTree::dropSnow()
{
    for (uint8_t x = 7; x > 0; --x)
        snowPixels[x] = snowPixels[x-1];

    snowPixels[0] = 0;
    uint16_t white = matrix->Color(255, 255, 255);

    for (uint8_t y = 0; y < 8; ++y)
        if ( (double)rand() / RAND_MAX < 0.1 )
                snowPixels[0] = snowPixels[0] | (0x01 << y);

    for (int x = 0; x < 8; ++x)
        for (int y = 0; y < 8; ++y)
            if ( (snowPixels[x] >> y) & 0x01 )
                matrix->drawPixel(x, y, white);
}

// Draws a fir on the matrix
void christmasTree::drawTree()
{
    uint16_t red = matrix->Color(255, 0, 0),
             green = matrix->Color(0, 255, 0),
             brownish = matrix->Color(210, 180, 40);

    matrix->drawFastVLine(0, 3, 2, red);  // Star
    matrix->drawFastVLine(1, 3, 2, green);  // Branches
    matrix->drawRect(2, 2, 2, 4, green);
    matrix->drawRect(4, 1, 2, 6, green);
    matrix->drawRect(6, 3, 2, 2, brownish);  // Stem
}

// Draws a gift on the matrix
void christmasTree::drawGift()
{
    uint16_t red = matrix->Color(255, 0, 0),
             green = matrix->Color(0, 255, 0);

    matrix->drawPixel(0, 1, red);  // Bow
    matrix->drawPixel(1, 2, red);
    matrix->drawPixel(2, 3, red);
    matrix->drawPixel(2, 4, red);
    matrix->drawPixel(1, 5, red);
    matrix->drawPixel(1, 6, red);
    matrix->fillRect(3, 1, 4, 6, green);  // Box
}

// Draws a child on the matrix
void christmasTree::drawChild()
{
    uint16_t blue = matrix->Color(0, 0, 255);

    matrix->drawRect(0, 3, 2, 2, blue);  // Head
    matrix->drawPixel(2, 1, blue);  // Hands
    matrix->drawPixel(2, 6, blue);
    matrix->drawFastVLine(3, 2, 4, blue);
    matrix->drawRect(4, 3, 2, 2, blue);  // Torso
    matrix->drawFastHLine(6, 2, 2, blue);  // Legs
    matrix->drawFastHLine(6, 5, 2, blue);
}

// Draws a house on the matrix
void christmasTree::drawHouse()
{
    uint16_t red = matrix->Color(255, 0, 0),
             yellow = matrix->Color(255, 255, 0);

    matrix->drawFastVLine(0, 3, 2, red);  // Housetop
    matrix->drawFastVLine(1, 2, 4, red);
    matrix->drawFastVLine(2, 1, 6, red);
    matrix->drawFastVLine(3, 0, 8, red);
    matrix->fillRect(4, 1, 4, 6, yellow);  // Walls
}

// Draws a space invader alien on the matrix
void christmasTree::drawSpaceInvader()
{
    uint16_t blue = matrix->Color(0, 0, 255);

    matrix->drawPixel(0, 1, blue);  // Antennas
    matrix->drawPixel(0, 6, blue);
    matrix->drawFastVLine(1, 2, 4, blue);  // Forehead
    matrix->drawFastVLine(2, 1, 6, blue);
    matrix->drawFastVLine(3, 0, 2, blue);  // Eyes Level
    matrix->drawFastVLine(3, 3, 2, blue);
    matrix->drawFastVLine(3, 6, 2, blue);
    matrix->drawFastVLine(4, 1, 6, blue);  // Nose Level
    matrix->drawPixel(5, 1, blue);  // Mouth
    matrix->drawPixel(6, 2, blue);
    matrix->drawPixel(5, 6, blue);
    matrix->drawPixel(6, 5, blue);
}

// Draws random pixels on the matrix
void christmasTree::drawRandom()
{
    uint16_t color;

    for (int x = 0; x < 8; ++x)
        for (int y = 0; y < 8; ++y)
            if ( (double)rand() / RAND_MAX < 0.5 )
            {
                color = matrix->Color(rand() % 256, rand() % 256, rand() % 256);
                matrix->drawPixel(x, y, color);
            }  
}
