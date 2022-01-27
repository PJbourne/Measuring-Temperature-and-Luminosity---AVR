# Measuring Temperature and Luminosity - AVR

![img1](https://github.com/PJbourne/Temp-Bright-Sensor-AVR/blob/main/atmega-proto-board.jpg)
Video:
[![img2](http://img.youtube.com/vi/TDRwlge7e1Q/0.jpg)](http://www.youtube.com/watch?v=TDRwlge7e1Q "")


Needed:
* Atmega328
* 1500uF Capacitor (or higher)
* LM335 (PRECISION TEMPERATURE SENSOR datasheet: http://www.farnell.com/datasheets/7759.pdf)
* LDR 5mm (Light Dependent Resistor OR Photoresistor)
* LCD 16x2 (with backlight)
* Breadboards + Jump Wires  OR  self produced PCB (You can use the free KiCad software)

No needed but can be used:
* Crystal Oscilator (+ 2x 22pF capacitors)
* High brightness led (for signal when poor ambient brightness)
* Led (to indicate SCK signal when uploading the code)
* 10K Trimmer Potentiometer (For precise adjustment of the LM335)

If you want to see the ![Schematic](https://github.com/PJbourne/Temp-Bright-Sensor-AVR/blob/main/Schematic.pdf)

If you want to see the ![Code](https://github.com/PJbourne/Temp-Bright-Sensor-AVR/blob/main/temp_bright_sens.ino)

![img3](https://www.componentsinfo.com/wp-content/uploads/2020/01/atmega328p-pinout.gif)

IMPORTANT NOTES:

* For programming atmega328 is needed an ISP programmer. In my case I used an Arduino Leonardo (Arduino as ISP). So I did uploaded the 'ArduinoISP' code (from Arduino's IDE) and wired correctly the AVR-ISP pinage (there are some tutorials teaching this, just google).
* For burning the code without External Oscilator, we gona use the internal oscilator, so it's needed to set a different kind of configuration at AVR config (there are tutorials in www.instructables.com, just google it).
* If you are using External Oscilator, after burning the code (with the atmega off) you can retire the 'Crystal+Capacitors', and run without then. I don't recommend.
* I used the resistors and capacitors I had in hand, but you can use or combine different values. I recommend to calculate the I current before changing the values (to avoid burning up anything you dont want to)
* You can use other kind of LDRs or LM sensors. But you need to verify the datasheet and change what is needed.
