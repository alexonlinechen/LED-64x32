byte n[25]={};
byte bingo_count = 0 ;
byte bingo_no ;
bool bingo = false;


//主程式
void runBingo(){


 //開始鍵
if( BTN_VALUE  == 5 ){

         if (!bingo){
                  bingo_get();
                  bingo = true;
         }

  
     if (bingo){
         // 再範圍內
         if (bingo_count < 26){

             bingoAnimation();
          
             bingo_no = n[bingo_count];//設定隨機取號後的順序           
             Serial.print(F("按鍵次數 ")); 
             Serial.println(bingo_count);
             Serial.print("賓果號碼:"); 
             Serial.println(bingo_no);
             bingo_count ++ ;  //放最後+1
                            } 

          //超過取號範圍  遊戲結束
          if (bingo_count >= 26){
                                 Serial.println("遊戲結束"); 
                                 //歸零/初始設定
                                 bingo_count =0;
                                 bingo_no = 0;  
                                 bingo = false;
                                 clearall();
                                }
                          } 
                   BTN_VALUE  = 0 ;
                }  //end BTN start

  showBingo(); //顯示賓果號碼
  
} //end runBingo



 void bingo_get(){

     //Serial.print("產生隨機順序 不重複 ");

        for(int i=0; i<25; i++){
                       n[i]=random(1, 26);
      
            for (int j = 0; j < i; j++) { 
                       
                   if (n[j] == n[i]){  i--; 
                                       break;
                                    }
                                        } 
                               }                 
                    }//end bingo_get


void showBingo(){

 //框
 display.drawRect(0,0,41,32,display.color565(0,0,255));
 display.drawRect(40,0,24,32,display.color565(0,0,255));

 drawFastYLine(0,0,32,display.color565(0,0,255));
 drawFastYLine(8,0,32,display.color565(0,0,255));
 drawFastYLine(16,0,32,display.color565(0,0,255));
 drawFastYLine(24,0,32,display.color565(0,0,255));
 drawFastYLine(32,0,32,display.color565(0,0,255));

 drawFastXLine(0,6,40,display.color565(0,0,255));
 drawFastXLine(0,12,40,display.color565(0,0,255));
   drawFastXLine(0,18,40,display.color565(0,0,255));
  drawFastXLine(0,19,40,display.color565(0,0,255));
   drawFastXLine(0,25,40,display.color565(0,0,255));

for(int i=1; i<6; i++){
 if(bingo_no == i)show05bitnumber(bingo_no,3,5,i*8-7,1,display.color565(255,255,255));
}

for(int i=6; i<11; i++){
 if(bingo_no == i)show05bitnumber(bingo_no,3,5,(i-5)*8-7,7,display.color565(255,255,255));
}

for(int i=11; i<16; i++){
 if(bingo_no == i)show05bitnumber(bingo_no,3,5,(i-10)*8-7,13,display.color565(255,255,255));
}

for(int i=16; i<21; i++){
 if(bingo_no == i)show05bitnumber(bingo_no,3,5,(i-15)*8-7,20,display.color565(255,255,255));
}

for(int i=21; i<26; i++){
 if(bingo_no == i)show05bitnumber(bingo_no,3,5,(i-20)*8-7,26,display.color565(255,255,255));
}


for(int i=1; i<26; i++){
 if(bingo_no == i)show20bitnumber(bingo_no,10,17,41,8,display.color565(255,0,0));

  }  
}   //end showbingo


//賓果動畫
void bingoAnimation() {
          
 for(int i=0;i< 20;i++) {
       byte  num = random(1, 20);
       show20bitnumber(num,10,17,41,8,display.color565(255,0,0));
       delay(100);     
               }
         
      }
    
