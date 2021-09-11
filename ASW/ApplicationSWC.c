#include "Rte_CoonlingControlSWC.h"
void ApplTemperatureControl()
{
	float Temperature
	//read data from ecu abstraction layer
	Rte_Read_RP_Temperature_Temperature(&Temperature);
	
	//control logic
	if(Temperature>50&&Temperature<75)
	{// start cooling fan (low speed)
      Rte_Call_RP_StartMotor_StartMotor(25);
	 
	}
	else if(Temperature>75)
	{
		//start cooling fan (high speed)
		Rte_Call_RP_StartMotor_StartMotor(50);
	}
	else if(Temperature<40)
	{
		Rte_Call_RP_StopMotor_StopMotor();
	}
}