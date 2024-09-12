
/*******************************************************
 * 函数名：hsv2rgb
 * 描述  ：颜色转换方法
 * 参数  ：h s v
 * 返回值：rgb
 **********************************************************/
uint16_t hsv2rgb(uint16_t hue, uint8_t saturation, uint8_t value)
{
    uint8_t red = 0;
    uint8_t green = 0;
    uint8_t blue = 0;
    uint16_t hi = (hue / 60) % 6;
    uint16_t F = 100 * hue / 60 - 100 * hi;
    uint16_t P = value * (100 - saturation) / 100;
    uint16_t Q = value * (10000 - F * saturation) / 10000;
    uint16_t T = value * (10000 - saturation * (100 - F)) / 10000;
    if(hue == 0){
      return display.color565(255*value/100, 255*value/100, 255*value/100);
    }
    switch (hi)
    {
    case 0:
        red = value;
        green = T;
        blue = P;
        break;
    case 1:
        red = Q;
        green = value;
        blue = P;
        break;
    case 2:
        red = P;
        green = value;
        blue = T;
        break;
    case 3:
        red = P;
        green = Q;
        blue = value;
        break;
    case 4:
        red = T;
        green = P;
        blue = value;
        break;
    case 5:
        red = value;
        green = P;
        blue = Q;
        break;
    default:
        return display.color565(255, 0, 0);
    }
    red = red * 255 / 100;
    green = green * 255 / 100;
    blue = blue * 255 / 100;
    return display.color565(red, green, blue);
}

    //畫X線 
void drawFastXLine(int16_t x, int16_t y, int16_t h, uint16_t c){
  for(int i=x;i<x+h;i++){
    display.drawPixel(i,y,c);
  }
}

void drawFastYLine(int16_t x, int16_t y, int16_t h, int16_t c){
  for(int i=y;i<y+h;i++){
    display.drawPixel(x,i,c);
  }
}

// 显示WiFi连接完成动画
void showWiFiDoneAnimation( bool clear)
{
  for (int i = 0; i < 8; i++)
  {
    showWiFiConnectDone(i, true);
    delay(100);
  }
  delay(500);
}


// WiFi连接完成动画帧
void showWiFiConnectDone(int status, bool clear)
{
  if (clear)
  {
    display.clearDisplay();
  }
  switch (status)
  {
  case 7:
    display.drawPixel(27, 1, 0x07E0);
  case 6:
    display.drawPixel(26, 2, 0x07E0);
  case 5:
    display.drawPixel(25, 3, 0x07E0);
  case 4:
    display.drawPixel(24, 4, 0x07E0);
  case 3:
    display.drawPixel(23, 5, 0x07E0);
  case 2:
    display.drawPixel(22, 4, 0x07E0);
  case 1:
    display.drawPixel(21, 3, 0x07E0);
  case 0:
    // char wifi[] = "WiFi";
    // for (int i = 0; i < 4; i++)
    // {
    //   showCharacter(i*4+3, 1, (int)wifi[i], Apple4x6, display.color565(65,105,225));
    // }
    display.drawFastVLine(2,2,2,0xFFFF);
    display.drawFastVLine(3,4,2,0xFFFF);
    display.drawFastVLine(4,2,2,0xFFFF);
    display.drawFastVLine(5,4,2,0xFFFF);
    display.drawFastVLine(6,2,2,0xFFFF);
    display.drawPixel(8,2,0xFFFF);
    display.drawFastVLine(8,4,2,0xFFFF);
    display.fillRect(10,1,6,6,display.color565(255,0,0));
    display.drawFastVLine(11,2,4,0x0000);
    display.drawPixel(12,2,0x0000);
    display.drawPixel(12,4,0x0000);
    display.drawPixel(14,2,0x0000);
    display.drawFastVLine(14,4,2,0x0000);
    break;
  }
  
}


void show05bitnumber(int number, int xlength, int ylength, int x, int y, uint16_t colorxy)
{
  String numStr = String(number);
  if(number<10){
   // showbitmap(bitdata05[(int)(0)],xlength,ylength, x, y, colorxy);
    showbitmap(bitdata05[(int)((String(numStr.charAt(0)).toInt() + 1) - 1)],xlength,ylength, x+4, y, colorxy);
  }else if(number<100){
    showbitmap(bitdata05[(int)((String(numStr.charAt(0)).toInt() + 1) - 1)],xlength,ylength, x, y, colorxy);
    showbitmap(bitdata05[(int)((String(numStr.charAt(1)).toInt() + 1) - 1)],xlength,ylength, x+4, y, colorxy);
  }
     }




