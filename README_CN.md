# DFRobot_I2C_Multiplexer

- [English Version](./README.md)

Gravity: I2C扩展器专门用于解决I2C器件地址的冲突，通过这款扩展器的转接，连接到主控板同一个I2C口上的多个相同地址的I2C器件就可以正常通信并使用了。

![正反面svg效果图](./resources/images/DFR0576.png)

## 产品链接(https://www.dfrobot.com.cn/goods-1827.html)

SKU：DFR0576

## 目录

* [概述](#概述)
* [库安装](#库安装)
* [方法](#方法)
* [兼容性](#兼容性y)
* [历史](#历史)
* [创作者](#创作者)

## 概述

I2C级联模块支持库

## 库安装

使用此库前，请首先下载库文件，将其粘贴到\Arduino\libraries目录中，然后打开examples文件夹并在该文件夹中运行演示。

## 方法

```C++

  /**
   * @fn scan
   * @brief 扫描I2C级联模块上连接所有的I2C设备
   * @param port 指定在哪个通道上进行扫描
   * @return uint8_t* 返回所有的设备的I2C地址
   */
  uint8_t *scan(uint8_t port);

  /**
   * @fn selectPort
   * @brief 指定I2C级联模块的通道
   * @param port 通道选择
   */
  void selectPort(uint8_t port);

  /**
   * @fn read
   * @brief I2C读取目标设备的数据
   * @param port 目标设备连接在I2C哪个端口上
   * @param addr 目标设备的I2C地址
   * @param reg 要读取的目标设备的寄存器
   * @param data 要存储的目标设备的数据
   * @param len 要读取的目标设备的数据长度
   * @return uint8_t 读取状态
   */
  uint8_t read(uint8_t port,uint8_t addr,uint8_t reg,uint8_t* data, uint8_t len);

  /**
   * @fn write
   * @brief I2C写进目标设备的数据
   * @param port 目标设备连接在I2C哪个端口上
   * @param addr 目标设备的I2C地址
   * @param reg 要写入的目标设备的寄存器
   * @param buf 要写入的目标设备的数据
   * @param len 要写入的目标设备的数据长度
   */
  void write(uint8_t port,uint8_t addr, uint8_t reg,uint8_t* buf, uint8_t len);

```

## 兼容性

主板               | 通过  | 未通过   | 未测试   | 备注
------------------ | :----------: | :----------: | :---------: | -----
FireBeetle-ESP32  |      √       |             |            | 
FireBeetle-ESP8266|      √       |              |             | 
Mega2560  |      √       |             |            | 
Arduino uno |       √      |             |            | 
Leonardo  |      √       |              |             | 
Micro：bit  |      √       |              |             | 
M0  |      √       |              |             | 

## 历史

- 2022/3/23 - 1.0.0 版本

## 创作者

Written by PengKaixing(kaixing.peng@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))