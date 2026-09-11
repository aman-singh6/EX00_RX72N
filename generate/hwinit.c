/************************************************************************
*
* Device     : RX/RX600/RX72N
*
* File Name  : hwsetup.c
*
* Abstract   : Hardware Setup file.
*
* History    : V1.00C (2019-07-17)  [Hardware Manual Revision : 1.00]
*
* NOTE       : THIS IS A TYPICAL EXAMPLE.
*
*  Copyright(c) 2019 Renesas Electronics Corporation.
*
************************************************************************/

#include "iodefine.h"
#ifdef __cplusplus
extern "C" {
#endif
extern void HardwareSetup(void);
#ifdef __cplusplus
}
#endif

void HardwareSetup(void)
{
/*
 BSC.CS0MOD.WORD = 0x1234;
 BSC.CS7CNT.WORD = 0x5678;
  
 SCI0.SCR.BIT.TE  = 0;
 SCI0.SCR.BIT.RE  = 0;
 SCI0.SCR.BIT.TE  = 1;
 SCI2.SSR.BIT.PER = 0;

 TMR0.TCR.BYTE = 0x12;
 TMR1.TCR.BYTE = 0x12;
 TMR2.TCR.BYTE = 0x12;
 
 P0.DDR.BYTE = 0x12;
 P1.DDR.BYTE = 0x12;
*/
}
