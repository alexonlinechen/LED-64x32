
//佔記憶體  4%



//http://webfish-channel.blogspot.com/2017/03/arduino3.html

// 設定方塊所有狀態.
const byte N1[2][16]PROGMEM  = { { 0,1,6,7,12,13,14,15,18,19,20,21,26,27,32,33 },
                               { 14,15,16,17,20,21,22,23,24,25,26,27,30,31,32,33 } }; // ID:1.

const byte N2[2][16]PROGMEM = { { 2,3,8,9,12,13,14,15,18,19,20,21,24,25,30,31 },
                              { 12,13,14,15,18,19,20,21,26,27,28,29,32,33,34,35 } };  // ID:2.

const byte L1[4][16]PROGMEM = { { 12,13,18,19,24,25,26,27,28,29,30,31,32,33,34,35 },
                              { 0,1,2,3,6,7,8,9,12,13,18,19,24,25,30,31 },
                              { 12,13,14,15,16,17,18,19,20,21,22,23,28,29,34,35 },
                              { 2,3,8,9,14,15,20,21,24,25,26,27,30,31,32,33 } }; // ID:3.

const byte L2[4][16]PROGMEM = { { 16,17,22,23,24,25,26,27,28,29,30,31,32,33,34,35 },
                              { 0,1,6,7,12,13,18,19,24,25,26,27,30,31,32,33},
                              { 12,13,14,15,16,17,18,19,20,21,22,23,24,25,30,31},
                              { 0,1,2,3,6,7,8,9,14,15,20,21,26,27,32,33 } }; // ID:4.

const byte T[4][16]PROGMEM  = { { 14,15,20,21,24,25,26,27,28,29,30,31,32,33,34,35 },
                              { 0,1,6,7,12,13,14,15,18,19,20,21,24,25,30,31 },
                              { 12,13,14,15,16,17,18,19,20,21,22,23,26,27,32,33 },
                              { 2,3,8,9,12,13,14,15,18,19,20,21,26,27,32,33 } }; // ID:5.

const byte O[1][16]PROGMEM  = { { 12,13,14,15,18,19,20,21,24,25,26,27,30,31,32,33 } };     // ID:6.

const byte I[2][12]PROGMEM  = { { 24,25,26,27,28,29,30,31,32,33,34,35 },
                              { 2,3,8,9,14,15,20,21,26,27,32,33 } };     // ID:7.

int T_score = 0 ;
//int T_topscore ;
int T_speed = 600 ;


// 方塊陣列.
byte brick[6][6];
byte nextbrick[6][6];

// 容器.
//  0:無.
// >0:方塊編號.
//255:閃爍方塊(黑).
//254:閃爍方塊(亮).
byte container[34][16] ;  //原32多+2為下降2格預留空間

// 方塊在容器的位置.
int containerX =  14;  //  為6的時候不能旋轉方塊).
int containerY = -4;  // -4表示在上邊界外慢慢往下掉).

// 方塊編號(1~7).
byte brickId = 1;
byte brickId2 ;

// 方塊狀態(0~3).
int  brickState = 0;

// 清除方塊數量.
byte clearBrickFlag = 0;
// 清除方塊閃爍次數.
byte flashNum = 0;



//---------------------------------------------------------------------------
// 初始.
//---------------------------------------------------------------------------
void Tetris_setup()
{
  
 // 產生隨機的seed.
 randomSeed(analogRead(0));
 // 重新開始遊戲.
 resetGame();
 BIG_resetGame();
}


