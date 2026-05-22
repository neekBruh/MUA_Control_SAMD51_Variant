/*
  @file varian.h
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  Modified by Sebas Monje <2024-2025> to M.U.A. MISSION

  -> GuaraníSat2 -> MUA_Control -> FIUNA -> LME
*/

#ifndef _VARIANT_SAMD51_MICROMOD_
#define _VARIANT_SAMD51_MICROMOD_

// The definitions here needs a SAMD core >=1.6.10
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10610

//----------------------------------------------------------------------------
//        Definitions
//----------------------------------------------------------------------------

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		(32768ul)

/** Master clock frequency */
#define VARIANT_MCK			  (120000000ul)

#define VARIANT_GCLK0_FREQ (120000000UL)
#define VARIANT_GCLK1_FREQ (48000000UL)
#define VARIANT_GCLK2_FREQ (100000000UL)

// #define PLACA_PRUEBAS
#define PLACA_FINAL
#define CORRECCION

//----------------------------------------------------------------------------
//        Headers
//----------------------------------------------------------------------------

#include "WVariant.h"

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef PLACA_FINAL
#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

//----------------------------------------------------------------------------
//        Pins
//----------------------------------------------------------------------------

// Number of pins defined in PinDescription array
#define PINS_COUNT           (49u)                
#define NUM_DIGITAL_PINS     (22u)
#define NUM_ANALOG_INPUTS    (3u)
#define NUM_ANALOG_OUTPUTS   (0u)
#define analogInputToDigitalPin(p)  ((p < 6u) ? (p) + 14u : -1)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

// General Purpose Pins
#define G0  0   // NC
#define G1  3   // PULSE_1
#define G2  4   // DIO
#define G3  5   // DIO
#define G4  6   // DIO
#define G5  8   // LED_SiPM1
#define G6  21  // NC
#define G7  22  // INTERFACE_EN
#define G8  25  // CS_MAX2
#define G9  26  // NC
//#define G10 33  // DIO
//#define G11 34  // DIO
#define G12 35  // CS_DAC2
#define G13 36  // CS_DAC1
#define G14 39  // NC
#define G15 40  // NC
#define G16 41  // NC
#define G17 46  // PULSE_2
#define G18 7   // LED_SiPM2

#define G33 33
#define G34 34


// LEDs
//-------------------------------------------
#define PIN_LED_13           (47u)  // PB03
#define PIN_LED              PIN_LED_13
#define LED_BUILTIN          PIN_LED_13
//-------------------------------------------

// Analog pins
//-------------------------------------------
#define PIN_A0               (1ul)  // PA02
#define PIN_A1               (44ul) // PB00
#define PIN_A2               (45ul) // PB01

static const uint8_t A0   = PIN_A0;
static const uint8_t A1   = PIN_A1;
static const uint8_t A2   = PIN_A2;

#define ADC_RESOLUTION		12
//-------------------------------------------

// Other pins
#define PIN_ATN              (2ul)  // PA03
static const uint8_t ATN = PIN_ATN;

// Serial Interfaces
//-------------------------------------------

#ifndef CORRECCION
// Serial1 
#define PIN_SERIAL1_TX       (19ul) // PB12
#define PIN_SERIAL1_RX       (20ul) // PB13
#define PAD_SERIAL1_TX       (UART_TX_PAD_0)
#define PAD_SERIAL1_RX       (SERCOM_RX_PAD_1)

// Serial2
#define PIN_SERIAL2_TX       (31ul) // PB16
#define PIN_SERIAL2_RX       (32ul) // PB17
#define PAD_SERIAL2_TX       (UART_TX_PAD_0)
#define PAD_SERIAL2_RX       (SERCOM_RX_PAD_1)
//-------------------------------------------
#else
// Serial2 
#define PIN_SERIAL2_TX       (19ul) // PB12
#define PIN_SERIAL2_RX       (20ul) // PB13
#define PAD_SERIAL2_TX       (UART_TX_PAD_0)
#define PAD_SERIAL2_RX       (SERCOM_RX_PAD_1)

// Serial1
#define PIN_SERIAL1_TX       (31ul) // PB16
#define PIN_SERIAL1_RX       (32ul) // PB17
#define PAD_SERIAL1_TX       (UART_TX_PAD_0)
#define PAD_SERIAL1_RX       (SERCOM_RX_PAD_1)
//-------------------------------------------
#endif

// SPI Interfaces
//-------------------------------------------
#define SPI_INTERFACES_COUNT 2
  
// SPI
#define PIN_SPI_MOSI         (27u)  // PA16
#define PIN_SPI_SCK          (28u)  // PA17
#define PIN_SPI_MISO         (29u)  // PA18
#define PIN_SPI_SS           (30u)  // PA19
#define PERIPH_SPI           sercom1
#define PAD_SPI_TX           SPI_PAD_0_SCK_1 // Este valor indica que el pin (MOSI) está en el pad 0 y el pin de reloj (SCK) está en el pad 1
#define PAD_SPI_RX           SERCOM_RX_PAD_2

