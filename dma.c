#include "dma.h"
#include "usart.h"

uint16_t AdcToDma_buffer[BUFFER_SIZE]={0};
uint16_t AdcToDma_buffer_1[BUFFER_SIZE]={0};


void Adc_Dma_Config()
{
	DMA_InitTypeDef DMA_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);
	
	DMA_InitStructure.DMA_Channel = DMA_Channel_0;                   						//选择Channel_0
  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&(ADC1->DR);							//数据传输的外设首地址，详解见上
	DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)&AdcToDma_buffer;	 	//自己定义待发送数组的首地址，要强制转换为32位
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;       							//数据传输方向选择为外设->内存
	DMA_InitStructure.DMA_BufferSize = BUFFER_SIZE;                    										//数据项的值和我们定义的数组大小一致		 
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable; 						//外设非增量模式			
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;        							//内存非增量模式		 
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;	//外设数据大小为半字	
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;     		//内存数据大小为半字		
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;     												  //DMA为循环模式	 
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;   											//DMA优先级为高		
	DMA_InitStructure.DMA_FIFOMode=DMA_FIFOMode_Disable;												//这里和官方例程不同
	DMA_InitStructure.DMA_FIFOThreshold=DMA_FIFOThreshold_HalfFull;							//FIFO相关的设置
	DMA_InitStructure.DMA_MemoryBurst=DMA_MemoryBurst_Single;										//存储器突发单次传输
	DMA_InitStructure.DMA_PeripheralBurst=DMA_PeripheralBurst_Single;						//外设突发单次传输
	DMA_Init(DMA2_Stream0, &DMA_InitStructure);
	
	DMA_DoubleBufferModeConfig(DMA2_Stream0, (uint32_t)AdcToDma_buffer_1, DMA_Memory_0);
  DMA_DoubleBufferModeCmd(DMA2_Stream0, ENABLE);
   
	DMA_Cmd(DMA2_Stream0, ENABLE);	 //使能DMA2_Stream0通道
	
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




