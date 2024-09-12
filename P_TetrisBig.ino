



const byte BIG_N1[2][64]PROGMEM = { { 52,53,54,55,56,57,58,59,64,65,66,67,68,69,70,71,76,77,78,79,80,81,82,83,
                               88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,108,109,110,111,112,
                               113,114,115,120,121,122,123,124,125,126,127,132,133,134,135,136,137,138,139 },
                         
                           { 4,5,6,7,16,17,18,19,28,29,30,31,40,41,42,43,52,53,54,55,56,57,58,59,
                             64,65,66,67,68,69,70,71,76,77,78,79,80,81,82,83,88,89,90,91,92,93,94,95,
                             104,105,106,107,116,117,118,119,128,129,130,131,140,141,142,143 } }; // ID:1.

const byte  BIG_N2[2][64]PROGMEM = { { 48,49,50,51,52,53,54,55,60,61,62,63,64,65,66,67,72,73,74,75,76,77,78,79,
                                       84,85,86,87,88,89,90,91,100,101,102,103,104,105,106,107,112,113,114,115,
                                       116,117,118,119,124,125,126,127,128,129,130,131,136,137,138,139,140,141,142,143 },
                         
                                   { 8,9,10,11,20,21,22,23,32,33,34,35,44,45,46,47,52,53,54,55,56,57,58,59,
                                     64,65,66,67,68,69,70,71,76,77,78,79,80,81,82,83,88,89,90,91,92,93,94,95,
                                    100,101,102,103,112,113,114,115,124,125,126,127,136,137,138,139 } };  // ID:2.

const byte  BIG_L1[4][64]PROGMEM = { { 8,9,10,11,20,21,22,23,32,33,34,35,44,45,46,47,56,57,58,59,68,69,70,71,80,81,82,
                                       83,92,93,94,95,100,101,102,103,104,105,106,107,112,113,114,115,116,117,118,119,
                                       124,125,126,127,128,129,130,131,136,137,138,139,140,141,142,143 },
                  
                                  { 48,49,50,51,60,61,62,63,72,73,74,75,84,85,86,87,96,97,98,99,100,101,102,103,104,105,106,107,
                                   108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,
                                   132,133,134,135,136,137,138,139,140,141,142,143 },
                  
                                  { 4,5,6,7,8,9,10,11,16,17,18,19,20,21,22,23,28,29,30,31,32,33,34,35,40,41,42,43,44,45,46,47,
                                   52,53,54,55,64,65,66,67,76,77,78,79,88,89,90,91,100,101,102,103,112,113,114,115,124,125,126,127,136,137,138,139 },
                  
                                  { 48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,
                                    76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,
                                    104,105,106,107,116,117,118,119,128,129,130,131,140,141,142,143 } }; // ID:3.

const byte  BIG_L2[4][64]PROGMEM = { { 4,5,6,7,8,9,10,11,16,17,18,19,20,21,22,23,28,29,30,31,32,33,34,35,40,41,42,43,44,45,46,47,
                                       56,57,58,59,68,69,70,71,80,81,82,83,92,93,94,95,104,105,106,107,116,117,118,119,128,129,130,131,140,141,142,143 },
                     
                                   {  56,57,58,59,68,69,70,71,80,81,82,83,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,
                                      114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143},
                     
                                   {4,5,6,7,16,17,18,19,28,29,30,31,40,41,42,43,52,53,54,55,64,65,66,67,76,77,78,79,88,89,90,91,100,
                                    101,102,103,104,105,106,107,112,113,114,115,116,117,118,119,124,125,126,127,128,129,130,131,136,137,138,139,140,141,142,143},
                     
                                   { 48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,
                                     80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,108,109,110,111,120,121,122,123,132,133,134,135 } }; // ID:4.

