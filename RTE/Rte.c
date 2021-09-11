#include"Rte.h"

float Temperature;
Std_ReturnType Rte_Write_PP_Tempereture_Tempreture(float result)
{
Temperature=result;
return RTE_E_OK;
}

Std_ReturnType Rte_Read_PP_Tempereture_Tempreture(float*result)
{
*result=Temperature;
return RTE_E_OK;
}

Rte_Call_RP_StartMotor_StartMotor(uint8 fanspeed)
{
	StartMotor_Function(fanspeed);
	return RTE_E_OK;
}

Rte_Call_RP_StopMotor_StopMotor()
{
	StopMotor_Function();
	return RTE_E_OK;
}