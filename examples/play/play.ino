/*!
 *@file play.ino
 *@brief  音乐播放示例程序
 *@copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 *@licence     The MIT License (MIT)
 *@author [fengli](li.feng@dfrobot.com)
 *@version  V1.0
 *@date  2020-12-02
 *@get from https://www.dfrobot.com
 *@https://github.com/DFRobot/DFRobot_PLAY
*/


#include <DFRobot_PLAY.h>
#include <SoftwareSerial.h>

SoftwareSerial Serial1(2, 3);  //RX  TX

DFRobot_PLAY DF1201S;
void setup(void){
  Serial.begin(115200);
  Serial1.begin(115200);
  while(!DF1201S.begin(Serial1)){
    Serial.println("初始化失败，请检查接线！");
    delay(1000);
  }
  /*设置音量为20*/
  DF1201S.setVol(/*VOL = */20);
  Serial.print("VOL:");
  /*获取音量*/
  Serial.println(DF1201S.getVol());
  /*进入音乐模式*/
  DF1201S.switchFunction(DF1201S.MUSIC);
  /*等待提示音播放完*/
  delay(2000);
  /*设置播放模式为全部循环*/
  DF1201S.setPlayMode(DF1201S.ALLCYCLE);
  Serial.print("PlayMode:");
  /*获取播放模式*/
  Serial.println(DF1201S.getPlayMode());
  
  //设置波特率为115200(需断电重启，掉电保存)
  //DF1201S.setBaudRate(115200);
  //打开指示灯(掉电保存)
  //DF1201S.setLED(true);
  //打开提示音(掉电保存)
  //DF1201S.setPrompt(true);
  //使能功放芯片
  //DF1201S.enableAMP();
  //失能功放芯片
  //DF1201S.disableAMP();
}

void loop(){
  Serial.println("开始播放");
  /*开始播放*/
  DF1201S.start();
  delay(3000);
  Serial.println("暂停播放");
  /*暂停播放*/
  DF1201S.pause();
  delay(3000);
  Serial.println("播放下一曲");
  /*播放下一曲*/
  DF1201S.next();
  delay(3000);
  Serial.println("播放上一曲");
  /*播放上一曲*/
  DF1201S.last();
  delay(3000);
  Serial.println("开始播放");
  //快进10S
  DF1201S.fastForward(/*FF = */10);
  //快退10S
  //DF1201S.fastReverse(/*FR = */10);
  //从第10S开始播放
  //DF1201S.setPlayTime(/*Play Time = */10);
  
  Serial.print("文件号:");
  //获取文件号
  Serial.println(DF1201S.getCurFileNumber());
  
  Serial.print("可播放文件的个数:");
  //获取可播放文件的个数
  Serial.println(DF1201S.getTotalFile());
  
  Serial.print("当前歌曲播放到的时间:");
  //获取当前歌曲播放到的时间
  Serial.println(DF1201S.getCurTime());
  
  Serial.print("当前歌曲播放的总时间:");
  //获取当前歌曲播放的总时间
  Serial.println(DF1201S.getTotalTime());
  Serial.print("当前播放文件名:");
  //获取播放文件的文件名
  Serial.println(DF1201S.getFileName());
  delay(3000);
  //播放第一号文件,编号根据文件拷贝进入U盘先后顺序排列
  DF1201S.playFileNum(/*File Number = */1);
  //播放test文件夹下的test.mp3文件
  //DF1201S.playSpecFile("/test/test.mp3");
  
  while(1);
  /*删除正在播放的文件*/
  //DF1201S.delCurFile();
}