void showbitnumber(int number, int xlength, int ylength, int x, int y, uint16_t colorxy)
{
  String numStr = String(number);
  if(number<10){
    showbitmap(bitdata10[(int)(0)],xlength,ylength, x, y, colorxy);
    showbitmap(bitdata10[(int)((String(numStr.charAt(0)).toInt() + 1) - 1)],xlength,ylength, x+6, y, colorxy);
  }else if(number<100){
    showbitmap(bitdata10[(int)((String(numStr.charAt(0)).toInt() + 1) - 1)],xlength,ylength, x, y, colorxy);
    showbitmap(bitdata10[(int)((String(numStr.charAt(1)).toInt() + 1) - 1)],xlength,ylength, x+6, y, colorxy);
  }else if(number<1000){
    showbitmap(bitdata10[(int)((String(numStr.charAt(0)).toInt() + 1) - 1)],xlength,ylength, x, y, colorxy);
    showbitmap(bitdata10[(int)((String(numStr.charAt(1)).toInt() + 1) - 1)],xlength,ylength, x+6, y, colorxy);
    showbitmap(bitdata10[(int)((String(numStr.charAt(2)).toInt() + 1) - 1)],xlength,ylength, x+12, y, colorxy);
  }else if(number<10000){
    showbitmap(bitdata10[(int)((String(numStr.charAt(0)).toInt() + 1) - 1)],xlength,ylength, x, y, colorxy);
    showbitmap(bitdata10[(int)((String(numStr.charAt(1)).toInt() + 1) - 1)],xlength,ylength, x+6, y, colorxy);
    showbitmap(bitdata10[(int)((String(numStr.charAt(2)).toInt() + 1) - 1)],xlength,ylength, x+12, y, colorxy);
    showbitmap(bitdata10[(int)((String(numStr.charAt(3)).toInt() + 1) - 1)],xlength,ylength, x+18, y, colorxy);
  }
     }


void show15bitnumber(int number, int xlength, int ylength, int x, int y, uint16_t colorxy){
  String numStr = String(number);
  if(number<10){
    showbitmap(bitdata15[(int)(0)],xlength,ylength, x, y, colorxy);
    showbitmap(bitdata15[(int)((String(numStr.charAt(0)).toInt() + 1) - 1)],xlength,ylength, x+11, y, colorxy);
  }else if(number<100){
    showbitmap(bitdata15[(int)((String(numStr.charAt(0)).toInt() + 1) - 1)],xlength,ylength, x, y, colorxy);
    showbitmap(bitdata15[(int)((String(numStr.charAt(1)).toInt() + 1) - 1)],xlength,ylength, x+11, y, colorxy);
  }
}





void show20bitnumber(int number, int xlength, int ylength, int x, int y, uint16_t colorxy){
  String numStr = String(number);
  if(number<10){
    showbitmap(bitdata20[(int)(0)],xlength,ylength, x, y, colorxy);
    showbitmap(bitdata20[(int)((String(numStr.charAt(0)).toInt() + 1) - 1)],xlength,ylength, x+12, y, colorxy);
  }else if(number<100){
    showbitmap(bitdata20[(int)((String(numStr.charAt(0)).toInt() + 1) - 1)],xlength,ylength, x, y, colorxy);
    showbitmap(bitdata20[(int)((String(numStr.charAt(1)).toInt() + 1) - 1)],xlength,ylength, x+12, y, colorxy);
  }
}




void showbigbitnumber(int number, int xlength, int ylength, int x, int y, uint16_t colorxy){
  String numStr = String(number);
  if(number<10){
    showbitmap(bitdata30[(int)(0)],xlength,ylength, x, y, colorxy);
    showbitmap(bitdata30[(int)((String(numStr.charAt(0)).toInt() + 1) - 1)],xlength,ylength, x+14, y, colorxy);
  }else if(number<100){
    showbitmap(bitdata30[(int)((String(numStr.charAt(0)).toInt() + 1) - 1)],xlength,ylength, x, y, colorxy);
    showbitmap(bitdata30[(int)((String(numStr.charAt(1)).toInt() + 1) - 1)],xlength,ylength, x+14, y, colorxy);
  }
}


