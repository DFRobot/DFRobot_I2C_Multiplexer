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
 * @maintainer  [qsjhyy](yihuan.huang@dfrobot.com)
 * @version  V1.0
 * @date  2022-12-06
 * @url https://github.com/DFRobot/DFRobot_I2C_Multiplexer
 */
#include "DFRobot_SSD1306_I2C.h"
#include "DFRobot_I2C_Multiplexer.h"

/*Create an OLED object, the address is 0x3c*/ 
DFRobot_SSD1306_I2C OLED(0x3c);

/*Create an I2C Multiplexer object, the address of I2C Multiplexer is 0X70*/
DFRobot_I2C_Multiplexer I2CMulti(&Wire, 0x70);

void setup(void){
  I2CMulti.begin();
  /*Let the OLED on port 0 display characters*/
  /**
   * @brief Enable a specific channel on the I2C multiplexer or disable all channels
   * @param port - Select channel, range: 0 - 8
   * @n 0-7 for enabling the corresponding channel separately, 8 for disabling all channels 
   * @note When“multiple multiplexer modules” are used on one I2C bus to connect “sensors with same I2C address”, to avoid conflicts,  
   * @n it is necessary to ensure that “the currently used channel”is the only enabled one among “all channels in all multiplexers” 
   * @n For instance, when one of the channels in the first multiplexer is enabled, in order to use any channel in the second multiplexer,  
   * @n please make sure that the channels in the first multiplexer are all disabled.
   */
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
  /**
   * Disable all channels to avoid interference when using multiple multiplexer.
   * If only one multiplexer is used, you don't need to do that.
   */
  // I2CMulti.selectPort(8);

  /*Let OLED on port 1 display characters */
  I2CMulti.selectPort(1);
  OLED.begin();
  OLED.setTextColor(1);
  OLED.setTextSize(2);
  
  OLED.setCursor(0,0);
  OLED.print("device B");
  OLED.setCursor(0,30);
  OLED.print("addr:0x3C");
  /**
   * Disable all channels to avoid interference when using multiple multiplexer.
   * If only one multiplexer is used, you don't need to do that.
   */
  // I2CMulti.selectPort(8);
}

void loop(void){
}
