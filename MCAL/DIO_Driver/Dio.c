//Mcal layer for dio driver
#include "Dio.h"
#include "TM4C123GH6PM.h"
#define BIT0 0x01
#define BIT1 0x02
//function to read channel
Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId )
{
	unsigned int Read_val;
	//assume channel 10 mapped to PortB
	if(ChannelId==10)
	{
		Read_val= GPIO_PORTB_DATA_R&BIT0;
		if(Read_val==0x00)
			return STD_LOW;
		else 
			return STD_HIGH;
	}
	if(ChannelId==11)
	{
		Read_val= GPIO_PORTB_DATA_R&BIT1;
		if(Read_val==0x00)
			return STD_LOW;
		else 
			return STD_HIGH;
	}
	//......continous for other pins
	
}

// function to write to a port
void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )

{
	if(ChannelId==10)
	{
		if(Level==STD_LOW)
			GPIO_PORTB_DATA_R&=~BIT0;
		else 
			GPIO_PORTB_DATA_R|=BIT0;
	}
	if(ChannelId==11)
	{
		if(Level==STD_LOW)
			GPIO_PORTB_DATA_R&=~BIT1;
		else 
			GPIO_PORTB_DATA_R|=BIT1;
	}
	
	//continue for other ids
}