//---------------------------------------------------------------------------
// 主迴圈.
//---------------------------------------------------------------------------
void Tetris_loop()
{

   
 int posX = 0;
 int posY = 0;

 // 0:準備開始中.
 if (gameStatus == 0) {
       
       if (BTN_VALUE == 5) {   // 按鍵-開始遊戲. 
             clearBrickFlag = 0;  // 清除方塊數量.
             gameStatus = 1;   // 設定遊戲中
         }
     }
 
// 1:遊戲中.
 else if (gameStatus == 1) {
      
      //設定最底邊界不為0 以免影響方塊至底
          for (int i = 0; i<16; i++) {  
              container[32][i]= 9;
             }

    
       // 開始方塊 -不需要清除連線的狀態
      if (clearBrickFlag == 0) {
        //方塊往下掉.
            
            
            if (BTN_VALUE == 2) {       
                 if (T_PlayMode == 0){  containerY = containerY+2; }
                                   }

            if (T_PlayMode == 1){
                       if(millis() - lastTime > T_speed){
                                    containerY = containerY+2; 
                                    lastTime = millis();  } 
                                   }
                                   
   
   // 判斷是否碰到其他方塊.
      if (!ifCopyToContainer()) {   
            containerY = containerY-2;   // 觸碰 Y往上移一格.
    
            // 遊戲結束.
            if (containerY < 0) {
                      gameover();
                      resetGame();   // 重新開始遊戲.
                      return;
                     }
             brickNew();   // 產生新塊   
           }
   
       // 已到底 產生新塊 
       else if (containerY >= 28) {    //方塊從初始到碰到底部的距離
                
                 brickNew();
        }
       // 判斷與設定要清除的方塊.  >0 代表開始消除
         clearBrickFlag = ifClearBrick();

   }  //end  clearBrickFlag>0

//-------------------------------------------------------------------- 


//--------------------------------------------------------------------  

                
      // 處理閃爍和清除方塊.
       if (clearBrickFlag > 0){
  
            // 閃爍方塊次數.
             flashNum++;
            // 閃爍方塊.
               brickFlash();
           // 清除方塊繼續遊戲.
            if (flashNum >= 3) {
                    clearBrick();  // 清除方塊.
                    clearBrickFlag = 0;   // 初始變數. 繼續執行掉落方塊
                    flashNum = 0;
                 }
            }
          }   //end 遊戲中
 
  
  // 清除畫面.
  display.clearDisplay(0);
  
  //--------------------------------------------------------------------
  // 搖桿往上操作變換方塊.
  // 方塊X座標 != -2 左邊空白  != 右邊移動範圍     
  if (BTN_VALUE == 1 && containerX != 6 && containerX != 20 && clearBrickFlag == 0) {

   // N1、N2、I(2種狀態).
   if ( brickId == 1 || brickId == 2 || brickId == 7) {
    brickState++;
    if (brickState > 1) { brickState = 0; }

    // 處理判斷是否可以旋轉方塊.
    processTransformToBrickArray();
    if (!ifCopyToContainer()) {
     brickState--;
     if (brickState < 0) { brickState = 1; }
    }
   }
   // L1、L2、T(4種狀態)
   else if (brickId == 3 || brickId == 4 || brickId == 5) {
    brickState++;
    if (brickState > 3) { brickState = 0; }

    // 處理判斷是否可以旋轉方塊.
    processTransformToBrickArray();
    if (!ifCopyToContainer()) {
     brickState--;
     if (brickState < 0) { brickState = 3; }
    }
   }
   // O(1種狀態)
   else if (brickId == 6 ) {
    brickState = 0;
   }
  }
  


  // 搖桿往下-快速下降方塊.
   if (BTN_VALUE == 2 && T_PlayMode == 1){T_speed = 70;}



  //--------------------------------------------------------------------
  // 處理轉換方塊到方塊陣列.
  processTransformToBrickArray();
  processNextoBrickArray();
  
  //--------------------------------------------------------------------
  // 操作左右移動方塊.
  
  if (clearBrickFlag == 0) {

    // 右移.
    if (BTN_VALUE == 4) {
       
     containerX = containerX+2;

           Serial.print(F("containerX:"));
           Serial.println(containerX); 
     
     // 判斷可否右移.
     if (ifCopyToContainer()) {
        //判斷右邊邊界是否為空白 空白多移1格
      if ( brick[2][4] == 0 && brick[5][5] == 0 )  //定位2區域來判斷是否空白0
      {
          //Serial.println(F("MAX:20格"));     
          if (containerX>20) { containerX = 20; } 
      }
      else {
       if (containerX>18) { containerX = 18; }
          // Serial.println(F("MAX:18格"));
      }
     }
     else {
      containerX =containerX-2;
     }
    }
    
    // 左移.
    if (BTN_VALUE == 3) 
    {

                 Serial.print(F("containerX:"));
           Serial.println(containerX); 
           
     containerX = containerX-2;
     // 判斷可否左移.
     if (ifCopyToContainer()) {
      if (containerX < 8) {    //if X座標低於左邊邊界0
          
           // 處理直立長條(特例).
        if (  brick[2][0] == 0 && brick[5][1] == 0 )    
       {
        Serial.println(F("MAX:長條-2格"));
        containerX = 6;
        drawFastYLine(7,0,32,display.color565(0,0,255));
       }
       else {
        containerX = 8;
       }
      }
     }
     else {
      containerX = containerX+2;
     }     
    }
   
  }
  
   //開始顯示畫面

   //顯示外框線
   showLine();
   //顯示分數
  showbitnumber(T_score,5,8,39,22,hsv2rgb(hueh, saturation, value));
  showbitnumber(T_topscore,5,8,39,12,hsv2rgb(hueh, saturation, value));

  
  //--------------------------------------------------------------------  
  // 畫容器.
  for (int iy = 0; iy<32; iy++) {
   for (int ix = 0; ix<16; ix++) {
    if (container[iy][ix] == 1 && container[iy][ix] != 255) {    
     display.drawPixel(ix+8,iy,display.color565(0,255,0));
    }
   else if (container[iy][ix] == 2 && container[iy][ix] != 255) {    
     display.drawPixel(ix+8,iy,display.color565(0,255,0));
    }
   else if (container[iy][ix] == 3  && container[iy][ix] != 255) {    
     display.drawPixel(ix+8,iy,display.color565(0,0,255));
    }
   else if (container[iy][ix] == 4 && container[iy][ix] != 255) {    
     display.drawPixel(ix+8,iy,display.color565(0,0,255));
    }
   else if (container[iy][ix] == 5 && container[iy][ix] != 255) {    
     display.drawPixel(ix+8,iy,display.color565(255,0,0));
    }            
   else if (container[iy][ix] == 6 && container[iy][ix] != 255) {    
     display.drawPixel(ix+8,iy,display.color565(255,255,0));
    }   
   else if (container[iy][ix] == 7 && container[iy][ix] != 255) {    
     display.drawPixel(ix+8,iy,display.color565(255,0,255));
    }
    
    else {
     display.drawPixel(ix+8,iy,display.color565(0,0,0));
    }    
   }
  }






  // 畫方塊.  
  for (int iy = 0; iy < 6; iy++) {
   for (int ix = 0; ix < 6; ix++) {
    posX = containerX + ix;
    posY = containerY + iy;
    if( posX >= 0 && posY >= 0){
     if (brick[iy][ix] > 0) {
        if (brickId == 1 || brickId == 2) {  //id 12綠色
         display.drawPixel(posX,posY,display.color565(0,255,0));
        }
         else if (brickId == 3 || brickId == 4) {
              display.drawPixel(posX,posY,display.color565(0,0,255));
                }
         else if (brickId == 5) {
              display.drawPixel(posX,posY,display.color565(255,0,0));
                }
         else if (brickId == 6) {
              display.drawPixel(posX,posY,display.color565(255,255,0));
                }                
         else if (brickId == 7) {
              display.drawPixel(posX,posY,display.color565(255,0,255));
                }                 
      }
     else {
      // 處理超出邊界不要畫.
      if (posX >= 24) {
       // 顯示空的0為黑.
       if(container[posY][posX] == 0){
      //  display.drawPixel(posX,posY,display.color565(0,0,0));
      //  drawFastYLine(24,0,32,display.color565(0,0,255)); //補上邊界線
       }       
      }      
     }
    }
   }
  }

  
  // 畫下一個 方塊2
  next_brick();

  
  BTN_VALUE = 0 ;
  
} //end loop





