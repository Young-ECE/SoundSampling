 #include "usart.h"
 
 void Usart_Config(uint32_t baud)
 {
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);//使能USART2时钟
   //USART2 初始化设置
	 
	USART_DeInit(USART2);
	USART_InitStructure.USART_BaudRate = baud;//波特率设置
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式
  USART_Init(USART2, &USART_InitStructure); //初始化串口
  USART_Cmd(USART2, ENABLE);  //使能串口
	 /***********************************/
	
	
#if EN_USART2_RX	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//开启相关中断
	//Usart1 NVIC 配置
  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;//串口2中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01;//抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0x01;		//子优先级1
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器、
#endif
	
}



void USART2_SendData_AutoClrFlag(USART_TypeDef* USARTx, uint16_t Data)
{
	USART_SendData(USART2,Data);
	while (!(USART2->SR & USART_SR_TXE));
	USART_ClearFlag(USART2, USART_FLAG_TC);//保证传输完毕
}
	 
	 
 