void showbitmap(String bitrgbstr, int xlength, int ylength, int x, int y, uint16_t colorxy) {
  //Serial.println("bitrgbstr = " + bitrgbstr);
  for (int i = x; i < x+(xlength); i = i + (1)) {
    for(int j = y; j < y+(ylength); j = j + (1)){
      if (String(bitrgbstr.charAt(((j-y)*xlength+i-x))).toInt() != 0) {
        display.drawPixel(i,j,colorxy);
      } else {
        display.drawPixel(i,j,display.color565( 0, 0, 0));
      }
    }
  }
  }



//漸變顏色 數字
void ShowColorNumber(int number, int xlength, int ylength, int x, int y){
  String numStr = String(number);
  if(number<10){
    ShowColorMap(bitdata30[(int)(0)],xlength,ylength, x, y);
    ShowColorMap(bitdata30[(int)((String(numStr.charAt(0)).toInt() + 1) - 1)],xlength,ylength, x+14, y);
    }
  else if(number<100){
    ShowColorMap(bitdata30[(int)((String(numStr.charAt(0)).toInt() + 1) - 1)],xlength,ylength, x, y);
    ShowColorMap(bitdata30[(int)((String(numStr.charAt(1)).toInt() + 1) - 1)],xlength,ylength, x+14, y);
     }
}



//漸變顏色 bitmap基本功能
void ShowColorMap(String bitrgbstr, int xlength, int ylength, int x, int y) {
  //Serial.println("bitrgbstr = " + bitrgbstr);
  for (int i = x; i < x+(xlength); i = i + (1)) {
    for(int j = y; j < y+(ylength); j = j + (1)){
      if (String(bitrgbstr.charAt(((j-y)*xlength+i-x))).toInt() != 0) {
        display.drawPixelRGB565(i,j,Gradient(i,j));
      } else {
        display.drawPixel(i,j,display.color565( 0, 0, 0));
      }
    }
  }
}






//大冒號
void showbigColon(int x,int y,bool l,uint16_t colorxy){
    if(l){
      drawFastXLine(x,y,2,colorxy);
      drawFastXLine(x,y+1,2,colorxy);
     // display.drawPixel(x,y,colorxy);
    }else{
      //display.drawPixel(x,y,display.color565(0, 0, 0));
      drawFastXLine(x,y,2,display.color565(0, 0, 0));
      drawFastXLine(x,y+1,2,display.color565(0, 0, 0));
    }
}




//配置同步方法
void configSync(uint8_t num){
  DynamicJsonDocument myObject(512);
  myObject["mode"] = Mode;
  myObject["brightNess"] = brightnessNow;
  myObject["huea"] = hue;
  myObject["hued"] = hue;
  myObject["hueh"] = hueh;
  myObject["huem"] = huem;
  myObject["hues"] = hues;
  myObject["huew"] = huew;
  myObject["hueb"] = hueb;

  myObject["hueo"] = start_H;
  myObject["huep"] = start_M;
  myObject["hueq"] = end_H;
  myObject["huer"] = end_M;
  
  myObject["readstartH"] = read_start_H;
  myObject["readstartM"] = read_start_M;
  myObject["readendH"] = read_end_H;
  myObject["readendM"] = read_end_M;
  
  
  myObject["clockMode"] = clockMode;
  myObject["dateMode"] = dateMode;
  myObject["bFansMode"] = bFansMode;
  myObject["loopMode"] = loopMode;
  String output;
  serializeJson(myObject, output);
  Serial.println(output);
  Serial.println("");
  webSocket.sendTXT(num, output);
}


