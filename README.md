# SUNLAMP

A lamp that lights up in the colors of the sunrise and sunset, using actual spectral data. It also simulates blackbody spectra and the color of the sky on other planets. There are plenty of sunrise alarm clocks available on the market, but none of them display a scientifically-accurate color of the sunrise or sunset. We were inspired by the shortening days to bring the sun indoors!

## External data and code used

We obtained irradiance spectra from [F. Zagury (2012)](https://www.scirp.org/pdf/ACS20120400011_46715429.pdf) at different time points in a sunrise. The implementation of the color-conversion algorithm from power spectra to RGB color was taken from Scipython user [christian](https://scipython.com/blog/converting-a-spectrum-to-a-colour/). Although ozone absorption simulation was not completed, a table of ozone absorption cross-sections was obtained from [ Gorshelev (2012)](https://www.scirp.org/pdf/ACS20120400011_46715429.pdf).

## How it works

The SÜNLÅMP system is composed of:

1. A pre-processing pipeline that turns solar spectrum data and blackbody spectra into equivalent colors
2. A GUI to control the colors displayed by the lamp via Bluetooth
3. Hardware: An Arduino Uno microcontroller, an HC-05 bluetooth module, a NeoPixel LED ring by Adafruit