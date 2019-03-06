#include "BSP_USART.h"	

//�ض���fputc���� 
int fputc(int ch, FILE *f)
{ 	
	while((UART7->SR&0X40)==0);//ѭ������,ֱ���������   
	UART7->DR = (u8) ch;      
	return ch;
}

//����1��ʼ��
void USART1_Init(u32 bound){
	
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
  
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;

#if USART1_RX_ENABLE == 1
	RCC_AHB1PeriphClockCmd(USART1_RX_GPIO_CLK ,ENABLE);
	GPIO_InitStructure.GPIO_Pin = USART1_RX_Pin;  
	GPIO_Init(USART1_RX_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(USART1_RX_GPIO_PORT, USART1_RX_PINSOURCE, GPIO_AF_USART1);
#endif
	
#if USART1_TX_ENABLE == 1
	RCC_AHB1PeriphClockCmd(USART1_TX_GPIO_CLK ,ENABLE);
	GPIO_InitStructure.GPIO_Pin = USART1_TX_Pin;
	GPIO_Init(USART1_TX_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(USART1_TX_GPIO_PORT, USART1_TX_PINSOURCE, GPIO_AF_USART1);
#endif
 
	USART_InitStructure.USART_BaudRate = bound;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure); 

	//�����ж���Դ
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	//���������ȼ�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 5;
	//������ռʽ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

//	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
//USART_ITConfig(USART1, USART_IT_PE, ENABLE);
	USART_ITConfig(USART1, USART_IT_IDLE, ENABLE);//�����ж�
	
	USART_Cmd(USART1, ENABLE);
}




//��ʼ��IO ����2
//bound:������
void USART2_Init(u32 bound){
	
   //GPIO�˿�����
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	//NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);//ʹ��USART2ʱ��
 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//�ٶ�50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //����
	
#if USART2_RX_ENABLE == 1
	RCC_AHB1PeriphClockCmd(USART2_RX_GPIO_CLK ,ENABLE);
	GPIO_InitStructure.GPIO_Pin = USART2_RX_Pin;  
	GPIO_Init(USART2_RX_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(USART2_RX_GPIO_PORT, USART2_RX_PINSOURCE, GPIO_AF_USART2);
#endif

#if	USART2_TX_ENABLE == 1
	RCC_AHB1PeriphClockCmd(USART2_TX_GPIO_CLK ,ENABLE);
	GPIO_InitStructure.GPIO_Pin = USART2_TX_Pin;
	GPIO_Init(USART2_TX_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(USART2_TX_GPIO_PORT, USART2_TX_PINSOURCE, GPIO_AF_USART2);
#endif

   //USART1 ��ʼ������
	USART_InitStructure.USART_BaudRate = bound;//����������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
  USART_Init(USART2, &USART_InitStructure); //��ʼ������1
	
  USART_Cmd(USART2, ENABLE);  //ʹ�ܴ���2 
	
	//USART_ClearFlag(USART1, USART_FLAG_TC);
	

//	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//��������ж�

//	//Usart1 NVIC ����
//  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;//����1�ж�ͨ��
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3;//��ռ���ȼ�3
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority =3;		//�����ȼ�3
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
//	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ�����

}




//����3��ʼ��---
void USART3_Init(u32 bound){
		
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
  
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	
#if USART3_RX_ENABLE == 1
	RCC_AHB1PeriphClockCmd(USART3_RX_GPIO_CLK ,ENABLE);
	GPIO_InitStructure.GPIO_Pin = USART3_RX_Pin;  
	GPIO_Init(USART3_RX_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(USART3_RX_GPIO_PORT, USART3_RX_PINSOURCE, GPIO_AF_USART3);
#endif

#if	USART3_TX_ENABLE == 1
	RCC_AHB1PeriphClockCmd(USART3_TX_GPIO_CLK ,ENABLE);
	GPIO_InitStructure.GPIO_Pin = USART3_TX_Pin;
	GPIO_Init(USART3_TX_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(USART3_TX_GPIO_PORT, USART3_TX_PINSOURCE, GPIO_AF_USART3);
#endif


	USART_InitStructure.USART_BaudRate = bound;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART3, &USART_InitStructure); 

	//�����ж���Դ
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	//���������ȼ�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 5;
	//������ռʽ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	//USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
	//USART_ITConfig(USART3, USART_IT_PE, ENABLE);
	USART_ITConfig(USART3, USART_IT_IDLE, ENABLE);//�����ж�
	
	USART_Cmd(USART3, ENABLE);
}



//����1DMA���ú���
void USART1_RXDMA_Config(uint32_t USART1_DMABuff_addr, uint32_t buffsize)
{
	DMA_InitTypeDef DMA_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);//����DMA2ʱ��
	  
	DMA_DeInit(DMA2_Stream2);// ��λ��ʼ��DMA������ 

	while(DMA_GetCmdStatus(DMA2_Stream2) != DISABLE);//ȷ��DMA��������λ���
	
	DMA_InitStructure.DMA_Channel = DMA_Channel_4; //usart1 rx��Ӧdma2��ͨ��4��������2 	
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART1->DR);	//����DMAԴ���������ݼĴ�����ַ 	
	DMA_InitStructure.DMA_Memory0BaseAddr = USART1_DMABuff_addr;//���ַ(Ҫ����ı�����ָ��)
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;		//���򣺴����赽�ڴ�		
	DMA_InitStructure.DMA_BufferSize = buffsize;	//�����СDMA_BufferSize=SENDBUFF_SIZE		
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable; //�����ַ����    	
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;	//�ڴ��ַ����
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;	//�������ݵ�λ		
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;	//�ڴ����ݵ�λ 8bit	
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;//DMAģʽ������ѭ��
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium; 	//���ȼ�����	     
	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable; 	//����FIFO       
	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_1QuarterFull;    
	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single; 	//�洢��ͻ������ 16 ������   	
	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;   //����ͻ������ 1 ������ 
	DMA_Init(DMA2_Stream2, &DMA_InitStructure);//����DMA2��������		 
	  
	DMA_Cmd(DMA2_Stream2, ENABLE);//ʹ��DMA
  
	while(DMA_GetCmdStatus(DMA2_Stream2) != ENABLE);// �ȴ�DMA��������Ч
  
	USART_DMACmd(USART1,USART_DMAReq_Rx,ENABLE); 	//ʹ��DMA����  
}



void USART3_RXDMA_Config(uint32_t USART3_DMABuff_addr, uint32_t buffsize)
{
	DMA_InitTypeDef DMA_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);//����DMA1ʱ��
	  
	DMA_DeInit(DMA1_Stream1);// ��λ��ʼ��DMA������ 

	while(DMA_GetCmdStatus(DMA1_Stream1) != DISABLE);//ȷ��DMA��������λ���
	
	DMA_InitStructure.DMA_Channel = DMA_Channel_4; //usart3 rx��Ӧdma1��ͨ��4��������1 	
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART3->DR);	//����DMAԴ���������ݼĴ�����ַ 	
	DMA_InitStructure.DMA_Memory0BaseAddr = USART3_DMABuff_addr;//���ַ(Ҫ����ı�����ָ��)
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;		//���򣺴����赽�ڴ�		
	DMA_InitStructure.DMA_BufferSize = buffsize;	//�����СDMA_BufferSize=SENDBUFF_SIZE		
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable; //�����ַ����    	
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;	//�ڴ��ַ����
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;	//�������ݵ�λ		
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;	//�ڴ����ݵ�λ 8bit	
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;//DMAģʽ������ѭ��
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium; 	//���ȼ�����	     
	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable; 	//����FIFO       
	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_1QuarterFull;    
	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single; 	//�洢��ͻ������ 16 ������   	
	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;   //����ͻ������ 1 ������ 
	DMA_Init(DMA1_Stream1, &DMA_InitStructure);//����DMA2��������		 
	  
	DMA_Cmd(DMA1_Stream1, ENABLE);//ʹ��DMA
  
	while(DMA_GetCmdStatus(DMA1_Stream1) != ENABLE);// �ȴ�DMA��������Ч
  
	USART_DMACmd(USART3,USART_DMAReq_Rx,ENABLE); 	//ʹ��DMA����  
}



