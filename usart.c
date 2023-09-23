 #include "usart.h"
 
 void Usart_Config(uint32_t baud)
 {
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);//ʹ��USART2ʱ��
   //USART2 ��ʼ������
	 
	USART_DeInit(USART2);
	USART_InitStructure.USART_BaudRate = baud;//����������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
  USART_Init(USART2, &USART_InitStructure); //��ʼ������
  USART_Cmd(USART2, ENABLE);  //ʹ�ܴ���
	 /***********************************/
	
	
#if EN_USART2_RX	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//��������ж�
	//Usart1 NVIC ����
  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;//����2�ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01;//��ռ���ȼ�1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0x01;		//�����ȼ�1
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ�����
#endif
	
}



void USART2_SendData_AutoClrFlag(USART_TypeDef* USARTx, uint16_t Data)
{
	USART_SendData(USART2,Data);
	while (!(USART2->SR & USART_SR_TXE));
	USART_ClearFlag(USART2, USART_FLAG_TC);//��֤�������
}
	 
	 
 