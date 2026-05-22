/*
  @file 
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  Modified by Sebas Monje <2024-2025> to M.U.A. MISSION

  -> GuaraníSat2 -> MUA_Control -> FIUNA -> LME
*/
/**
 * PIO_SERCOM:      First SERCOM
 * PIO_SERCOM_ALT:  Second SERCOM
 */


#include "variant.h"
// PIN DESCRIPTIONS
const PinDescription g_APinDescription[]=
{ 
  // 0 - NC (NO CONECTED) - TC2_1
  { PORTA,  1, PIO_DIGITAL,     PIN_ATTR_NONE,    No_ADC_Channel, TC2_CH1,    TC2_CH1,      EXTERNAL_INT_1},

  // 1 - NC  
  { PORTA,  2, PIO_ANALOG,      PIN_ATTR_ANALOG,  ADC_Channel0,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 },
  
  // 2 - VANAREF
  { PORTA,  3, PIO_ANALOG,      PIN_ATTR_ANALOG,  ADC_Channel1,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // DAC/VREFP
  
  // 3 - PULSE_1 - DIGITAL I
  { PORTB,  4, PIO_DIGITAL,     PIN_ATTR_NONE,    No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4 },
  
  // 4 - DIGITAL I/O
  { PORTB,  5, PIO_DIGITAL,     PIN_ATTR_NONE,    No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5 },

  // 5 ... 8 - DIGITAL I/O
  { PORTB,  6, PIO_DIGITAL,     PIN_ATTR_NONE,    No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 },
  { PORTB,  7, PIO_DIGITAL,     PIN_ATTR_NONE,    No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7 },
  { PORTB,  8, PIO_DIGITAL,     PIN_ATTR_PWM_E,   No_ADC_Channel, TC4_CH0,    TC4_CH0,      EXTERNAL_INT_8 },
  { PORTB,  9, PIO_DIGITAL,     PIN_ATTR_NONE,    No_ADC_Channel, TC4_CH1,    TC4_CH1,      EXTERNAL_INT_9 },

  // 9 ... 12 - SPI1 (MOSI1, SCK1, MISO1, CS1) : SERCOM 0 - ADC      // PAD_0 (MOSI), PAD_1 (SCK), PAD_2 (MISO)
  { PORTA,  4, PIO_SERCOM_ALT,  PIN_ATTR_PWM_E,   No_ADC_Channel, TC0_CH0,    TC0_CH0,      EXTERNAL_INT_4 },
  { PORTA,  5, PIO_SERCOM_ALT,  PIN_ATTR_PWM_E,   No_ADC_Channel, TC0_CH1,    NOT_ON_TIMER, EXTERNAL_INT_5 },
  { PORTA,  6, PIO_SERCOM_ALT,  PIN_ATTR_PWM_E,   No_ADC_Channel, TC1_CH0,    TC1_CH0,      EXTERNAL_INT_6 },
  { PORTA,  7, PIO_DIGITAL,     PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7 },

  // 13 ... 18 - QSPI (D0, D1, D2, D3, SCK, CS) - FLASH MEMORY
  { PORTA,  8, PIO_COM,         PIN_ATTR_NONE,    No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NMI },
  { PORTA,  9, PIO_COM,         PIN_ATTR_NONE,    No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9 },
  { PORTA, 10, PIO_COM,         PIN_ATTR_NONE,    No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10 },
  { PORTA, 11, PIO_COM,         PIN_ATTR_NONE,    No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 },
  { PORTB, 10, PIO_COM,         PIN_ATTR_NONE,    No_ADC_Channel, TCC1_CH0,   TC5_CH0,      EXTERNAL_INT_10 },
  { PORTB, 11, PIO_COM,         PIN_ATTR_NONE,    No_ADC_Channel, TCC1_CH1,   TC5_CH1,      EXTERNAL_INT_11 },

  // 19 ... 20 - UART (Tx, Rx) : SERCOM 4 - Serial 1 - OBC        // PAD_0 (Tx), PAD_1 (Rx) // 
  // 19 ... 20 - UART (Tx, Rx) : SERCOM 4 - Serial 1 - GPS        // PAD_0 (Tx), PAD_1 (Rx) // CORRECCION
  { PORTB, 12, PIO_SERCOM,      PIN_ATTR_PWM_G,   No_ADC_Channel, TCC3_CH0,   NOT_ON_TIMER, EXTERNAL_INT_12 },
  { PORTB, 13, PIO_SERCOM,      PIN_ATTR_PWM_G,   No_ADC_Channel, TCC0_CH1,   TC4_CH1,      EXTERNAL_INT_13 },

  // 21 - NC
  { PORTB, 14, PIO_DIGITAL,     PIN_ATTR_DIGITAL, No_ADC_Channel, TCC4_CH0,   TC5_CH0,      EXTERNAL_INT_14 },
  
  // 22 - DIGITAL O - INTERFACE_EN
  { PORTB, 15, PIO_DIGITAL,     PIN_ATTR_DIGITAL, No_ADC_Channel, TCC4_CH1,   TC5_CH1,      EXTERNAL_INT_15 },

  // 23 ... 24 - I2C (SDA, SCL) : SERCOM 2 - TMP100               // PAD_0 (SDA), PAD_1 (SCL)
  { PORTA, 12, PIO_SERCOM,      PIN_ATTR_PWM_G,   No_ADC_Channel, TCC1_CH2,   TC2_CH0,      EXTERNAL_INT_12 },
  { PORTA, 13, PIO_SERCOM,      PIN_ATTR_PWM_G,   No_ADC_Channel, TCC1_CH3,   NOT_ON_TIMER, EXTERNAL_INT_13 },

  // 25 - DIGITAL O - CS_MAX2
  { PORTA, 14, PIO_DIGITAL,     PIN_ATTR_PWM_G,   No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_14 },
  
  // 26 - NC - TC3_CH1
  { PORTA, 15, PIO_DIGITAL,     PIN_ATTR_PWM_G,   No_ADC_Channel, TCC2_CH1,   TC3_CH1,      EXTERNAL_INT_15 },

  // 27 ... 30 - SPI (MOSI, SCK, MISO, CS_MAX1) : SERCOM 1 - MAX1932
  { PORTA, 16, PIO_SERCOM,      PIN_ATTR_PWM_F,   No_ADC_Channel, TCC1_CH0,   TC2_CH0,      EXTERNAL_INT_0 },
  { PORTA, 17, PIO_SERCOM,      PIN_ATTR_PWM_G,   No_ADC_Channel, TCC0_CH5,   NOT_ON_TIMER, EXTERNAL_INT_1 },
  { PORTA, 18, PIO_SERCOM,      PIN_ATTR_PWM_F,   No_ADC_Channel, TCC1_CH2,   TC3_CH0,      EXTERNAL_INT_2 },
  { PORTA, 19, PIO_DIGITAL,     PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 },// D14 - 3.3V_EN

  // 31 ... 32 - UART (Tx, Rx): SERCOM 5 - Serial 2 - GPS
  // 31 ... 32 - UART (Tx, Rx): SERCOM 5 - Serial 2 - OBC   // CORRECCION
  { PORTB, 16, PIO_SERCOM,      PIN_ATTR_PWM_G,   No_ADC_Channel, TCC3_CH0,   TC6_CH0,      EXTERNAL_INT_0 },
  { PORTB, 17, PIO_SERCOM,      PIN_ATTR_PWM_F,   No_ADC_Channel, TCC3_CH1,   TC6_CH1,      EXTERNAL_INT_1 },

  // 33 ... 34 - DIGITAL I/O
  { PORTA, 20, PIO_DIGITAL,     PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4 },
  { PORTA, 21, PIO_DIGITAL,     PIN_ATTR_PWM_F,   No_ADC_Channel, TCC0_CH1,   TC7_CH0,      EXTERNAL_INT_5 },
  
  // 35 ... 36 - DIGITAL O - CS_DAC2, CS_DAC1
  { PORTA, 22, PIO_DIGITAL,     PIN_ATTR_PWM_F,   No_ADC_Channel, TCC0_CH2,   TC4_CH0,      EXTERNAL_INT_6 },
  { PORTA, 23, PIO_DIGITAL,     PIN_ATTR_PWM_G,   No_ADC_Channel, TCC0_CH3,   TC4_CH1,      EXTERNAL_INT_7 },

  // 37 ... 38 - USB - Serial
  { PORTA, 24, PIO_COM,         PIN_ATTR_NONE,    No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8 },
  { PORTA, 25, PIO_COM,         PIN_ATTR_NONE,    No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9 },
  
  // 39 ... 41 - NC
  { PORTB, 22, PIO_DIGITAL,     PIN_ATTR_NONE,    No_ADC_Channel, NOT_ON_PWM, TC7_CH0,      EXTERNAL_INT_6 },
  { PORTB, 23, PIO_DIGITAL,     PIN_ATTR_NONE,    No_ADC_Channel, NOT_ON_PWM, TC7_CH1,      EXTERNAL_INT_7 },
  { PORTA, 27, PIO_DIGITAL,     PIN_ATTR_NONE,    No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 }, 

  // 42 - SWO
  { PORTB, 30, PIO_DIGITAL,     PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, TC0_CH0,      EXTERNAL_INT_14 },
  
  // 43 ... 45 - NC
  { PORTB, 31, PIO_TIMER,       PIN_ATTR_NONE,    No_ADC_Channel, NOT_ON_PWM, TC0_CH0,      EXTERNAL_INT_15 },
  { PORTB,  0, PIO_ANALOG,      PIN_ATTR_ANALOG,  ADC_Channel12,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_0 },
  { PORTB,  1, PIO_ANALOG,      PIN_ATTR_ANALOG,  ADC_Channel13,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_1 },
  
  // 46 - PULSE_2 - DIGITAL I
  { PORTB,  2, PIO_DIGITAL,     PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 },
  
  // 47 - DIGITAL O - BUILT_IN_LED
  { PORTB,  3, PIO_DIGITAL,     PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 },

  // 48 ... 49 - I2C1 (SDA1, SCL1) : SERCOM 3
  { PORTA, 22, PIO_SERCOM,      PIN_ATTR_PWM_F,   No_ADC_Channel, TCC0_CH2,   TC4_CH0,      EXTERNAL_INT_6 },
  { PORTA, 23, PIO_SERCOM,      PIN_ATTR_PWM_G,   No_ADC_Channel, TCC0_CH3,   TC4_CH1,      EXTERNAL_INT_7 },

} ;

//Grommeck 2026-05-22 Removed TC6
const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TCC3, 
                                                        TCC4, TC0, TC1, TC2, 
                                                        TC3, TC4, TC5};

