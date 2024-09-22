#include "Config.h"

void setup(){
 Serial.begin(115200);
 Tetris_setup();

 display.setTextWrap(false);
 display.begin(16);
 display.setFastUpdate(true);
 display.setBrightness(8);   //亮度
 display.clearDisplay();
 display.setTextColor(display.color565(0,255,0));  //預設文字顏色
 display.setDriverChip(FM6124);
 display_update_enable(true);

  //showWiFiDoneAnimation(true);

  configTime(MY_TZ, MY_NTP_SERVER); 
  
  EEPROM.begin(EEPROM_SIZE);
  
  // 如果值为EEPROM_CONFIRM则判断存有预置值
  if (EEPROM.read(EEPROM_GAIN) != EEPROM_CONFIRM) {
    EEPROM.write(EEPROM_GAIN, EEPROM_CONFIRM);
    EEPROM.write(EEPROM_BRIGHTNESS, brightnessNow);
    EEPROM.write(EEPROM_MODE, Mode);
    EEPROM.write(EEPROM_COLOR, hue/2);
    EEPROM.write(EEPROM_COLOR_H, hueh/2);
    EEPROM.write(EEPROM_COLOR_M, huem/2);
    EEPROM.write(EEPROM_COLOR_S, hues/2);
    EEPROM.write(EEPROM_COLOR_W, huew/2);
    EEPROM.write(EEPROM_PIC_X, pic_x);
    EEPROM.write(EEPROM_PIC_Y, pic_y);
    EEPROM.write(EEPROM_CLOCK_MODE, clockMode);
    EEPROM.write(EEPROM_DATE_MODE, dateMode);
    EEPROM.write(EEPROM_LOOP_MODE, loopMode);
  
    //EEPROM.write(EEPROM_COLOR_B, hueb/2);

    EEPROM.commit();
  }else{
    brightnessNow = EEPROM.read(EEPROM_BRIGHTNESS);
    Mode = EEPROM.read(EEPROM_MODE);
    hue = int(EEPROM.read(EEPROM_COLOR))*2;
    hueh = int(EEPROM.read(EEPROM_COLOR_H))*2;
    huem = int(EEPROM.read(EEPROM_COLOR_M))*2;
    hues = int(EEPROM.read(EEPROM_COLOR_S))*2;
    huew = int(EEPROM.read(EEPROM_COLOR_W))*2;
    pic_x = int(EEPROM.read(EEPROM_PIC_X));
    pic_y = int(EEPROM.read(EEPROM_PIC_Y));
    clockMode = int(EEPROM.read(EEPROM_CLOCK_MODE));
    dateMode = int(EEPROM.read(EEPROM_DATE_MODE));
    loopMode = int(EEPROM.read(EEPROM_LOOP_MODE));
    T_topscore = int(EEPROM.read(EEPROM_T_TOPscore));
    S_topscore = int(EEPROM.read(EEPROM_S_TOPscore));

    read_start_H = int(EEPROM.read(EEPROM_START_H));
    read_start_M = int(EEPROM.read(EEPROM_START_M));
    read_end_H = int(EEPROM.read(EEPROM_END_H));
    read_end_M = int(EEPROM.read(EEPROM_END_M));
    random_gif_no = int(EEPROM.read(EEPROM_GIF_NO));
    random_min = int(EEPROM.read(EEPROM_RANDOM_MIN));

    start_H = read_start_H;
    start_M = read_start_M;
    end_H = read_end_H;
    end_M = read_end_M;

    
  }


    // 啟動WIFI 
    setwifi();

    //顯示讀取後亮度
    // display.setBrightness(brightnessNow);



  //顯示已連線IP   @(ShowPage)
   ShowIP();
   delay(3000);

   //初始化fs網頁
   fssetup();


    //初始化網頁功能
     InitServer();
     switchMode(true,Mode);
    }  //end Setup



 void loop(){
    ShowClock();
    WebServer_run();
    switchMode(false,Mode);
    switchGameMode(GameMode);
    delay(10);

   }




   
