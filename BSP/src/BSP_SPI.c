#include "BSP_SPI.h"

//�������Ƕ�SPI1�ĳ�ʼ��
void SPI1_Init(void)
{	 
  GPIO_InitTypeDef  GPIO_InitStructure;
  SPI_InitTypeDef  SPI_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);//ʹ��SPI1ʱ��

  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
	
	RCC_AHB1PeriphClockCmd(SPI1_MISO_GPIO_CLK, ENABLE);//ʹ��GPIOʱ�� 
  GPIO_InitStructure.GPIO_Pin = SPI1_MISO_Pin;//���ù������	
  GPIO_Init(SPI1_MISO_GPIO_PORT, &GPIO_InitStructure);//��ʼ��
	GPIO_PinAFConfig(SPI1_MISO_GPIO_PORT,SPI1_MISO_PINSOURCE,GPIO_AF_SPI1); //����Ϊ SPI1

	RCC_AHB1PeriphClockCmd(SPI1_MOSI_GPIO_CLK, ENABLE);//ʹ��GPIOʱ�� 
  GPIO_InitStructure.GPIO_Pin = SPI1_MOSI_Pin;//���ù������	
  GPIO_Init(SPI1_MOSI_GPIO_PORT, &GPIO_InitStructure);//��ʼ��
	GPIO_PinAFConfig(SPI1_MOSI_GPIO_PORT,SPI1_MOSI_PINSOURCE,GPIO_AF_SPI1); //����Ϊ SPI1
 
	RCC_AHB1PeriphClockCmd(SPI1_SCK_GPIO_CLK, ENABLE);//ʹ��GPIOʱ�� 
  GPIO_InitStructure.GPIO_Pin = SPI1_SCK_Pin;//���ù������	
  GPIO_Init(SPI1_SCK_GPIO_PORT, &GPIO_InitStructure);//��ʼ��
	GPIO_PinAFConfig(SPI1_SCK_GPIO_PORT,SPI1_SCK_PINSOURCE,GPIO_AF_SPI1); //����Ϊ SPI1
	
	//����ֻ���SPI�ڳ�ʼ��
	RCC_APB2PeriphResetCmd(RCC_APB2Periph_SPI1,ENABLE);//��λSPI1
	RCC_APB2PeriphResetCmd(RCC_APB2Periph_SPI1,DISABLE);//ֹͣ��λSPI1

	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;  //����SPI�������˫�������ģʽ:SPI����Ϊ˫��˫��ȫ˫��
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;		//����SPI����ģʽ:����Ϊ��SPI
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;		//����SPI�����ݴ�С:SPI���ͽ���8λ֡�ṹ
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;		//����ͬ��ʱ�ӵĿ���״̬Ϊ�͵�ƽ
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;	//����ͬ��ʱ�ӵĵڶ��������أ��������½������ݱ�����
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;		//NSS�ź���Ӳ����NSS�ܽţ����������ʹ��SSIλ������:�ڲ�NSS�ź���SSIλ����
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;		//���岨����Ԥ��Ƶ��ֵ:������Ԥ��ƵֵΪ2
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;	//ָ�����ݴ����MSBλ����LSBλ��ʼ:���ݴ����MSBλ��ʼ
	SPI_InitStructure.SPI_CRCPolynomial = 7;	//CRCֵ����Ķ���ʽ
	SPI_Init(SPI1, &SPI_InitStructure);  //����SPI_InitStruct��ָ���Ĳ�����ʼ������SPIx�Ĵ���
 
	SPI_Cmd(SPI1, ENABLE); //ʹ��SPI����

	SPI_ReadWriteByte(SPI1, 0xff);//��������		 
}   