//Grommeck 2026-05-22 Removed TC6_GCLK_ID
const uint32_t GCLK_CLKCTRL_IDs[TCC_INST_NUM+TC_INST_NUM] = { TCC0_GCLK_ID, TCC1_GCLK_ID, TCC2_GCLK_ID, 
                                                              TCC3_GCLK_ID, TCC4_GCLK_ID, TC0_GCLK_ID, 
                                                              TC1_GCLK_ID, TC2_GCLK_ID, TC3_GCLK_ID, 
                                                              TC4_GCLK_ID, TC5_GCLK_ID};

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;
SERCOM sercom4( SERCOM4 ) ;
SERCOM sercom5( SERCOM5 ) ;

#ifndef CORRECCION
Uart Serial1( &sercom4, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ) ;
Uart Serial2( &sercom5, PIN_SERIAL2_RX, PIN_SERIAL2_TX, PAD_SERIAL2_RX, PAD_SERIAL2_TX ) ;

void SERCOM4_0_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM4_1_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM4_2_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM4_3_Handler()
{
  Serial1.IrqHandler();
}

void SERCOM5_0_Handler()
{
  Serial2.IrqHandler();
}
void SERCOM5_1_Handler()
{
  Serial2.IrqHandler();
}
void SERCOM5_2_Handler()
{
  Serial2.IrqHandler();
}
void SERCOM5_3_Handler()
{
  Serial2.IrqHandler();
}
#else
Uart Serial2( &sercom4, PIN_SERIAL2_RX, PIN_SERIAL2_TX, PAD_SERIAL2_RX, PAD_SERIAL2_TX ) ;
Uart Serial1( &sercom5, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ) ;

void SERCOM4_0_Handler()
{
  Serial2.IrqHandler();
}
void SERCOM4_1_Handler()
{
  Serial2.IrqHandler();
}
void SERCOM4_2_Handler()
{
  Serial2.IrqHandler();
}
void SERCOM4_3_Handler()
{
  Serial2.IrqHandler();
}

void SERCOM5_0_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM5_1_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM5_2_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM5_3_Handler()
{
  Serial1.IrqHandler();
}
#endif


// 27/09
// Resolving sparkfun_samd51_micromod dependencies...
// Platform Manager: Updating atmelsam @ 8.2.1
// Platform Manager: Removing atmelsam @ 8.2.1
// Platform Manager: atmelsam@8.2.1 has been removed!      
// Platform Manager: Installing platformio/atmelsam @ 8.3.0
// Downloading  [####################################]  100%
// Unpacking  [####################################]  100%
// Platform Manager: atmelsam@8.3.0 has been installed!
// PS C:\Users\Pc\Documents\SAMD_Prueba1> 
