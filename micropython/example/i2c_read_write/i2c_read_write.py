'''!
  @file i2c_read_write.py
  @brief Plug the I2C device onto the port 0 of module,
  @n     then connect module and ESP32.
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
import  DFRobot_I2C_Multiplexer
from machine import Pin,I2C

I2CMultiAddr = 0x70     #I2C Multiplexer addr
port = 0                #I2C device is connected to port 0
i2cAddr = 24            #The address of I2C 
            
buf = bytearray(3)      #The information to be sent
buf[0] = 0
buf[1] = 111
buf[2] = 107

nbytes = 3              #The length of the received data 

#Create an DFRobot_I2C_Multiplexer object, the address of DFRobot_I2C_Multiplexer is 0X70
I2CMulti = DFRobot_I2C_Multiplexer.DFRobot_I2C_Multiplexer(I2CMultiAddr)  
I2CMulti.writeto(port,i2cAddr,buf)            #Write buf to I2C device on port 0
msg = I2CMulti.readfrom(port,i2cAddr,nbytes)  #Read 3-byte length messages from the I2C device on port 0
print(msg)





