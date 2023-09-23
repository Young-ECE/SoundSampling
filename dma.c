#include "dma.h"
#include "usart.h"

uint16_t AdcToDma_buffer[BUFFER_SIZE]={0};
uint16_t AdcToDma_buffer_1[BUFFER_SIZE]={0};


void Adc_Dma_Config()
{
	DMA_InitTypeDef DMA_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);
	
	DMA_InitStructure.DMA_Channel = DMA_Channel_0;                   						//ѡ��Channel_0
  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&(ADC1->DR);							//���ݴ���������׵�ַ��������
	DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)&AdcToDma_buffer;	 	//�Լ����������������׵�ַ��Ҫǿ��ת��Ϊ32λ
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;       							//���ݴ��䷽��ѡ��Ϊ����->�ڴ�
	DMA_InitStructure.DMA_BufferSize = BUFFER_SIZE;                    										//�������ֵ�����Ƕ���������Сһ��		 
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable; 						//���������ģʽ			
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;        							//�ڴ������ģʽ		 
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;	//�������ݴ�СΪ����	
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;     		//�ڴ����ݴ�СΪ����		
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;     												  //DMAΪѭ��ģʽ	 
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;   											//DMA���ȼ�Ϊ��		
	DMA_InitStructure.DMA_FIFOMode=DMA_FIFOMode_Disable;												//����͹ٷ����̲�ͬ
	DMA_InitStructure.DMA_FIFOThreshold=DMA_FIFOThreshold_HalfFull;							//FIFO��ص�����
	DMA_InitStructure.DMA_MemoryBurst=DMA_MemoryBurst_Single;										//�洢��ͻ�����δ���
	DMA_InitStructure.DMA_PeripheralBurst=DMA_PeripheralBurst_Single;						//����ͻ�����δ���
	DMA_Init(DMA2_Stream0, &DMA_InitStructure);
	
	DMA_DoubleBufferModeConfig(DMA2_Stream0, (uint32_t)AdcToDma_buffer_1, DMA_Memory_0);
  DMA_DoubleBufferModeCmd(DMA2_Stream0, ENABLE);
   
	DMA_Cmd(DMA2_Stream0, ENABLE);	 //ʹ��DMA2_Stream0ͨ��
	
	#if 1
	
	NVIC_InitTypeDef NVIC_InitStruct;
  NVIC_InitStruct.NVIC_IRQChannel = DMA2_Stream0_IRQn;
  NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x01;
  NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x00;
  NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStruct);

	DMA_ITConfig(DMA2_Stream0, DMA_IT_TC, ENABLE);
	
	#endif
}




