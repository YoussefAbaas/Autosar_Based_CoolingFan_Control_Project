
#include "Adc.h"
#include "StandardTypes.h"
#include "TM4C123GH6PM.h"
//function to start adc conversion
void Adc_StartGroupConversion( Adc_GroupType Group )
{
	if(Group==0)
	{
		//code to start Adc conversion
		SYSCTL_RCGCADC_R|=(1<<0)//enable clock to adc
		SYSCTL_RCGCGPIO_R|=(1<<5)//enable clock to port E
		GPIO_PORTE_AFSEL_R|=(1<<3) //pin E3 has alternate function
		GPIO_PORTE_DEN_R&=~(1<<3); //disable digital mode
		GPIO_PORTE_AMSEL_R|=(1<<3); //enable analog mode
		ADC0_ACTSS_R&=~(1<<3); //disable sample sequencer
		ADC0_EMUX_R&=~0xf000; // make sw event as start conversion trigger
		ADC0_SSMUX3_R=0;//select channel 0 
		ADC0_PC_R=0x3;//sample rate is 250kps
		ADC0_PSSI_R|=(1<<3);//start conversion
		while(ADC0_RIS_R&8==0);//wait until conversion finishes
		
	}
}
//function to read adc group
Std_ReturnType Adc_ReadGroup( Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr )
{
	unsigned int ADC_Value;
	Std_ReturnType return_type=E_OK;
	if(Group==0)
	{
		ADC_Value=ADC0_SSFIFO3_R;   // read adc value from register
		*DataBufferPtr=ADC_Value; //write back adc value
	}
	return return_type;
}