const byte  BIG_T[4][64]PROGMEM  = { { 8,9,10,11,20,21,22,23,32,33,34,35,44,45,46,47,52,53,54,55,56,57,58,59,64,65,66,67,68,69,70,71,76,77,
                                       78,79,80,81,82,83,88,89,90,91,92,93,94,95,104,105,106,107,116,117,118,119,128,129,130,131,140,141,142,143 },
                     
                                   { 52,53,54,55,64,65,66,67,76,77,78,79,88,89,90,91,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,
                                     114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143 },
                     
                                   { 4,5,6,7,16,17,18,19,28,29,30,31,40,41,42,43,52,53,54,55,56,57,58,59,64,65,66,67,68,69,70,71,76,77,78,79,80,81,82,83,
                                    88,89,90,91,92,93,94,95,100,101,102,103,112,113,114,115,124,125,126,127,136,137,138,139 },
                     
                                  { 48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,
                                    85,86,87,88,89,90,91,92,93,94,95,100,101,102,103,112,113,114,115,124,125,126,127,136,137,138,139 } }; // ID:5.

const byte  BIG_O[1][64]PROGMEM  = { { 48,49,50,51,52,53,54,55,60,61,62,63,64,65,66,67,72,73,74,75,76,77,78,79,
                                       84,85,86,87,88,89,90,91,96,97,98,99,100,101,102,103,108,109,110,111,112,113,114,115,
                                       120,121,122,123,124,125,126,127,132,133,134,135,136,137,138,139 } };     // ID:6.

const byte  BIG_I[2][48]PROGMEM  = { { 8,9,10,11,20,21,22,23,32,33,34,35,44,45,46,47,56,57,58,59,68,69,70,71,80,81,82,83,92,93,94,95,
                                       104,105,106,107,116,117,118,119,128,129,130,131,140,141,142,143 },
                     
                                   {  48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,
                                      72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95 } };     // ID:7.


// 方塊陣列.
byte BIG_brick[12][12];

byte BIG_container[32][68] ;
int BIG_containerX = -8;  
int BIG_containerY = 8; 

// 清除方塊數量.
byte BIG_clearBrickFlag = 0;
// 清除方塊閃爍次數.
byte BIG_flashNum = 0;
byte BIG_gameStatus = 0;
int BIG_score;


