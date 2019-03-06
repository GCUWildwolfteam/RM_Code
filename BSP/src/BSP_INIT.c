#include "BSP_INIT.h"
#include "delay.h"
#include "Config.h"

u8 DBUS_DataBuf[Rc_BuffSIZE];
u8 GYIMU_RxBuff[GYIMU_BuffSIZE];
u8 Judge_DataBuff[Judge_BuffSIZE];

void BSP_Init(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//����ϵͳ�ж����ȼ�����4
	delay_init(180);			//��ʼ���δ�ʱ��
	CAN1_Init();					//can�ṹ��ʼ��
	BEEP_Init(89, 2000);	//��������ʼ��
	LED_Init();						//led�Ƴ�ʼ��
	FrictBSP_init();			//Ħ���ֵ��pwm��ʼ��
	IMUBSP_Init();				//�����ǳ�ʼ��
	Dr16BSP_Init();				//ң������ʼ��
	USART2_Init(115200);	//����2��ʼ��
	JudgeBSP_Init();			//����ϵͳ��ʼ��
	ServoBSP_Init();			//�����ʼ��
}


void IMUBSP_Init(void)
{
//������gy955����
#if IMUGY955_BSP_CONFIG == 3
	USART3_Init(115200);
	USART3_RXDMA_Config((uint32_t)GYIMU_RxBuff,GYIMU_BuffSIZE);	
#elif IMUGY955_BSP_CONFIG == 6
	USART6_Init(115200);	
	USART6_RXDMA_Config((uint32_t)GYIMU_RxBuff,GYIMU_BuffSIZE);	
#elif IMUGY955_BSP_CONFIG == 7
	UART7_Init(115200);
	UART7_RXDMA_Config((uint32_t)GYIMU_RxBuff,GYIMU_BuffSIZE);	
#elif IMUGY955_BSP_CONFIG == 8
	UART8_Init(115200);	
	UART8_RXDMA_Config((uint32_t)GYIMU_RxBuff,GYIMU_BuffSIZE);	
#endif
	
}


void FrictBSP_init(void)
{	
#if FRICT_BSP_CONFIG == 1
	TIM1_PWM_Init(179, 19999,1000);		//Ħ����180M/180/20000=50HZ
#elif FRICT_BSP_CONFIG == 12
	TIM12_PWM_Init(89, 19999,1000);		//Ħ����180M/180/20000=50HZ
#elif FRICT_BSP_CONFIG == 5
	TIM5_PWM_Init(89, 19999,1000);		//Ħ����180M/180/20000=50HZ	
#elif FRICT_BSP_CONFIG == 8
	TIM8_PWM_Init(179, 19999,1000);		//Ħ����180M/180/20000=50HZ
#endif	
}

void Dr16BSP_Init(void)
{
#if DR16_BSP_CONFIG == 1
	USART1_Init(100000);
	USART1_RXDMA_Config((uint32_t)DBUS_DataBuf,Rc_BuffSIZE);	
#else
	
#endif
}


void JudgeBSP_Init(void)
{
#if JUDGE_BSP_CONFIG ==6
	USART6_Init(115200);
	USART6_RXDMA_Config((uint32_t)Judge_DataBuff,Judge_BuffSIZE);	
#elif JUDGE_BSP_CONFIG == 7
	UART7_Init(115200);
	UART7_RXDMA_Config((uint32_t)Judge_DataBuff,Judge_BuffSIZE);	
#endif
}


void ServoBSP_Init(void)
{
#if LIDSERVO_BSP_CONFIG == 5
	TIM5_PWM_Init(89, 19999,1000);		//Ħ����180M/180/20000=50HZ
#endif
}


