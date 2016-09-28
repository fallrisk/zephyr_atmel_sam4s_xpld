/*
 * Copyright (c) 2016 Intel Corporation.
 * Copyright (c) 2013-2015 Wind River Systems, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file SoC configuration macros for the Atmel SAM4 family processors.
 */

#ifndef _ATMEL_SAM4_SOC_H_
#define _ATMEL_SAM4_SOC_H_

/* IRQ numbers (from section 11.1, Peripheral Identifiers). */
#define IRQ_SUPC	0	/* Supply Controller                    */
#define IRQ_RSTC	1	/* Reset Controller                     */
#define IRQ_RTC		2	/* Real-time Clock                      */
#define IRQ_RTT		3	/* Real-time Timer                      */
#define IRQ_WDG		4	/* Watchdog Timer                       */
#define IRQ_PMC		5	/* Power Management Controller          */
#define IRQ_EEFC0	6	/* Enhanced Embedded Flash Controller 0 */
#define IRQ_EEFC1	7	/* Enhanced Embedded Flash Controller 1 */
#define IRQ_UART0	8	/* UART                                 */
#define IRQ_UART1	9	/* UART                                 */
#define IRQ_SMC		10	/*                                  */
#define IRQ_PIOA	11	/* Parallel IO Controller A             */
#define IRQ_PIOB	12	/* Parallel IO Controller B             */
#define IRQ_PIOC	13	/* Parallel IO Controller C             */
#define IRQ_USART0	14	/* USART #0                             */
#define IRQ_USART1	15	/* USART #1                             */
#define IRQ_HSMCI	18	/* High Speed Multimedia Card Interface */
#define IRQ_TWI0	19	/* Two-wire Interface #0                */
#define IRQ_TWI1	20	/* Two-wire Interface #1                */
#define IRQ_SPI 	21	/* SPI                                  */
#define IRQ_SSC		22	/* Synchronous Serial Controller        */
#define IRQ_TC0		23	/* Timer Counter Channel #0             */
#define IRQ_TC1		24	/* Timer Counter Channel #1             */
#define IRQ_TC2		25	/* Timer Counter Channel #2             */
#define IRQ_TC3		26	/* Timer Counter Channel #3             */
#define IRQ_TC4		27	/* Timer Counter Channel #4             */
#define IRQ_TC5		28	/* Timer Counter Channel #5             */
#define IRQ_ADC		29	/* ADC Controller                       */
#define IRQ_DACC	30	/* DAC Controller                       */
#define IRQ_PWM		31	/* PWM Controller                       */
#define IRQ_CRCCU	32	/* CRC Controller                       */
#define IRQ_ACC		33	/*                    */
#define IRQ_UDP		34	/* USB Device Port                      */

/* PID: Peripheral IDs (from section 11.1, Peripheral Identifiers).
 * PMC uses PIDs to enable clock for peripherals.
 */
#define PID_UART0	8	/* UART                                 */
#define PID_UART1	9	/* UART                                 */
#define PID_SMC		10	/*                                 */
#define PID_PIOA	11	/* Parallel IO Controller A             */
#define PID_PIOB	12	/* Parallel IO Controller B             */
#define PID_PIOC	13	/* Parallel IO Controller C             */
#define PID_USART0	14	/* USART #0                             */
#define PID_USART1	15	/* USART #1                             */
#define PID_HSMCI	18	/* High Speed Multimedia Card Interface */
#define PID_TWI0	19	/* Two-wire Interface #0                */
#define PID_TWI1	20	/* Two-wire Interface #1                */
#define PID_SPI 	21	/* SPI                                  */
#define PID_SSC		22	/* Synchronous Serial Controller        */
#define PID_TC0		23	/* Timer Counter Channel #0             */
#define PID_TC1		24	/* Timer Counter Channel #1             */
#define PID_TC2		25	/* Timer Counter Channel #2             */
#define PID_TC3		26	/* Timer Counter Channel #3             */
#define PID_TC4		27	/* Timer Counter Channel #4             */
#define PID_TC5		28	/* Timer Counter Channel #5             */
#define PID_ADC		29	/* ADC Controller                       */
#define PID_DACC	30	/* DAC Controller                       */
#define PID_PWM		31	/* PWM Controller                       */
#define PID_CRCCU	32	/*                       */
#define PID_ACC		33	/* USB OTG High Speed                   */
#define PID_UDP		34	/* USB Device Port                      */

/* Power Manager Controller */
#define	PMC_ADDR	0x400E0400

#define PMC_CKGR_UCKR_UPLLEN		(1 << 16)
#define PMC_CKGR_UCKR_UPLLCOUNT		(3 << 20)

#define PMC_CKGR_MOR_KEY		(0x37 << 16)
#define PMC_CKGR_MOR_MOSCXTST		(0xFF << 8)
#define PMC_CKGR_MOR_MOSCXTEN		(1 << 0)
#define PMC_CKGR_MOR_MOSCRCEN		(1 << 3)
#define PMC_CKGR_MOR_MOSCRCF_4MHZ	(0 << 4)
#define PMC_CKGR_MOR_MOSCRCF_8MHZ	(1 << 4)
#define PMC_CKGR_MOR_MOSCRCF_12MHZ	(2 << 4)
#define PMC_CKGR_MOR_MOSCSEL		(1 << 24)

#define PMC_CKGR_PLLAR_PLLACOUNT	(0x3F << 8)
#define PMC_CKGR_PLLAR_ONE		(1 << 29)

/*
 * PLL clock = Main * (MULA + 1) / DIVA
 *
 * By default, MULA == 6, DIVA == 1.
 * With main crystal running at 12 MHz,
 * PLL = 12 * (6 + 1) / 1 = 84 MHz
 *
 * With processor clock prescaler at 1,
 * the processor clock is at 84 MHz.
 */
