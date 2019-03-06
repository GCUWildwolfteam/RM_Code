#include "BSP_TIM.h"

//TIM1��PWM��ʼ��
void TIM1_PWM_Init(u16 prescaler, u16 period, u16 Pulse)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;	/* ����ʱ���ṹ�� */
	TIM_OCInitTypeDef  TIM_OCInitStructure;	/*��������ȽϽṹ��*/
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);//ʹ�ܶ�ʱ��ʱ��
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;    
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 

	//���ö�ʱ��ʱ�ӷ�Ƶ
	TIM_TimeBaseStructure.TIM_Prescaler = prescaler;
	//�����Զ���װ�ؼĴ�����ֵ
	TIM_TimeBaseStructure.TIM_Period = period;
	//��������ʱ��������˲���Ƶ������Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	//���ü���ģʽ�����ϼ���
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
	
	//�������ģʽ��PWM1ģʽ
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	//ʹ�����
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	//��ʹ�ܻ������
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
	//���ó�ʼռ�ձ�
	TIM_OCInitStructure.TIM_Pulse = Pulse;
	//����PWM���ԣ���ʼ��ƽΪ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	//���ÿ���ʱ�����ƽ
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
	
	//���û������PWM���ԣ���ʼ��ƽΪ��(����ҲҪ���ã�����������ܳ���)
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	//���û����������ʱ�����ƽ(����ҲҪ���ã�����������ܳ���)
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;

