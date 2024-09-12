
void showWeather(bool implement){
    uint16_t showColor = hsv2rgb(hue, saturation, value);
   
    if ( millis() - weatherTime > 60000*5 || implement)   //設定多久更新天氣  (60秒 x ?分鐘)
    {  
        weatherNow("http://114.33.152.14:8080/weather/json.php");
        Serial.println(F("擷取JSON"));
        weatherTime = millis(); 
    }

 /*   //天氣模式輪播   15秒
    if(millis() - loopTime > 15000 && !implement){
      if(++weatherMode>1) weatherMode=1;
      loopTime = millis();
      display.clearDisplay();
    }

    switch(weatherMode){
      case 1:     
    display.clearDisplay();
 */       
 // display.fillRect(0+GlobalX,0+GlobalY,8,8,display.color565(0,0,0));  //設定某個範圍為黑色(空白)
  
     if ( millis() - colonTime > 1000 )
     {
    colon = !colon;
    colonTime = millis();
     }
    showbigColon(38,6,colon,hsv2rgb(hue, saturation, value));
    showbigColon(38,14,colon,hsv2rgb(hue, saturation, value));
  

 if ( millis() - last_M_Time > 25000){ 

    time(&now);
    localtime_r(&now, &tm);
    H = tm.tm_hour;
    M = tm.tm_min;

        
         show20bitnumber(H,10,17,14,2,hsv2rgb(hueh, saturation, value));
         show20bitnumber(M,10,17,41,2,hsv2rgb(huem, saturation, value)); 
 
        //天氣圖
        if(tq_code == "0"){       SetEmojiXY(4, 3, 3, 3);   //晴
        }else if(tq_code == "1"){ SetEmojiXY(4, 6, 4, 3);  //多雲
        }else if(tq_code == "2"){ SetEmojiXY(4, 7, 3, 3);  //陰
        }else if(tq_code == "3"){ rain();    //雨
        }else if(tq_code == "4"){ thunderstorm();   //雷雨
        }else if(tq_code == "5"){ windy();       //風           
        }else{ SetEmojiXY(5, 3, 3, 3); }

        //溫度
        GlobalX = 2;
        GlobalY = 23;
        TempPattern();
        GlobalX = 0;
        GlobalY = 0;
        showbitnumber(temp_read.toInt(),5,8,12,23,display.color565(255,48,48));

        cdPattern(23,24,showColor);   // .C 符號
       

       // 濕度
        GlobalX = 35;
        GlobalY = 23;
        HumPattern();
        showbitnumber(hum_read.toInt(),5,8,45,23,display.color565(65,105,225));
        GlobalX = 0;
        GlobalY = 0;
        pcPattern(56,24,showColor);  // %符號
        
        last_M_Time = millis(); 
        }
     }



/*
void showWeatherDay(bool implement){
    uint16_t showColor = hsv2rgb(hue, saturation, value);
    if ( millis() - lastTime > 60000*5 || implement)
    {
         
        weatherNow("http://114.33.152.14:8080/weather/json.php");
        if(!implement){
            lastTime = millis();
        }else{
            loopTime = millis();
        }
        display.clearDisplay();
    }


    //天氣模式輪播
    if(millis() - loopTime > 5000 && !implement){
      if(++weatherMode>5) weatherMode=1;
      loopTime = millis();
      display.clearDisplay();
    }

    
    switch(weatherMode){
      case 1:

       // display.fillRect(0+GlobalX,0+GlobalY,8,8,display.color565(0,0,0));
        
        if(tq_code == "0"){       sunnyDay();   //晴
        }else if(tq_code == "1"){ cloudyDay();  //多雲
        }else if(tq_code == "2"){ overcast();  //陰
        }else if(tq_code == "3"){ rain();    //雨
        }else if(tq_code == "4"){ thunderstorm();   //雷雨
        }else if(tq_code == "5"){ windy();       //風           
        }else{  }
        break;
      case 2:

        GlobalY = 8;
        TempPattern();
        showbitnumber(temp_read.toInt(),3,5,10+GlobalX,2+GlobalY,showColor);
        cdPattern(16,0,showColor);
        break;
      case 3:

        GlobalY = 16;
        HumPattern();
        showbitnumber(hum_read.toInt(),3,5,10+GlobalX,2+GlobalY,showColor);
        pcPattern(16,0,showColor);
        GlobalY = 0;
        break;
      case 4:
        showTime(false);
        break;
      case 5:
        showMouthDay(false);
        break;
    }
    //display();
}

*/