//����6��ʼ��---��������������
void USART6_Init(u32 bound)
{		
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6, ENABLE);
  
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	
#if USART6_RX_ENABLE == 1
	RCC_AHB1PeriphClockCmd(USART6_RX_GPIO_CLK ,ENABLE);
	GPIO_InitStructure.GPIO_Pin = USART6_RX_Pin;  
	GPIO_Init(USART6_RX_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(USART6_RX_GPIO_PORT, USART6_RX_PINSOURCE, GPIO_AF_USART6);
#endif

#if	USART6_TX_ENABLE == 1
	RCC_AHB1PeriphClockCmd(USART6_TX_GPIO_CLK ,ENABLE);
	GPIO_InitStructure.GPIO_Pin = USART6_TX_Pin;
	GPIO_Init(USART6_TX_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(USART6_TX_GPIO_PORT, USART6_TX_PINSOURCE, GPIO_AF_USART6);
#endif

	USART_InitStructure.USART_BaudRate = bound;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART6, &USART_InitStructure); 

	//�����ж���Դ
	NVIC_InitStructure.NVIC_IRQChannel = USART6_IRQn;
	//���������ȼ�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 5;
	//������ռʽ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	//USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
	//USART_ITConfig(USART3, USART_IT_PE, ENABLE);
	USART_ITConfig(USART6, USART_IT_IDLE, ENABLE);//�����ж�
	
	USART_Cmd(USART6, ENABLE);
}



