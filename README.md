christmasTree
=============

This is a library for creating interactive ornaments for the christmas tree that are based on Arduino and the NeoMatrix modules from Adafruit.

![tree](http://i859.photobucket.com/albums/ab154/lampnick67/a5b723ce-8f7a-47ff-815c-b58340f14032_zps6f6e0fd6.png?t=1387458279)


<br>
The library provides a set of ornaments with the additional option of droping snow.

![ornaments](http://i859.photobucket.com/albums/ab154/lampnick67/ornaments_zps38f3c417.png)

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