#if TIM1_CH1_ENABLE == 1
	//��ʼ��Ϊ��Ӧͨ���������ͨ��1
	RCC_AHB1PeriphClockCmd(TIM1_CH1_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = TIM1_CH1_Pin;
	GPIO_Init(TIM1_CH1_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(TIM1_CH1_GPIO_PORT,TIM1_CH1_PINSOURCE, GPIO_AF_TIM1);
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);
#endif	

#if TIM1_CH2_ENABLE == 1
	//��ʼ��Ϊ��Ӧͨ���������ͨ��1
	RCC_AHB1PeriphClockCmd(TIM1_CH2_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = TIM1_CH2_Pin;
	GPIO_Init(TIM1_CH2_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(TIM1_CH2_GPIO_PORT,TIM1_CH2_PINSOURCE, GPIO_AF_TIM1);
	TIM_OC2Init(TIM1, &TIM_OCInitStructure);
#endif	

#if TIM1_CH3_ENABLE == 1
	//��ʼ��Ϊ��Ӧͨ���������ͨ��1
	RCC_AHB1PeriphClockCmd(TIM1_CH3_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = TIM1_CH3_Pin;
	GPIO_Init(TIM1_CH3_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(TIM1_CH3_GPIO_PORT,TIM1_CH3_PINSOURCE, GPIO_AF_TIM1);
	TIM_OC3Init(TIM1, &TIM_OCInitStructure);
#endif	

#if TIM1_CH4_ENABLE == 1
	//��ʼ��Ϊ��Ӧͨ���������ͨ��1
	RCC_AHB1PeriphClockCmd(TIM1_CH4_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = TIM1_CH4_Pin;
	GPIO_Init(TIM1_CH4_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(TIM1_CH4_GPIO_PORT,TIM1_CH4_PINSOURCE, GPIO_AF_TIM1);
	TIM_OC4Init(TIM1, &TIM_OCInitStructure);
#endif	

	//ʹ�ܶ�ʱ��
	TIM_Cmd(TIM1, ENABLE);
	
	/* �߼���ʱ����Ҫʹ��PWM��� */
	TIM_CtrlPWMOutputs(TIM1, ENABLE);
}


void TIM2_PWM_Init(u16 prescaler, u16 period, u16 Pulse)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;	/* ����ʱ���ṹ�� */
	TIM_OCInitTypeDef  TIM_OCInitStructure;	/*��������ȽϽṹ��*/
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//ʹ�ܶ�ʱ��ʱ��
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;    
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 

	//���ö�ʱ��ʱ�ӷ�Ƶ
	TIM_TimeBaseStructure.TIM_Prescaler = prescaler;
	//�����Զ���װ�ؼĴ�����ֵ
	TIM_TimeBaseStructure.TIM_Period = period;
	//��������ʱ��������˲���Ƶ������Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	//���ü���ģʽ�����ϼ���
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
	//�������ģʽ��PWM1ģʽ
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	//ʹ�����
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	//��ʹ�ܻ������
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
	//���ó�ʼռ�ձ�
	TIM_OCInitStructure.TIM_Pulse = Pulse;
	//����PWM���ԣ���ʼ��ƽΪ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	//���ÿ���ʱ�����ƽ
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
	
	//���û������PWM���ԣ���ʼ��ƽΪ��(����ҲҪ���ã�����������ܳ���)
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	//���û����������ʱ�����ƽ(����ҲҪ���ã�����������ܳ���)
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;
	
#if TIM2_CH1_ENABLE == 1
	//��ʼ��Ϊ��Ӧͨ���������ͨ��1
	RCC_AHB1PeriphClockCmd(TIM2_CH1_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = TIM2_CH1_Pin;
	GPIO_Init(TIM2_CH1_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(TIM2_CH1_GPIO_PORT,TIM2_CH1_PINSOURCE, GPIO_AF_TIM2);
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);
#endif	

#if TIM2_CH2_ENABLE == 1
	//��ʼ��Ϊ��Ӧͨ���������ͨ��1
	RCC_AHB1PeriphClockCmd(TIM2_CH2_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = TIM2_CH2_Pin;
	GPIO_Init(TIM2_CH2_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(TIM2_CH2_GPIO_PORT,TIM2_CH2_PINSOURCE, GPIO_AF_TIM2);
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
#endif	

#if TIM2_CH3_ENABLE == 1
	//��ʼ��Ϊ��Ӧͨ���������ͨ��1
	RCC_AHB1PeriphClockCmd(TIM2_CH3_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = TIM2_CH3_Pin;
	GPIO_Init(TIM2_CH3_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(TIM2_CH3_GPIO_PORT,TIM2_CH3_PINSOURCE, GPIO_AF_TIM2);
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);
#endif	

#if TIM2_CH4_ENABLE == 1
	//��ʼ��Ϊ��Ӧͨ���������ͨ��1
	RCC_AHB1PeriphClockCmd(TIM2_CH4_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = TIM2_CH4_Pin;
	GPIO_Init(TIM2_CH4_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(TIM2_CH4_GPIO_PORT,TIM2_CH4_PINSOURCE, GPIO_AF_TIM2);
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);
#endif	

	//ʹ�ܶ�ʱ��
	TIM_Cmd(TIM2, ENABLE);
}

void TIM4_PWM_Init(u16 prescaler, u16 period, u16 Pulse)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;	/* ����ʱ���ṹ�� */
	TIM_OCInitTypeDef  TIM_OCInitStructure;	/*��������ȽϽṹ��*/
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//ʹ�ܶ�ʱ��ʱ��
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;    
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 

	//���ö�ʱ��ʱ�ӷ�Ƶ
	TIM_TimeBaseStructure.TIM_Prescaler = prescaler;
	//�����Զ���װ�ؼĴ�����ֵ
	TIM_TimeBaseStructure.TIM_Period = period;
	//��������ʱ��������˲���Ƶ������Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	//���ü���ģʽ�����ϼ���
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	
	//�������ģʽ��PWM1ģʽ
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	//ʹ�����
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	//��ʹ�ܻ������
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
	//���ó�ʼռ�ձ�
	TIM_OCInitStructure.TIM_Pulse = Pulse;
	//����PWM���ԣ���ʼ��ƽΪ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	//���ÿ���ʱ�����ƽ
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
	
	//���û������PWM���ԣ���ʼ��ƽΪ��(����ҲҪ���ã�����������ܳ���)
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	//���û����������ʱ�����ƽ(����ҲҪ���ã�����������ܳ���)
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;
	

#if TIM4_CH1_ENABLE == 1
	//��ʼ��Ϊ��Ӧͨ���������ͨ��1
	RCC_AHB1PeriphClockCmd(TIM4_CH1_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = TIM4_CH1_Pin;
	GPIO_Init(TIM4_CH1_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(TIM4_CH1_GPIO_PORT,TIM4_CH1_PINSOURCE, GPIO_AF_TIM4);
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);
#endif	

#if TIM4_CH2_ENABLE == 1
	//��ʼ��Ϊ��Ӧͨ���������ͨ��1
	RCC_AHB1PeriphClockCmd(TIM4_CH2_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = TIM4_CH2_Pin;
	GPIO_Init(TIM4_CH2_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(TIM4_CH2_GPIO_PORT,TIM4_CH2_PINSOURCE, GPIO_AF_TIM4);
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);
#endif	

#if TIM4_CH3_ENABLE == 1
	//��ʼ��Ϊ��Ӧͨ���������ͨ��1
	RCC_AHB1PeriphClockCmd(TIM4_CH3_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = TIM4_CH3_Pin;
	GPIO_Init(TIM4_CH3_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(TIM4_CH3_GPIO_PORT,TIM4_CH3_PINSOURCE, GPIO_AF_TIM4);
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);
#endif	

#if TIM4_CH4_ENABLE == 1
	//��ʼ��Ϊ��Ӧͨ���������ͨ��1
	RCC_AHB1PeriphClockCmd(TIM4_CH4_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = TIM4_CH4_Pin;
	GPIO_Init(TIM4_CH4_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(TIM4_CH4_GPIO_PORT,TIM4_CH4_PINSOURCE, GPIO_AF_TIM4);
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);
#endif	

	//ʹ�ܶ�ʱ��
	TIM_Cmd(TIM4, ENABLE);
}


void TIM5_PWM_Init(u16 prescaler, u16 period, u16 Pulse)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;	/* ����ʱ���ṹ�� */
	TIM_OCInitTypeDef  TIM_OCInitStructure;	/*��������ȽϽṹ��*/
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);//ʹ�ܶ�ʱ��ʱ��
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;    
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 

	//���ö�ʱ��ʱ�ӷ�Ƶ
	TIM_TimeBaseStructure.TIM_Prescaler = prescaler;
	//�����Զ���װ�ؼĴ�����ֵ
	TIM_TimeBaseStructure.TIM_Period = period;
	//��������ʱ��������˲���Ƶ������Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	//���ü���ģʽ�����ϼ���
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);
	
	//�������ģʽ��PWM1ģʽ
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	//ʹ�����
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	//��ʹ�ܻ������
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
	//���ó�ʼռ�ձ�
	TIM_OCInitStructure.TIM_Pulse = Pulse;
	//����PWM���ԣ���ʼ��ƽΪ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	//���ÿ���ʱ�����ƽ
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
	
	//���û������PWM���ԣ���ʼ��ƽΪ��(����ҲҪ���ã�����������ܳ���)
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	//���û����������ʱ�����ƽ(����ҲҪ���ã�����������ܳ���)
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;
	

#if TIM5_CH1_ENABLE == 1
	//��ʼ��Ϊ��Ӧͨ���������ͨ��1
	RCC_AHB1PeriphClockCmd(TIM5_CH1_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = TIM5_CH1_Pin;
	GPIO_Init(TIM5_CH1_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(TIM5_CH1_GPIO_PORT,TIM5_CH1_PINSOURCE, GPIO_AF_TIM5);
	TIM_OC1Init(TIM5, &TIM_OCInitStructure);
#endif	

#if TIM5_CH2_ENABLE == 1
	//��ʼ��Ϊ��Ӧͨ���������ͨ��1
	RCC_AHB1PeriphClockCmd(TIM5_CH2_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = TIM5_CH2_Pin;
	GPIO_Init(TIM5_CH2_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(TIM5_CH2_GPIO_PORT,TIM5_CH2_PINSOURCE, GPIO_AF_TIM5);
	TIM_OC2Init(TIM5, &TIM_OCInitStructure);
#endif	

#if TIM5_CH3_ENABLE == 1
	//��ʼ��Ϊ��Ӧͨ���������ͨ��1
	RCC_AHB1PeriphClockCmd(TIM5_CH3_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = TIM5_CH3_Pin;
	GPIO_Init(TIM5_CH3_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(TIM5_CH3_GPIO_PORT,TIM5_CH3_PINSOURCE, GPIO_AF_TIM5);
	TIM_OC3Init(TIM5, &TIM_OCInitStructure);
#endif	

#if TIM5_CH4_ENABLE == 1
	//��ʼ��Ϊ��Ӧͨ���������ͨ��1
	RCC_AHB1PeriphClockCmd(TIM5_CH4_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = TIM5_CH4_Pin;
	GPIO_Init(TIM5_CH4_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(TIM5_CH4_GPIO_PORT,TIM5_CH4_PINSOURCE, GPIO_AF_TIM5);
	TIM_OC4Init(TIM5, &TIM_OCInitStructure);
#endif	

	//ʹ�ܶ�ʱ��
	TIM_Cmd(TIM5, ENABLE);

}



void TIM8_PWM_Init(u16 prescaler, u16 period, u16 Pulse)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;	/* ����ʱ���ṹ�� */
	TIM_OCInitTypeDef  TIM_OCInitStructure;	/*��������ȽϽṹ��*/
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);//ʹ�ܶ�ʱ��ʱ��
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;    
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  

	//���ö�ʱ��ʱ�ӷ�Ƶ
	TIM_TimeBaseStructure.TIM_Prescaler = prescaler;
	//�����Զ���װ�ؼĴ�����ֵ
	TIM_TimeBaseStructure.TIM_Period = period;
	//��������ʱ��������˲���Ƶ������Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	//���ü���ģʽ�����ϼ���
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	
	TIM_TimeBaseInit(TIM8, &TIM_TimeBaseStructure);
	
	//�������ģʽ��PWM1ģʽ
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	//ʹ�����
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	//��ʹ�ܻ������
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
	//���ó�ʼռ�ձ�
	TIM_OCInitStructure.TIM_Pulse = Pulse;
	//����PWM���ԣ���ʼ��ƽΪ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	//���ÿ���ʱ�����ƽ
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
	
	//���û������PWM���ԣ���ʼ��ƽΪ��(����ҲҪ���ã�����������ܳ���)
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	//���û����������ʱ�����ƽ(����ҲҪ���ã�����������ܳ���)
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;
	

#if TIM8_CH1_ENABLE == 1
	//��ʼ��Ϊ��Ӧͨ���������ͨ��1
	RCC_AHB1PeriphClockCmd(TIM8_CH1_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = TIM8_CH1_Pin;
	GPIO_Init(TIM8_CH1_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(TIM8_CH1_GPIO_PORT,TIM8_CH1_PINSOURCE, GPIO_AF_TIM8);
	TIM_OC1Init(TIM8, &TIM_OCInitStructure);
#endif	

#if TIM8_CH2_ENABLE == 1
	//��ʼ��Ϊ��Ӧͨ���������ͨ��1
	RCC_AHB1PeriphClockCmd(TIM8_CH2_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = TIM8_CH2_Pin;
	GPIO_Init(TIM8_CH2_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(TIM8_CH2_GPIO_PORT,TIM8_CH2_PINSOURCE, GPIO_AF_TIM8);
	TIM_OC2Init(TIM8, &TIM_OCInitStructure);
#endif	

#if TIM8_CH3_ENABLE == 1
	//��ʼ��Ϊ��Ӧͨ���������ͨ��1
	RCC_AHB1PeriphClockCmd(TIM8_CH3_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = TIM8_CH3_Pin;
	GPIO_Init(TIM8_CH3_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(TIM8_CH3_GPIO_PORT,TIM8_CH3_PINSOURCE, GPIO_AF_TIM8);
	TIM_OC3Init(TIM8, &TIM_OCInitStructure);
#endif	

#if TIM8_CH4_ENABLE == 1
	//��ʼ��Ϊ��Ӧͨ���������ͨ��1
	RCC_AHB1PeriphClockCmd(TIM8_CH4_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = TIM8_CH4_Pin;
	GPIO_Init(TIM8_CH4_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(TIM8_CH4_GPIO_PORT,TIM8_CH4_PINSOURCE, GPIO_AF_TIM8);
	TIM_OC4Init(TIM8, &TIM_OCInitStructure);
#endif	

	//ʹ�ܶ�ʱ��
	TIM_Cmd(TIM8, ENABLE);

	/* �߼���ʱ����Ҫʹ��PWM��� */
	TIM_CtrlPWMOutputs(TIM8, ENABLE);
}




//����Ħ���ֶ�Ӧtim12��ͨ��1,2 
void TIM12_PWM_Init(u16 prescaler, u16 period, u16 Pulse)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;	/* ����ʱ���ṹ�� */
	TIM_OCInitTypeDef  TIM_OCInitStructure;	/*��������ȽϽṹ��*/
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM12, ENABLE);//ʹ�ܶ�ʱ��ʱ��
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;    
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_Init(GPIOH, &GPIO_InitStructure);
	GPIO_PinAFConfig(GPIOH,GPIO_PinSource6, GPIO_AF_TIM12);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_Init(GPIOH, &GPIO_InitStructure);
	GPIO_PinAFConfig(GPIOH,GPIO_PinSource9, GPIO_AF_TIM12);

	//���ö�ʱ��ʱ�ӷ�Ƶ
	TIM_TimeBaseStructure.TIM_Prescaler = prescaler;
	//�����Զ���װ�ؼĴ�����ֵ
	TIM_TimeBaseStructure.TIM_Period = period;
	//��������ʱ��������˲���Ƶ������Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	//���ü���ģʽ�����ϼ���
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	
	TIM_TimeBaseInit(TIM12, &TIM_TimeBaseStructure);
	
	//�������ģʽ��PWM1ģʽ
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	//ʹ�����
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	//��ʹ�ܻ������
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
	//���ó�ʼռ�ձ�
	TIM_OCInitStructure.TIM_Pulse = Pulse;
	//����PWM���ԣ���ʼ��ƽΪ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	//���ÿ���ʱ�����ƽ
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
	
	//���û������PWM���ԣ���ʼ��ƽΪ��(����ҲҪ���ã�����������ܳ���)
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	//���û����������ʱ�����ƽ(����ҲҪ���ã�����������ܳ���)
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;

	//��ʼ��Ϊ��Ӧͨ���������ͨ��1
	TIM_OC1Init(TIM12, &TIM_OCInitStructure);

	//��ʼ��Ϊ��Ӧͨ���������ͨ��1
	TIM_OC2Init(TIM12, &TIM_OCInitStructure);

	//ʹ�ܶ�ʱ��
	TIM_Cmd(TIM12, ENABLE);

}