//温度计图案
void TempPattern(){
  
  drawFastYLine(1+GlobalX,4+GlobalY,3,display.color565(255,255,255));
  drawFastYLine(2+GlobalX,0+GlobalY,5,display.color565(255,255,255));
  drawFastYLine(3+GlobalX,0+GlobalY,1,display.color565(255,255,255));
  drawFastYLine(4+GlobalX,0+GlobalY,5,display.color565(255,255,255));
  drawFastYLine(2+GlobalX,5+GlobalY,2,display.color565(255,48,48));
  drawFastYLine(3+GlobalX,3+GlobalY,4,display.color565(255,48,48));
  drawFastYLine(4+GlobalX,5+GlobalY,2,display.color565(255,48,48));
  drawFastXLine(2+GlobalX,7+GlobalY,3,display.color565(255,255,255));
  drawFastYLine(5+GlobalX,4+GlobalY,3,display.color565(255,255,255));
  
}

//湿度计图案
void HumPattern(){

  drawFastYLine(1+GlobalX,4+GlobalY,3,display.color565(255,255,255));
  drawFastYLine(2+GlobalX,0+GlobalY,5,display.color565(255,255,255));
  drawFastYLine(3+GlobalX,0+GlobalY,1,display.color565(255,255,255));
  drawFastYLine(4+GlobalX,0+GlobalY,5,display.color565(255,255,255));
  drawFastYLine(2+GlobalX,5+GlobalY,2,display.color565(65,105,255));
  drawFastYLine(3+GlobalX,3+GlobalY,4,display.color565(65,105,255));
  drawFastYLine(4+GlobalX,5+GlobalY,2,display.color565(65,105,255));
  drawFastXLine(2+GlobalX,7+GlobalY,3,display.color565(255,255,255));
  drawFastYLine(5+GlobalX,4+GlobalY,3,display.color565(255,255,255));
 
}

//℃
void cdPattern(int16_t x, int16_t y, uint16_t color){
  display.drawPixel(x+2,y+2,color);
  drawFastYLine(x+4,y+2,5,color);
  display.drawPixel(x+5,y+2,color);
  display.drawPixel(x+6,y+2,color);
  display.drawPixel(x+5,y+6,color);
  display.drawPixel(x+6,y+6,color);
}

//%
void pcPattern(int16_t x, int16_t y, uint16_t color){
  display.drawPixel(x+3,y+2,color);
  display.drawPixel(x+3,y+6,color);
  display.drawPixel(x+3,y+5,color);
  display.drawPixel(x+4,y+4,color);
  display.drawPixel(x+5,y+3,color);
  display.drawPixel(x+5,y+2,color);
  display.drawPixel(x+5,y+6,color);

}

// 白天晴
void sunnyDay(){
    display.fillRect(2+GlobalX,3+GlobalY,4,2,display.color565(255,255,0));
    display.fillRect(3+GlobalX,2+GlobalY,2,4,display.color565(255,255,0));
    display.drawPixel(2+GlobalX,0+GlobalY,display.color565(255,255,0));
    display.drawPixel(5+GlobalX,0+GlobalY,display.color565(255,255,0));
    display.drawPixel(0+GlobalX,2+GlobalY,display.color565(255,255,0));
    display.drawPixel(7+GlobalX,2+GlobalY,display.color565(255,255,0));
    display.drawPixel(0+GlobalX,5+GlobalY,display.color565(255,255,0));
    display.drawPixel(7+GlobalX,5+GlobalY,display.color565(255,255,0));
    display.drawPixel(2+GlobalX,7+GlobalY,display.color565(255,255,0));
    display.drawPixel(5+GlobalX,7+GlobalY,display.color565(255,255,0));
}

// 夜晚晴
void sunnyNight(){
    display.drawFastVLine(0+GlobalX,3+GlobalY,3,display.color565(190,190,190));
    display.drawFastVLine(1+GlobalX,3+GlobalY,3,display.color565(255,255,255));
    display.drawFastHLine(2+GlobalX,7+GlobalY,3,display.color565(190,190,190));
    display.drawPixel(5+GlobalX,0+GlobalY,display.color565(255,255,0));
    display.drawPixel(7+GlobalX,2+GlobalY,display.color565(255,255,0));
    display.drawPixel(4+GlobalX,4+GlobalY,display.color565(255,255,0));
    display.drawPixel(6+GlobalX,6+GlobalY,display.color565(255,255,0));
    display.drawPixel(2+GlobalX,1+GlobalY,display.color565(190,190,190));
    display.drawPixel(1+GlobalX,2+GlobalY,display.color565(190,190,190));
    display.drawPixel(1+GlobalX,6+GlobalY,display.color565(190,190,190));
    display.drawPixel(3+GlobalX,1+GlobalY,display.color565(255,255,255));
    display.drawPixel(2+GlobalX,2+GlobalY,display.color565(255,255,255));
    display.drawPixel(2+GlobalX,6+GlobalY,display.color565(255,255,255));
}