//---------------------------------------------------------------------------
// 主迴圈.
//---------------------------------------------------------------------------
void BIG_Tetris_loop()
{

 int posX = 0;
 int posY = 0;

 // 0:準備開始中.
 if (BIG_gameStatus == 0) {
       
       if (BTN_VALUE == 5) {   // 按鍵-開始遊戲.   
             BIG_clearBrickFlag = 0;  // 清除方塊數量.
             BIG_gameStatus = 1;   // 設定遊戲中.
         }
     }
 
// 1:遊戲中.
 else if (BIG_gameStatus == 1) {
  
      if (BTN_VALUE == 6) {   }  //測試　-列印容器狀態
      
      //設定最底邊界不為0 以免影響方塊至底
          for (int i = 0; i<32; i++) {  
              BIG_container[i][64]= 9;

            }

    
       // 開始方塊 -不需要清除連線的狀態
      if (BIG_clearBrickFlag == 0) {
            
           // 方塊往下掉.
            if (BTN_VALUE == 2) {       
                 if (T_PlayMode == 0){
                      BIG_containerX = BIG_containerX+4; 
                                  }
                                 }
            if (T_PlayMode == 1){
                  if(millis() - lastTime > T_speed){
                                    BIG_containerX = BIG_containerX+4;  
                                    lastTime = millis();  } 
                                   }                     

                                 
   
   // 判斷是否碰到其他方塊.
      if (!BIG_ifCopyToContainer()) {
            
            BIG_containerX = BIG_containerX-4;   // 觸碰 X往上移一格.
    
            // 遊戲結束.
            if (BIG_containerX < 0) {
                      BIG_gameover();
                      show_BIG_score();
                      BIG_resetGame();   // 重新開始遊戲.
                      return;
                     }
                BIG_brickNew();   // 產生新塊.
           }
   
       // 已到底 產生新塊 
       else if (BIG_containerX >= 60) {    //方塊從初始到碰到底部的距離
                 BIG_brickNew();
        }
       // 判斷與設定要清除的方塊.  >0 代表開始消除
         BIG_clearBrickFlag = BIG_ifClearBrick();

   }  //end  clearBrickFlag>0


//-------------------------------------------------------------------- 
//--------------------------------------------------------------------  

                
      // 處理閃爍和清除方塊.
       if (BIG_clearBrickFlag > 0){
  
            // 閃爍方塊次數.
             BIG_flashNum++;
            // 閃爍方塊.
             BIG_brickFlash();
           // 清除方塊繼續遊戲.
            if (BIG_flashNum >= 3) {
                    BIG_clearBrick();  // 清除方塊.
                    BIG_clearBrickFlag = 0;   // 初始變數. 繼續執行掉落方塊
                    BIG_flashNum = 0;
                 }   
            }
          }   //end 遊戲中
 
  
  // 清除畫面.
  display.clearDisplay(0);
  
  //--------------------------------------------------------------------
  // 搖桿往上操作變換方塊.
  // 方塊X座標 != -2 左邊空白  != 右邊移動範圍     
  if (BTN_VALUE == 1 && BIG_containerY != -4 && BIG_containerY != 34 && BIG_clearBrickFlag == 0) {

   // N1、N2、I(2種狀態).
   if ( brickId == 1 || brickId == 2 || brickId == 7) {
    brickState++;
    if (brickState > 1) { brickState = 0; }

    // 處理判斷是否可以旋轉方塊.
    BIG_processTransformToBrickArray();
    if (!BIG_ifCopyToContainer()) {
     brickState--;
     if (brickState < 0) { brickState = 1; }
    }
   }
   // L1、L2、T(4種狀態)
   else if (brickId == 3 || brickId == 4 || brickId == 5) {
    brickState++;
    if (brickState > 3) { brickState = 0; }

    // 處理判斷是否可以旋轉方塊.
    BIG_processTransformToBrickArray();
    if (!BIG_ifCopyToContainer()) {
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
 if (BTN_VALUE == 2 && T_PlayMode == 1)T_speed = 70;


  //--------------------------------------------------------------------
  // 處理轉換方塊到方塊陣列.
  BIG_processTransformToBrickArray();

  //--------------------------------------------------------------------
  // 操作左右移動方塊.
  
  if (BIG_clearBrickFlag == 0) {

    // 右移.
    if (BTN_VALUE == 4) {
       
     BIG_containerY = BIG_containerY-4;
     // 判斷可否右移.
    if (BIG_ifCopyToContainer()) {
        if (BIG_containerY < 0) {
        //判斷右邊邊界是否為空白 空白多移1格
      if ( BIG_brick[0][2] == 0 && BIG_brick[0][6] == 0 && BIG_brick[0][10] == 0)  //定位2區域來判斷是否空白0
      {    
          if (BIG_containerY<0) { BIG_containerY = -4; } 
      }
      else {
        BIG_containerY = 0; 
      }
     }
     }
     else {
      BIG_containerY =BIG_containerY+4;
     }
    }
    
    // 左移.
    if (BTN_VALUE == 3) 
    {
     BIG_containerY = BIG_containerY+4;
     // 判斷可否左移.
     if (BIG_ifCopyToContainer()) {
      if (BIG_containerY > 20) {    //if 座標低於左邊邊界0
          
           // 處理直立長條(特例).
        if (  BIG_brick[10][2] == 0 && BIG_brick[10][5] == 0 )    
       {
        BIG_containerY = 24;
       }
       else {
        BIG_containerY = 20;
       }
      }
     }
     else {
      BIG_containerY = BIG_containerY-4;
     }     
    }
   
  }
  
  //開始顯示畫面
  //--------------------------------------------------------------------  
  // 畫容器.
  for (int iy = 0; iy<32; iy++) {
   for (int ix = 0; ix<64; ix++) {
    if (BIG_container[iy][ix] == 1 && BIG_container[iy][ix] != 255) {    
     display.drawPixel(ix,iy,display.color565(0,255,0));
    }
   else if (BIG_container[iy][ix] == 2 && BIG_container[iy][ix] != 255) {    
     display.drawPixel(ix,iy,display.color565(0,255,0));
    }
   else if (BIG_container[iy][ix] == 3  && BIG_container[iy][ix] != 255) {    
     display.drawPixel(ix,iy,display.color565(0,0,255));
    }
   else if (BIG_container[iy][ix] == 4 && BIG_container[iy][ix] != 255) {    
     display.drawPixel(ix,iy,display.color565(0,0,255));
    }
   else if (BIG_container[iy][ix] == 5 && BIG_container[iy][ix] != 255) {    
     display.drawPixel(ix,iy,display.color565(255,0,0));
    }            
   else if (BIG_container[iy][ix] == 6 && BIG_container[iy][ix] != 255) {    
     display.drawPixel(ix,iy,display.color565(255,255,0));
    }   
   else if (BIG_container[iy][ix] == 7 && BIG_container[iy][ix] != 255) {    
     display.drawPixel(ix,iy,display.color565(255,0,255));
    }
    
    else {
     display.drawPixel(ix,iy,display.color565(0,0,0));
    }    
   }
  }


  // 畫方塊.  
  for (int iy = 0; iy < 12; iy++) {
   for (int ix = 0; ix < 12; ix++) {
    posX = BIG_containerX + ix;
    posY = BIG_containerY + iy;
    if( posX >= 0 && posY >= 0){
     if (BIG_brick[iy][ix] > 0) {
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
    }
   }
  }



BTN_VALUE = 0 ;
  
} //end loop





//--------------------------------------------------------------------
// 處理轉換方塊到方塊陣列.
//--------------------------------------------------------------------
void BIG_processTransformToBrickArray()
{
 // N1.
 if (brickId == 1) {
  BIG_transformToBrickArray((byte *)BIG_N1, 64, brickState, brickId);
 }
 // N2.
 else if (brickId == 2) {
  BIG_transformToBrickArray((byte *)BIG_N2, 64, brickState, brickId);
 }
 // L1.
 else if (brickId == 3) {
  BIG_transformToBrickArray((byte *)BIG_L1, 64, brickState, brickId);
 }
 // L2.
 else if (brickId == 4) {
  BIG_transformToBrickArray((byte *)BIG_L2, 64, brickState, brickId);
 }
 // T.
 else if (brickId == 5) {
  BIG_transformToBrickArray((byte *)BIG_T, 64, brickState, brickId);
 }
 // O.
 else if (brickId == 6) {
     BIG_transformToBrickArray((byte *)BIG_O, 64, brickState, brickId);
 }
 // I.
 else if (brickId == 7) {
  BIG_transformToBrickArray((byte *)BIG_I, 48, brickState, brickId);
 }
}

//---------------------------------------------------------------------------
// 轉換方塊到方塊陣列.
// pBrick : 方塊陣列.
// bLengthY: 方塊大小.
// bState : 方塊狀態.
//  bBrickId: 方塊編號.
//---------------------------------------------------------------------------
void BIG_transformToBrickArray(byte *pBrick, byte bLengthY, byte bState, byte bBrickId)
{
 byte bx, by;

 // 清除方塊陣列.
 for (int iy = 0; iy < 12; iy++) {
  for (int ix = 0; ix < 12; ix++) {
   BIG_brick[iy][ix] = 0;
  }  
 }

 // 轉換方塊到方塊陣列.
 for (int i = 0; i < bLengthY; i++) {
  bx = (pgm_read_byte(pBrick + bState * bLengthY + i)) % 12;
  by = (pgm_read_byte(pBrick + bState * bLengthY + i)) / 12;
  BIG_brick[by][bx] = bBrickId;
 }
}

//---------------------------------------------------------------------------
// 判斷是否可以複製到容器內.
// true:可以.  false:不可以.
//---------------------------------------------------------------------------
bool BIG_ifCopyToContainer() {          
 int posX = 0;
 int posY = 0;
 for (int iy = 0; iy < 12; iy++) {
  for (int ix = 0; ix < 12; ix++) {
   if (BIG_brick[iy][ix] != 0) {
    posX = BIG_containerX + ix;
    posY = BIG_containerY + iy;
    if (posX >= 0 && posY >= 0 ) {  //0= 左邊界 -2代表長條直立最靠左邊的狀態
        if (BIG_container[posY][posX] != 0) {
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
void BIG_copyToContainer() {

 
 int posX = 0;
 int posY = 0;
 for (int iy = 0; iy < 12; iy++) {
  for (int ix = 0; ix < 12; ix++) {
   if (BIG_brick[iy][ix] != 0) {
    posX = BIG_containerX + ix;
    posY = BIG_containerY + iy;
    if (posX >= 0 && posY >= 0) {
     BIG_container[posY][posX] = BIG_brick[iy][ix];
     
    }
    
   }
  }
 }
}

//---------------------------------------------------------------------------
// 判斷與設定要清除的方塊. lineNum >0 代表需要消除
//---------------------------------------------------------------------------
byte BIG_ifClearBrick() {

 int pointNum = 0; 
 int lineNum = 0;

 for (int ix = 63; ix > 1; ix--) {
  for (int iy = 0; iy < 32; iy++) {
 
   if (BIG_container[iy][ix] > 0) {
          pointNum++;
          }

   if (pointNum == 32) {  
    // Serial.println(F("開始消除32")); 
    for (int i = 0; i<32; i++) {
     lineNum++;
     BIG_container[i][ix] = 255;   //將要消除的方塊定位為255(亮)
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
void BIG_clearBrick() {
  //Serial.println(F("開始消除 - 需要被清除的方塊"));
  byte temp = 0;
   for(int x=63; x>0; x--)
   {
     bool LineFull = true ;
     
     for (int y=0; y<32; y++)
     {
        if (BIG_container[y][x] == 0)
        {
          LineFull = false ; 
          break;
        }
     }
   

 //  確定一行有滿的方塊 開始消除  消除一行+10分
 if(LineFull){
       for (int ix = 68; ix > 1; ix--) {    // 最大容器範圍
         for (int iy = 0; iy < 32; iy++) {
            if (BIG_container[iy][ix] == 255 || BIG_container[iy][ix] == 254) {
                temp = BIG_container[iy][ix-1];
                BIG_container[iy][ix-1] = BIG_container[iy][ix];
                BIG_container[iy][ix] = temp;
                  }
               } 
             } 
    for (int iy = 0; iy < 32; iy++) {
           BIG_container[iy][0] = 0;  //因為消除方塊 需補上空白不然 會gameover
           BIG_container[iy][1] = 0;  
         }
         BIG_score +=5;   
         Serial.print(F("BIG分數:"));
         Serial.println(BIG_score);
         }
        }
      }


//---------------------------------------------------------------------------
// 閃爍方塊.
//---------------------------------------------------------------------------
void BIG_brickFlash() {
  //Serial.println(F("閃爍方塊"));
 for (int iy = 0; iy < 32; iy++) {
   for (int ix = 0; ix < 68; ix++) {
      if (BIG_container[iy][ix] == 255) {
          BIG_container[iy][ix] = 254;
          display.drawPixel(ix,iy,display.color565(0,100,125));
          }
       else if (BIG_container[iy][ix] == 254) {
           BIG_container[iy][ix] = 255;
           }
  }
 }
 delay(80);
}


//---------------------------------------------------------------------------
// 產生新塊.
//---------------------------------------------------------------------------
void BIG_brickNew(){

 gamespeed();

 // 複製方塊到容器內.
 BIG_copyToContainer();
 // 初始方塊.
 BIG_containerX = -8;
 BIG_containerY = 8;

 // 亂數產生方塊.
 brickId = (byte)random(1, 8);
  Serial.print(F("方塊ID"));
  Serial.println(brickId);
 // 初始方塊狀態.
 brickState = 0;
}

//---------------------------------------------------------------------------
// 重新開始遊戲.
//---------------------------------------------------------------------------
void BIG_resetGame()
{
 
  Serial.println(F("Game Over"));
 // 遊戲狀態.
BIG_gameStatus = 0;

 // 亂數產生方塊.
 brickId = (byte)random(1, 8);
 Serial.print(F("方塊ID"));
 Serial.println(brickId);
 // 方塊狀態(0~3).
 brickState = 0;

 // 方塊在容器的位置.
BIG_containerY = 8;
 if (brickId == 1 || brickId == 2) {
  BIG_containerX = 0;
 }
 else if (brickId == 7) {
  BIG_containerX = -8;
 }
 else {
  BIG_containerX = -4;
 }
 
 // 清除方塊數量(暫停).
  BIG_clearBrickFlag = 1;

 // 清除容器.
 for (int iy = 0; iy < 32; iy++) {
  for (int ix = 0; ix < 64; ix++) {
   BIG_container[iy][ix] = 0;
  }
 } 
}


void BIG_gameover(){

    if(BIG_score > T_topscore && T_PlayMode == 1){   //寫入最高分
      T_topscore = BIG_score ;
        EEPROM.write(EEPROM_T_TOPscore, T_topscore);
        EEPROM.commit();
    }
  
    for (int ix = 64; ix>=0; ix--) {
      delay(30);
       for (int iy = 0; iy<32; iy++) {
          if (BIG_container[iy][ix] != 0 && BIG_container[iy][ix] != 255) {    
              display.drawPixel(ix,iy,display.color565(0,100,125));
               }
            }
        }
       delay(1500);
        for (int ix = 64; ix>=0; ix--) {
          delay(30);
            for (int iy = 0; iy<32; iy++) {
              display.drawPixel(ix,iy,display.color565(0,0,0));
                 }  
                }
       }


void show_BIG_score(){
//showbitnumber(BIG_score,5,8,39,12,hsv2rgb(hueh, saturation, value));
//String BIG_numStr = String(BIG_score);
//String Top_numStr = String(T_topscore);
   SetEmojiXY(5, 6, 5, 5);
   showbitnumber(T_topscore,5,8,18,5,hsv2rgb(hueh, saturation, value));
   SetEmojiXY(9, 5, 5, 17);
   showbitnumber(BIG_score,5,8,18,17,hsv2rgb(hueh, saturation, value));

   delay(8000);
   clearall();
   
   
/*
    bool BgCover = true ;
    uint8_t r, g, b;
   
   for (int i = 0; i < 192; i++)
      {
         curremoji[i] = pgm_read_byte(gImage_emojis1+(192 * (10 * (5 - 1) + (6 - 1)) + i));
        
    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            
            r = curremoji[3 * (y * 8 + x)];
            g = curremoji[3 * (y * 8 + x) + 1];
            b = curremoji[3 * (y * 8 + x) + 2];
            if (BgCover || r || g || b)
                display.drawPixel(10+y,20+x,display.color565(r,g,b));

          }
        }
      }
      
   for (int i = 0; i < 192; i++)
      {
         curremoji[i] = pgm_read_byte(gImage_emojis2+(192 * (10 * (9 - 6) + (5 - 1)) + i));
        
    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            
            r = curremoji[3 * (y * 8 + x)];
            g = curremoji[3 * (y * 8 + x) + 1];
            b = curremoji[3 * (y * 8 + x) + 2];
            if (BgCover || r || g || b)
                display.drawPixel(30+y,20+x,display.color565(r,g,b));

          }
        }
      }


 /*String numStr = String(BIG_score);
 String bitrgbstr = bitdata10.charAt(((j-15)*5+i-10)).toInt();
//x= 10  y = 15
  for (int i = 10; i < 10+(5); i = i + (1)) {
    for(int j = 15; j < 15+(8); j = j + (1)){
      if (bitrgbstr != 0) {
        display.drawPixel(j,i,display.color565( 255, 0, 0));
      } else {
        display.drawPixel(j,i,display.color565( 0, 0, 0));
      }
    }
  }



      //display.setTextWrap(true);  // we don't wrap text so it scrolls nicely
    //  display.setRotation(3);
      //display.setFlip(true);
      display.setTextColor(display.color565(255,255,255));
      display.setCursor(10,10);
      display.print("999");
*/

  
}


   
