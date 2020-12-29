/*!
 *@file test.ino
 *@brief  DFplayer模块完整功能测试程序
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

DFRobot_PLAY rp;

void setup(){
  Serial.begin(115200);
  Serial1.begin(115200);
  while(!rp.begin(Serial1)){
    Serial.println("初始化失败，请检查接线！");
    delay(1000);
  }
  Serial.print("setLED = ");
  Serial.println(rp.setLED(true));
  Serial.print("setPrompt = ");
  Serial.println(rp.setPrompt(true));
  Serial.print("setVol = ");
  Serial.println(rp.setVol(10));
  Serial.print("getVol = ");
  Serial.println(rp.getVol());
  Serial.print("switchFunction = ");
  Serial.println(rp.switchFunction(rp.MUSIC));
  delay(1000);
  Serial.print("setPlayMode = ");
   Serial.println(rp.setPlayMode(rp.ALLCYCLE));
  Serial.print("getPlayMode = ");
   Serial.println(rp.getPlayMode());
   
  Serial.print("start = ");
  Serial.println(rp.start());
  delay(3000);
  Serial.print("queryFile = ");
  Serial.println(rp.getCurFileNumber());
  Serial.println(rp.getTotalFile());
  Serial.println(rp.getCurTime());
  Serial.println(rp.getTotalTime());
  Serial.println(rp.getFileName());

  Serial.println("AMP : ");

    rp.disableAMP();
    delay(5000);
    rp.enableAMP();
    delay(5000);
  
  Serial.println("FF : ");
  Serial.println(rp.fastForward(10));
  delay(5000);
  Serial.println(rp.fastReverse(10));
  delay(5000);
  Serial.println(rp.setPlayTime(10));
  delay(5000);
  Serial.println("next ");
  Serial.println(rp.next());
  delay(5000);
  Serial.println("last");
  Serial.println(rp.last());
  delay(10000);

  rp.playSpecFile("/DF***/*******.MP3");
  delay(3000);

  rp.playFileNum(2);
  delay(3000);
  Serial.print("start = ");
  //Serial.println(rp.delCurFile());
  Serial.print("switchFunction = ");
  
  
  Serial.println(rp.switchFunction(rp.UFDISK));
}

void loop(){
}
