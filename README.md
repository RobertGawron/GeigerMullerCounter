# GeigerMullerCounter

[![Docs Generation](https://github.com/RobertGawron/GeigerMullerCounter/workflows/Docs%20Generation/badge.svg)](https://github.com/RobertGawron/GeigerMullerCounter/actions?query=workflow%3A%22Docs+Generation%22)

The Geiger–Müller counter is a relatively simple tool to measure ionizing radiation. When high voltage (typically 380-420V) is applied to the Geiger–Müller tube, the tube doesn't conducts electricity, but it does conducts for a short period, when radiation particle is observed. Those pulses are observed by the detector. The level of ionizing radiation is proportional to the amount of pulses detected in a constant interval of time (typically from 20s to 2,5min).

## System architecture

<img src="./Documentation/Diagrams/ArchitectureOverview.svg"  width="100%">

## Hardware and Software details

[Details are described on my blog.
](http://robertgawron.blogspot.com/2015/02/homemade-geigermuller-counter-part-i.htmll) [HardwareDataLogger](https://github.com/RobertGawron/HardwareDataLogger) is a simple pulse counter based on NUCLEO-F091RC with additional shield (for real-time data display using LCD).

## Hazards

* **The device uses high voltage and can lead to unpleasant shock, injury or death. Don't touch the PCB or tubes when power is on.**

## Experiments made with this tool

* [Measuring nuclear-radiation of potassium from cigarette ashes
](https://robertgawron.blogspot.com/2015/07/measuring-radioactivity-of-potassium.html)
* [Trip to Śnieżka to measure radioactivity levels
](https://robertgawron.blogspot.com/2015/06/a-trip-with-geiger-counter-on-sniezka.html)
