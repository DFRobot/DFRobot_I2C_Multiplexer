/*!
 * @file DFRobot_I2C_Multiplexer.cpp
 * @brief The I2C cascade module support library
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      PengKaixing(kaixing.peng@dfrobot.com)
 * @version  V1.0.0
 * @date  2022-03-23
 * @url https://github.com/DFRobot/DFRobot_I2C_Multiplexer
 */

#include <DFRobot_I2C_Multiplexer.h>

DFRobot_I2C_Multiplexer::DFRobot_I2C_Multiplexer(TwoWire *pWire, uint8_t addr)
{
  _pWire=pWire;
  _I2CMultiplexer_addr = addr;
 
}

void DFRobot_I2C_Multiplexer::begin(void)
{
  _pWire->begin();
}

uint8_t *DFRobot_I2C_Multiplexer::scan(uint8_t port)
{
  static uint8_t dev[127] = {0};
  memset(dev,0,sizeof(dev));
  uint8_t i = 0;
  selectPort(port);
  byte error, address;
  for(address = 1; address < 127; address++ ) 
  {
    if (address == _I2CMultiplexer_addr)
      continue;
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0)
    {
      dev[i] = address;
      i++;
    }
  }
  return dev;
}

void DFRobot_I2C_Multiplexer::selectPort(uint8_t port)
{
  if (port > 7) 
    return;
  Wire.beginTransmission(_I2CMultiplexer_addr);
  Wire.write(1 << port);
  Wire.endTransmission();
}

void DFRobot_I2C_Multiplexer::write(uint8_t port,uint8_t addr, uint8_t reg,uint8_t* buf, uint8_t len)
{
  selectPort(port);
  Wire.beginTransmission(addr); 
  Wire.write(reg);              
  uint8_t i = 0;
  for(i = 0; i < len; i++)
  {
    Wire.write(*buf); 
    buf++;
  }
  Wire.endTransmission();    
}

uint8_t DFRobot_I2C_Multiplexer::read(uint8_t port,uint8_t addr,uint8_t reg,uint8_t* data, uint8_t len)
{
  selectPort(port);
  int i = 0;
  Wire.beginTransmission(addr); 
  Wire.write(reg); 
  Wire.endTransmission(); 
  Wire.requestFrom(addr, len);
  while (Wire.available())   
  {
    data[i++] = Wire.read(); 
  }
  return i;
}
