#ifndef __MYIIC2_H
#define __MYIIC2_H
#include "sys.h"

#if defined MYIIC2_C
#define SDA2_IN()  {GPIOB->CRL&=0X0FFFFFFF;GPIOB->CRL|=(u32)8<<28;}
#define SDA2_OUT() {GPIOB->CRL&=0X0FFFFFFF;GPIOB->CRL|=(u32)3<<28;}

//IO操作函数	 
#define IIC2_SCL    PBout(6) //SCL
#define IIC2_SDA    PBout(7) //SDA	 
#define READ2_SDA   PBin(7)  //输入SDA 

//IIC所有操作函数
void IIC2_Init(void);                //初始化IIC的IO口				 
void IIC2_Start(void);				//发送IIC开始信号
void IIC2_Stop(void);	  			//发送IIC停止信号
void IIC2_Send_Byte(u8 txd);			//IIC发送一个字节
u8 IIC2_Read_Byte(unsigned char ack);//IIC读取一个字节
u8 IIC2_Wait_Ack(void); 				//IIC等待ACK信号
void IIC2_Ack(void);					//IIC发送ACK信号
void IIC2_NAck(void);				//IIC不发送ACK信号
void ADS2_delay(void);
void IIC2_Write_One_Byte(u8 daddr,u8 addr,u8 data);
u8 IIC2_Read_One_Byte(u8 daddr,u8 addr);	 
//I2C读数据寄存器
unsigned int ReadDataCfgReg2(u8 index,u8 firstAddress,u8 SecondAddress);
#else
extern int Velocity;                       //倾角输出*1000
extern u32 tempVel;
//IIC所有操作函数
extern void IIC2_Init(void);                //初始化IIC的IO口				 
extern void IIC2_Start(void);				//发送IIC开始信号
extern void IIC2_Stop(void);	  			//发送IIC停止信号
extern void IIC2_Send_Byte(u8 txd);			//IIC发送一个字节
extern u8 IIC2_Read_Byte(unsigned char ack);//IIC读取一个字节
extern u8 IIC2_Wait_Ack(void); 				//IIC等待ACK信号
extern void IIC2_Ack(void);					//IIC发送ACK信号
extern void IIC2_NAck(void);				//IIC不发送ACK信号
extern void ADS2_delay(void) ;
extern void IIC2_Write_One_Byte(u8 daddr,u8 addr,u8 data);
extern u8 IIC2_Read_One_Byte(u8 daddr,u8 addr);	 
//I2C读数据寄存器  
extern unsigned int ReadDataCfgReg2(u8 index,u8 firstAddress,u8 SecondAddress);
#endif
#endif
















