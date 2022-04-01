
float Vertical_Kp=8,Vertical_Kd=0.3;     // 直立环Kp、Kd  8、0.3
float velocity_KP=0,velocity_KI=0;         //速度环KP、KI

int balance_UP(float current_angle,float Med_Angle,float current_gyro)
{  
   float Bias;//角度误差
   int Vertical_pwm;//直立环计算出来的电机控制pwm
   Bias=current_angle-Med_Angle;                   
   //求出平衡的角度中值和机械相关
   Vertical_pwm=Vertical_Kp*Bias+Vertical_Kd*current_gyro;  
   //计算平衡控制的电机PWM  PD控制   kp是P系数 kd是D系数 
   
  //PWM 限幅度  Arduino的PWM 最高为255  限制在250
  if(Vertical_pwm<-150)
    Vertical_pwm=-150;     
  if(Vertical_pwm>150)
    Vertical_pwm=150;  

   return Vertical_pwm;
}

/*入口参数：电机编码器的值
返回值：速度控制PWM*/
int velocity(int V_L,int V_R)
{  
    float a=0.7;
    static float Velocity,Encoder_error,Encoder,Movement,Encoder_error_last;
    static float Encoder_Integral;
   //=============速度PI控制器=======================//  
    Encoder_error =(V_L+V_R)-0;      
    //===获取最新速度偏差==测量速度（左右编码器之和）-目标速度（此处为零） 
    Encoder =(1-a)*Encoder_error + a*Encoder_error_last;          //===一阶低通滤波器       
    Encoder_error_last=Encoder_error;   //===一阶低通滤波器    
    Encoder_Integral +=Encoder; //===积分出位移 积分时间：10ms
    if(Encoder_Integral>10000)    Encoder_Integral=10000;   
    //===积分限幅
    if(Encoder_Integral<-10000)    Encoder_Integral=-10000;   
    //===积分限幅  
    Velocity=Encoder*velocity_KP+Encoder_Integral*velocity_KI;  
    //===速度控制  
//    if(pitch<-40||pitch>40)   Encoder_Integral=0;   
//    //===电机关闭后清除积分
    return Velocity;
}
