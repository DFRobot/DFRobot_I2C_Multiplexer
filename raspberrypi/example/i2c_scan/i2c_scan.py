# -*- coding: utf-8 -*-
'''!
  @file i2c_scan.py
  @brief Connect I2C devices to module, and connect module to Arduino, 
  @n     then download this example, open serial monitor to check the I2C addr.
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

I2CMultiAddr = 0x70       #I2C Multiplexer addr

I2CMulti = DFRobot_I2C_Multiplexer.DFRobot_I2C_Multiplexer(I2CMultiAddr)
for Port in range(0,8):   #Scan i2C devices of each port
  print("Port:%s" %Port)
  addr = I2CMulti.scan(Port)
  if(len(addr)):
    print("i2c addr:%s" %addr)
