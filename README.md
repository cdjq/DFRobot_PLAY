# DFRobot_PLAY

您是否在寻找一款简单又强大的MP3播放模块？看这里！这款MP3播放模块支持arduino、AT指令、板载按键和AD按键四种控制方式。
通过板载按键即使在没有微控制器的情况下也能进行音乐播放和切换。模块搭载了128MB的存储空间，通过USB线您可以很容易的将
您喜欢的音乐拷贝到模块中。该模块可作为电脑或Raspberry Pi声卡，用USB数据线将模块和电脑连接，电脑播放音乐即可通过该
模块输出。

## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary
1.播放音乐



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
   * @brief 设置波特率(需断电重启，掉电保存)
   * @param 9600,19200,38400,57600,115200
   * @return true or false
   */
  bool setBaudRate(uint32_t baud);

  /**
   * @brief 设置播放模式
   * @param ePlayMode_t:SINGLECYCLE,ALLCYCLE,SINGLE,RANDOM,FOLDER
   * @return true or false
   */
  bool setPlayMode(ePlayMode_t mode);

  /**
   * @brief 设置指示灯(掉电保存)
   * @param true or false
   * @return true or false
   */
  bool setLED(bool on);
  
  /**
   * @brief 设置提示音(掉电保存)
   * @param true or false
   * @return true or false
   */
  bool setPrompt(bool on);
  
  /**
   * @brief 设置音量
   * @param vol:0-30
   * @return true or false
  */
  bool setVol(uint8_t vol);
  
  /**
   * @brief 设置工作模式
   * @param eFunction_t:MUSIC,RECORD,UFDISK
   * @return true or false
   */
  bool switchFunction(eFunction_t function);
  
  /**
   * @brief 下一曲
   * @return true or false
   */
  bool next();
  
  /**
   * @brief 上一曲
   * @return true or false
   */
  bool last();
  
  /**
   * @brief 播放(在音乐模式下) or 录音(在录音模式下)
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





