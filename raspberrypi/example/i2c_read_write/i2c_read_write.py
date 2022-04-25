# -*- coding: utf-8 -*-
'''!
  @file i2c_read_write.py
  @brief Plug the I2C device onto the 0 port of module,
  @n     then connect module and Arduino, and download the sample.
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
import sys
import os
import time
sys.path.append(os.path.dirname(os.path.dirname(os.path.dirname(os.path.realpath(__file__)))))
import DFRobot_I2C_Multiplexer

I2CMultiAddr = 0x70     #I2C Multiplexer addr
port = 0                #The I2C device is connected to port 0

i2cDevAddr = 24         #I2C device addr
reg = 0                 #I2C register addr

buf = [111,107]         #The information will be sent 
nbytes = 3              #The length of received data

#Create an I2C Multiplexer object, the address of I2C Multiplexer is 0X70
I2CMulti = DFRobot_I2C_Multiplexer.DFRobot_I2C_Multiplexer(I2CMultiAddr)  

#Write buf to the Reg register of the I2C device on port 0
I2CMulti.writeto_mem(port,i2cDevAddr,reg,buf)

#Read message of 3 bytes length from the Reg register of the I2C device on Port 0.
data = I2CMulti.readfrom_mem(port,i2cDevAddr,reg,nbytes)
print(data)
