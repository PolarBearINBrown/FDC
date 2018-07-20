#define MYIIC2_C
#include "myiic2.h"
#include "delay.h"
 
//��ʼ��IIC
void IIC2_Init(void)
{					     
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOB, ENABLE );	
	   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_Out_PP ;   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_SetBits(GPIOB,GPIO_Pin_6|GPIO_Pin_7); 	// �����
}

//I2C��ʱ
void ADS2_delay(void) 
{
  unsigned char i;
  for(i=0;i<40;i++); 
}

//I2Cʱ��
void ADS2_clock(void)  
{
  IIC2_SCL=1;//SCL=1
  ADS2_delay(); 
  IIC2_SCL=0;//SCL=0 
  ADS2_delay();   
}
//����IIC��ʼ�ź�
void IIC2_Start(void)
{
	SDA2_OUT();     //sda�����
	IIC2_SDA=1;	  	  
	IIC2_SCL=1;
	ADS2_delay(); 
 	IIC2_SDA=0;//START:when CLK is high,DATA change form high to low 
	ADS2_delay();
  ADS2_delay(); 
	IIC2_SCL=0;//ǯסI2C���ߣ�׼�����ͻ�������� 
}	  
//����IICֹͣ�ź�
void IIC2_Stop(void)
{
	SDA2_OUT();//sda�����
	IIC2_SCL=1;
	IIC2_SDA=0;//STOP:when CLK is high DATA change form low to high
 	ADS2_delay();
// 	IIC_SCL=1; 
	IIC2_SDA=1;//����I2C���߽����ź�
	ADS2_delay();							   	
}
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
u8 IIC2_Wait_Ack(void)
{
	u8 ucErrTime=0;
	SDA2_IN();      //SDA����Ϊ����  
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
	IIC2_SCL=0;//ʱ�����0 	   
	return 0;  
}

//����ACKӦ��
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
//������ACKӦ��
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
//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��			  
void IIC2_Send_Byte(u8 txd)
{                        
    u8 t;   
	SDA2_OUT(); 	    
    IIC2_SCL=0;//����ʱ�ӿ�ʼ���ݴ���
    for(t=0;t<8;t++)
    {              
        //IIC_SDA=(txd&0x80)>>7;
		if((txd&0x80))
			IIC2_SDA=1;
		else
			IIC2_SDA=0;
		//ADS_delay();    //��TEA5767��������ʱ���Ǳ����
		ADS2_clock();
		txd<<=1; 		
    }	 
		//ADS_delay();
} 	    
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK   
u8 IIC2_Read_Byte(unsigned char ack)
{
	unsigned char i,adsdata;
  SDA2_IN();//SDA����Ϊ����
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


//I2C�����ݼĴ���0x02 �����ֽ� ���ֽ���ǰ  
//
unsigned int ReadDataCfgReg2(u8 index,u8 firstAddress,u8 SecondAddress)  
{ 
  unsigned int temp;
  u8 result[4];
  IIC2_Start(); 
  IIC2_Send_Byte(0x2A);
  IIC2_Wait_Ack();
  ADS2_delay();
  result[0]=(IIC2_Read_Byte(1)&firstAddress)*0x100;//���ֽ� ����λ���
  IIC2_Ack(); 
  result[1]=(IIC2_Read_Byte(1));          //temp=���ֽ�+���ֽ�
	IIC2_Ack(); 
	if(index==1)
	{
		result[2]=(IIC2_Read_Byte(1)&SecondAddress);//
		IIC2_Ack(); 
		result[3]=(IIC2_Read_Byte(1));          //temp=���ֽ�+���ֽ�
		IIC2_Ack(); 
	}
  
	
  IIC2_Stop();
  temp = (int)(((result[0] << 24) | (result[1] << 16) | (result[2] << 8) | (result[3] & 0xff)));  
  return(temp); 
     
}
