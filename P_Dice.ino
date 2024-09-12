


PROGMEM const byte big[8][8] = {
                 { 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 1, 0, 0, 0, 0},
                 { 1, 1, 1, 1, 1, 1, 1, 0}, 
                 { 0, 0, 0, 1, 0, 0, 0, 0},
                 { 0, 0, 1, 0, 1, 0, 0, 0},
                 { 0, 1, 0, 0, 0, 1, 0, 0},
                 { 1, 0, 0, 0, 0, 0, 1, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0},              
               };

PROGMEM const byte small[8][8] = {
                 { 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 1, 0, 0, 0, 0},
                 { 0, 0, 0, 1, 0, 0, 0, 0}, 
                 { 0, 0, 0, 1, 0, 0, 0, 0},
                 { 0, 0, 0, 1, 0, 0, 0, 0},
                 { 0, 1, 0, 1, 0, 1, 0, 0},
                 { 1, 0, 0, 1, 0, 0, 1, 0},
                 { 0, 0, 1, 1, 0, 0, 0, 0},               
               };               


PROGMEM const byte diceOne[12][12] = {
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                
               };

PROGMEM const byte diceTwo[12][12] = {
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},          
               };              

PROGMEM const byte diceThree[12][12] = {
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                
               };   

PROGMEM const byte diceFour[12][12] = {
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 0},
                 { 0, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 0},
                 { 0, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                  
               }; 

PROGMEM const byte diceFive[12][12] = {
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                
               }; 

PROGMEM const byte diceSix[12][12] = {
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},               
               }; 


int diceX = 5 ;
int diceY = 0 ;

bool bet_zone = false;
bool big_samll_pos  = false ;
byte big_samll_num   ;

int dicePos = 1 ;
byte dicenum ;
int dice_score = 100 ;
int bet_score = 10 ;

#define MATH_ANIMATION 20

 
 
void rundice(){

 //  display.clearDisplay(); 

  //右鍵
  if( BTN_VALUE  == 4 ){

          if (!big_samll_pos) dicePos += 1;
          if ( dicePos > 6) dicePos = 1 ;
          
          diceX += 9 ;
          if ( diceX > 50) diceX = 5; 

         // 押注區域  的條件
         if ( big_samll_pos && diceX > 9 ){ 
               diceX = -10;  //超出 Led範圍 避免影響到押注區
               bet_zone = true ;
             }
         if ( big_samll_pos && diceX >=-1 && diceX <= 9 ){ 
               bet_zone = false ;
             }

         //大小區域的條件 
         if ( big_samll_pos && diceX == -1) diceX = 0;
         if ( big_samll_pos && diceX == 0 ) big_samll_num = 1;   //大
         if ( big_samll_pos && diceX == 9 ) big_samll_num = 2;   //小             
         
    /*   Serial.print(F("骰子X: "));
       Serial.println(diceX); 
       Serial.print(F("選擇骰子: "));
       Serial.println(dicePos);   
       Serial.print(F("大小: "));
       Serial.println(big_samll_num); 
       Serial.print(F("區域: "));
       Serial.println(big_samll_pos); 
       Serial.print(F("押注: "));
       Serial.println(bet_zone);     */     
         }


  //左鍵
  if( BTN_VALUE  == 3 ){

            if (!big_samll_pos) dicePos -= 1;
            if ( dicePos < 1) dicePos = 6 ;
      
            diceX -= 9 ;
            if (!big_samll_pos && diceX < 5) diceX = 50;

            //押注區域的條件
            if (big_samll_pos && diceX == -9) bet_zone = true ;        
            if (big_samll_pos && diceX < -10  ) diceX = 9;                           
            if ( big_samll_pos && diceX >= 0 &&  diceX <= 9 ) bet_zone = false ;

            //大小區域的條件 
            if ( big_samll_pos && diceX < 0) diceX = -10;
            if ( big_samll_pos && diceX == 0 ) big_samll_num = 1;   //大
            if ( big_samll_pos && diceX == 9 ) big_samll_num = 2;   //小
                        
    /*  Serial.print(F("骰子X: "));
       Serial.println(diceX); 
       Serial.print(F("選擇骰子: "));
       Serial.println(dicePos);   
       Serial.print(F("大小: "));
       Serial.println(big_samll_num); 
       Serial.print(F("區域: "));
       Serial.println(big_samll_pos); 
       Serial.print(F("押注: "));
       Serial.println(bet_zone); 
            //Serial.println(F(dicePos));
            //Serial.println(diceX);   */
            }

    //上按鍵
   if( BTN_VALUE  == 1 ){
 
      if (big_samll_pos && !bet_zone) {
            diceX = 5;
            diceY = 0 ; 
            dicePos = 1 ; 
            big_samll_num = 0 ;
            big_samll_pos = false;
           // Serial.print(F("押注金額: "));
           // Serial.println(bet_score); 
            }
            
      if(bet_zone){    //增加押注
            bet_score+= 10 ;
            if(bet_score > 100) bet_score =100;
           // Serial.print(F("押注金額: "));
           //  Serial.println(bet_score); 
           }           
    }


   //下按鍵
    if( BTN_VALUE  == 2 ){

          if(!big_samll_pos) {
            big_samll_num = 1 ;
            diceY = 9 ;
            diceX = 0;        
          }
         // if(!big_samll_pos && !bet_zone) diceX = 0; 
         big_samll_pos = true; 
         
         if(bet_zone){  //減少押注
             
             display.fillRect(38,12,26,9,display.color565(0,0,0)); //清除押注區避免重疊  
             bet_score-= 10 ;
             if(bet_score < 10 )  bet_score = 10 ;
           // Serial.print(F("押注金額: "));
            //Serial.println(bet_score); 
         }
                
    }


   

    //開始鍵
    if( BTN_VALUE  == 5 && dice_score != 0 && dice_score >= bet_score && !bet_zone){
       clearall();
       delay(500);
       diceMath();        
       //Serial.print(F("抽出點數: "));
       //Serial.println(dicenum);
        dice_score = dice_score - bet_score ;  //扣掉押注金額
        D_score(); 
        delay(500); 
        display.clearDisplay();
    }

//cleardice();
  
 //畫框  9x9
  display.drawRect(5,0,10,10,display.color565(0,0,0));
  display.drawRect(14,0,10,10,display.color565(0,0,0));
  display.drawRect(23,0,10,10,display.color565(0,0,0));
  display.drawRect(32,0,10,10,display.color565(0,0,0));
  display.drawRect(41,0,10,10,display.color565(0,0,0));
  display.drawRect(50,0,10,10,display.color565(0,0,0));
  
  display.drawRect(0,9,10,10,display.color565(0,0,0));
  display.drawRect(9,9,10,10,display.color565(0,0,0));
 
 //畫選擇框  9x9
  display.drawRect(0+diceX,0+diceY,10,10,display.color565(255,0,0));
 
 //畫押注框
   if(bet_zone)   display.drawRect(37,11,27,10,display.color565(0,255,0));  //押注框(綠) 

   if(!bet_zone)  display.drawRect(37,11,27,10,display.color565(0,0,0));
   


//顯示emjoi 骰子
   GlobalX = 0;
   GlobalY = 0;
   SetEmojiXY(10, 10, 6, 1);
   SetEmojiXY(10, 9, 15, 1); 
   SetEmojiXY(10, 8, 24, 1);
   SetEmojiXY(10, 7, 33, 1); 
   SetEmojiXY(10, 6, 42, 1);
   SetEmojiXY(10, 5, 51, 1);    

   //骰子結果
   finaldice();
   display.drawRect(3,19,12,12,display.color565(0,125,125));
   

//顯示大小圖案
 GlobalX = 1;
 GlobalY = 10;
 draw_big_small(big);

 GlobalX = 10;
 draw_big_small(small);
 
  //分數
  GlobalX = 0;
  GlobalY = 0;
  SetEmojiXY(9, 5, 27, 12);
  SetEmojiXY(6, 5, 27, 22); 
  showbitnumber(bet_score,5,8,39,12,display.color565(0,255,255));
  showbitnumber(dice_score,5,8,39,22,display.color565(0,255,255));

   

BTN_VALUE  = 0 ;
 
    
   }  // end rundice



