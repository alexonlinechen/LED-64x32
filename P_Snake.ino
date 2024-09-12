
#define SNAKEWIDTH  1 //Snake width
#define FIELD_HEIGHT  32 
#define FIELD_WIDTH  32
#define  DIR_UP    1 
#define  DIR_DOWN  2 
#define  DIR_LEFT  3 
#define  DIR_RIGHT 4 

/* ------ Game related ------ */
int curLength; //蛇的長度
int xs[127];//Array containing all snake segments,
int ys[127];// max snake length is array length
int xs2[127];
int ys2[127];
int dir;  //方向
int S_score;
int S_speed = 300;

boolean snakeGameOver;
boolean snakeRunning = false;

int ax = 0;  // 要吃的彩蛋 x 座標
int ay = 0;  //   y 

unsigned long prevUpdateTime = 0;

 
//初始化
void snakeInit(){
  // Serial.println(F("初始化"));
  display.clearDisplay(); 
  //蛇的初始座標 方向 
  curLength = 3;
  xs[0]=3; xs[1]=2; xs[2]=1;
  ys[0]=FIELD_HEIGHT/2; ys[1]=FIELD_HEIGHT/2; ys[2]=FIELD_HEIGHT/2;
  xs2[0]=3; 
  ys2[0]=FIELD_HEIGHT/2+1;
  
  dir = DIR_RIGHT;
  S_score = 0;
  
  //彩蛋 隨機座標 
  ax = random(FIELD_WIDTH-2);
  ay = random(FIELD_HEIGHT-2);  
  snakeGameOver = false;
}


void runSnake(){

   if(!snakeRunning){
           snakeInit();
           if (BTN_VALUE == 5) {
                  snakeRunning = true;
                      }
                    }


  if(snakeRunning){   

    if(millis() - lastTime > S_speed){
     
   //檢查　蛇的自碰撞
    int i=curLength-1;
    while (i>=2){
      if (collide(xs[0], xs[i], ys[0], ys[i], SNAKEWIDTH, SNAKEWIDTH, SNAKEWIDTH, SNAKEWIDTH)){
        Serial.println(F("已碰撞-gameover"));
        die();
      }
      i = i-1;
    }
    
    if (snakeGameOver){
          snakeRunning = false;
          delay(7000);
          clearall();
         //break;
      }

    //檢查蛇頭與 彩蛋 的碰撞
    if (collide(xs[0], ax, ys[0], ay, 2, 2, 2, 2)){
      
      //增加分數和蛇的長度；
      S_score = S_score +10;
     // Serial.print(F("SNAKE分數:"));
     // Serial.println(S_score);
      
      //顯示讚的圖案
       SetEmojiXY(6, 1, 45, 2); 
       //FlashEmojiXY(6, 1, 35, 2);
       prevUpdateTime = millis(); 
     
            
      curLength = curLength +1;
      
      //新增蛇段以及新段的臨時位置
      xs[curLength-1] = 255;
      ys[curLength-1] = 255;
      
      //設定新的 彩蛋 座標
      ax = random(FIELD_WIDTH-2);
      ay = random(FIELD_HEIGHT-2);
      
     
      int i=curLength-1;
      for(int i=0; i<curLength; i++) {
        if (collide(ax, xs[i], ay, ys[i], SNAKEWIDTH, SNAKEWIDTH, SNAKEWIDTH, SNAKEWIDTH)){
           ax = random(FIELD_WIDTH-2);
           ay = random(FIELD_HEIGHT-2);
           i=0;
        }
       }
      }
    
    //移動一格 蛇的位置
    i = curLength-1;
    while (i>=1){
      xs[i] = xs[i-1];    
      ys[i] = ys[i-1];
      i = i-1;
    }
    
      
    //確定蛇頭的新位置
    if (dir == DIR_RIGHT){
      xs[0] = xs[0] + SNAKEWIDTH; 
      xs2[0] = xs[0]; 
      ys2[0] = ys[0] + SNAKEWIDTH;
    } 
    else if (dir == DIR_LEFT){
      xs[0] = xs[0] - SNAKEWIDTH;
      xs2[0] = xs[0];
      ys2[0] = ys[0] + SNAKEWIDTH;
    } 
    else if (dir == DIR_UP){
      ys[0] = ys[0] - SNAKEWIDTH; 
      ys2[0] = ys[0];
      xs2[0] = xs[0] + SNAKEWIDTH;      
    } 
    else {//DOWN
      ys[0] = ys[0] + SNAKEWIDTH; 
      ys2[0] = ys[0];
      xs2[0] = xs[0] + SNAKEWIDTH;
    }
    
  lastTime = millis(); 
 }   
    
    
    
    //檢查是否在比賽場地外
    if ((xs[0]<0) || (xs[0]>=FIELD_WIDTH) || (ys[0]<0) || (ys[0]>=FIELD_HEIGHT)){
      if (xs[0]<0) {xs[0] =FIELD_WIDTH -2;}
      else if (xs[0]>=FIELD_WIDTH) {xs[0] = 0;}      
      else if (ys[0]<0) {ys[0] =FIELD_HEIGHT -2;}
      else if (ys[0]>=FIELD_HEIGHT) {ys[0] = 0;}    
    }
    
    clearTablePixels();
    
   
    //Draw apple
     display.drawPixel(ax,ay,display.color565(255,0,0));
     display.drawPixel(ax+1,ay,display.color565(255,0,0));
     display.drawPixel(ax,ay+1,display.color565(255,0,0));
     display.drawPixel(ax+1,ay+1,display.color565(255,0,0));

    //Draw snake
    for (int i=1; i<curLength; i++){
    
      display.drawPixel(xs[i],ys[i],display.color565(255,255,255));
      display.drawPixel(xs[i]+1,ys[i],display.color565(255,255,255));     
      display.drawPixel(xs[i],ys[i]+1,display.color565(255,255,255));
      display.drawPixel(xs[i]+1,ys[i]+1,display.color565(255,255,255));

      display.drawPixel(xs[0],ys[0],display.color565(0,255,0)); //眼睛1
      display.drawPixel(xs2[0],ys2[0],display.color565(0,255,0)); //眼睛2     
    }
          

    //在等待繪製下一步動作時檢查按鈕並設定蛇的移動方向

    boolean dirChanged = false;    
      if (BTN_VALUE != 0 && !dirChanged){  //每個循環只能改變一次方向
        dirChanged = true;
        setDirection();
      }


    
  }  // end (snakeRunning)
  

     //顯示分數
     
     SetEmojiXY(5, 6, 33, 12);
     SetEmojiXY(9, 5, 33, 22);
     showbitnumber(S_score,5,8,42,22,hsv2rgb(hueh, saturation, value));
     showbitnumber(S_topscore,5,8,42,12,hsv2rgb(hueh, saturation, value));


     //顯示外框
     drawFastYLine(32,0,32,display.color565(0,0,255));
     drawFastYLine(63,0,32,display.color565(0,0,255));
     drawFastXLine(32,0,32,display.color565(0,0,255));
     drawFastXLine(32,31,32,display.color565(0,0,255));


     //消除讚 
     if( millis() - prevUpdateTime > 5000){     
         prevUpdateTime = millis(); 
         display.fillRect(45,2,53,10,display.color565(0,0,0));
         }
      
  
}   //end run snake