static const uint8_t SS	  = PIN_SPI_SS ;
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;

// SPI1
#define PIN_SPI1_MOSI         (9u)    // PA04
#define PIN_SPI1_SCK          (10u)   // PA05
#define PIN_SPI1_MISO         (11u)   // PA06
#define PIN_SPI1_SS           (12u)   // PA07
#define PERIPH_SPI1           sercom0
#define PAD_SPI1_TX           SPI_PAD_0_SCK_1
#define PAD_SPI1_RX           SERCOM_RX_PAD_2

static const uint8_t SS1	 = PIN_SPI1_SS ;
static const uint8_t MOSI1 = PIN_SPI1_MOSI ;
static const uint8_t MISO1 = PIN_SPI1_MISO ;
static const uint8_t SCK1  = PIN_SPI1_SCK ;
//-------------------------------------------

// QSPI FLASH
//-------------------------------------------
#define PIN_QSPI_D0           (13u)   // PA08
#define PIN_QSPI_D1           (14u)   // PA09
#define PIN_QSPI_D2           (15u)   // PA10
#define PIN_QSPI_D3           (16u)   // PA11

#define PIN_QSPI_SCK          (17u)   // PB10
#define PIN_QSPI_CS           (18u)   // PB10

#define EXTERNAL_FLASH_DEVICE MT25QL01GBBB // Memoria FLASH externa de la placa de desarrollo MUA_Control FINAL
#define EXTERNAL_FLASH_USE_QSPI

#if !defined(VARIANT_QSPI_BAUD_DEFAULT)
  #define VARIANT_QSPI_BAUD_DEFAULT 5000000
#endif
//-------------------------------------------

// Wire Interfaces
//-------------------------------------------
#define WIRE_INTERFACES_COUNT 2

// I2C
#define PIN_WIRE_SDA         (23u)  // PA12
#define PIN_WIRE_SCL         (24u)  // PA13
#define PERIPH_WIRE          sercom2
#define WIRE_IT_HANDLER      SERCOM2_Handler
#define WIRE_IT_HANDLER_0    SERCOM2_0_Handler
#define WIRE_IT_HANDLER_1    SERCOM2_1_Handler
#define WIRE_IT_HANDLER_2    SERCOM2_2_Handler
#define WIRE_IT_HANDLER_3    SERCOM2_3_Handler

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

// I2C1
#define PIN_WIRE1_SDA         (48u)   // PA22
#define PIN_WIRE1_SCL         (49u)   // PA23
#define PERIPH_WIRE1          sercom3
#define WIRE1_IT_HANDLER      SERCOM3_Handler
#define WIRE1_IT_HANDLER_0    SERCOM3_0_Handler
#define WIRE1_IT_HANDLER_1    SERCOM3_1_Handler
#define WIRE1_IT_HANDLER_2    SERCOM3_2_Handler
#define WIRE1_IT_HANDLER_3    SERCOM3_3_Handler

static const uint8_t SDA1 = PIN_WIRE1_SDA;
static const uint8_t SCL1 = PIN_WIRE1_SCL;
//----------------------------------------------

// USB
//----------------------------------------------
#define PIN_USB_DM          (37ul)  // PA24
#define PIN_USB_DP          (38ul)  // PA25
#define PIN_USB_HOST_ENABLE (41ul)
//----------------------------------------------

#ifdef __cplusplus
}
#endif

//----------------------------------------------------------------------------
//        Arduino objects - C++ only
//----------------------------------------------------------------------------

#ifdef __cplusplus

//	------------------------
//	 SERCOM DEFINITION
//	------------------------    // Placa Final
extern SERCOM sercom0;          // SPI1
extern SERCOM sercom1;          // SPI
extern SERCOM sercom2;          // I2C
extern SERCOM sercom3;          // I2C1
extern SERCOM sercom4;          // Serial1 -> CORRECCION Serial2
extern SERCOM sercom5;          // Serial2 -> CORRECCION Serial1

extern Uart Serial1;
extern Uart Serial2;

#endif

#define SERIAL_PORT_USBVIRTUAL      Serial
#define SERIAL_PORT_MONITOR         Serial
// Serial has no physical pins broken out, so it's not listed as HARDWARE port

#define SERIAL_PORT_HARDWARE        Serial1
#define SERIAL_PORT_HARDWARE_OPEN   Serial1

#define SERIAL_PORT_HARDWARE2       Serial2
#define SERIAL_PORT_HARDWARE2_OPEN  Serial2

#endif

#endif // SAMD51 MicroMod Processor Board
