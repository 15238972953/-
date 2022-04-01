////左电机端口定义
//#define MotorLpin1   22 //控制位3
//#define MotorLpin2   23 //控制位4
//#define MotorLpwm    4  //使能调速 ENB
//#define MotorLcountA 2 //编码器A 中断号：0
//#define MotorLcountB 3 //编码器B 中断号：1
// 
////右电机端口定义
//#define MotorRpin1   24 //控制位1
//#define MotorRpin2   25 //控制位2
//#define MotorRpwm    5  //使能调速 ENA
//#define MotorRcountA 20 //编码器A 中断号：3
//#define MotorRcountB 21 //编码器B 中断号：2

void Motor_Init(void){
  //左电机
  pinMode(MotorLpin1,OUTPUT);  //驱动芯片控制引脚
  pinMode(MotorLpin2,OUTPUT);  //驱动芯片控制引脚
  pinMode(MotorLpwm,OUTPUT);   //驱动芯片控制引脚，PWM调速
  pinMode(MotorLcountA,INPUT); //左轮编码器A引脚
  pinMode(MotorLcountB,INPUT); //左轮编码器B引脚
  
  //右电机
  pinMode(MotorRpin1,OUTPUT);  //驱动芯片控制引脚
  pinMode(MotorRpin2,OUTPUT);  //驱动芯片控制引脚
  pinMode(MotorRpwm,OUTPUT);   //驱动芯片控制引脚，PWM调速
  pinMode(MotorRcountA,INPUT); //右轮编码器A引脚
  pinMode(MotorRcountB,INPUT); //右轮编码器B引脚
}
void Set_Pwm(int pwm_out){
 
  if(pwm_out>0){
  //左电机
  digitalWrite(MotorLpin1,HIGH);
  digitalWrite(MotorLpin2,LOW);
  analogWrite(MotorLpwm,pwm_out);
  //右电机
  digitalWrite(MotorRpin1,LOW);
  digitalWrite(MotorRpin2,HIGH);
  analogWrite(MotorRpwm,pwm_out);
  }
  else if(Vertical_pwm<=0){
  //后退模式
  //左电机
  digitalWrite(MotorLpin1,LOW);
  digitalWrite(MotorLpin2,HIGH);
  analogWrite(MotorLpwm,-pwm_out);
  
  //右电机
  digitalWrite(MotorRpin1,HIGH);
  digitalWrite(MotorRpin2,LOW);
  analogWrite(MotorRpwm,-pwm_out);
  }
}
