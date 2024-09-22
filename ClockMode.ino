

/// ####  時鐘顯示模式   ####

//时钟模式一 HH:mm
void ClockMode1(){        

if ( millis() - last_H_Time > 60000){   //間隔20秒顯示一次 避免閃爍

//時間H   變化/動畫效果
   if( tempH != H){
   for(int i=-20;i<7;i++){
      display.fillRect(0,0,64,6,display.color565(0,0,0));
      showbigbitnumber(H,12,20,2,i,hsv2rgb(hueh, saturation, value)); 
      delay(3);
      tempH = H;    
         }
      }    
      
     showbigbitnumber(tempH,12,20,2,6,hsv2rgb(hueh, saturation, value));  
     last_H_Time = millis();
  } 

  
  if ( millis() - colonTime > 1000 )
  {
    colon = !colon;
    colonTime = millis();
  }
  showbigColon(31,11,colon,hsv2rgb(hue, saturation, value));
  showbigColon(31,20,colon,hsv2rgb(hue, saturation, value));
      


if ( millis() - last_M_Time > 25000){ 
  
//時間M   變化/動畫效果
 if( tempM != M){
   for(int i=-20;i<7;i++){
      display.fillRect(0,0,64,6,display.color565(0,0,0));
      showbigbitnumber(M,12,20,35,i,hsv2rgb(huem, saturation, value));  
      delay(3);
      tempM = M;
           }
          }
     showbigbitnumber(tempM,12,20,35,6,hsv2rgb(huem, saturation, value));
     last_M_Time = millis();
  } 
}




//时钟模式2  漸變HH:mm
void ClockMode2(){        
  
  if ( millis() - colonTime > 1000 )
  {
    colon = !colon;
    colonTime = millis();
  }
  showbigColon(31,11,colon,hsv2rgb(hue, saturation, value));
  showbigColon(31,20,colon,hsv2rgb(hue, saturation, value));

    if(randomColor)random_color();
    ShowColorNumber(H,12,20,2,6);   //  顯示漸變H
    ShowColorNumber(M,12,20,35,6);  //  顯示漸變M

 
}



//时钟模式3: HH:mm:ss
void ClockMode3(){

 if ( millis() - last_H_Time > 60000){ 
  //時間H   變化/動畫效果
   if( tempH != H){
   for(int i=-20;i<3;i++){
      display.fillRect(0,0,64,2,display.color565(0,0,0));
      showbigbitnumber(H,12,20,3,i,hsv2rgb(hueh, saturation, value)); 
      delay(10);
    tempH = H;
  }
 }   
showbigbitnumber(tempH,12,20,3,2,hsv2rgb(hueh, saturation, value));
last_H_Time = millis();
} 



  if ( millis() - colonTime > 1000 )
  {
    colon = !colon;
    colonTime = millis();
  }
  showbigColon(32,8,colon,hsv2rgb(hue, saturation, value));
  showbigColon(32,18,colon,hsv2rgb(hue, saturation, value));


if ( millis() - last_M_Time > 25000){ 
//時間M   變化/動畫效果
 if( tempM != M){
   for(int i=-20;i<3;i++){
      display.fillRect(0,0,64,2,display.color565(0,0,0));
      showbigbitnumber(M,12,20,36,i,hsv2rgb(huem, saturation, value));  
      delay(10);
    tempM = M;
  }
 }
 showbigbitnumber(tempM,12,20,36,2,hsv2rgb(huem, saturation, value)); 
  last_M_Time = millis();
  }
  
  showbitnumber(S,5,8,36,24,hsv2rgb(hues, saturation, value));
}



//时钟模式4:  圖片emoji:時HH:分mm
void ClockMode4(){
   
  SetEmojiXY(pic_x, pic_y, 0 ,10);

 if ( millis() - last_H_Time > 6000){ 
 
 //時間H   變化/動畫效果
   if( tempH != H){
   for(int i=-20;i<7;i++){
      display.fillRect(0,0,64,6,display.color565(0,0,0));
      showbigbitnumber(H,12,20,9,i,hsv2rgb(hueh, saturation, value)); 
      delay(16);
    tempH = H;
  }
 }     
  showbigbitnumber(tempH,12,20,9,6,hsv2rgb(hueh, saturation, value));
  last_H_Time = millis();
} 

  
  if ( millis() - colonTime > 1000 )
  {
    colon = !colon;
    colonTime = millis();
  }
  showbigColon(36,11,colon,hsv2rgb(hue, saturation, value));
  showbigColon(36,20,colon,hsv2rgb(hue, saturation, value));

if ( millis() - last_M_Time > 2500){ 
  //時間M   變化/動畫效果
 if( tempM != M){
   for(int i=-20;i<7;i++){
      display.fillRect(0,0,64,6,display.color565(0,0,0));
      showbigbitnumber(M,12,20,38,i,hsv2rgb(huem, saturation, value));  
      delay(16);
    tempM = M;
  }
 }
  showbigbitnumber(tempM,12,20,38,6,hsv2rgb(huem, saturation, value)); 
   last_M_Time = millis();
  }
}


