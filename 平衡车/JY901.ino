#include <JY901.h>  //调用陀螺仪库
#include <Wire.h>
//陀螺仪读值
void MPU() 
{
  while (Serial1.available()) {
    JY901.CopeSerialData(Serial1.read()); //Call JY901 data cope function
//   delay(2);
  }
  //输出角度
  Serial.print("Angle:");
  Serial.print((float)JY901.stcAngle.Angle[1]/32768*180);
  current_angle = (float)JY901.stcAngle.Angle[1]/32768*180;
//  if(current_angle>Med_Angle+30||current_angle<Med_Angle-30)
//  current_angle = 0;
  //输出角加速度
  Serial.print("Gyro:");
  Serial.println((float)JY901.stcGyro.w[1]/32768*2000);
  current_gyro = (float)JY901.stcGyro.w[1]/32768*2000;
}
