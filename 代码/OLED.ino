#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
void OLED()   {                
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)

  display.clearDisplay(); //清屏

  display.setTextSize(1);             //设置字体大小
  display.setTextColor(WHITE);        //设置字体颜色白色
  display.setCursor(0,0);             //设置字体的起始位置
  display.println("Hello, world!");   //输出字符并换行
  display.println("12345");
  display.setTextSize(2);             //设置字体大小
  display.setTextColor(WHITE);        //设置字体白色
  display.print("0x");                //输出字符
  display.println(0xDEADBEEF, HEX);   //输出为ASCII编码的十六进制
  
  display.display();                  //把缓存的都显示
}