//--------------------------------------------------------------------
// 處理轉換方塊到方塊陣列.  方塊1 和下一個方塊2
//--------------------------------------------------------------------
void processTransformToBrickArray()
{
 // N1.
 if (brickId == 1) {
  transformToBrickArray((byte *)N1, 16, brickState, brickId);
 }
 // N2.
 else if (brickId == 2) {
  transformToBrickArray((byte *)N2, 16, brickState, brickId);
 }
 // L1.
 else if (brickId == 3) {
  transformToBrickArray((byte *)L1, 16, brickState, brickId);
 }
 // L2.
 else if (brickId == 4) {
  transformToBrickArray((byte *)L2, 16, brickState, brickId);
 }
 // T.
 else if (brickId == 5) {
  transformToBrickArray((byte *)T, 16, brickState, brickId);
 }
 // O.
 else if (brickId == 6) {
     transformToBrickArray((byte *)O, 16, brickState, brickId);
 }
 // I.
 else if (brickId == 7) {
  transformToBrickArray((byte *)I, 12, brickState, brickId);
 }
}


void processNextoBrickArray()
{
 // N1.
 if (brickId2 == 1 ) {
  transNextBrick((byte *)N1, 16, 0, brickId2);
 }
 // N2.
 else if (brickId2 == 2) {
  transNextBrick((byte *)N2, 16, 0, brickId2);
 }
 // L1.
 else if (brickId2 == 3) {
  transNextBrick((byte *)L1, 16, 0, brickId2);
 }
 // L2.
 else if (brickId2 == 4) {
  transNextBrick((byte *)L2, 16, 0, brickId2);
 }
 // T.
 else if (brickId2 == 5) {
  transNextBrick((byte *)T, 16, 0, brickId2);
 }
 // O.
 else if (brickId2 == 6) {

     transNextBrick((byte *)O, 16, 0, brickId2);
 }
 // I.
 else if (brickId2 == 7) {
  transNextBrick((byte *)I, 12, 0, brickId2);
 }
}