//顯示 隨機骰子
 void printDice(const byte dice[][12]){

  byte posx = 17 ;
  byte posy = 9 ;
  
  int x,y ;

  display.drawRect(posx-1,posy-1,14,14,display.color565(0,0,255));
  

  for (x=0;x<12;x++){   
    for (y=0;y<12;y++){
      if (pgm_read_byte_near ( &dice[x][y]) == 1){
         display.drawPixel(y+posx,x+posy,display.color565(255,255,255));
      } 
      
     else if (pgm_read_byte_near ( &dice[x][y]) == 2){
         display.drawPixel(y+posx,x+posy,display.color565(255,0,0));
      } 
      
      else {
         display.drawPixel(y+posx,x+posy,display.color565(0,0,0));
      }
    }
  }
}


//顯示大小圖案 8x8
void draw_big_small(const byte dice[][8]){

   byte x,y;   
  for (x=0;x<8;x++){   
    for (y=0;y<8;y++){
      if (pgm_read_byte_near ( &dice[x][y]) == 1){
         display.drawPixel(y+GlobalX,x+GlobalY,display.color565(255,255,255));
      }            
      else {
         display.drawPixel(y+GlobalX,x+GlobalY,display.color565(0,0,0));
          }
         } 
        }
       }


    void diceMath() {
     
       // Clear pixels     
      for(int i=0;i< MATH_ANIMATION;i++) {

         dicenum = random(1, 7);
         
        switch (dicenum) {
        case 1:
          printDice(diceOne);
          break;
        case 2:
          printDice(diceTwo);
          break;
        case 3:
          printDice(diceThree);
          break;
        case 4:
          printDice(diceFour);
          break;
        case 5:
          printDice(diceFive);
          break;
        case 6:
          printDice(diceSix);
          break;
        }
        delay(100);
      }     
   
    }


void cleardice() {

   //清除選擇框線的移動範圍  避免殘影
    byte x,y;   
    for (x=0;x<64;x++){   
      for (y=0;y<19;y++){
         display.drawPixel(x,y,display.color565(0,0,0));
             }
           } 
    }


void D_score(){

  //算分數
  if (dicenum == dicePos && big_samll_num == 0 ) dice_score += bet_score*5 ;
  
  
  //算大小x2倍
  if ( big_samll_pos == 1 ) {
      if ( big_samll_num == 1 && dicenum>=4 )dice_score += bet_score*2 ;  //大
      if ( big_samll_num == 2 && dicenum<=3 )dice_score += bet_score*2 ;  //小
  }
  
  //Serial.print(F("分數: "));
  //Serial.println(dice_score);
  
}



 void finaldice() {

     GlobalX = 0;
     GlobalY = 0;
        switch (dicenum) {
        case 1:
          SetEmojiXY(10, 10, 5, 21);
          break;
        case 2:
          SetEmojiXY(10, 9, 5, 21);
          break;
        case 3:
          SetEmojiXY(10, 8, 5, 21);
          break;
        case 4:
          SetEmojiXY(10, 7, 5, 21);
          break;
        case 5:
          SetEmojiXY(10, 6, 5, 21);
          break;
        case 6:
          SetEmojiXY(10, 5, 5, 21);
          break;
        }
      }