//时钟模式5: GIF時鐘 + HH:mm
void ClockMode5(){
  
    time(&now);
    localtime_r(&now, &tm);
    H = tm.tm_hour;
    M = tm.tm_min;

//間隔30秒顯示時間
if ( millis() - lastTime > 30000){  

 //清空時鐘顯示區域
    for (int x = 40; x<64; x++) {
       for (int y = 0; y<32; y++) {
              display.drawPixel(x,y,display.color565(0,0,0));
                 }
                 lastTime = millis();
                }  
    
    show15bitnumber(H,9,14,40,1,hsv2rgb(hueh, saturation, value));   
     display.drawPixel(48,16,hsv2rgb(hue, saturation, value));
     display.drawPixel(53,16,hsv2rgb(hue, saturation, value));
    show15bitnumber(M,9,14,40,18,hsv2rgb(huem, saturation, value)); 
       }  



   onlyGif();  //間隔時間 播放gif

     } //end ClockMode5


 //隨機模式
void ClockMode6(){


  switch(randomMode){
      case 1:
            ClockMode1();
      break; 
      case 2:
            ClockMode2();
      break; 
      case 3:     
           ClockMode3();    
      break;
      case 4:
           ClockMode4();
       break;
      case 5:
           ClockMode5();           
      break;                      
      default:
           ClockMode1();
      } 
      
if ( millis() - randomTime > random_min*60000){    //間隔 - 分鐘顯示時間

   randomMode = random(1, 6);
   Serial.print(F("切換隨機模式："));
   Serial.println(randomMode);
   display.clearDisplay();
   randomTime = millis();
 } 
  
}





/// ####  時鐘顯示 功能   ####

//显示时间
void showTime(bool implement)
{
   if ( millis() - ColorTime > 400 | implement)  //控制漸變顏色頻率/秒速
  {
    time(&now);
    localtime_r(&now, &tm);
    H = tm.tm_hour;
    M = tm.tm_min;
    S = tm.tm_sec;
    D = tm.tm_wday;

       colorLoop = colorLoop+1;
      if(colorLoop>60) colorLoop = 1;
  ColorTime = millis();
  }  
  
  //時間模式
  switch(clockMode){
      case 1:
            ClockMode1();
      break; 
      case 2:
            ClockMode2();
      break; 
      case 3:     
           ClockMode3();    
      break;
      case 4:
           ClockMode4();
       break;
      case 5:
           ClockMode5();           
      break;  
      case 6:
           ClockMode6();           
      break;  
                    
      default:
           ClockMode1();
      }    
    } //end showTime




//显示日期
void showMouthDay() {
 if ( millis() - lastTime > 2000)
  {
    time(&now);
    localtime_r(&now, &tm); 
    currentMonth = tm.tm_mon + 1 ;  //取得月份
    monthDay = tm.tm_mday;          //取得日期
    D = tm.tm_wday;                 //取得星期

    lastTime = millis();
    display.clearDisplay();   
   }

  switch(dateMode){
    case 1:
      showbigbitnumber(currentMonth,12,20,2,6,hsv2rgb(hueh, saturation, value));
      drawFastYLine(31,10,10,display.color565(255,255,255));
      showbigbitnumber(monthDay,12,20,35,6,hsv2rgb(huem, saturation, value));
     
      //星期
      showWeek(10,29,huew,5);
      break;
    case 2:
      SetEmojiXY(pic_x, pic_y, 0, 10);
      showbigbitnumber(currentMonth,12,20,9,6,hsv2rgb(hueh, saturation, value));
      drawFastYLine(36,10,10,display.color565(255,255,255));
      showbigbitnumber(monthDay,12,20,38,6,hsv2rgb(huem, saturation, value)); 

      //星期
      showWeek(10,29,huew,5);
      break;
  }


}



//显示 星期  (顯示格子位置代表星期)
void showWeek(int x, int y, int colorhue, int len) {
  for(int i=0;i<7;i++){
    drawFastXLine(x+i*(len+1),y+1,len,display.color565(255,255,255));
   // drawFastXLine(x+i*(len+1),y,len,hsv2rgb(colorhue, saturation, value));
  }
  int d = D;

  if(D == 0){    //星期日 紅色
      d = 7;
      drawFastXLine(x+(d-1)*(len+1),y,len,hsv2rgb(1, saturation, value));  
     }
     
   if(D == 6){    //星期六 綠色
     drawFastXLine(x+(d-1)*(len+1),y,len,hsv2rgb(120, saturation, value));
      }
      
   drawFastXLine(x+(d-1)*(len+1),y,len,hsv2rgb(colorhue, saturation, value));
  
}


//模式2  時間+日期輪播
void showDateLoop(bool implement){ 

    if(millis() - loopTime > 10000 && !implement){
      if(++dateloopMode>2) dateloopMode=1;
      loopTime = millis();
      display.clearDisplay();
    }
    
    switch(dateloopMode){
      case 1:
      showTime(false);
      break;
      case 2:
      showMouthDay();
      break;
                       }
    
}



//显示时钟的冒号方法
void showColon(int x,int y,bool l,uint16_t colorxy){
  String pstr = "101";
  for(int j = y; j < y+3; j = j + (1)){
    if (String(pstr.charAt(j-y)).toInt() != 0) {
      if(l){
        display.drawPixel(x,j,colorxy);
     }else{
       display.drawPixel(x,j,display.color565(0, 0, 0));
     }
    } else {
      display.drawPixel(x,j,display.color565(0, 0, 0));
    }
  }
}
    
