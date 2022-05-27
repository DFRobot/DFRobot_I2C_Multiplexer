/*!
 * @file multiSsd1306.ino
 * @brief Connect two SSD1306 devices to the port 0 and  port 1 on the i2c multiplexer respectively 
 * @n     and then connect the I2c multiplexer and Arduino, download this sample. The address of I2C and
 * @n     the name of SSD1306 display module can be seen.
 * @n     Download Display library https://github.com/DFRobot/DFRobot_Display.git
 * @n     Download SSD1306 library https://github.com/DFRobot/DFRobot_SSD1306.git
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
#include "DFRobot_SSD1306_I2C.h"
#include "DFRobot_I2C_Multiplexer.h"

/*Create an OLED object, the address is 0x3c*/ 
DFRobot_SSD1306_I2C OLED(0x3c);

/*Create an I2C Multiplexer object, the address of I2C Multiplexer is 0X70*/
DFRobot_I2C_Multiplexer I2CMulti(&Wire, 0x70);

void setup(void){
  I2CMultiplexer.begin();
  /*Let the OLED on port 0 display characters*/
  // Select port
  I2CMulti.selectPort(0);
  // Initialize OLED
  OLED.begin();                
  OLED.setTextColor(1);
  OLED.setTextSize(2);

  // Set the corrdianate of characters
  OLED.setCursor(0,0);
  // Display characters
  OLED.print("device A");       
  OLED.setCursor(0,30);
  OLED.print("addr:0x3C");

  /*Let OLED on port 1 display characters */
  I2CMulti.selectPort(1);
  OLED.begin();
  OLED.setTextColor(1);
  OLED.setTextSize(2);
  
  OLED.setCursor(0,0);
  OLED.print("device B");
  OLED.setCursor(0,30);
  OLED.print("addr:0x3C");
}

void loop(void){
}
