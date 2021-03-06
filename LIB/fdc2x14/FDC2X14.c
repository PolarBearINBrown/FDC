#define _FDC2X14_C
#include "sys.h"		    
#include "FDC2X14.h"	
#include "myiic.h"
#include "myiic2.h"
#include "delay.h"

#define FDC2X14_Address 0x2A
#define FDC2X14_W FDC2X14_Address<<1
#define FDC2X14_R (FDC2X14_Address<<1)|1
#define DATA_CH0 0x00
#define DATA_LSB_CH0 0x01
#define DATA_CH1 0x02
#define DATA_LSB_CH1 0x03
#define DATA_CH2 0x04
#define DATA_LSB_CH2 0x05
#define DATA_CH3 0x06
#define DATA_LSB_CH3 0x07
#define RCOUNT_CH0 0x08
#define RCOUNT_CH1 0x09
#define RCOUNT_CH2 0x0A
#define RCOUNT_CH3 0x0B
#define OFFSET_CH0 0x0C
#define OFFSET_CH1 0x0D
#define OFFSET_CH2 0x0E
#define OFFSET_CH3 0x0F
#define SETTLECOUNT_CH0 0x10
#define SETTLECOUNT_CH1 0x11
#define SETTLECOUNT_CH2 0x12
#define SETTLECOUNT_CH3 0x13
#define CLOCK_DIVIDERS_C_CH0 0x14
#define CLOCK_DIVIDERS_C_CH1 0x15
#define CLOCK_DIVIDERS_C_CH2 0x16
#define CLOCK_DIVIDERS_C_CH3 0x17
#define STATUS 0x18
#define ERROR_CONFIG 0x19
#define CONFIG 0x1A
#define MUX_CONFIG 0x1B
#define RESET_DEV 0x1C
#define DRIVE_CURRENT_CH0 0x1E
#define DRIVE_CURRENT_CH1 0x1F
#define DRIVE_CURRENT_CH2 0x20
#define DRIVE_CURRENT_CH3 0x21
#define MANUFACTURER_ID 0x7E
#define DEVICE_ID 0x7F

int Error[8];

void WriteRegfdc2214(unsigned char add,unsigned int value)
{
	IIC_Start();
	IIC_Send_Byte(FDC2X14_W);	 //ADDR=0时，地址0X2A<<1+0=0X54
	IIC_Wait_Ack();          	//等应答
	IIC_Send_Byte(add);      	//写地址
	IIC_Wait_Ack();          	//等应答
	IIC_Send_Byte(value>>8); 	//写高8位
	IIC_Wait_Ack();
	IIC_Send_Byte(value&0xff);	//写低8位
	IIC_Wait_Ack();
	IIC_Stop();               	//产生一个停止条件
	delay_ms(10);
}

void WriteRegfdc2214_2(unsigned char add,unsigned int value)
{
	IIC2_Start();
	IIC2_Send_Byte(FDC2X14_W);	 //ADDR=0时，地址0X2A<<1+0=0X54
	IIC2_Wait_Ack();          	//等应答
	IIC2_Send_Byte(add);      	//写地址
	IIC2_Wait_Ack();          	//等应答
	IIC2_Send_Byte(value>>8); 	//写高8位
	IIC2_Wait_Ack();
	IIC2_Send_Byte(value&0xff);	//写低8位
	IIC2_Wait_Ack();
	IIC2_Stop();               	//产生一个停止条件
	delay_ms(10);
}

int ReadFDC2X14(u8 firstAddress,u8 secondAddress)
{
	unsigned int temp;
	u8 result[4];
	IIC_Start(); 
	IIC_Send_Byte(FDC2X14_W);
	IIC_Wait_Ack();
	ADS_delay();
	IIC_Send_Byte(firstAddress);
	IIC_Wait_Ack();
	ADS_delay();
	IIC_Stop();
	ADS_delay();
	
	IIC_Start();
	IIC_Send_Byte(FDC2X14_R);
	IIC_Wait_Ack();
	ADS_delay();
	result[0]=IIC_Read_Byte(1);//高字节 高四位清除
	result[0]=result[0]<<4;
	result[0]=result[0]>>4;
	IIC_Ack(); 
	ADS_delay();
	result[1]=IIC_Read_Byte(1);          //temp=高字节+低字节
	IIC_Ack(); 
	IIC_Stop();
	ADS_delay();
	
	IIC_Start(); 
	IIC_Send_Byte(FDC2X14_W);
	IIC_Wait_Ack();
	ADS_delay();
	IIC_Send_Byte(secondAddress);
	IIC_Wait_Ack();
	ADS_delay();
	IIC_Stop();
	ADS_delay();
	
	IIC_Start();
	IIC_Send_Byte(FDC2X14_R);
	IIC_Wait_Ack();
	ADS_delay();
	result[2]=IIC_Read_Byte(1);//高字节 高四位清除
	IIC_Ack(); 
	ADS_delay();
	result[3]=IIC_Read_Byte(1);          //temp=高字节+低字节
	IIC_Ack(); 
	IIC_Stop();
	ADS_delay();
	
	temp=(int)(((result[0]<< 24)|(result[1] << 16)|(result[2] << 8)|(result[3] & 0xff)));  
	return(temp); 
}

