#include <MsTimer2.h>     //定时器库的头文件
float Med_Angle=1;      // 机械中值，能使得小车真正平衡住的角度 
float current_angle;       //存储陀螺仪数据
float current_gyro;
int Vertical_pwm,Velocity;
int pushButton = 35;
int motorL=0;
int motorR=0;
int pwm_out;
int V_L,V_R;
int tick = 0; //计数值

//左电机端口定义
#define MotorLpin1   22 //控制位3
#define MotorLpin2   23 //控制位4
#define MotorLpwm    4  //使能调速 ENB
#define MotorLcountA 2 //编码器A 中断号：0
#define MotorLcountB 3 //编码器B 中断号：1
 
//右电机端口定义
#define MotorRpin1   24 //控制位1
#define MotorRpin2   25 //控制位2
#define MotorRpwm    5  //使能调速 ENA
#define MotorRcountA 20 //编码器A 中断号：3
#define MotorRcountB 21 //编码器B 中断号：2
void setup()
{
  Serial.begin(9600);
  Serial1.begin(115200); 
  Motor_Init();//电机端口初始化
  pinMode(pushButton, INPUT_PULLUP);
//  MsTimer2::set(5, MPU); //设置中断，每5ms进入一次中断服务程序 MPU()
//  MsTimer2::start(); //开始计时
}
void loop()
{
  int buttonState = digitalRead(pushButton);
  Serial.println(buttonState);
  if(buttonState==0)
  {
    while(1)
    {
//    MsTimer2::set(5, MPU); //设置中断，每5ms进入一次中断服务程序 MPU()
//    MsTimer2::start(); //开始计时
   MPU();
   Read_Moto_V();//读取脉冲计算速度
   Velocity = velocity(V_L,V_R);                                          //速度环
   Vertical_pwm = balance_UP(current_angle,Velocity+Med_Angle,current_gyro);    //直立环
   pwm_out = Vertical_pwm;
   Set_Pwm(pwm_out);
   Serial.println(pwm_out);
    }
  }
}
