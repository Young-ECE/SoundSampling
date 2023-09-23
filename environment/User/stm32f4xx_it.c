#include "usart.h"
#include "dma.h"
#include "key.h"


/**************************���ڽ����жϷ�����********************************************/

void USART2_IRQHandler(void)  	//����2�жϷ������
{
	uint8_t Res;
 
	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)  //�����ж�
	{
		
		Res =USART_ReceiveData(USART2);	//��ȡ���յ�������
		USART_SendData(USART2,Res);
		
  }	
   USART_ClearFlag(USART2, USART_FLAG_RXNE);
} 

/**************************DMA�жϷ�����********************************************/
void DMA2_Stream0_IRQHandler(void)
{
	  uint8_t* adr;//��ַͷ��
	
  if (DMA_GetITStatus(DMA2_Stream0, DMA_IT_TCIF0))
  {
    DMA_ClearITPendingBit(DMA2_Stream0, DMA_IT_TCIF0);
		if (DMA_GetCurrentMemoryTarget(DMA2_Stream0))
		{
			adr =  AdcToDma_buffer;
		}
		else
		{	
		  adr =  AdcToDma_buffer_1;
    }
	
	  USART2_SendData_AutoClrFlag(USART2,0xFF);
	  USART2_SendData_AutoClrFlag(USART2,0xFF);//֡ͷ
		for(int i=0;i<BUFFER_SIZE*2;i+=2)       
     	{
			
		  USART2_SendData_AutoClrFlag(USART2,adr[i+1]);
			USART2_SendData_AutoClrFlag(USART2,adr[i]); //�����С�����⣨STM32F4��С�˴洢����λ�ڸߵ�ַ����λ�ڵ͵�ַ��
	    }
	  USART2_SendData_AutoClrFlag(USART2,0x0D);
		USART2_SendData_AutoClrFlag(USART2,0x0A);//֡β
			
   }
}
/**************************�ⲿ�жϷ�����********************************************/

void EXTI3_IRQHandler(void)
{
	delay_ms(10);
	if(KEY_3 == 0)
	{
		keyValue = KEY_3_PRESS;
	}
	EXTI_ClearITPendingBit(EXTI_Line3);
	
}
void EXTI4_IRQHandler(void)
{
	delay_ms(10);
	if(KEY_4 == 0)
	{
		keyValue = KEY_4_PRESS;
	}
	EXTI_ClearITPendingBit(EXTI_Line4);
	
}



/*************************************************/



void NMI_Handler(void)
{
}


void HardFault_Handler(void)
{
  
  while (1)
  {
  }
}


void MemManage_Handler(void)
{
  
  while (1)
  {
  }
}


void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}


void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}


void SVC_Handler(void)
{
}


void DebugMon_Handler(void)
{
}


void PendSV_Handler(void)
{
}




