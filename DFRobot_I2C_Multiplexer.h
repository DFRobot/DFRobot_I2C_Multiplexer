/*!
 * @file DFRobot_I2C_Multiplexer.h
 * @brief This library is for the I2C cascade module.
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      PengKaixing(kaixing.peng@dfrobot.com)
 * @version  V1.0.0
 * @date  2022-03-23
 * @url https://github.com/DFRobot/DFRobot_I2C_Multiplexer
 */

#ifndef _DFRobot_I2CMultiplexer_H_
#define _DFRobot_I2CMultiplexer_H_

#include "Wire.h"
#include <Arduino.h>

class DFRobot_I2C_Multiplexer
{
public:
  DFRobot_I2C_Multiplexer(TwoWire *pWire, uint8_t addr);

  /**
   * @fn begin
   * @brief IIC initialize
   */
  void begin(void);

  /**
   * @fn scan
   * @brief Scan all I2C devices connected to the I2C cascade module
   * @param port   Specify the port for scanning
   * @return uint8_t* Return the I2C address of all devices
   */
  uint8_t *scan(uint8_t port);

  /**
   * @fn selectPort
   * @brief  Specify the port of the I2C cascade module
   * @param port  Select port 
   */
  void selectPort(uint8_t port);

  /**
   * @fn read
   * @brief   Read the data of the target I2C device
   * @param port    The I2C port that the target device is connected to
   * @param addr    I2C address of the target device
   * @param reg     Register of the target device to be read
   * @param data    Data of the target device to be stored
   * @param len     Data length of the target device to be read
   * @return uint8_t read status
   */
  uint8_t read(uint8_t port,uint8_t addr,uint8_t reg,uint8_t* data, uint8_t len);

  /**
   * @fn write
   * @brief    Write the data into the target I2C device
   * @param port    The I2C port that the target device is connected to
   * @param addr    I2C address of the target device
   * @param reg     Register of the target device to be written
   * @param buf     Data of the target device to be written
   * @param len     Data length of the target device to be written
   */
  void write(uint8_t port,uint8_t addr, uint8_t reg,uint8_t* buf, uint8_t len);
private:
  TwoWire *_pWire;
  uint8_t _I2CMultiplexer_addr;
};

#endif
