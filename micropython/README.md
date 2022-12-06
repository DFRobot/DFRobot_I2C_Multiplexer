# DFRobot_I2C_Multiplexer

- [中文版](./README_CN.md)

On the same I2C port, DFRobot Gravity: I2C Multiplexer solves the address conflict and enables the normal communication with multiple same-address I2C devices.

![正反面svg效果图](./../resources/images/DFR0576.png)

## Product Link(https://www.dfrobot.com/product-1780.html)

SKU：DFR0576

## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary

This library is for the Gravity: Digital 1-to-8 I2C Multiplexer.

## Installation

To use this library, first download the library to ESP32 using UPY, then open the routines folder.  To execute a routine i2c_read_write.py, type python i2C_read_write.py on the command line .

## Methods

```python

    '''!
      @brief   Scan all I2C devices connected to the I2C cascade module
      @param port  Specify the port for scanning
      @return  Return the I2C address of all devices
    '''
    def scan(self,port):

    '''!
      @brief Enable a specific channel on the I2C multiplexer or disable all channels
      @param port - Select channel, range: 0- 8
      @n 0-7 for enabling the corresponding channel separately, 8 for disabling all channels 
      @note When“multiple multiplexer modules” are used on one I2C bus to connect “sensors with same I2C address”, to avoid conflicts,  
      @n it is necessary to ensure that “the currently used channel”is the only enabled one among “all channels in all multiplexers” 
      @n For instance, when one of the channels in the first multiplexer is enabled, in order to use any channel in the second multiplexer,  
      @n please make sure that the channels in the first multiplexer are all disabled.
    '''   
    def select_port(self,port):

    '''!
      @brief   Write the data into the target I2C device
      @param port    The I2C port that the target device is connected to
      @param addr    I2C address of the target device
      @param reg     Register of the target device to be written
      @param buf     Data of the target device to be written
    '''
    def writeto_mem(self,port,addr,reg,buf):

    '''!
      @brief   Read the data of the target I2C device
      @param port     The I2C port that the target device is connected to
      @param addr     I2C address of the target device
      @param reg      Register of the target device to be read
      @param nbytes   Data of the target device to be stored
      @return uint8_t read status
    '''
    def readfrom_mem(self,port,addr,reg,nbytes):

```

## Compatibility

| Mainboard         | Pass | Miss | No Test | Note |
| ------------ | :--: | :----: | :----: | :--: |
| esp32 |  √   |        |        |      |

## History

- 2022/03/23 - 1.0.1 Version
- 2022/12/06 - 1.0.2 Version

## Credits

Written by PengKaixing(kaixing.peng@dfrobot.com), 2022. (Welcome to our [website](https://www.dfrobot.com/))
