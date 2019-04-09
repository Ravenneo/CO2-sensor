# CO2-sensor

Important.  

I am facing some issues with the script and the Arduino Leonardo. Be aware with the serial interface as in the Leonardo USB is manage by same chip.  I do not recomend use the program in Leonardo for now.

Lab CO2 Sensor

-Instal MQ135 and Firmware Libraries in your Arduino Library folder

-Run Lab CO2 Sensor.ino 

-Lets MQ135 runs during 24h

-Check in Serial Monitor your Rzero and substitute it in your MQ-135 Library. -Check global CO2 and do the same.

-If LCD is on but does not show numbers, you should play with the IC2 potenciometer 

-Wire in Arduino UNO (most of guides) it is different, the CristalLiquid screen is conected to Analogic IN. There are plenty of information in the links below 



Help Links:


Arduino Firmware circuito.io For I2C LCD Screen (I am using the screen with 3.3V pin): https://www.circuito.io/static/reply/index.html?solutionId=5ca9f8dc984b7f00308a37a9&solutionPath=storage.circuito.io

Before you can use the sensor, it has to be calibrated check MQ135 Library> https://hackaday.io/project/3475-sniffing-trinket/log/12363-mq135-arduino-library

For calibration check also: Trends in Atmospheric Carbon Dioxide> https://www.esrl.noaa.gov/gmd/ccgg/trends/gl_trend.html

In my code the MQ-135 Sensor is conected to Analogic In A2.
