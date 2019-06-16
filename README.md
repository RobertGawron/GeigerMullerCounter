GeigerMullerCounter
====

The Geiger–Müller counter is a relatively simple tool to measure ionizing radiation. When high voltage (typically 380-420V) is applied to the Geiger–Müller tube, the tube doesn't conducts electricity, but it does conducts for a short period, when radiation particle is observed. Those pulses are observed by the detector. The level of ionizing radiation is proportional to the amount of pulses detected in a constant interval of time (typically from 20s to 2,5min).

Geiger–Müller tube behavior can be described as a "button", that is "pushed" by an ionizing particle.


![idea of Geiger Counter](https://4.bp.blogspot.com/-KCsPYwagOFw/VXyOXtrlVbI/AAAAAAAAEcg/QMKBcfXkLTc/s320/gm-idea.png)

Let's go further into the details. Geiger–Müller tube is made of two electrodes, ionizing particle creates a spark gap between them, to reduce amount of current that flows in this situation, a resistor is put in series with the tube. Marked as R1 on above circuit, R6 on below. Typically it's in a range 1-10M, acceptable values are listed in documentation of the GM tube.

There are a different ways to obtain a signal from the tube, in presented here, a resistor is connected in series between the tube and ground, changes of the voltage on the resistor are measured by the detector. This resistor is marked as R2 on above diagram, R7 on below. Typically it's in a range 10-220k.

Similarly to diode, a Geiger–Müller tube has its polarity, when connected in the opposite direction it will work incorrectly.

Below is shown a signal from GM tube when a particle is detected.

![osciloscope screen](https://4.bp.blogspot.com/-f4pXtW7s-5A/V7Ma7NMT35I/AAAAAAAAE7c/2HAEItzmLPwYWF3ToTk3f13wbBkIftrOACLcB/s800/DS1Z_QuickPrint34.png)

Below is presented the device, in current version STM32 board was used to gather and show results. They can be either sent to PC or displayed on LCD. It's possible to connect three tubes to increase area of measurement. A small 5V boost converter was used to give exactly 5V input voltage for GM device (this 5V is later boosted to 400V). 

![fully assembled Geiger Counter](https://3.bp.blogspot.com/-_3CKmZ1QnIo/XOAy621jSjI/AAAAAAAAHRE/66iQ-M-SztIo9eHhjFRh3G_ZOJzXFzpXwCLcBGAs/s1600/IMG_3292.JPG)

More info can be found on my blog:

* Details of the device and experiments made with it: http://robertgawron.blogspot.com/2015/02/homemade-geigermuller-counter-part-i.html
* Measuring nuclear-radiation of potassium from cigarette ashes: https://robertgawron.blogspot.com/2015/07/measuring-radioactivity-of-potassium.html
* Trip to Śnieżka to measure radioactivity levels: https://robertgawron.blogspot.com/2015/06/a-trip-with-geiger-counter-on-sniezka.html

