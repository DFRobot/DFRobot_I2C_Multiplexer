/*!
 * @file scanI2C.ino
 * @brief Connect I2C devices to I2C Multiplexer, and connect I2C Multiplexer to Arduino, 
 * @n     then download this example open serial monitor to check the I2C addr.
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

/*Create an I2C Multiplexer object, the address of I2C Multiplexer is 0x70*/
DFRobot_I2C_Multiplexer I2CMultiplexer(&Wire, 0x70);

void setup(){
  Serial.begin(9600);
  delay(1000);
  Serial.println("Scan ready!");

  /*Print I2C device of each port*/
  for(uint8_t port = 0; port < 8; port++)
  {
    Serial.print("Port:");
    Serial.print(port);
    uint8_t *dev = I2CMultiplexer.scan(port);
    while (*dev)
    {
      Serial.print("  i2c addr ");
      Serial.print(*dev);
      dev++;
    }
    Serial.println();
  }
}

void loop(){
  
}
