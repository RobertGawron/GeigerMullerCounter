# GeigerMullerCounter

[![Docs Generation](https://github.com/RobertGawron/GeigerMullerCounter/workflows/Docs%20Generation/badge.svg)](https://github.com/RobertGawron/GeigerMullerCounter/actions?query=workflow%3A%22Docs+Generation%22)

## Purpose

The Geiger–Müller counter is a simple, reliable tool designed to measure ionizing radiation. It is widely used in experiments, radiation detection, and environmental monitoring.

## Principle of Operation
When a high voltage (typically 380–420V) is applied to the Geiger–Müller tube, the tube does not conduct electricity under normal conditions. However, when a radiation particle interacts with the tube, it briefly conducts a current, producing a pulse. These pulses are counted by the detector, and the number of pulses in a given time interval (typically 20 seconds to 2.5 minutes) is proportional to the level of ionizing radiation.

## Final Version
Below is an image of the device (the green PCB in the center). Other components in the image are not relevant to this project, as they belong to the [Cosmic Ray Detector](https://github.com/RobertGawron/CosmicRayDetector), where the Geiger counter is used as a building block.

![Final version of the Geiger Counter.](./Documentation/Pictures/Device_09_09_2024.jpg)

## System Architecture

<img src="./Documentation/Diagrams/ArchitectureOverview.svg"  width="100%">

## Hardware 

For more details about the hardware design and implementation, visit my [blog post on the Geiger–Müller counter](http://robertgawron.blogspot.com/2015/02/homemade-geigermuller-counter-part-i.html).

Tools: KiCad (for PCB design).

# Software

Data from the Geiger–Müller counter is collected and managed using the [HardwareDataLogger](https://github.com/RobertGawron/HardwareDataLogger), which is built around an STM32 microcontroller for data collection, display, and storage (via SD card), and an ESP8266 for WiFi communication.

Tools: C++, Python.

## Safety Hazards

**Warning: The device operates at high voltage (380–420V). Contact with the PCB or Geiger tube while powered can cause electric shocks, injuries, or even death. Do not touch any components while the device is powered on.**

## Experiments Conducted

* [Measuring Nuclear Radiation of Potassium from Cigarette Ashes](https://robertgawron.blogspot.com/2015/07/measuring-radioactivity-of-potassium.html): Cigarette ashes are the burnt remains of tobacco leaves, which are rich in potassium. In natural environments, potassium contains the radioactive isotope potassium-40 (K-40), which contributes to the measured radiation levels.
* [Cosmic Ray Detector](https://github.com/RobertGawron/CosmicRayDetector): a device designed to detect high-energy particles, known as cosmic rays, that originate from outer space.
* [Trip to Śnieżka mountain to measure radioactivity levels](https://robertgawron.blogspot.com/2015/06/a-trip-with-geiger-counter-on-sniezka.html): mountains naturally have elevated radiation levels due to increased cosmic rays and radioactive minerals in the rocks. Additionally, near Śnieżka Mountain, a Cold War-era uranium mine in Kowary contributed to the region's historical radiation levels.

## License
This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for details.