/*
//切换模式风格方法
void switchLoopMode(int oldMode, int newMode){
  switch(loopMode){
    case 1://上下切换
      for(int i=0;i<9;i++){
       display.clearDisplay();
       GlobalX = -i;
       switchMode(false,oldMode);

        //從X座標開始遞減
       GlobalX = 8-i;
       switchMode(false,newMode);
       //display();
       delay(16);
      }
      break;
      
    case 2://渐隐渐显
      for(int i=0;i<40;i++){
        display.clearDisplay();
        if(i<20){
          if(brightnessNow<20){
            if(brightnessNow>i){
              display.setBrightness(brightnessNow-i);
            }else{
              display.setBrightness(0);
            }
          }else{
            display.setBrightness(brightnessNow-brightnessNow/20*(i+1));
          }
          switchMode(false,oldMode);
        }else{
          if(brightnessNow<20){
            if(brightnessNow>(i-20)){
              display.setBrightness(i-20);
            }else{
              display.setBrightness(brightnessNow);
            }
          }else{
            display.setBrightness(brightnessNow/20*(i-19));
          }
          switchMode(false,newMode);
        }
        //display();
        delay(16);
      }
      break;    
  }
}


/*
//B站图案
void BPattern(int ani){
  String  pstr[3] = {
    "0100001000100100011111101000000110100101101001011000000101111110",
    "0100001000100100011111101000000110000001100000011000000101111110",
    "0100001000100100011111101000000110100101100000011000000101111110"};
  for (int i = 0; i < 8; i = i + (1)) {
    for(int j = 0; j < 8; j = j + (1)){
      if (String(pstr[ani].charAt((j*8+i))).toInt() != 0) {
        display.drawPixel(i+GlobalX,j+GlobalY,display.color565(0,191,255));
      } else {
        display.drawPixel(i+GlobalX,j+GlobalY,display.color565(0, 0, 0));
      }
    }
  }
}
*/



int hueLoop(int h){
  return h>360? h-360:h;
}



//获取天气实况
void weatherNow(String url){
  //if(loopChangeStatus) return;
  DynamicJsonDocument doc(1024);  //分配内存
  http.begin(wifiClient, url);    //请求网址

  int httpGet = http.GET();    //获得服务器状态码
  if(httpGet > 0)
  {
    Serial.printf("HTTPGET is %d",httpGet);    //打印服务器状态码
    if(httpGet == HTTP_CODE_OK)    //判断是否请求成功
    {
      String json = http.getString();    //获得响应体信息
      Serial.println(json);    //打印响应体信息
      deserializeJson(doc, json);    //Json解析
      String temp = doc["temperature"];
      String hum = doc["humidity"];
      String numtq = doc["weather"];
      hum_read = hum;
      temp_read = temp;
      tq_code = numtq;

      Serial.print(F("温度:"));
      Serial.println(temp_read);
      Serial.print(F("湿度:"));
      Serial.println(hum_read);
      Serial.print(F("天氣代碼:"));
      Serial.println(tq_code);
    }
    else
    {
      Serial.printf("ERROR1!!");
    }
  }
  else
  {
    Serial.printf("ERROR2!!");
  }
  http.end();
}




/*******************************************************
 * 函数名：handleSettingMessage
 * 描述  ：文字配置信息处理，在网页采用json格式发送配置信息，因此用json库进行处理
 * 参数  ：无
 * 返回值：无
 **********************************************************/
void handleSettingMessage()
{
    // size_t inputLength; (optional)

    StaticJsonDocument<512> doc;
    DeserializationError error = deserializeJson(doc, settingMessage);

    if (error) {
    Serial.print(F("解析Json() 格式錯誤:"));
    Serial.println(error.f_str());
    return;
    }

    //取得GIF檔名的JSON參數
   String gif = doc["GIFname"];  
   GIFname = gif ;

  //解析 漸變顏色參數RGBA RGB-B
   rA = doc["redA"];
   gA = doc["greenA"]; 
   bA = doc["blueA"]; 
   rB = doc["redB"];
   gB = doc["greenB"]; 
   bB = doc["blueB"]; 
  int random_color_check = doc["random"]; 
  if(random_color_check == 0)randomColor =false ;

   //解析JSON 文字  str轉char
     String input = doc["InputText"];
     strcpy(InputText_str,input.c_str());
    

     //解析JSON 文字  ssid 跟 pw
     String ssid = doc["SSID"];
     String pwd = doc["PASSWORD"];
     setssid = ssid;
     setpwd = pwd;
     Serial.print(F("WIFI: JSON"));
     Serial.println(setssid);
     Serial.println(setpwd);

}



/**************** EEPROM_writeAnything 寫入文字 功能**************************/
template <class T> int EEPROM_writeAnything(int ee, const T& value)
{
    const byte* p = (const byte*)(const void*)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
          EEPROM.write(ee++, *p++);
          EEPROM.commit();
    return i;
}

template <class T> int EEPROM_readAnything(int ee, T& value)
{
    byte* p = (byte*)(void*)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
          *p++ = EEPROM.read(ee++);
    return i;
}



