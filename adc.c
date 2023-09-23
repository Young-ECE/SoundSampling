#include "adc.h"

void ADC_Config()
{
	ADC_InitTypeDef ADC_InitStructure;
	ADC_CommonInitTypeDef ADC_CommonInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);//时钟使能
	
	/********************************/
	ADC_DeInit();
	ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;//独立模式
	ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div8;//预分频8分频。
	ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//这条语句不影响通道间的延迟，只用于多个ADC使用时，才有效,采样频率与它无关
  ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //DMA失能
  ADC_CommonInit(&ADC_CommonInitStructure);
	
	/********************************************************************************************************/
	ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//设置ADC的分辨率为12位，即每个采样值占用12位
  ADC_InitStructure.ADC_ScanConvMode = DISABLE;//非扫描
  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;//连续采样
  ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//禁止外部触发
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//右对齐
  ADC_InitStructure.ADC_NbrOfConversion = 1;//只转换规则序列1
  ADC_Init(ADC1, &ADC_InitStructure);
	
	/**********转换组设置***************************/
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_480Cycles );//采样频率为21.314kHz
  
  ADC_DMARequestAfterLastTransferCmd(ADC1, ENABLE);
	ADC_DMACmd(ADC1, ENABLE);
	
	ADC_Cmd(ADC1, ENABLE);//使能
 
}