
void InitServer(){
  // start MDNS
  if (MDNS.begin(MDNS_NAME)) {
    Serial.println(F("MDNS 服務開啟"));
  }
  // start web server
  // handle index
 // server.on("/", []() {
 // });
  
  server.begin();

  // start webSocket server
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
  // Add service to MDNS
  MDNS.addService("http", "tcp", 80);
  MDNS.addService("ws", "tcp", 81);
}

void WebServer_run(){
  MDNS.update();
  webSocket.loop();
  server.handleClient();  
}

/*******************************************************
 * 函数名：webSocketEvent
 * 描述  ：处理网页webSocket数据，事件回调函数
 * 参数  ：
 *         @num 设备序号
 *         @type 消息类型
 *         @payload 消息内容
 *         @length 消息长度
 * 返回值：无
 **********************************************************/
void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length)
{
    switch (type)
    {
    case WStype_DISCONNECTED:
        Serial.printf("[%u] Disconnected!\n", num);
        break;
    case WStype_CONNECTED:
    {
         drawFastXLine(0,0,64,display.color565(0,255,0));
        delay(2000);
        IPAddress ip = webSocket.remoteIP(num);
        Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);
        webSocket.sendTXT(num, "Connected"); // send message to client
        configSync(num); // 配置同步
    }
    break;
    case WStype_TEXT:
    {
        Serial.printf("[%u] get Text: %s\n", num, payload);
        if(((char *)payload)[0] == '{'||((char *)payload)[0] == 's') 
        {
          strcpy(settingMessage,(char *)payload);
          if (settingMessage[0] == 's')//亮度
          {
            uint8_t bt= ((int)settingMessage[1]-48)*100+((int)settingMessage[2]-48)*10+(int)settingMessage[3]-48;
            // if(bt>=0&&bt<=255) brightnessNow = bt;　
             display.setBrightness(bt);
           
          }

          //收到{ 開頭的符號 代表要解析JSON
          else if(settingMessage[0] == '{')
          {
             handleSettingMessage();
          }
        }
        else if (((char *)payload)[0] != 'C') 
        {
          strcpy(socketMessage, (char *)payload);
          if (socketMessage[0] == 'p')
          {
              display.clearDisplay();
              pic_x = ((int)socketMessage[2]) - 47;
              pic_y = ((int)socketMessage[1]) - 47;
              SetEmojiXY(pic_x, pic_y, 0 ,10);
             
          }

          else if (socketMessage[0] == 'U')
          {
            BTN_VALUE = 1;
          }
          else if (socketMessage[0] == 'D')
          {
            BTN_VALUE = 2;

          }
          else if (socketMessage[0] == 'L')
          {
            BTN_VALUE = 3;
          }
          else if (socketMessage[0] == 'R')
          {
            BTN_VALUE = 4;;
          }
          else if (socketMessage[0] == 'S')
          {
            BTN_VALUE = 5;
            Serial.println(F("開始"));
          }
          else if (socketMessage[0] == 'P')  //暫停專用鍵
          {
            display.clearDisplay();
            BTN_VALUE = 6;
            
            if(GameMode==99){ GameMode = ModeNow;
                          toTargetGameMode(GameMode);}           
            
           else if(GameMode!=99){   ModeNow = GameMode;
                            GameMode = 99;   }

          
            Serial.print(F("Mode:"));
            Serial.println(Mode);
            Serial.print(F("ModeNow:"));
            Serial.println(ModeNow);
          }
          else if (socketMessage[0] == 'H')  
          {      
            Serial.println(F("啟動播放GIF功能"));
            playGif();
          }
          else if (socketMessage[0] == 'J')
          {      
             Serial.println(F("固定播放-GIF"));
             GifRandom = false ;
          }
          
          else if (socketMessage[0] == 'V')
          {      
          Serial.println(F("GIF隨機播放"));
          GifRandom = true ;
          }
          
          else if (socketMessage[0] == 'K')
          {      
            Serial.println(F("清除畫面clearall"));
              clearall();         
          }

          else if (socketMessage[0] == 'Z')
          {      
            Serial.println(F("漸變顏色隨機撥放"));
            randomColor = true ;         
          }          

          else if (socketMessage[0] == 'W')  //WIFI設定按鈕
          {      
          save_ssid();
          display.clearDisplay();
          display.setCursor(20, 8);
          display.print(F("Saved"));
          delay(1000); 
          display.setCursor(14, 18);
          display.print(F("RE-BOOT"));
          delay(4000);       
          ESP.reset();
          }


          
          else if (socketMessage[0] == 'F')
          {

          }
          else if (socketMessage[0] == 't')//时钟风格
          {
              int cm = (int)socketMessage[1]-48;
              display.clearDisplay();
             // clockMode = cm<5? cm:1;
              clockMode = cm;
              Serial.print(F("clockMode:"));
              Serial.println(clockMode);
          }
          else if (socketMessage[0] == 'd')//日期风格
          {
              int dm = (int)socketMessage[1]-48;
              display.clearDisplay();
              dateMode = dm<3? dm:1;
          }
          else if (socketMessage[0] == 'T')//切换Tetris 模式
          {
              int dm = (int)socketMessage[1]-48;
       
              if (gameStatus == 0){ T_PlayMode = dm; }
                      Serial.println(F("Tetris 模式:")); 
                      Serial.println(T_PlayMode);
    
                          
          }
          else if (socketMessage[0] == 'b')
          {

          }
          else if(socketMessage[0] == 'm')//模式变更
          {
            if(socketMessage[1] == 'c'){//下一个模式
             // nextMode();
              //configSync(num); // 配置同步
            }else{
              display.clearDisplay(); 
              GameMode = 0;
              int m = (int)socketMessage[1]-48;
              toTargetMode(m);
            } 
          }else if(socketMessage[0] == 'h'){//颜色设置
                int hh= ((int)socketMessage[2]-48)*100+((int)socketMessage[3]-48)*10+(int)socketMessage[4]-48;
                Serial.print(F("传入色值："));
                Serial.println(hh);
                if(hh>=0&&hh<=360){  
                    switch (socketMessage[1])
                    {
                    case 'a':
                        hue = hh;
                        hueh = hh;
                        huem = hh;
                        hues = hh;
                        huew = hh;
                        hueb = hh;
                        break;
                    case 'd':
                        hue = hh;
                        break;
                    case 'h':
                        hueh = hh;
                        break;
                    case 'm':
                        huem = hh;
                        break;
                    case 's':
                        hues = hh;
                        break;   
                    case 'w':
                        huew = hh;
                        break;   
                    case 'o':   
                        start_H = hh;
                        break;
                        
                    case 'p':
                        start_M = hh;
                        break;
                        
                    case 'q':
                        end_H = hh;
                        break;
                        
                    case 'r':
                        end_M = hh;
                        break;

                    case 'g':
                        gifcount = hh;
                        break; 

                    case 'n':
                        random_gif_no = hh;
                        break;                         

                    case 'u':
                        random_min = hh;
                      //  Serial.print(F("UU值："));
                       // Serial.println(random_min);
                        break;      
                                                                                      
                    default:
                        break;
                    }
                }
          }else if(socketMessage[0] == 'c'){
              configSave();
          }
          
          else if(socketMessage[0] == 'g'){
              display.clearDisplay(); 
              Mode = 99;
              int m = (int)socketMessage[1]-48;
              toTargetGameMode(m);
          }
          
          
          else if(socketMessage[0] == 'o'){
              if(Mode == DRAW_MODE){
              Serial.println(F("模式正确"));
              for (uint8_t y = 0; y < yres; y++) {   
                for (uint8_t x = 0; x < xres; x++) {  
                  uint8_t r = payload[y*xres*3+x*3+1]*2;
                  uint8_t g = payload[y*xres*3+x*3+2]*2;
                  uint8_t b = payload[y*xres*3+x*3+3]*2;
                  display.drawPixel(x,y,display.color565(r,g,b));
                }
              }
              //Serial.printf("(%u, %u) color: %u, %u, %u\n", x, y, r, g, b);
              //display();
            }else{
              Serial.println(F("模式错误"));
            }   
          }  // end draw mode
          
        }
    }
    break;
    }
}