//---------------------------------------------------------------------------
// 轉換方塊到方塊陣列.
// pBrick : 方塊陣列.
// bLengthY: 方塊大小.
// bState : 方塊狀態.
//  bBrickId: 方塊編號.
//---------------------------------------------------------------------------
void transformToBrickArray(byte *pBrick, byte bLengthY, byte bState, byte bBrickId)
{
 byte bx, by;

 // 清除方塊陣列.
 for (int iy = 0; iy < 6; iy++) {
  for (int ix = 0; ix < 6; ix++) {
   brick[iy][ix] = 0;
  }  
 }

 // 轉換方塊到方塊陣列.
 for (int i = 0; i < bLengthY; i++) {
  bx = (pgm_read_byte(pBrick + bState * bLengthY + i)) % 6;
  by = (pgm_read_byte(pBrick + bState * bLengthY + i)) / 6;
  brick[by][bx] = bBrickId;
 }
}

//---------------------------------------------------------------------------
void transNextBrick(byte *pBrick, byte bLengthY, byte bState, byte bBrickId)
{
 byte nbx, nby;

 // 清除方塊2陣列.
 for (int iy = 0; iy < 6; iy++) {
  for (int ix = 0; ix < 6; ix++) {
   nextbrick[iy][ix] = 0;
  }  
 }

 // 轉換方塊2到方塊陣列.
 for (int i = 0; i < bLengthY; i++) {
  nbx = (pgm_read_byte(pBrick + bState * bLengthY + i)) % 6;
  nby = (pgm_read_byte(pBrick + bState * bLengthY + i)) / 6;
  nextbrick[nby][nbx] = bBrickId;
 }
}

//---------------------------------------------------------------------------
// 判斷是否可以複製到容器內.
// true:可以.  false:不可以.
//---------------------------------------------------------------------------
bool ifCopyToContainer() {  
       
 int posX = 0;
 int posY = 0;
 for (int iy = 0; iy < 6; iy++) {
  for (int ix = 0; ix < 6; ix++) {
   if (brick[iy][ix] != 0) {
    posX = containerX-8 + ix;
    posY = containerY + iy;
    if (posX >= 0 && posY >= 0 ) {  //0= X的左邊界 8代表長條直立最靠左邊的狀態
        if (container[posY][posX] != 0) {
            Serial.println(F("不能複製到容器"));
            return false;
      
     }
    }
   }
  }
 }
 return true; 
}



//---------------------------------------------------------------------------
// 方塊顯示到容器內.
//---------------------------------------------------------------------------
void copyToContainer() {

 
 int posX = 0;
 int posY = 0;
 for (int iy = 0; iy < 6; iy++) {
  for (int ix = 0; ix < 6; ix++) {
   if (brick[iy][ix] != 0) {
    posX = containerX-8 + ix;   //-8代表左邊偏移
    posY = containerY + iy;
    if (posX >= 0 && posY >= 0) {
     container[posY][posX] = brick[iy][ix];
     
    }
    
   }
  }
 }
}

//---------------------------------------------------------------------------
// 判斷與設定要清除的方塊. lineNum >0 代表需要消除
//---------------------------------------------------------------------------
byte ifClearBrick() {

 int pointNum = 0; 
 int lineNum = 0;
 for (int iy = 0; iy < 32; iy++) {
  for (int ix = 0; ix < 16; ix++) {
   if (container[iy][ix] > 0) {
          pointNum++;
          }

       //pointNum 累積滿X格16 開始消除
   if (pointNum == 16) {    
    for (int i = 0; i < 16; i++) {
     lineNum++;
     container[iy][i] = 255;   //將要消除的方塊定位為255(亮)
    }
   }
  }
  pointNum = 0;
 }                   
 return lineNum;
}

