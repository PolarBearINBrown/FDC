#define MYIIC2_C
#include "myiic2.h"
#include "delay.h"
 
//初始化IIC
void IIC2_Init(void)
{					     
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOB, ENABLE );	
	   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_Out_PP ;   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_SetBits(GPIOB,GPIO_Pin_6|GPIO_Pin_7); 	// 输出高
}

//I2C延时
void ADS2_delay(void) 
{
  unsigned char i;
  for(i=0;i<40;i++); 
}

//I2C时钟
void ADS2_clock(void)  
{
  IIC2_SCL=1;//SCL=1
  ADS2_delay(); 
  IIC2_SCL=0;//SCL=0 
  ADS2_delay();   
}
//产生IIC起始信号
void IIC2_Start(void)
{
	SDA2_OUT();     //sda线输出
	IIC2_SDA=1;	  	  
	IIC2_SCL=1;
	ADS2_delay(); 
 	IIC2_SDA=0;//START:when CLK is high,DATA change form high to low 
	ADS2_delay();
  ADS2_delay(); 
	IIC2_SCL=0;//钳住I2C总线，准备发送或接收数据 
}	  
//产生IIC停止信号
void IIC2_Stop(void)
{
	SDA2_OUT();//sda线输出
	IIC2_SCL=1;
	IIC2_SDA=0;//STOP:when CLK is high DATA change form low to high
 	ADS2_delay();
// 	IIC_SCL=1; 
	IIC2_SDA=1;//发送I2C总线结束信号
	ADS2_delay();							   	
}
//等待应答信号到来
//返回值：1，接收应答失败
//        0，接收应答成功
u8 IIC2_Wait_Ack(void)
{
	u8 ucErrTime=0;
	SDA2_IN();      //SDA设置为输入  
	IIC2_SDA=1;ADS2_delay();	   
	IIC2_SCL=1;ADS2_delay();	 
	while(READ2_SDA)
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			IIC2_Stop();
			return 1;
		}
	}
	IIC2_SCL=0;//时钟输出0 	   
	return 0;  
}

//产生ACK应答
void IIC2_Ack(void)
{
	ADS2_delay();
// 	IIC_SCL=0;
	SDA2_OUT();
	IIC2_SDA=0;
	ADS2_delay();
	IIC2_SCL=1;
	ADS2_delay();
	IIC2_SCL=0;
	ADS2_delay();
}
//不产生ACK应答
void IIC2_NAck(void)
{
	IIC2_SCL=0;
	SDA2_OUT();
	IIC2_SDA=1;
	delay_us(2);
	IIC2_SCL=1;
	delay_us(2);
	IIC2_SCL=0;
}					 				     
//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答			  
void IIC2_Send_Byte(u8 txd)
{                        
    u8 t;   
	SDA2_OUT(); 	    
    IIC2_SCL=0;//拉低时钟开始数据传输
    for(t=0;t<8;t++)
    {              
        //IIC_SDA=(txd&0x80)>>7;
		if((txd&0x80))
			IIC2_SDA=1;
		else
			IIC2_SDA=0;
		//ADS_delay();    //对TEA5767这三个延时都是必须的
		ADS2_clock();
		txd<<=1; 		
    }	 
		//ADS_delay();
} 	    
//读1个字节，ack=1时，发送ACK，ack=0，发送nACK   
u8 IIC2_Read_Byte(unsigned char ack)
{
	unsigned char i,adsdata;
  SDA2_IN();//SDA设置为输入
  adsdata=0; 
	 for(i=0;i<8;i++) 
	 {
		adsdata <<=1; 
		if(READ2_SDA==1) 
		 adsdata |= 0x01;
		else
		 adsdata |= 0x00;
		//ADS_delay();
		ADS2_clock();
	 }  
  return(adsdata); 
}


//I2C读数据寄存器0x02 两个字节 高字节在前  
//
unsigned int ReadDataCfgReg2(u8 index,u8 firstAddress,u8 SecondAddress)  
{ 
  unsigned int temp;
  u8 result[4];
  IIC2_Start(); 
  IIC2_Send_Byte(0x2A);
  IIC2_Wait_Ack();
  ADS2_delay();
  result[0]=(IIC2_Read_Byte(1)&firstAddress)*0x100;//高字节 高四位清除
  IIC2_Ack(); 
  result[1]=(IIC2_Read_Byte(1));          //temp=高字节+低字节
	IIC2_Ack(); 
	if(index==1)
	{
		result[2]=(IIC2_Read_Byte(1)&SecondAddress);//
		IIC2_Ack(); 
		result[3]=(IIC2_Read_Byte(1));          //temp=高字节+低字节
		IIC2_Ack(); 
	}
  
	
  IIC2_Stop();
  temp = (int)(((result[0] << 24) | (result[1] << 16) | (result[2] << 8) | (result[3] & 0xff)));  
  return(temp); 
     
}
