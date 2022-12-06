# -*- coding: utf-8 -*-
'''!
  @DFRobot_I2C_Multiplexer.py
  @brief Raspberry Pi library for I2C cascade module 
  @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license     The MIT License (MIT)
  @author      PengKaixing(kaixing.peng@dfrobot.com)
  @maintainer  [qsjhyy](yihuan.huang@dfrobot.com)
  @version  V1.0
  @date  2022-12-06
  @url https://github.com/DFRobot/DFRobot_I2C_Multiplexer
'''
import time
import sys
import smbus

class DFRobot_I2C_Multiplexer:
  '''!
    @brief  I2C cascade module library class
  '''
  def __init__(self,addr):
    self.i2c = smbus.SMBus(1)
    self.addr = addr
  
  def scan(self,port):
    '''!
      @brief   Scan all I2C devices connected to the I2C cascade module
      @param port  Specify the port for scanning
      @return  Return the I2C address of all devices
    '''
    buf = []
    self.select_port(port)
    for addr in range(0,128):
      if(addr == self.addr):
        continue
      try:
        self.i2c.write_byte(addr,0)
        buf.append(addr)
      except:
        pass
    return buf
  
  def select_port(self,port):
    '''!
      @brief Enable a specific channel on the I2C multiplexer or disable all channels
      @param port - Select channel, range: 0- 8
      @n 0-7 for enabling the corresponding channel separately, 8 for disabling all channels 
      @note When“multiple multiplexer modules” are used on one I2C bus to connect “sensors with same I2C address”, to avoid conflicts,  
      @n it is necessary to ensure that “the currently used channel”is the only enabled one among “all channels in all multiplexers” 
      @n For instance, when one of the channels in the first multiplexer is enabled, in order to use any channel in the second multiplexer,  
      @n please make sure that the channels in the first multiplexer are all disabled.
    '''    
    if(port > 8):
      return
    data = (1<<port) & 0xFF
    self.i2c.write_byte(self.addr,data)
    
  def writeto_mem(self,port,addr,reg,buf):
    '''!
      @brief Write the data into the target I2C device 
      @param port    The I2C port that the target device is connected to
      @param addr    I2C address of the target device
      @param reg     Register of the target device to be written
      @param buf     Data of the target device to be written
    '''
    self.select_port(port)
    self.i2c.write_i2c_block_data(addr,reg,buf)
    
  def readfrom_mem(self,port,addr,reg,nbytes):
    '''!
      @brief  Read the data of the target I2C device
      @param port    The I2C port that the target device is connected to
      @param addr    I2C address of the target device
      @param reg     Register of the target device to be read
      @param nbytes  Data of the target device to be stored
      @return uint8_t read status
    '''
    self.select_port(port)
    return self.i2c.read_i2c_block_data(addr,reg,nbytes)

