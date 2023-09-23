#include "adc.h"

void ADC_Config()
{
	ADC_InitTypeDef ADC_InitStructure;
	ADC_CommonInitTypeDef ADC_CommonInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);//ʱ��ʹ��
	
	/********************************/
	ADC_DeInit();
	ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;//����ģʽ
	ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div8;//Ԥ��Ƶ8��Ƶ��
	ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//������䲻Ӱ��ͨ������ӳ٣�ֻ���ڶ��ADCʹ��ʱ������Ч,����Ƶ�������޹�
  ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //DMAʧ��
  ADC_CommonInit(&ADC_CommonInitStructure);
	
	/********************************************************************************************************/
	ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//����ADC�ķֱ���Ϊ12λ����ÿ������ֵռ��12λ
  ADC_InitStructure.ADC_ScanConvMode = DISABLE;//��ɨ��
  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;//��������
  ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//��ֹ�ⲿ����
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//�Ҷ���
  ADC_InitStructure.ADC_NbrOfConversion = 1;//ֻת����������1
  ADC_Init(ADC1, &ADC_InitStructure);
	
	/**********ת��������***************************/
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_480Cycles );//����Ƶ��Ϊ21.314kHz
  
  ADC_DMARequestAfterLastTransferCmd(ADC1, ENABLE);
	ADC_DMACmd(ADC1, ENABLE);
	
	ADC_Cmd(ADC1, ENABLE);//ʹ��
 
}