void USART6_RXDMA_Config(uint32_t USART6_DMABuff_addr, uint32_t buffsize)
{
	DMA_InitTypeDef DMA_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);//����DMA1ʱ��
	  
	DMA_DeInit(DMA2_Stream1);// ��λ��ʼ��DMA������ 

	while(DMA_GetCmdStatus(DMA2_Stream1) != DISABLE);//ȷ��DMA��������λ���
	
	DMA_InitStructure.DMA_Channel = DMA_Channel_5; //usart6 rx��Ӧdma1��ͨ��5��������1 	
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART6->DR);	//����DMAԴ���������ݼĴ�����ַ 	
	DMA_InitStructure.DMA_Memory0BaseAddr = USART6_DMABuff_addr;//���ַ(Ҫ����ı�����ָ��)
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;		//���򣺴����赽�ڴ�		
	DMA_InitStructure.DMA_BufferSize = buffsize;	//�����СDMA_BufferSize=SENDBUFF_SIZE		
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable; //�����ַ����    	
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;	//�ڴ��ַ����
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;	//�������ݵ�λ		
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;	//�ڴ����ݵ�λ 8bit	
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;//DMAģʽ������ѭ��
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium; 	//���ȼ�����	     
	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable; 	//����FIFO       
	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_1QuarterFull;    
	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single; 	//�洢��ͻ������ 16 ������   	
	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;   //����ͻ������ 1 ������ 
	DMA_Init(DMA2_Stream1, &DMA_InitStructure);//����DMA2��������		 
	  
	DMA_Cmd(DMA2_Stream1, ENABLE);//ʹ��DMA
  
	while(DMA_GetCmdStatus(DMA2_Stream1) != ENABLE);// �ȴ�DMA��������Ч
  
	USART_DMACmd(USART6,USART_DMAReq_Rx,ENABLE); 	//ʹ��DMA����  
}


//��ʼ��IO ����7
//bound:������
void UART7_Init(u32 bound)
{
	
   //GPIO�˿�����
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART7,ENABLE);//ʹ��USART2ʱ��
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//�ٶ�50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //����
	
	
#if UART7_RX_ENABLE == 1
	RCC_AHB1PeriphClockCmd(UART7_RX_GPIO_CLK ,ENABLE);
	GPIO_InitStructure.GPIO_Pin = UART7_RX_Pin;  
	GPIO_Init(UART7_RX_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(UART7_RX_GPIO_PORT, UART7_RX_PINSOURCE, GPIO_AF_UART7);
#endif

#if	UART7_TX_ENABLE == 1
	RCC_AHB1PeriphClockCmd(UART7_TX_GPIO_CLK ,ENABLE);
	GPIO_InitStructure.GPIO_Pin = UART7_TX_Pin;
	GPIO_Init(UART7_TX_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(UART7_TX_GPIO_PORT, UART7_TX_PINSOURCE, GPIO_AF_UART7);
#endif

   //USART1 ��ʼ������
	USART_InitStructure.USART_BaudRate = bound;//����������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
  USART_Init(UART7, &USART_InitStructure); //��ʼ������1
	
  USART_Cmd(UART7, ENABLE);  //ʹ�ܴ���2 
	
	//USART_ClearFlag(USART1, USART_FLAG_TC);
	
	USART_ITConfig(UART7, USART_IT_IDLE, ENABLE);//�����ж�
	//USART_ITConfig(UART7, USART_IT_RXNE, ENABLE);//��������ж�

	//Usart1 NVIC ����
  NVIC_InitStructure.NVIC_IRQChannel = UART7_IRQn;//����1�ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=5;//��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;		//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���

}



void UART7_RXDMA_Config(uint32_t USART6_DMABuff_addr, uint32_t buffsize)
{
	DMA_InitTypeDef DMA_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);//����DMA1ʱ��
	  
	DMA_DeInit(DMA1_Stream3);// ��λ��ʼ��DMA������ 

	while(DMA_GetCmdStatus(DMA1_Stream3) != DISABLE);//ȷ��DMA��������λ���
	
	DMA_InitStructure.DMA_Channel = DMA_Channel_5; //usart6 rx��Ӧdma1��ͨ��5��������1 	
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&UART7->DR);	//����DMAԴ���������ݼĴ�����ַ 	
	DMA_InitStructure.DMA_Memory0BaseAddr = USART6_DMABuff_addr;//���ַ(Ҫ����ı�����ָ��)
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;		//���򣺴����赽�ڴ�		
	DMA_InitStructure.DMA_BufferSize = buffsize;	//�����СDMA_BufferSize=SENDBUFF_SIZE		
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable; //�����ַ����    	
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;	//�ڴ��ַ����
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;	//�������ݵ�λ		
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;	//�ڴ����ݵ�λ 8bit	
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;//DMAģʽ������ѭ��
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium; 	//���ȼ�����	     
	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable; 	//����FIFO       
	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_1QuarterFull;    
	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single; 	//�洢��ͻ������ 16 ������   	
	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;   //����ͻ������ 1 ������ 
	DMA_Init(DMA1_Stream3, &DMA_InitStructure);//����DMA2��������		 
	  
	DMA_Cmd(DMA1_Stream3, ENABLE);//ʹ��DMA
  
	while(DMA_GetCmdStatus(DMA1_Stream3) != ENABLE);// �ȴ�DMA��������Ч
  
	USART_DMACmd(UART7,USART_DMAReq_Rx,ENABLE); 	//ʹ��DMA����  
}



