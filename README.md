christmasTree
=============

This is a library for creating interactive ornaments for the christmas tree that are based on Arduino and the NeoMatrix modules from Adafruit.

![tree](https://raw.githubusercontent.com/wiki/nlamprian/christmasTree/assets/tree.png)


<br>
The library provides a set of ornaments with the additional option of droping snow.

![ornaments](https://raw.githubusercontent.com/wiki/nlamprian/christmasTree/assets/ornaments.png)

Interface
---------

```cpp
void begin(uint8_t brightness = 20) - Initializes an instance with an optional argument for the brightness of the pixels
void setBrightness(uint8_t brightness) - Sets the brightness of the NeoMatrix pixels
void setOrnaments(uint8_t ornaments) - Sets the ornaments to be drawn on a NeoMatrix module
void refresh() - If snow has been enabled, the snowflakes will scroll down
void refresh(uint8_t ornaments) - Same as before, but updates the ornaments to be drawn
```

The options fot the ornaments are the following:

`SNOW_BACK, SNOW_FRONT, TREE, GIFT, CHILD, HOUSE, SPACE_INVADER, RANDOM`

Pick them by summing them and passing the result to the setOrnaments and/or refresh methods.

Examples
--------

There is an example sketch that picks and draws a random ornament on a NeoMatrix module every 10 sec.
