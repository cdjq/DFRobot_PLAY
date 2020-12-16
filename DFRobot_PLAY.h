/*!
 *@file DFRobot_PLAY.cpp
 *@brief 定义DFRobot_PLAY 类的基础结构，基础方法的实现
 *@copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 *@licence     The MIT License (MIT)
 *@author [fengli](li.feng@dfrobot.com)
 *@version  V1.0
 *@date  2020-12-02
 *@get from https://www.dfrobot.com
 *@https://github.com/DFRobot/DFRobot_PLAY
*/


#ifndef DFROBOT_RP_H
#define DFROBOT_RP_H

#include <Arduino.h>
#include <string.h>

//extern Stream *dbg;
class DFRobot_PLAY
{
public:

  typedef enum{
    MUSIC = 1,  //音乐模式
    UFDISK,     //从机模式
  }eFunction_t;
  
  typedef struct{
   String str;
   uint8_t length;
  }sPacket_t;
  
  typedef enum{
    SINGLECYCLE = 1,  //单曲循环
    ALLCYCLE,         //全部循环
    SINGLE,           //单曲播放一次
    RANDOM,           //随机播放
    FOLDER,           //文件夹循环
    ERROR,             
  }ePlayMode_t;



  DFRobot_PLAY();
  //~DFRobot_PLAY();
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
  
  //bool operation( );
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
  void playSpecFile(String str);
  
  /**
   * @brief 播放指定编号文件,编号根据文件拷贝进入U盘先后顺序排列
   * @param 文件编号，可通过getCurFileNumber()获取
   */
  void playFileNum(int16_t num);

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
private:
  uint8_t getINT(String str);
  uint8_t unicodeToUtf8(uint16_t unicode ,uint8_t * uft8);
  sPacket_t pack(String cmd = " ",String para = " " );
  Stream *_s = NULL;
  void writeATCommand(String command,uint8_t length);
  String readAck(uint8_t len = 4);
  eFunction_t curFunction;
  String atCmd;
  
  uint8_t pauseFlag;
  
};

#endif