//��ʼ��IO ����78
//bound:������
void UART8_Init(u32 bound)
{
	
   //GPIO�˿�����
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART8,ENABLE);//ʹ��USART2ʱ��
 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//�ٶ�50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //����
	
#if UART8_RX_ENABLE == 1
	RCC_AHB1PeriphClockCmd(UART8_RX_GPIO_CLK ,ENABLE);
	GPIO_InitStructure.GPIO_Pin = UART8_RX_Pin;  
	GPIO_Init(UART8_RX_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(UART8_RX_GPIO_PORT, UART8_RX_PINSOURCE, GPIO_AF_UART8);
#endif

#if	UART8_TX_ENABLE == 1
	RCC_AHB1PeriphClockCmd(UART8_TX_GPIO_CLK ,ENABLE);
	GPIO_InitStructure.GPIO_Pin = UART8_TX_Pin;
	GPIO_Init(UART8_TX_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(UART8_TX_GPIO_PORT, UART8_TX_PINSOURCE, GPIO_AF_UART8);
#endif

   //USART1 ��ʼ������
	USART_InitStructure.USART_BaudRate = bound;//����������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
  USART_Init(UART8, &USART_InitStructure); //��ʼ������1
	
  USART_Cmd(UART8, ENABLE);  //ʹ�ܴ���2 
	
	//USART_ClearFlag(UART8, USART_FLAG_TC);
	
	USART_ITConfig(UART8, USART_IT_IDLE, ENABLE);//�����ж�
	//USART_ITConfig(UART7, USART_IT_RXNE, ENABLE);//��������ж�

	//Usart1 NVIC ����
  NVIC_InitStructure.NVIC_IRQChannel = UART8_IRQn;//����1�ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=5;//��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;		//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���

}



void UART8_RXDMA_Config(uint32_t UART8_DMABuff_addr, uint32_t buffsize)
{
	DMA_InitTypeDef DMA_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);//����DMA1ʱ��
	  
	DMA_DeInit(DMA1_Stream6);// ��λ��ʼ��DMA������ 

	while(DMA_GetCmdStatus(DMA1_Stream6) != DISABLE);//ȷ��DMA��������λ���
	
	DMA_InitStructure.DMA_Channel = DMA_Channel_5; //usart6 rx��Ӧdma1��ͨ��5��������1 	
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&UART8->DR);	//����DMAԴ���������ݼĴ�����ַ 	
	DMA_InitStructure.DMA_Memory0BaseAddr = UART8_DMABuff_addr;//���ַ(Ҫ����ı�����ָ��)
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;		//���򣺴����赽�ڴ�		
	DMA_InitStructure.DMA_BufferSize = buffsize;	//�����СDMA_BufferSize=SENDBUFF_SIZE		
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable; //�����ַ����    	
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;	//�ڴ��ַ����
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;	//�������ݵ�λ		
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;	//�ڴ����ݵ�λ 8bit	
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;//DMAģʽ������ѭ��
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium; 	//���ȼ�����	     
	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable; 	//����FIFO       
	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_1QuarterFull;    
	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single; 	//�洢��ͻ������ 16 ������   	
	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;   //����ͻ������ 1 ������ 
	DMA_Init(DMA1_Stream6, &DMA_InitStructure);//����DMA2��������		 
	  
	DMA_Cmd(DMA1_Stream6, ENABLE);//ʹ��DMA
  
	while(DMA_GetCmdStatus(DMA1_Stream6) != ENABLE);// �ȴ�DMA��������Ч
  
	USART_DMACmd(UART8,USART_DMAReq_Rx,ENABLE); 	//ʹ��DMA����  
}


/**
  * @brief  USART����һ���ַ�
  * @param  USARTx 	USART����
  *			ch 		�ַ�
  * @retval None
  */
void USART_sendChar(USART_TypeDef* USARTx, char ch)
{
	/* ����һ���ֽ����ݵ����� */
	USART_SendData(USARTx, (uint8_t) ch);
	
	/* �ȴ�������� */
	while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);	
}


















