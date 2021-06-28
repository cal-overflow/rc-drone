## Airplane RC Drone

Designing a RC Airplane over the 2021 summer break.

### Arduino Libraries needed:

* [PWMServo](https://github.com/PaulStoffregen/PWMServo)

* [RadioHead](https://www.airspayce.com/mikem/arduino/RadioHead/index.html)

[Installing Arduino libraries](https://www.arduino.cc/en/guide/libraries)

In order for these two libraries to work in the same Arduino sketch, The libraries cannot share the same timer.
Change the  RadioHead timer to 2 by:

1. Uncommenting the following line in `RH_ASK.cpp` (line 17 in version 1.41)
        #define RH_ASK_ARDUINO_USE_TIMER2
2. Adding the following line to both `RH_ASK.h` and `RadioHead.h`
        #define RH_ASK_ARDUINO_USE_TIMER2

## Pin-Out requirements:

**Transmitter**: must be connected to pin 12

**Receiver**: must be connected to pin 11


## Contributors

[Spencer Dunham](https://github.com/Sdunham01)

[Gautham Ajith](https://github.com/gajith0104)

[Christian Lisle](http://christianlisle.com)
