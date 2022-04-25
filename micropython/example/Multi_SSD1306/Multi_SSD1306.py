'''!
  @file multi_ssd1306.py
  @brief Connect two SSD1306 devices to the port 0 and  port 1 on the I2C multiplexer respectively 
  @n     and then connect the I2cmultiplexer and Arduino, download this sample. The address of I2C and
  @n     the name of SSD1306 display module can be seen.
  @detail  I2C address selection
  @n       A0  A1  A2  I2C_addr
  @n       0   0   0   0x70(default)
  @n       0   0   1   0x71
  @n       0   1   0   0x72
  @n       0   1   1   0x73
  @n       1   0   0   0x74
  @n       1   0   1   0x75
  @n       1   1   0   0x76
  @n       1   1   1   0x77
  @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license     The MIT License (MIT)
  @author      PengKaixing(kaixing.peng@dfrobot.com)
  @version  V1.0
  @date  2022-03-23
  @url https://github.com/DFRobot/DFRobot_I2C_Multiplexer
'''
#hardware platform: FireBeetle-ESP32

from machine import Pin,I2C
import ssd1306
import DFRobot_I2C_Multiplexer

I2CMultiAddr = 0x70     #I2C Multiplexer addr
I2CMulti = DFRobot_I2C_Multiplexer.DFRobot_I2C_Multiplexer(I2CMultiAddr)  #Create an DFRobot_I2C_Multiplexer object

i2c = I2C(scl=Pin(22), sda=Pin(21), freq=100000)

#Let the SSD1306 on the port 0 display characters 
I2CMulti.selectPort(0)                #Select port
lcdA=ssd1306.SSD1306_I2C(128,64,i2c)  #Create a SSD1306 Object
lcdA.text("devicd A",0,0)             #Set the coordinate of character string and character 
lcdA.text("i2c addr 0x3C",0,30)
lcdA.show()                           #display pix

#Let SSD1306 on port 1 display characters 
I2CMulti.selectPort(1)
lcdB=ssd1306.SSD1306_I2C(128,64,i2c)
lcdB.text("devicd B",0,0)
lcdB.text("i2c addr 0x3C",0,30)
lcdB.show()

