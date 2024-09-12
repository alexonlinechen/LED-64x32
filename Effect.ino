
/////// 特效代碼區 ////////

//移動像素
void movingPixel(int x, int y, int colorh){
    int pixel = y;
    display.drawPixel(x, pixel, hsv2rgb(colorh, 100, 100 ));
    if(pixel-1 >= 0){ display.drawPixel(x, pixel-1, hsv2rgb(colorh, 80, 80 ));}
    if(pixel-2 >= 0){ display.drawPixel(x, pixel-2, hsv2rgb(colorh, 70, 70 ));}
    if(pixel-3 >= 0){ display.drawPixel(x, pixel-3, hsv2rgb(colorh, 45, 45 ));}
    if(pixel-4 >= 0){ display.drawPixel(x, pixel-4, hsv2rgb(colorh, 25, 25 ));}
    if(pixel-5 >= 0){ display.drawPixel(x, pixel-5, hsv2rgb(colorh, 10, 10 ));}
    if(pixel-6 >= 0){ display.drawPixel(x, pixel-6, display.color565(0, 0, 0));}
}


/*
//代碼雨 
void showRainingCode(bool implement) {
  if ( millis() - lastTime > 100 | implement)
  {
    if(!implement){
      lastTime = millis();
    }
    for(int i=0; i<8; i++){
      if(stepIndex[i] > stepsTillNext[i]){
        Running[i] = true;
        stepsTillNext[i] = 23;  // 进行数组初始化
        columnIndex[i] = random((i*7), ((i+1)*7));
        stepIndex[i] = 0;
      }
      if(Running[i] == true){
        movingPixel(columnIndex[i]+GlobalX, stepIndex[i]+GlobalY, colorh);
        if(stepIndex[i] == 23){
          Running[i] = false;
        }
      }
      stepIndex[i] += 1;
    }
    ////display();
  }
}



//B站粉丝数  (顯示bitmap動畫)
void showBlibliFans(bool implement){
  int ani = 0;
  long dis = millis() - lastTime;
  if ( dis > 20000 | implement)
  {
    lastTime = millis();
  }
  if(50< dis && dis < 100){
    ani = 1;
  }else if(dis < 200){
    ani = 2;
  }else if(dis < 270){
    ani = 1;
  }
  display.clearDisplay();
  //顯示連續動畫 bitmap
  BPattern(ani);
  //display();
}

*/

//渐变色颜色计算方法
uint16_t Gradient(int x, int y){

  int n = 0;
  if(colorLoop<31){
    if(x+y>colorLoop){
      n = x+y-colorLoop;
    }else{
      n = colorLoop-x-y;
    }
  }else{
    if(x+y>(colorLoop-30)){
      n = 30-(x+y-colorLoop+30);
    }else{
      n = 30-(colorLoop-30-x-y);
    }
  }
  int r = (rB-rA)/30*n+rA;
  int g = (gB-gA)/30*n+gA;
  int b = (bB-bA)/30*n+bA;

  return display.color565(r,g,b);

}




   //清除畫面特效

   void clearall() {

  for (int x = 0; x < 64; x++){
        drawFastYLine(x,0,32,display.color565(0,0,0));
        delay(10); 
       }
     }


       void random_color(){

     if ( millis() - lastTime > 60000){  
        rA = rB;  gA = gB;  bA = bB; 
        rB = random(0, 256);  gB = random(0, 256);  bB = random(0, 256); 
        lastTime = millis();
        }      
      }
