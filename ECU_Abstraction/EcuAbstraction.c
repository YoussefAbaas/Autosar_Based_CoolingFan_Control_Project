#include"Rte_TempHBridgeSWC.h"

//code for runnable read tempreture

void ReadTemperature_Function()
{
	uint16 adc_result;
	float PinVoltage,Temperature;
	//trigger adc conversion and read result
	Adc_StartGroupConversion(0);
	Adc_ReadGroup(0,&adc_result);
	
	//convert adc value to voltage 
	//assume 12 bits adc with ref 3.3v
	PinVoltage=(3.3/4095)*adc_result;
	//convert voltage to temperature (can be done in sensor actuator swc)
	//sensor -> for 35deg output in 0.35v
	Temperature=PinVoltage*100;
	
	//write temperature result to RTE
	 Rte_Write_PP_Tempereture_Tempreture(Temperature)
	
}
//code for runnable StartMotor (server)
void StartMotor_Function(uint8 Fanspeed)
{
	if(Fanspeed<50)
	{
		//trigger cooling fan with halfspeed
	    //H-bridge setting login to (1,0)
		Dio_WriteChannel(10,STD_High);
		Dio_WriteChannel(11,STD_LOW);
	}
	else //run fan at full speed 
	{
		//H-bridge setting login to (1,1)
		Dio_WriteChannel(10,STD_High);
		Dio_WriteChannel(11,STD_High);
	}
}
//code for runnable StopMotor
void StopMotor_Function()
{
	//H-bridge setting login to (0,0)
	Dio_WriteChannel(10,STD_LOW);
	Dio_WriteChannel(11,STD_LOW);
}