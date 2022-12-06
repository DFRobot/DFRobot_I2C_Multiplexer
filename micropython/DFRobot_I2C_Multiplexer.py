'''!
  @DFRobot_I2C_Multiplexer.py
  @brief ESP32 python library for I2C cascade module 
  @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license     The MIT License (MIT)
  @author      PengKaixing(kaixing.peng@dfrobot.com)
  @maintainer  [qsjhyy](yihuan.huang@dfrobot.com)
  @version  V1.0
  @date  2022-12-06
  @url https://github.com/DFRobot/DFRobot_I2C_Multiplexer
'''

from machine import Pin,I2C
import time

class DFRobot_I2C_Multiplexer:
  '''!
    @brief  I2C cascade module library class
  '''
  def __init__(self,I2CMultiAddr):
    self.i2c = I2C(scl=Pin(22), sda=Pin(21), freq=10000)
    self.addr = I2CMultiAddr
  
  def scan(self,port):
    '''!
      @brief       Scan all I2C devices connected to the I2C cascade module
      @param port  Specify the port for scanning
      @return      Return the I2C address of all devices
    '''
    buf = []
    i = 0
    self.selectPort(port)
    for addr in range(0,128):
      if(addr == self.addr):
        continue
      try:
        if(self.i2c.writeto(addr,b'0')):
          buf.append(addr)
      except:
        pass
    return buf
  
  def selectPort(self,port):
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
    buf = bytearray(1)
    buf[0] = (1<<port) & 0xFF
    self.i2c.start()
    self.i2c.writeto(self.addr,buf)
    self.i2c.stop()
  
  def writeto(self,port,addr,buf):
    '''!
      @brief  Write the data of the target I2C device
      @param port  The I2C port that the target device is connected to
      @param addr  I2C address of the target device
      @param buf   Data of the target device to be written
    '''
    self.selectPort(port)
    return self.i2c.writeto(addr,buf)
  
  def readfrom(self,port,addr,nbytes):
    '''!
      @brief  Read the data of the target device
      @param port    The I2C port that the target device is connected to
      @param addr    I2C address of the target device
      @param nbytes  Data of the target device to be stored
      @return uint8_t read status
    '''
    self.selectPort(port)
    return self.i2c.readfrom(addr,nbytes)
    
  def writeto_mem(self,port,addr,reg,buf):
    '''!
      @brief  Write the data of the target I2C device
      @param port   The I2C port that the target device is connected to
      @param addr   I2C address of the target device
      @param reg    Register of the target device to be written
      @param buf    Data of the target device to be written
    '''
    self.selectPort(port)
    return self.i2c.writeto_mem(addr,reg,buf)
    
  def readfrom_mem(self,port,addr,reg,nbytes):
    '''!
      @brief  Read the data of the target I2C device
      @param port    The I2C port that the target device is connected to
      @param addr    I2C address of the target device
      @param reg     Register of the target device to be read
      @param nbytes  Data of the target device to be stored
      @return uint8_t read status
    '''
    self.selectPort(port)
    return self.i2c.readfrom_mem(addr,reg,nbytes)