// 從目前按鈕狀態 設定方向 
void setDirection(){
  switch(BTN_VALUE){
    case 1:
    if(dir==DIR_DOWN){   //無法向 反方向移動
      break;
    }else{
      dir = DIR_UP;
      break;
    }

    case 2:
    if(dir==DIR_UP){
      break;
    }else{
      dir = DIR_DOWN;
      break;
    }
    
    case 3:
    if(dir==DIR_RIGHT){
      break;
    } else{
      dir = DIR_LEFT;
      break;
    }
    case 4:
    if(dir==DIR_LEFT){
      break;
    } else{
      dir = DIR_RIGHT;
      break;   
    }
 }
}


/* Ending, show score */
void die(){
  snakeGameOver = true;
  Serial.println(F("die -gameover"));

  SetEmojiXY(4, 10, 45, 2);
  
   if(S_score > S_topscore){   //寫入最高分
        S_topscore = S_score ;
        EEPROM.write(EEPROM_S_TOPscore, S_topscore);
        EEPROM.commit();
    }
}

// 碰撞偵測函數 
boolean collide(int x1, int x2, int y1, int y2, int w1, int w2, int h1, int h2){
  if ((x1+w1>x2) && (x1<x2+w2) && (y1+h1>y2) && (y1<y2+h2)){
    return true;
  } 
  else {
    return false;
  }
}


 void clearTablePixels(){ 
   for (int x=0; x<FIELD_WIDTH; x++){ 
      for (int y=0; y<FIELD_HEIGHT; y++){ 
      display.drawPixel(x,y,display.color565(0,0,0));
    } 
   }
 } 


     void Snake_speed(){
      if(S_score >= 0 && S_score < 100){S_speed = 300;}
      if(S_score >= 100 && S_score < 200){S_speed = 250;}
      if(S_score >= 200 && S_score < 300 ){S_speed = 200;}
      if(S_score >= 300 && S_score < 400){S_speed = 150;}
      if(S_score >= 400 && S_score < 500){S_speed = 100;}
      if(S_score >= 500 && S_score < 600){S_speed = 75;}
      if(S_score >= 600 && S_score < 700){S_speed = 50;}
      if(S_score >= 700 && S_score < 800){S_speed = 40;}
      if(S_score >= 800 && S_score < 900){S_speed = 30;}
      if(S_score >= 900 && S_score < 1000){S_speed = 20;}
      if(S_score >= 1000 && S_score < 1100){S_speed = 10;}
      if(S_score >= 1100 && S_score < 1200){S_speed = 10;}
      if(S_score >= 1200 && S_score < 1300){S_speed = 10;}
      if(S_score >= 1300 && S_score < 1400){S_speed = 10;}
    }