#define PMC_CKGR_PLLAR_MULA	\
	((CONFIG_SOC_ATMEL_SAM4_PLLA_MULA) << 16)
#define PMC_CKGR_PLLAR_DIVA	\
	((CONFIG_SOC_ATMEL_SAM4_PLLA_DIVA) << 0)

/*
 * PLL clock = Main * (MULB + 1) / DIVB
 *
 * By default, MULB == 6, DIVB == 1.
 * With main crystal running at 12 MHz,
 * PLL = 12 * (6 + 1) / 1 = 84 MHz
 *
 * With processor clock prescaler at 1,
 * the processor clock is at 84 MHz.
 */
#define PMC_CKGR_PLLAR_MULB	\
	((CONFIG_SOC_ATMEL_SAM4_PLLB_MULB) << 16)
#define PMC_CKGR_PLLAR_DIVB	\
	((CONFIG_SOC_ATMEL_SAM4_PLLB_DIVB) << 0)

#define PMC_MCKR_CSS_MASK		(0x3)
#define PMC_MCKR_CSS_SLOW		(0 << 0)
#define PMC_MCKR_CSS_MAIN		(1 << 0)
#define PMC_MCKR_CSS_PLLA		(2 << 0)
#define PMC_MCKR_CSS_UPLL		(3 << 0)
#define PMC_MCKR_PRES_MASK		(0x70)
#define PMC_MCKR_PRES_CLK		(0 << 4)
#define PMC_MCKR_PRES_DIV2		(1 << 4)
#define PMC_MCKR_PRES_DIV4		(2 << 4)
#define PMC_MCKR_PRES_DIV8		(3 << 4)
#define PMC_MCKR_PRES_DIV16		(4 << 4)
#define PMC_MCKR_PRES_DIV32		(5 << 4)
#define PMC_MCKR_PRES_DIV64		(6 << 4)
#define PMC_MCKR_PRES_DIV3		(7 << 4)
#define PMC_MCKR_PLLADIV2		(1 << 12)
#define PMC_MCKR_UPLLDIV2		(1 << 13)

#define PMC_FSMR_LPM			(1 << 20)

#define PMC_INT_MOSCXTS			(1 << 0)
#define PMC_INT_LOCKA			(1 << 1)
#define PMC_INT_MCKRDY			(1 << 3)
#define PMC_INT_LOCKU			(1 << 6)
#define PMC_INT_OSCSELS			(1 << 7)
#define PMC_INT_PCKRDY0			(1 << 8)
#define PMC_INT_PCKRDY1			(1 << 9)
#define PMC_INT_PCKRDY2			(1 << 10)
#define PMC_INT_MOSCSELS		(1 << 16)
#define PMC_INT_MOSCRCS			(1 << 17)
#define PMC_INT_CFDEV			(1 << 18)
#define PMC_INT_CFDS			(1 << 19)
#define PMC_INT_FOS			(1 << 20)

/* UART */
#define UART0_ADDR	0x400E0600
#define UART1_ADDR	0x400E0800

/* EEFC */
#define EEFC_BANK0_ADDR	0x400E0A00
#define EEFC_BANK1_ADDR	0x400E0C00

/* Peripheral DMA Controller (PDC) */
#define PDC_PTCR_RXTEN	(1 << 0)
#define PDC_PTCR_RXTDIS	(1 << 1)
#define PDC_PTCR_TXTEN	(1 << 8)
#define PDC_PTCR_TXTDIS	(1 << 9)

/* PIO Controllers */
#define PIOA_ADDR	0x400E0E00
#define PIOB_ADDR	0x400E1000
#define PIOC_ADDR	0x400E1200

/* Supply Controller (SUPC) */
#define SUPC_ADDR	0x400E1410

#define SUPC_CR_KEY	(0xA5 << 24)
#define SUPC_CR_XTALSEL	(1 << 3)

#define SUPC_SR_OSCSEL	(1 << 7)

/* Two-wire Interface (TWI) */
#define TWI0_ADDR	0x40018000
#define TWI1_ADDR	0x4001C000

/* Watchdog timer (WDT) */
#define WDT_ADDR	0x400E1450

#define WDT_DISABLE	(1 << 15)

#ifndef _ASMLANGUAGE

#include <device.h>
#include <misc/util.h>
#include <drivers/rand32.h>

#include "soc_registers.h"

/* uart configuration settings */
#define UART_IRQ_FLAGS 0

/* EEFC Register struct */
#define __EEFC0		((volatile struct __eefc *)EEFC_BANK0_ADDR)
#define __EEFC1		((volatile struct __eefc *)EEFC_BANK1_ADDR)

/* PMC Register struct */
#define __PMC		((volatile struct __pmc *)PMC_ADDR)

/* PIO Registers struct */
#define __PIOA		((volatile struct __pio *)PIOA_ADDR)
#define __PIOB		((volatile struct __pio *)PIOB_ADDR)
#define __PIOC		((volatile struct __pio *)PIOC_ADDR)
#define __PIOD		((volatile struct __pio *)PIOD_ADDR)
#define __PIOE		((volatile struct __pio *)PIOE_ADDR)
#define __PIOF		((volatile struct __pio *)PIOF_ADDR)

/* Supply Controller Register struct */
#define __SUPC		((volatile struct __supc *)SUPC_ADDR)

/* Two-wire Interface (TWI) */
#define __TWI0		((volatile struct __twi *)TWI0_ADDR)
#define __TWI1		((volatile struct __twi *)TWI1_ADDR)

/* Watchdog timer (WDT) */
#define __WDT		((volatile struct __wdt *)WDT_ADDR)

#endif /* !_ASMLANGUAGE */

#endif /* _ATMEL_SAM3_SOC_H_ */