// 白多云
void cloudyDay(){
    display.drawPixel(2+GlobalX,0+GlobalY,display.color565(255,255,0));
    display.drawPixel(4+GlobalX,0+GlobalY,display.color565(255,255,0));
    display.drawPixel(0+GlobalX,1+GlobalY,display.color565(255,255,0));
    display.drawPixel(0+GlobalX,3+GlobalY,display.color565(255,255,0));
    display.drawFastHLine(2+GlobalX,2+GlobalY,3,display.color565(255,255,0));
    display.drawPixel(5+GlobalX,2+GlobalY,display.color565(255,255,255));
    display.fillRect(2+GlobalX,3+GlobalY,5,5,display.color565(255,255,255));
    display.drawPixel(2+GlobalX,3+GlobalY,display.color565(255,255,0));
    display.drawFastHLine(4+GlobalX,3+GlobalY,3,display.color565(180,180,180));
    display.drawFastHLine(4+GlobalX,4+GlobalY,2,display.color565(150,150,150));
    display.drawPixel(4+GlobalX,5+GlobalY,display.color565(150,150,150));
    display.drawFastVLine(1+GlobalX,5+GlobalY,2,display.color565(180,180,180));
    display.drawFastVLine(7+GlobalX,4+GlobalY,3,display.color565(180,180,180));
}


//功能：夜晚多云
void cloudyNight(){
    display.drawFastVLine(1+GlobalX,2+GlobalY,2,display.color565(255,255,255));
    display.drawFastVLine(2+GlobalX,1+GlobalY,4,display.color565(255,255,255));
    display.drawFastHLine(2+GlobalX,4+GlobalY,2,display.color565(255,255,255));
    display.drawFastHLine(3+GlobalX,5+GlobalY,4,display.color565(255,255,255));
    display.drawFastHLine(3+GlobalX,6+GlobalY,2,display.color565(128,128,128));
    display.drawPixel(0+GlobalX,0+GlobalY,display.color565(255,255,255));
    display.drawPixel(3+GlobalX,0+GlobalY,display.color565(255,255,255));
    display.drawPixel(6+GlobalX,1+GlobalY,display.color565(255,255,0));
    display.drawPixel(1+GlobalX,4+GlobalY,display.color565(128,128,128));
    display.drawPixel(7+GlobalX,4+GlobalY,display.color565(255,255,255));
    display.drawPixel(2+GlobalX,5+GlobalY,display.color565(128,128,128));
    display.drawPixel(1+GlobalX,7+GlobalY,display.color565(255,255,255));
    display.drawPixel(7+GlobalX,7+GlobalY,display.color565(255,255,255));
}


// 功能：阴
void overcast(){
    display.drawFastVLine(1+GlobalX,2+GlobalY,2,display.color565(100,100,100));
    display.drawFastVLine(5+GlobalX,1+GlobalY,2,display.color565(100,100,100));
    display.drawPixel(4+GlobalX,2+GlobalY,display.color565(100,100,100));
    display.drawPixel(7+GlobalX,2+GlobalY,display.color565(100,100,100));
    display.drawFastHLine(5+GlobalX,2+GlobalY,2,display.color565(200,200,200));
    display.drawFastHLine(0+GlobalX,3+GlobalY,8,display.color565(190,190,190));
    display.drawPixel(0+GlobalX,3+GlobalY,display.color565(100,100,100));
    display.drawPixel(3+GlobalX,3+GlobalY,display.color565(100,100,100));
    display.drawFastHLine(0+GlobalX,4+GlobalY,7,display.color565(180,180,180));
    display.drawFastHLine(0+GlobalX,5+GlobalY,7,display.color565(150,150,150));
    display.drawPixel(0+GlobalX,5+GlobalY,display.color565(100,100,100));
    display.drawPixel(7+GlobalX,5+GlobalY,display.color565(100,100,100));
    display.drawFastHLine(1+GlobalX,6+GlobalY,6,display.color565(110,110,110));
}



