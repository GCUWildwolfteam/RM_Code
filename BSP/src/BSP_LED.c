#include "BSP_LED.h" 
#include "sys.h"


//��ʼ��PF9��PF10Ϊ�����.��ʹ���������ڵ�ʱ��		    
//LED IO��ʼ��
void LED_Init(void)
{    	 
  GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF|RCC_AHB1Periph_GPIOE | RCC_AHB1Periph_GPIOG | RCC_AHB1Periph_GPIOB , ENABLE);//ʹ��GPIOFʱ��

  //GPIOF9,F10��ʼ������

  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//����
	
#if BOARDTYPE == 1
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
  GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
  GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ��
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8;  
  GPIO_Init(GPIOG, &GPIO_InitStructure);//��ʼ��
	
	GPIO_SetBits(GPIOF,GPIO_Pin_14);//GPIOF9,F10���øߣ�����
	GPIO_SetBits(GPIOE,GPIO_Pin_11);//GPIOF9,F10���øߣ�����
	GPIO_SetBits(GPIOG,GPIO_Pin_1);
	GPIO_SetBits(GPIOG,GPIO_Pin_2);
	GPIO_SetBits(GPIOG,GPIO_Pin_3);
	GPIO_SetBits(GPIOG,GPIO_Pin_4);
	GPIO_SetBits(GPIOG,GPIO_Pin_5);
	GPIO_SetBits(GPIOG,GPIO_Pin_6);
	GPIO_SetBits(GPIOG,GPIO_Pin_7);
	GPIO_SetBits(GPIOG,GPIO_Pin_8);
	#else
		//PB4Ĭ���������Կڣ�����������Ҫ������ͨio��������Ҫ��ֹjtag
//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_4;  
  GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

		LEDa = 1;
		LEDb = 1;
		LED1 = 1;
		LED2 = 1;
		LED3 = 1;
		LED4 = 1;
		LED5 = 1;
		LED6 = 1;
		LED7 = 1;


#endif	
}



/**
	* @brief  �����źŵ�
  * @param	�ƺ�  ״̬��0 ��  1��
  * @retval None
  */
void SetSignal(u8 num, u8 sta)
{
	switch (num)
	{
		case 0:
			LEDa = sta;
			break;
		case 1:
			LEDb = sta;
			break;
		case 2:
			LED1 = sta;
			break;
		case 3:
			LED2 = sta;
			break;
		case 4:
			LED3 = sta;
			break;
		case 5:
			LED4 = sta;
			break;
		case 6:
			LED5 = sta;
			break;
		case 7:
			LED6 = sta;
			break;		
		case 8:
			LED7 = sta;
			break;			
		case 9:
			LED8 = sta;
			break;		
		default:
			break;
	}

}