//---------------------------------------------------------------------------
// 清除的方塊.
//---------------------------------------------------------------------------
void clearBrick() {
  //  Serial.println(F("開始消除 - 需要被清除的方塊"));
   for (int y = 32-1 ; y>0; y--)
   {
     bool LineFull = true ;
     for(int x=0; x<16; x++)
     {
        if (container[y][x] == 0)
        {
          LineFull = false ; 
          break;
        }
     }
   

 //  確定一行有滿的方塊 開始消除  消除一行+10分
 if(LineFull){
       byte temp = 0;
   for (int iy = 32; iy > 1; iy--) {
       for (int ix = 0; ix < 16; ix++) { 
           if (container[iy][ix] == 255 || container[iy][ix] == 254) {
                     temp = container[iy - 1][ix];
                     container[iy - 1][ix] = container[iy][ix];
                     container[iy][ix] = temp;       
                  }
               } 
             } 
    for (int ix = 0; ix < 16; ix++) {
           container[0][ix] = 0;  //因為消除方塊 需補上空白不然 會gameover
           container[1][ix] = 0;  
         }
         T_score +=10;   
         Serial.print(F("分數:"));
         Serial.println(T_score);
         }
        }
      }


//---------------------------------------------------------------------------
// 閃爍方塊.
//---------------------------------------------------------------------------
void brickFlash() {
  //Serial.println(F("閃爍方塊"));
 for (int iy = 0; iy < 32; iy++) {
   for (int ix = 0; ix < 16; ix++) {
      if (container[iy][ix] == 255) {
          container[iy][ix] = 254;
          display.drawPixel(ix+8,iy,display.color565(0,100,125));
          }
       else if (container[iy][ix] == 254) {
           container[iy][ix] = 255;
           }
  }
 }
 delay(80);
}

//---------------------------------------------------------------------------
// 產生新塊.
//---------------------------------------------------------------------------
void brickNew(){
 gamespeed(); //速度控制

 // 複製方塊到容器內.
 copyToContainer();
 // 初始方塊.
 containerX = 14;
 containerY = -4;


 // 亂數產生方塊.
 //brickId = (byte)random(1, 8);
 brickId = brickId2;  //將方塊2設為要下降的方塊
 brickId2 = (byte)random(1, 8);
  Serial.print(F("new1方塊ID"));
  Serial.println(brickId);
  Serial.print(F("new2方塊ID"));
  Serial.println(brickId2);
 // 初始方塊狀態.
 brickState = 0;

}

//---------------------------------------------------------------------------
// 重新開始遊戲.
//---------------------------------------------------------------------------
void resetGame()
{
 
  Serial.println(F("Game Over"));
 // 遊戲狀態.
 gameStatus = 0;
 
 T_speed = 600;
 T_score = 0;

 // 亂數產生方塊.
 brickId = (byte)random(1, 8);
 brickId2 = (byte)random(1, 8);
 Serial.print(F("over1方塊ID"));
 Serial.println(brickId);
  Serial.print(F("over2方塊ID"));
 Serial.println(brickId2);
 
 // 方塊狀態(0~3).
 brickState = 0;

 // 方塊在容器的位置.
 containerX = 14;
 if (brickId == 1 || brickId == 2) {
  containerY = 0;
 }
 else if (brickId == 7) {
  containerY = -4;
 }
 else {
  containerY = -2;
 }
 
 // 清除方塊數量(暫停).
 clearBrickFlag = 1;

 // 清除容器.
 for (int iy = 0; iy < 32; iy++) {
  for (int ix = 0; ix < 16; ix++) {
   container[iy][ix] = 0;
  }
 } 
}

