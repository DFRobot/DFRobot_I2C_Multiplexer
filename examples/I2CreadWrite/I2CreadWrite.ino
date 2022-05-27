/*!
 * @file I2CreadWrite.ino
 * @brief Plug the I2C device onto the port 0 of I2cmultiplexer,
 * @n     then connect i2c multiplexer and Arduino, and download the sample.
 * @detail  I2C address selection
 * @n       A0  A1  A2  I2C_addr
 * @n       0   0   0   0x70(default)
 * @n       0   0   1   0x71
 * @n       0   1   0   0x72
 * @n       0   1   1   0x73
 * @n       1   0   0   0x74
 * @n       1   0   1   0x75
 * @n       1   1   0   0x76
 * @n       1   1   1   0x77
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      PengKaixing(kaixing.peng@dfrobot.com)
 * @version  V1.0.0
 * @date  2022-03-23
 * @url https://github.com/DFRobot/DFRobot_I2C_Multiplexer
 */
#include <DFRobot_I2C_Multiplexer.h>

/*Create an I2C Multiplexer object,and the address of I2C Multiplexer is 0X70*/
DFRobot_I2C_Multiplexer I2CMultiplexer(&Wire, 0x70);

/*Plug I2C device onto port 0*/
uint8_t port = 0;

/*The address of I2C is 0x18*/
uint8_t i2c_addr = 0x18;

/*The register address of I2C*/
uint8_t reg = 0;

void setup()
{
  Serial.begin(9600);
  I2CMultiplexer.begin();
}

void loop()
{
  uint8_t buf[3] = {0}; 
  /**
   * @brief Read 3 bytes from the 0 register of the I2C device on port 0 into the buf, 
   * @n     then prints the data from the buf in hexadecimal order
   */
  if(I2CMultiplexer.read(port,i2c_addr,reg,buf,3) > 0)
  {
    Serial.println((int)buf[0],HEX);  
    Serial.println((int)buf[1],HEX);
    Serial.println((int)buf[2],HEX);
  }
  
  /*Wirte the data of I2C*/ 
  uint8_t data[2] = {111,107};
  
  /*Write data to the 0 register of the I2C device on port 0, the length of data is 3*/
  I2CMultiplexer.write(port,i2c_addr,reg, data, 2);
  delay(1000);
}