//显示画板功能
void showDrawingBoard(bool implement) {
  MDNS.update();
  unsigned long t = millis();
  webSocket.loop();
  server.handleClient();
  if(implement){
    display.clearDisplay();
    Serial.println(F("畫板功能啟用"));
  }
 /* if ((t - lastTime) > 10 * 1000 | implement) {
    counter++;
    bool ping = (counter % 2);
    int i = webSocket.connectedClients(ping);
    Serial.printf("%d Connected websocket clients ping: %d\n", i, ping);
    lastTime = millis();
  }*/
}



//设置保存
void configSave(){
  Serial.println(F("按键保存配置"));
  if (EEPROM.read(EEPROM_GAIN) != EEPROM_CONFIRM) {  // not equal to EEPROM_CONFIRM
    EEPROM.write(EEPROM_GAIN, EEPROM_CONFIRM);  // write value EEPROM_CONFIRM to byte 256
  }
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

  EEPROM.write(EEPROM_START_H, start_H);
  EEPROM.write(EEPROM_START_M, start_M);
  EEPROM.write(EEPROM_END_H, end_H);
  EEPROM.write(EEPROM_END_M, end_M);

  EEPROM.write(EEPROM_LOOP_MODE, loopMode);

  EEPROM.commit();
  Serial.println(F("保存完畢"));


  /*   //文字移動特效
  int x = xres;
  for(int i=0;i<52;i++){
    display.clearDisplay();
    display.fillScreen(0);
    display.setCursor(x, 0);
    display.print(F("Saved"));
    display.setTextColor(display.color565(148,0,211));
    if(--x < -36) {
      x = display.width();
    }
    system_soft_wdt_feed();
    delay(70);
  }
*/
   display.clearDisplay();
   display.setCursor(20, 8);
   display.print(F("Saved"));
   delay(4000); 
  
  display.clearDisplay();
  switchMode(true,Mode);
}



void display_updater(){
  display.display(30);  //30-60 is usually fine
    }

void display_update_enable(bool is_enable){

  if (is_enable)
    display_ticker.attach(0.001, display_updater);
  else
    display_ticker.detach();
   }



   /****************************wifi 相關設定********************/

   
//設定wifi啟動
  void setwifi(){
  WiFi.mode(WIFI_STA);
  const char* ssid ;        
  const char* password; 
  dataType d;
  EEPROM_readAnything(90, d);
  ssid = d.testssid;
  password = d.testpass;
 Serial.print(F("SSID: "));
 Serial.println(ssid);
 Serial.print(F("Password: "));
 Serial.println(password);
  byte count = 0;

  WiFi.begin(ssid, password);
  
    //如果wifi 沒有連接則 啟動AP
    if (testWifi() == false) {
       
       Serial.println(F("啟動AP模式 "));
       setupAP();
        return;
      }
  
 
  }

  bool testWifi(void) {

  display.clearDisplay();
 // display.setCursor(20, 8);
//  display.print(F("WIFI"));
 // display.setCursor(8, 18);
 // display.print(F("Connect"));
 // delay(2000);
  int c = 0;
  Serial.println(F("等待 WIFI 連接..."));
  while ( c <= 30 ) {
  if (WiFi.status() == WL_CONNECTED) { 
  Serial.print(F("Local IP: "));
  Serial.println(WiFi.localIP());
  //ShowIP();
  delay(1000);
  
      return true; 
      }
    Serial.print(WiFi.status());  
    delay(1000);
    Serial.print(F("."));
     c++;
  }
  Serial.println(F(""));
  Serial.println(F("連接超時, 打開 AP 模式"));
  return false;
}


//設定WIFI為AP模式
  void setupAP() {
  WiFi.disconnect();
  delay(1000);
  const char* APssid = "數位時鐘192.168.4.1";        
  const char* APpassword = "";  
  WiFi.mode(WIFI_AP);
  WiFi.softAP(APssid, APpassword);    // IP is usually 192.168.4.1
  Serial.println();
  Serial.print(F("SoftAP IP: "));
  Serial.println(WiFi.softAPIP());
  
  display.clearDisplay();
  display.setCursor(18, 10);
  display.print(F("AP MODE "));
  delay(1000); 
  scroll_text(16,50,"192.168.4.1 /index.html",255,0,0);
  delay(4000);  
 }

   //保存ssid数据
  void save_ssid(){
  dataType d; // 宣告結構變數，放入資料
  strcpy(d.testssid, setssid.c_str());
  strcpy(d.testpass, setpwd.c_str());
  
  Serial.print(F("SSID:"));
  Serial.println(setssid);
  Serial.print(F("PWD:"));
  Serial.println(setpwd);
  EEPROM_writeAnything(90, d);
  Serial.println(F(" 寫入資料中"));
  Serial.println(F("---------------"));

  }