//功能：雨
void rain(){
    display.fillRect(1+GlobalX,1+GlobalY,2,4,display.color565(255,255,255));
    display.fillRect(2+GlobalX,3+GlobalY,5,2,display.color565(255,255,255));
    display.fillRect(4+GlobalX,1+GlobalY,4,3,display.color565(255,255,255));

    display.drawPixel(5+GlobalX,0+GlobalY,display.color565(150,150,150));
    display.drawPixel(4+GlobalX,1+GlobalY,display.color565(150,150,150));
    display.drawPixel(7+GlobalX,1+GlobalY,display.color565(150,150,150));
    display.drawPixel(0+GlobalX,2+GlobalY,display.color565(150,150,150));
    display.drawPixel(1+GlobalX,4+GlobalY,display.color565(150,150,150));
    display.drawPixel(0+GlobalX,3+GlobalY,display.color565(255,255,255));
    display.drawPixel(6+GlobalX,0+GlobalY,display.color565(255,255,255));
    display.drawPixel(1+GlobalX,5+GlobalY,display.color565(0,255,255));
    display.drawPixel(0+GlobalX,6+GlobalY,display.color565(0,255,255));
    display.drawPixel(4+GlobalX,5+GlobalY,display.color565(0,255,255));
    display.drawPixel(3+GlobalX,6+GlobalY,display.color565(0,255,255));
    display.drawPixel(2+GlobalX,7+GlobalY,display.color565(0,255,255));
    display.drawPixel(7+GlobalX,5+GlobalY,display.color565(0,255,255));
    display.drawPixel(6+GlobalX,6+GlobalY,display.color565(0,255,255));
    display.drawPixel(5+GlobalX,7+GlobalY,display.color565(0,255,255));
}

//功能：雷雨
void thunderstorm(){
    display.fillRect(2+GlobalX,3+GlobalY,2,2,display.color565(255,255,255));
    display.fillRect(4+GlobalX,2+GlobalY,2,3,display.color565(255,255,255));
    display.drawFastVLine(1+GlobalX,3+GlobalY,2,display.color565(100,100,100));
    display.drawFastVLine(6+GlobalX,2+GlobalY,4,display.color565(100,100,100));
    display.drawFastHLine(0+GlobalX,5+GlobalY,4,display.color565(100,100,100));
    display.drawFastHLine(2+GlobalX,2+GlobalY,2,display.color565(100,100,100));
    display.drawFastHLine(4+GlobalX,1+GlobalY,2,display.color565(100,100,100));
    display.drawFastHLine(5+GlobalX,5+GlobalY,3,display.color565(100,100,100));
    display.drawPixel(4+GlobalX,3+GlobalY,display.color565(255,255,0));
    display.drawPixel(3+GlobalX,4+GlobalY,display.color565(255,255,0));
    display.drawPixel(4+GlobalX,5+GlobalY,display.color565(255,255,0));
    display.drawPixel(3+GlobalX,6+GlobalY,display.color565(255,255,0));
    display.drawPixel(2+GlobalX,7+GlobalY,display.color565(255,255,0));
    display.drawPixel(1+GlobalX,6+GlobalY,display.color565(0,0,255));
    display.drawPixel(0+GlobalX,7+GlobalY,display.color565(0,0,255));
    display.drawPixel(6+GlobalX,6+GlobalY,display.color565(0,0,255));
    display.drawPixel(5+GlobalX,7+GlobalY,display.color565(0,0,255));
}


// 功能：风
void windy(){
    display.fillRect(2+GlobalX,2,3,2,display.color565(255,255,255));
    display.drawFastHLine(0+GlobalX,0+GlobalY,2,display.color565(255,255,255));
    display.drawFastHLine(1+GlobalX,1+GlobalY,2,display.color565(255,255,255));
    display.drawFastHLine(4+GlobalX,1+GlobalY,2,display.color565(255,255,255));
    display.drawFastHLine(5+GlobalX,0+GlobalY,2,display.color565(255,255,255));
    display.drawFastHLine(4+GlobalX,4+GlobalY,3,display.color565(255,255,255));
    display.drawPixel(6+GlobalX,5+GlobalY,display.color565(255,255,255));
    display.drawFastVLine(1+GlobalX,3+GlobalY,2,display.color565(255,255,255));
    display.drawFastVLine(0+GlobalX,4+GlobalY,2,display.color565(255,255,255));
    display.drawFastVLine(3+GlobalX,4+GlobalY,4,display.color565(130,130,130));
}
    