int ReadFDC2X14_2(u8 firstAddress,u8 secondAddress)
{
	unsigned int temp;
	u8 result[4];
	IIC2_Start(); 
	IIC2_Send_Byte(FDC2X14_W);
	IIC2_Wait_Ack();
	ADS2_delay();
	IIC2_Send_Byte(firstAddress);
	IIC2_Wait_Ack();
	ADS2_delay();
	IIC2_Stop();
	ADS2_delay();
	
	IIC2_Start();
	IIC2_Send_Byte(FDC2X14_R);
	IIC2_Wait_Ack();
	ADS2_delay();
	result[0]=IIC2_Read_Byte(1);//高字节 高四位清除
	result[0]=result[0]<<4;
	result[0]=result[0]>>4;
	IIC2_Ack(); 
	ADS2_delay();
	result[1]=IIC2_Read_Byte(1);          //temp=高字节+低字节
	IIC2_Ack(); 
	IIC2_Stop();
	ADS2_delay();
	
	IIC2_Start(); 
	IIC2_Send_Byte(FDC2X14_W);
	IIC2_Wait_Ack();
	ADS2_delay();
	IIC2_Send_Byte(secondAddress);
	IIC2_Wait_Ack();
	ADS2_delay();
	IIC2_Stop();
	ADS2_delay();
	
	IIC2_Start();
	IIC2_Send_Byte(FDC2X14_R);
	IIC2_Wait_Ack();
	ADS2_delay();
	result[2]=IIC2_Read_Byte(1);//高字节 高四位清除
	IIC2_Ack(); 
	ADS2_delay();
	result[3]=IIC2_Read_Byte(1);          //temp=高字节+低字节
	IIC2_Ack(); 
	IIC2_Stop();
	ADS2_delay();
	
	temp=(int)(((result[0]<< 24)|(result[1] << 16)|(result[2] << 8)|(result[3] & 0xff)));  
	return(temp); 
}

//void Get_Error(void)
//{
//	Error[0]=ReadFDC2X14(DATA_CH0,DATA_LSB_CH0);
//	Error[1]=ReadFDC2X14(DATA_CH1,DATA_LSB_CH1);
//	Error[2]=ReadFDC2X14(DATA_CH2,DATA_LSB_CH2);
//	Error[3]=ReadFDC2X14(DATA_CH3,DATA_LSB_CH3);
//	Error[4]=ReadFDC2X14_2(DATA_CH0,DATA_LSB_CH0);
//	Error[5]=ReadFDC2X14_2(DATA_CH1,DATA_LSB_CH1);
//	Error[6]=ReadFDC2X14_2(DATA_CH2,DATA_LSB_CH2);
//	Error[7]=ReadFDC2X14_2(DATA_CH3,DATA_LSB_CH3);
//}

void Set_Error(void)
{
	for(int i=0;i<8;i++)
	{
		Error[i]=0;
	}
}