// 滾動文字     Y座標,延遲時間 ,"文字內容"  顏色RGB
  void scroll_text(uint8_t ypos, unsigned long scroll_delay, String text, uint8_t colorR, uint8_t colorG, uint8_t colorB)
{
    uint16_t text_length = text.length();
    display.setTextWrap(false);  // we don't wrap text so it scrolls nicely
    display.setTextSize(1);
    display.setRotation(0);
    display.setTextColor(display.color565(colorR,colorG,colorB));

    // Asuming 5 pixel average character width
    for (int xpos=matrix_width; xpos>-(matrix_width+text_length*5); xpos--)
    {
      display.setTextColor(display.color565(colorR,colorG,colorB));
      display.clearDisplay();
      display.setCursor(xpos,ypos);
      display.println(text);
      delay(scroll_delay);
      yield();

      // This might smooth the transition a bit if we go slow
      // display.setTextColor(display.color565(colorR/4,colorG/4,colorB/4));
      // display.setCursor(xpos-1,ypos);
      // display.println(text);

      delay(scroll_delay/5);
      yield();

    }
}



 void ShowIP(){

  display.clearDisplay();
  
  String myip = WiFi.localIP().toString().c_str();
  myip = myip+" /index.html";
  scroll_text(10,50,myip,255,0,0);
  
}

//定時顯示/關閉 時鐘模式
void ShowClock (){

    time(&now);
    localtime_r(&now, &tm);
    H = tm.tm_hour;
    M = tm.tm_min;

    if(end_H != end2_H || end_M != end2_M )runonce =true;

    if(runonce == true){
      if(H == end_H && M == end_M ){
             Serial.println(F(" 關閉時鐘"));
             Mode = 99;
             clearall();
             runonce = false;
             }}

      if(runonce == false){       
         if(H == start_H && M == start_M){
             Serial.println(F(" 開啟時鐘")); 
             Mode = EEPROM.read(EEPROM_MODE);
             runonce = true;
             }}   
   }







/*******************************************************
* 函数名：SetEmojiXY
* 描述  ：依据数组设置Emoji图片到指定坐标
* 参数  ：
*        @x  图片位于第x行 1~10
*        @y  图片位于第y列 1~10
* 返回值：无
**********************************************************/
void FlashEmojiXY(int emoji_y, int emoji_x, int x, int y) // 1~10
{
    int i;
    if (emoji_y <= 5)
    {
        for (i = 0; i < 192; i++)
        {
            curremoji[i] = pgm_read_byte(gImage_emojis1+(192 * (10 * (emoji_y - 1) + (emoji_x - 1)) + i));
        }
    }
    else if (emoji_y <= 10)
    {
        for (i = 0; i < 192; i++)
        {
            curremoji[i] = pgm_read_byte(gImage_emojis2+(192 * (10 * (emoji_y - 6) + (emoji_x - 1)) + i));
        }
    }
    
    DrawPic(curremoji,true,x+GlobalX,y+GlobalY,8,8);
    delay(500);
    display.fillRect(x,y,x+8,y+8,display.color565(0,0,0));
    DrawPic(curremoji,true,x+GlobalX,y+GlobalY,8,8);
    delay(500);
    display.fillRect(x,y,x+8,y+8,display.color565(0,0,0));
    DrawPic(curremoji,true,x+GlobalX,y+GlobalY,8,8);
    delay(500);
    display.fillRect(x,y,x+8,y+8,display.color565(0,0,0));
}


/*
  void trashcar(){

    time(&now);
    localtime_r(&now, &tm);
    H = tm.tm_hour;
    M = tm.tm_min;
    S = tm.tm_sec;
    D = tm.tm_wday;
 

   if (D!=0 && D!=3 && H>17 && M>40){
       
       weatherNow("http://114.33.152.14:8080/weather/trashcar.php");
       
          if(location.toInt() == 1){    

            Serial.println(F("開始播放垃圾車動畫"));
            display.clearDisplay();
            String tempGIFname = GIFname ;
              GIFname = "trashcar";
              playGif(); 
              GIFname = tempGIFname ;
             } 
          }
        }


        */
