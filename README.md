# LED_tester

Simply device to help work with LEDs.

- [About](#About)
- [Scheme](#Scheme)
- [IDE](#IDE)

## About

The device in the plan has 3 operating modes:

<ul>
<li>[WS2812 color tester](#WS2812 color tester)</li>
<li>[PWM generator for simply LED](#PWM generator for simply LED)</li>
<li>[Tester for characteristic PWM change in time](#Tester for characteristic PWM change in time)</li>
</ul>

### WS2812 color tester

The device can control the intensity of red, green and blue colors on a scale from 0 to 255.<br>
To do this, use the joystick: up / down to select a color and right / left to increase the color saturation value

### PWM generator for simply LED

//todo

### Tester for characteristic PWM change in time

//todo

## Scheme

The code is prepared for Wio Terminal. About platform: [video](https://youtu.be/NfK_IA_MOQ4). <br>
WS2812 data pin is connected to BCM27.

## IDE

The project is prepared for the Platform IO environment. A video on how to install such an environment can be watched on this [video](https://youtu.be/Em9NuebT2Kc).

<br><br>
Formatting is done using clang-format. The description of the tool configuration is in the [video](https://youtu.be/xxuaOG0WjIE).
<br><br>
The code contains a comment prepared for doxygen, their use is described in the [video](https://youtu.be/1YKJtrCsPD4).