void SPI4_Init(void)
{	 
  GPIO_InitTypeDef  GPIO_InitStructure;
  SPI_InitTypeDef  SPI_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI4, ENABLE);//ʹ��SPI4ʱ��

  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
	
	RCC_AHB1PeriphClockCmd(SPI4_MISO_GPIO_CLK, ENABLE);//ʹ��GPIOʱ�� 
  GPIO_InitStructure.GPIO_Pin = SPI4_MISO_Pin;//���ù������	
  GPIO_Init(SPI4_MISO_GPIO_PORT, &GPIO_InitStructure);//��ʼ��
	GPIO_PinAFConfig(SPI4_MISO_GPIO_PORT,SPI4_MISO_PINSOURCE,GPIO_AF_SPI4); //����Ϊ SPI4

	RCC_AHB1PeriphClockCmd(SPI4_MOSI_GPIO_CLK, ENABLE);//ʹ��GPIOʱ�� 
  GPIO_InitStructure.GPIO_Pin = SPI4_MOSI_Pin;//���ù������	
  GPIO_Init(SPI4_MOSI_GPIO_PORT, &GPIO_InitStructure);//��ʼ��
	GPIO_PinAFConfig(SPI4_MOSI_GPIO_PORT,SPI4_MOSI_PINSOURCE,GPIO_AF_SPI4); //����Ϊ SPI4
 
	RCC_AHB1PeriphClockCmd(SPI4_SCK_GPIO_CLK, ENABLE);//ʹ��GPIOʱ�� 
  GPIO_InitStructure.GPIO_Pin = SPI4_SCK_Pin;//���ù������	
  GPIO_Init(SPI4_SCK_GPIO_PORT, &GPIO_InitStructure);//��ʼ��
	GPIO_PinAFConfig(SPI4_SCK_GPIO_PORT,SPI4_SCK_PINSOURCE,GPIO_AF_SPI4); //����Ϊ SPI4
	
	//����ֻ���SPI�ڳ�ʼ��
	RCC_APB2PeriphResetCmd(RCC_APB2Periph_SPI4,ENABLE);//��λSPI4
	RCC_APB2PeriphResetCmd(RCC_APB2Periph_SPI4,DISABLE);//ֹͣ��λSPI4

	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;  //����SPI�������˫�������ģʽ:SPI����Ϊ˫��˫��ȫ˫��
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;		//����SPI����ģʽ:����Ϊ��SPI
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;		//����SPI�����ݴ�С:SPI���ͽ���8λ֡�ṹ
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;		//����ͬ��ʱ�ӵĿ���״̬Ϊ�͵�ƽ
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;	//����ͬ��ʱ�ӵĵڶ��������أ��������½������ݱ�����
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;		//NSS�ź���Ӳ����NSS�ܽţ����������ʹ��SSIλ������:�ڲ�NSS�ź���SSIλ����
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;		//���岨����Ԥ��Ƶ��ֵ:������Ԥ��ƵֵΪ2
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;	//ָ�����ݴ����MSBλ����LSBλ��ʼ:���ݴ����MSBλ��ʼ
	SPI_InitStructure.SPI_CRCPolynomial = 7;	//CRCֵ����Ķ���ʽ
	SPI_Init(SPI4, &SPI_InitStructure);  //����SPI_InitStruct��ָ���Ĳ�����ʼ������SPIx�Ĵ���
 
	SPI_Cmd(SPI4, ENABLE); //ʹ��SPI����

	SPI_ReadWriteByte(SPI1,0xff);//��������		 
}   



//SPI�ٶ����ú���
//SPI�ٶ�=fAPB2/��Ƶϵ��
//@ref SPI_BaudRate_Prescaler:SPI_BaudRatePrescaler_2~SPI_BaudRatePrescaler_256  
//fAPB2ʱ��һ��Ϊ84Mhz��
void SPI_SetSpeed(SPI_TypeDef* SPIx, u8 SPI_BaudRatePrescaler)
{
  assert_param(IS_SPI_BAUDRATE_PRESCALER(SPI_BaudRatePrescaler));//�ж���Ч��
	SPIx->CR1&=0XFFC7;//λ3-5���㣬�������ò�����
	SPIx->CR1|=SPI_BaudRatePrescaler;	//����SPI1�ٶ� 
	SPI_Cmd(SPIx,ENABLE); //ʹ��SPI1
} 

//SPI ��дһ���ֽ�
//TxData:Ҫд����ֽ�
//����ֵ:��ȡ�����ֽ�
u8 SPI_ReadWriteByte(SPI_TypeDef* SPIx, u8 TxData)
{		 			 
 
  while (SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_TXE) == RESET){}//�ȴ���������  
	
	SPI_I2S_SendData(SPIx, TxData); //ͨ������SPIx����һ��byte  ����
		
  while (SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_RXNE) == RESET){} //�ȴ�������һ��byte  
 
	return SPI_I2S_ReceiveData(SPIx); //����ͨ��SPIx������յ�����	
 		    
}





