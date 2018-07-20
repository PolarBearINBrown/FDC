#ifndef __MYIIC2_H
#define __MYIIC2_H
#include "sys.h"

#if defined MYIIC2_C
#define SDA2_IN()  {GPIOB->CRL&=0X0FFFFFFF;GPIOB->CRL|=(u32)8<<28;}
#define SDA2_OUT() {GPIOB->CRL&=0X0FFFFFFF;GPIOB->CRL|=(u32)3<<28;}

//IO��������	 
#define IIC2_SCL    PBout(6) //SCL
#define IIC2_SDA    PBout(7) //SDA	 
#define READ2_SDA   PBin(7)  //����SDA 

//IIC���в�������
void IIC2_Init(void);                //��ʼ��IIC��IO��				 
void IIC2_Start(void);				//����IIC��ʼ�ź�
void IIC2_Stop(void);	  			//����IICֹͣ�ź�
void IIC2_Send_Byte(u8 txd);			//IIC����һ���ֽ�
u8 IIC2_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
u8 IIC2_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void IIC2_Ack(void);					//IIC����ACK�ź�
void IIC2_NAck(void);				//IIC������ACK�ź�
void ADS2_delay(void);
void IIC2_Write_One_Byte(u8 daddr,u8 addr,u8 data);
u8 IIC2_Read_One_Byte(u8 daddr,u8 addr);	 
//I2C�����ݼĴ���
unsigned int ReadDataCfgReg2(u8 index,u8 firstAddress,u8 SecondAddress);
#else
extern int Velocity;                       //������*1000
extern u32 tempVel;
//IIC���в�������
extern void IIC2_Init(void);                //��ʼ��IIC��IO��				 
extern void IIC2_Start(void);				//����IIC��ʼ�ź�
extern void IIC2_Stop(void);	  			//����IICֹͣ�ź�
extern void IIC2_Send_Byte(u8 txd);			//IIC����һ���ֽ�
extern u8 IIC2_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
extern u8 IIC2_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
extern void IIC2_Ack(void);					//IIC����ACK�ź�
extern void IIC2_NAck(void);				//IIC������ACK�ź�
extern void ADS2_delay(void) ;
extern void IIC2_Write_One_Byte(u8 daddr,u8 addr,u8 data);
extern u8 IIC2_Read_One_Byte(u8 daddr,u8 addr);	 
//I2C�����ݼĴ���  
extern unsigned int ReadDataCfgReg2(u8 index,u8 firstAddress,u8 SecondAddress);
#endif
#endif
















