# DFRobot_PLAY

Here comes the DFPlayer Pro-a mini simple but powerful MP3 Player! This MP3 player module supports four controlling modes: Arduino, AT command, on-board buttons, and ADKEY. You can directly press the on-board button to play or switch music without using a controller. By using a USB cable, you can easily copy your favorite songs into this module to play them any where you want, or use it as a sound card for your PC or Raspberry Pi after connecting them together.

## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary
1. Playing Music



## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods
```C++
  /**
   * @brief init function
   * @return true or false
   */
  bool begin(Stream &s);
  
  /**
   * @brief Set baud rate(Need to power off and restart, power-down save) 
   * @param 9600,19200,38400,57600,115200
   * @return true or false
   */
  bool setBaudRate(uint32_t baud);

  /**
   * @brief Set playback mode 
   * @param ePlayMode_t:SINGLECYCLE,ALLCYCLE,SINGLE,RANDOM,FOLDER
   * @return true or false
   */
  bool setPlayMode(ePlayMode_t mode);

  /**
   * @brief Set indicator(Power-down save) 
   * @param true or false
   * @return true or false
   */
  bool setLED(bool on);
  
  /**
   * @brief Set prompt tone (Power-down save) 
   * @param true or false
   * @return true or false
   */
  bool setPrompt(bool on);
  
  /**
   * @brief Set volume 
   * @param vol:0-30
   * @return true or false
  */
  bool setVol(uint8_t vol);
  
  /**
   * @brief Set working mode 
   * @param eFunction_t:MUSIC,RECORD,UFDISK
   * @return true or false
   */
  bool switchFunction(eFunction_t function);
  
  /**
   * @brief Next 
   * @return true or false
   */
  bool next();
  
  /**
   * @brief Previous 
   * @return true or false
   */
  bool last();
  
  /**
   * @brief Play播放(在音乐模式下) or 录音(在录音模式下)
   * @return true or false
   */
  bool start();
  
  /**
   * @brief 暂停播放(在音乐模式下) or 暂停录音(在录音模式下)
   * @return true or false
   */
  bool pause();
  /**
   * @brief 删除当前播放文件
   * @return true or false
   */
  bool delCurFile();
  
  /**
   * @brief 播放指定路径文件
   * @param 指定路径
   */
  bool playSpecFile(String str);
  
  /**
   * @brief 播放指定编号文件,编号根据文件拷贝进入U盘先后顺序排列
   * @param 文件编号，可通过getCurFileNumber()获取
   */
  bool playFileNum(int16_t num);

  /**
   * @brief 获取音量
   * @return vol
   */
  uint8_t getVol();

  /**
   * @brief 获取播放模式
   * @return ePlayMode_t
   */
  ePlayMode_t getPlayMode();
  
  /**
   * @brief 获取文件编号
   */
  uint16_t getCurFileNumber();
  
  /**
   * @brief 获取可播放文件的个数
   */
  uint16_t getTotalFile();
  
  /**
   * @brief 获取当前歌曲播放到的时间
   */
  uint16_t getCurTime();
  
  /**
   * @brief 获取当前歌曲播放的总时间
   */
  uint16_t getTotalTime();
  
  /**
   * @brief 获取播放文件的文件名
   */
  String   getFileName();
  
  /**
   * @brief 使能功放芯片
   * @return true or false
   */
  bool enableAMP();
  /**
   * @brief 禁止功放芯片
   * @return true or false
   */
  bool disableAMP();
  
  /**
   * @brief 使当前播放歌曲快进
   * @param second  快进的时间(单位：S)
   */
  bool fastForward(uint16_t second);
  
  /**
   * @brief 使当前播放歌曲后退
   * @param second  后退的时间(单位：S)
   */
  bool fastReverse(uint16_t second);
  
  /**
   * @brief 使当前播放歌曲从固定时间点开始播放
   * @param second  固定时间点
   */
  bool setPlayTime(uint16_t second);
```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino Uno        |      √       |              |             | 
Mega2560        |      √       |              |             | 
Leonardo        |      √       |              |             | 
ESP32        |      √       |              |             | 
ESP8266        |      √       |              |             | 
M0        |      √       |              |             | 


## History

- Date 2020-7-31
- Version V0.1


## Credits

Written by fengli(li.feng@dfrobot.com), 2020.7.31 (Welcome to our [website](https://www.dfrobot.com/))





