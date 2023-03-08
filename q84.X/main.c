#include "mcc_generated_files/mcc.h"

/*
	Main application
 */
void main(void)
{
	// Initialize the device
	SYSTEM_Initialize();

	DMA1_SetSourceAddress((uint24_t) bpattern);
	DMA2_SetSourceAddress((uint24_t) dpattern);
	DMA1_SetSourceSize(8);
	DMA1_SetDestinationSize(1);
	DMA1_SetDestinationAddress((uint16_t) & LATB);
	DMA2_SetSourceSize(8);
	DMA2_SetDestinationSize(1);
	DMA2_SetDestinationAddress((uint16_t) & LATD);

	bpattern[0] = 0xff;
	dpattern[1] = 0xff;
	bpattern[2] = 0xff;
	dpattern[3] = 0xff;
	bpattern[4] = 0xff;
	dpattern[5] = 0xff;
	bpattern[6] = 0xff;
	dpattern[7] = 0xff;

	while (true) {
		d_trig_SetHigh();
		IO_RD0_Toggle();
		IO_RD1_Toggle();
		IO_RD2_Toggle();
		IO_RD3_Toggle();
		IO_RD4_Toggle();
		IO_RD5_Toggle();
		IO_RD6_Toggle();
		IO_RD7_Toggle();
		d_trig_SetLow();
		DMA1_StartTransfer();
		d_trig_SetHigh();
		IO_RD0_Toggle();
		IO_RD1_Toggle();
		IO_RD2_Toggle();
		IO_RD3_Toggle();
		IO_RD4_Toggle();
		IO_RD5_Toggle();
		IO_RD6_Toggle();
		IO_RD7_Toggle();
		d_trig_SetLow();
		d_trig_SetHigh();
		DMA2_StartTransfer();
		d_trig_SetLow();
	}
}
/**
 End of File
 */