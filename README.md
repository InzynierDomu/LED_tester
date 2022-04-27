# LED_tester

Simply device to help work with LEDs.

- [About](#About)
- [Scheme](#Scheme)
- [IDE](#IDE)

## About

The device in the plan has 3 operating modes:

<ul>
<li>WS2812 color picker</li>
<li>PWM generator for simply LED</li>
<li>Change of PWM in time characteristics</li>
</ul>

### Mode changing

The modes can be changed with buttons on top pic 1. 
<ol>
<li>WS2812 color picker</li>
<li>PWM generator for simply LED</li>
<li>Change of PWM in time characteristics</li>
</ol>
![mode_buttons](https://www.inzynierdomu.pl/wp-content/uploads/2019/12/IMG_5677_edited-scaled.jpg)
pic 1. Mode changing buttons

### Joystick

Every mode has different handling reactions from joystick (1. on pic 2.) control.
![pwm_chart_mode](https://www.inzynierdomu.pl/wp-content/uploads/2019/12/IMG_5678_edited-scaled.jpg)
pic 2. Change of PWM in time characteristics mode

### WS2812 color picker

The device can control the intensity of red, green and blue colors on a scale from 0 to 255.<br>
To do this, use the joystick: up / down to select a color; right / left to increase / decrease the color saturation value
![color_mode](https://www.inzynierdomu.pl/wp-content/uploads/2019/12/IMG_5679_edited-scaled.jpg)
pic 3. WS2812 color picker mode

### PWM generator for simply LED

The device can control the intensity LED light with PWM.
To do this, use the joystick: up / down to change duty.
![pwm_mode](https://www.inzynierdomu.pl/wp-content/uploads/2019/12/IMG_5681_edited-scaled.jpg)
pic 4. PWM generator for simply LED mode

### Change of PWM in time characteristics

The device can control the intensity LED light with PWM in time or manual based on mathematical function (pic 2.).
To do this, use the joystick: up / down to select mathematical function; right / left to change input to mathematical function; center to run mathematical function from 0 to max PWM value.

## Scheme

The code is prepared for Wio Terminal. About platform: [video](https://youtu.be/NfK_IA_MOQ4). <br>
WS2812 data pin is connected to BCM27. LED connected to BCM23.

## IDE

The project is prepared for the Platform IO environment. A video on how to install such an environment can be watched on this [video](https://youtu.be/Em9NuebT2Kc).

<br><br>
Formatting is done using clang-format. The description of the tool configuration is in the [video](https://youtu.be/xxuaOG0WjIE).
<br><br>
The code contains a comment prepared for doxygen, their use is described in the [video](https://youtu.be/1YKJtrCsPD4).