void FDC2X14_Init(void)//双通道
{
	WriteRegfdc2214(0x08,0x04D6);//转换时间
	WriteRegfdc2214(0x09,0x04D6);
	WriteRegfdc2214(0x0A,0x04D6);//转换时间
	WriteRegfdc2214(0x0B,0x04D6);

	WriteRegfdc2214(0x0C,0x0F00); //调0值 	CH0
	WriteRegfdc2214(0x0D,0x0F00); //调0值   CH1
	WriteRegfdc2214(0x0E,0x0F00); //调0值   CH2
	WriteRegfdc2214(0x0F,0x0F00); //调0值   CH3

	WriteRegfdc2214(0x10,0x000A);//作用时间 CH1
	WriteRegfdc2214(0x11,0x000A);//CH2
	WriteRegfdc2214(0x12,0x000A);//CH3
	WriteRegfdc2214(0x13,0x000A);//CH4

	WriteRegfdc2214(0x14,0x2002);//分频
	WriteRegfdc2214(0x15,0x2002);
	WriteRegfdc2214(0x16,0x2002);//分频
	WriteRegfdc2214(0x17,0x2002);

	WriteRegfdc2214(0x19,0x0000);
	WriteRegfdc2214(0x1B,0xC20D);//配置多通道   2通道--0x820D

	WriteRegfdc2214(0x1E,0x9000); //驱动电流 CH0
	WriteRegfdc2214(0x1F,0x9000); //CH1
	WriteRegfdc2214(0x20,0x9000); //CH2
	WriteRegfdc2214(0x21,0x9000); //CH3

	WriteRegfdc2214(0x1A,0x1C81);//配置寄存器
	
	//------------------------------------
	WriteRegfdc2214_2(0x08,0x04D6);//转换时间
	WriteRegfdc2214_2(0x09,0x04D6);
	WriteRegfdc2214_2(0x0A,0x04D6);//转换时间
	WriteRegfdc2214_2(0x0B,0x04D6);

	WriteRegfdc2214_2(0x0C,0x0F00); //调0值 	CH0
	WriteRegfdc2214_2(0x0D,0x0F00); //调0值   CH1
	WriteRegfdc2214_2(0x0E,0x0F00); //调0值   CH2
	WriteRegfdc2214_2(0x0F,0x0F00); //调0值   CH3

	WriteRegfdc2214_2(0x10,0x000A);//作用时间 CH1
	WriteRegfdc2214_2(0x11,0x000A);//CH2
	WriteRegfdc2214_2(0x12,0x000A);//CH3
	WriteRegfdc2214_2(0x13,0x000A);//CH4

	WriteRegfdc2214_2(0x14,0x2002);//分频
	WriteRegfdc2214_2(0x15,0x2002);
	WriteRegfdc2214_2(0x16,0x2002);//分频
	WriteRegfdc2214_2(0x17,0x2002);

	WriteRegfdc2214_2(0x19,0x0000);
	WriteRegfdc2214_2(0x1B,0xC20D);//配置多通道   2通道--0x820D

	WriteRegfdc2214_2(0x1E,0x9000); //驱动电流 CH0
	WriteRegfdc2214_2(0x1F,0x9000); //CH1
	WriteRegfdc2214_2(0x20,0x9000); //CH2
	WriteRegfdc2214_2(0x21,0x9000); //CH3

	WriteRegfdc2214_2(0x1A,0x1C81);//配置寄存器
	
	Set_Error();
}

int FDC_ClearCH(u8 index)
{
	switch(index)
	{
		case 0x00:
			return ReadFDC2X14(DATA_CH0,DATA_LSB_CH0);
		case 0x01:
			return ReadFDC2X14(DATA_CH1,DATA_LSB_CH1);
		case 0x02:
			return ReadFDC2X14(DATA_CH2,DATA_LSB_CH2);
		case 0x03:
			return ReadFDC2X14(DATA_CH3,DATA_LSB_CH3);
		case 0x04:
			return ReadFDC2X14_2(DATA_CH0,DATA_LSB_CH0);
		case 0x05:
			return ReadFDC2X14_2(DATA_CH1,DATA_LSB_CH1);
		case 0x06:
			return ReadFDC2X14_2(DATA_CH2,DATA_LSB_CH2);
		case 0x07:
			return ReadFDC2X14_2(DATA_CH3,DATA_LSB_CH3);
	}
	return -1;
}

int FDC_GetCH(u8 index)
{
	switch(index)
	{
		case 0x00:
			return (ReadFDC2X14(DATA_CH0,DATA_LSB_CH0)-Error[0])/-100;
		case 0x01:
			return (ReadFDC2X14(DATA_CH1,DATA_LSB_CH1)-Error[1])/-100;
		case 0x02:
			return (ReadFDC2X14(DATA_CH2,DATA_LSB_CH2)-Error[2])/-100;
		case 0x03:
			return (ReadFDC2X14(DATA_CH3,DATA_LSB_CH3)-Error[3])/-100;
		case 0x04:
			return (ReadFDC2X14_2(DATA_CH0,DATA_LSB_CH0)-Error[4])/-100;
		case 0x05:
			return (ReadFDC2X14_2(DATA_CH1,DATA_LSB_CH1)-Error[5])/-100;
		case 0x06:
			return (ReadFDC2X14_2(DATA_CH2,DATA_LSB_CH2)-Error[6])/-100;
		case 0x07:
			return (ReadFDC2X14_2(DATA_CH3,DATA_LSB_CH3)-Error[7])/-100;
	}
	return -1;
}