/*
void printall()
{
       for (int i = 0; i < 16; i++) { 
           Serial.print(container[26][i]);}
           Serial.println("");
       for (int i = 0; i < 16; i++) {     
           Serial.print(container[27][i]);}
           Serial.println("");
       for (int i = 0; i < 16; i++) {
           Serial.print(container[28][i]);}
           Serial.println("");  
       for (int i = 0; i < 16; i++) {           
           Serial.print(container[29][i]);}
           Serial.println(""); 
       for (int i = 0; i < 16; i++) {           
           Serial.print(container[30][i]);}
           Serial.println(""); 
       for (int i = 0; i < 16; i++) {           
           Serial.print(container[31][i]);}
            Serial.println("");
           Serial.println("----------------------------------------------------------");  
       for (int i = 0; i < 16; i++) {          
          Serial.print(container[32][i]);}
          Serial.println(""); 
       for (int i = 0; i < 16; i++) {          
          Serial.print(container[33][i]);}
          Serial.println("");     
    }  */

    void gamespeed(){
      if(T_score >= 0 && T_score < 100){T_speed = 600;}
      if(T_score >= 100 && T_score < 200){T_speed = 550;}
      if(T_score >= 200 && T_score < 300 ){T_speed = 500;}
      if(T_score >= 300 && T_score < 400){T_speed = 450;}
      if(T_score >= 400 && T_score < 500){T_speed = 400;}
      if(T_score >= 500 && T_score < 600){T_speed = 350;}
      if(T_score >= 600 && T_score < 700){T_speed = 300;}
      if(T_score >= 700 && T_score < 800){T_speed = 250;}
      if(T_score >= 800 && T_score < 900){T_speed = 200;}
      if(T_score >= 900 && T_score < 1000){T_speed = 150;}
      if(T_score >= 1000 && T_score < 1100){T_speed = 100;}
      if(T_score >= 1100 && T_score < 1200){T_speed = 80;}
      if(T_score >= 1200 && T_score < 1300){T_speed = 60;}
      if(T_score >= 1300 && T_score < 1400){T_speed = 40;}
    }


void gameover(){

    if(T_score > T_topscore && T_PlayMode == 1){   //寫入最高分
      T_topscore = T_score ;
        EEPROM.write(EEPROM_T_TOPscore, T_topscore);
        EEPROM.commit();
    }
  
    for (int iy = 32; iy>=0; iy--) {
      delay(50);
       for (int ix = 0; ix<16; ix++) {
          if (container[iy][ix] != 0 && container[iy][ix] != 255) {    
              display.drawPixel(ix+8,iy,display.color565(0,100,125));
               }
            }
        }
       delay(1500);
        for (int iy = 32; iy>=0; iy--) {
          delay(50);
            for (int ix = 0; ix<16; ix++) {
              display.drawPixel(ix+8,iy,display.color565(0,0,0));
                 }  
                }
       }

  // 畫方塊2.
  void next_brick(){
   int posX = 30;
   int posY =2 ;
  for (int iy = 0; iy < 6; iy++) {
    for (int ix = 0; ix < 6; ix++) {
         if (nextbrick[iy][ix] > 0) {
        if (brickId2 == 1 || brickId2 == 2) {  //id 12綠色
         display.drawPixel(posX+ix,posY+iy,display.color565(0,255,0));
        }
         else if (brickId2 == 3 || brickId2 == 4) {
              display.drawPixel(posX+ix,posY+iy,display.color565(0,0,255));
                }
         else if (brickId2 == 5) {
              display.drawPixel(posX+ix,posY+iy,display.color565(255,0,0));
                }
         else if (brickId2 == 6) {
              display.drawPixel(posX+ix,posY+iy,display.color565(255,255,0));
                }                
         else if (brickId2 == 7) {
              display.drawPixel(posX+ix,posY+iy,display.color565(255,0,255));
                }                
    }
    }
    }   
  }

void showLine(){


  SetEmojiXY(6, 1, 45, 2);
  SetEmojiXY(5, 6, 30, 12);
  SetEmojiXY(9, 5, 30, 22);
  

drawFastYLine(0,0,32,display.color565(0,0,255));
drawFastXLine(1,0,6,display.color565(0,0,255));
drawFastXLine(1,31,6,display.color565(0,0,255));
drawFastYLine(7,0,32,display.color565(0,0,255));

drawFastYLine(1,1,30,display.color565(255,255,255));
drawFastYLine(6,1,30,display.color565(255,255,255));
drawFastXLine(2,1,4,display.color565(255,255,255));
drawFastXLine(2,30,4,display.color565(255,255,255));

drawFastYLine(24,0,32,display.color565(0,0,255));
drawFastYLine(25,0,32,display.color565(255,255,255));
drawFastYLine(26,0,32,display.color565(255,255,255));
drawFastYLine(27,0,32,display.color565(255,255,255));



drawFastYLine(29,1,7,display.color565(255,255,255));
drawFastYLine(36,1,7,display.color565(255,255,255));
drawFastXLine(29,1,7,display.color565(255,255,255));
drawFastXLine(29,8,8,display.color565(255,255,255));

drawFastYLine(28,0,32,display.color565(0,0,255));
drawFastYLine(63,0,32,display.color565(0,0,255));
drawFastXLine(28,0,35,display.color565(0,0,255));
drawFastXLine(28,31,35,display.color565(0,0,255));


 
}
