/*
 * stm32.h
 *
 *  Created on: Nov 6, 2024
 *      Author: Lochi
 */

#ifndef INC_STM32_H_
#define INC_STM32_H_

#include "stm32f4xx.h"

#define pass 		(void)0
#define unused(var)	(void)var

#define ArraySize(x) 	(sizeof(x)/sizeof((x)[0]) )

#define HAL_DELAY_COEFFICENT	100
#define SEC_PER_MINUTE			60

//////////////////////////////////
// Base addresses
//////////////////////////////////

// Documented in the STM32 Discovery Manual
#define AHB1_HiPerformance_ADDR	0x40020000
#define APB2_Peripheral_ADDR	0x40010000
#define APB1_Peripheral_ADDR	0x40000000

//////////////////////////////////
// Referenced Addresses
//////////////////////////////////

// Documented in the STM32 Discovery Manual
// AHB1
#define RCC_ADDR	(AHB1_HiPerformance_ADDR + 0x00003800)

// APB2
#define SYSCFG_ADDR	(APB2_Peripheral_ADDR + 0x00003800)

// APB1
#define TIM2_OFFSET 0x00000000;
#define TIM5_OFFSET 0x00000C00;

#define TIM2_ADDR	(APB1_Peripheral_ADDR + 0x00000000)
#define TIM5_ADDR	(APB1_Peripheral_ADDR + 0x00000C00)
#define TIM7_ADDR	(APB1_Peripheral_ADDR + 0x00001400)

#define TIM_7		((GPTIMR_RegDef_t*) TIM7_ADDR)


// Offsets of TIMx_CR[1]
#define CLK_ENABLE_OFFSET			0x0
#define CLK_DIV_OFFSET				0x8
#define CLK_CENTERED_MODE_OFFSET 	0x5
#define CLK_DIR_OFFSET				0x4
#define CLK_ARR_BUFFERED_OFFSET		0x7
#define CLK_ONEPULSE_OFFSET			0x3
#define	CLK_UPDATEDISABLE_OFFSET	0x1

#define	CLK_INTERUPTUPDATE_OFFSET	0x0

//////////////////////////////////
// Direct Reference
// Code will call these to reference the registers
//////////////////////////////////

//#define RCC ((RCC_RegDef_t*) RCC_ADDR)

//#define SYSCFG 	((SYSCFG_RegDef_t*) SYSCFG_ADDR)
//#define EXTI	((EXTI_RegDef_t*) EXTI_ADDR)


//////////////////////////////////
// Macro Functions
//////////////////////////////////
// Clock Controls

#define GPIO_CLK_ENABLE(bit) 	(RCC->AHB1ENR |= (1 << bit))
#define GPIO_CLK_DISABLE(bit) 	(RCC->AHB1ENR &= ~(1 << bit))

#define GPIOA_CLK_ENABLE()		(GPIO_CLK_ENABLE(0))
#define GPIOA_CLK_DISABLE() 	(GPIO_CLK_DISABLE(0))
//
//#define GPIOG_CLK_ENABLE() 		(GPIO_CLK_ENABLE(6))
//#define GPIOG_CLK_DISABLE() 	(GPIO_CLK_DISABLE(6))

#define SYSCFG_CLK_ENABLE()		(RCC->APB2ENR |= (1<<14))
#define	SYSCFG_CLK_DISABLE()	(RCC->APB2ENR &= ~(1<<14))


#define TIM_CLK_ENABLE(bit)			(RCC->APB1EN |= (1<<bit))
#define TIM_CLK_DISABLE(bit)		(RCC->APB1EN &= ~(1<<bit))

//#define TIM2_CLK_ENABLE()			(TIM_CLK_ENABLE(0))
//#define TIM5_CLK_ENABLE()			(TIM_CLK_ENABLE(3))
#define TIM7_CLK_ENABLE()			(TIM_CLK_ENABLE(5))

//#define TIM2_CLK_DISABLE()			(TIM_CLK_DISABLE(0))
//#define TIM5_CLK_DISABLE()			(TIM_CLK_DISABLE(3))
#define TIM7_CLK_DISABLE()			(TIM_CLK_DISABLE(5))


//////////////////////////////////
// Defined Keywords
//////////////////////////////////
#define ACTIVE		1
#define NON_ACTIVE	0
#define SET			1
#define RESET		0
#define ENABLE		SET
#define ENABLED		SET
#define DISABLE		RESET
#define DISABLED	RESET

//////////////////////////////////
// Register Mapping Structs
//////////////////////////////////
//typedef struct{
//	volatile uint32_t CR;
//	volatile uint32_t PLLCFG;
//	volatile uint32_t CFG;
//	volatile uint32_t CIR;
//	volatile uint32_t AHB1RST;
//	volatile uint32_t AHB2RST;
//	volatile uint32_t AHB3RST;
//	volatile uint32_t Reserved_1[1];
//	volatile uint32_t APB1RST;
//	volatile uint32_t APB2RST;
//	volatile uint32_t Reserved_2[2];
//	volatile uint32_t AHB1EN;
//	volatile uint32_t AHB2EN;
//	volatile uint32_t AHB3EN;
//	volatile uint32_t Reserved_3;
//	volatile uint32_t APB1EN;
//	volatile uint32_t APB2EN;
//	volatile uint32_t Reserved_4[2];
//	volatile uint32_t AHB1LPEN;
//	volatile uint32_t AHB2LPEN;
//	volatile uint32_t AHB3LPEN;
//	volatile uint32_t Reserved_5;
//	volatile uint32_t APB1LPEN;
//	volatile uint32_t APB2LPEN;
//	volatile uint32_t Reserved_6;
//	volatile uint32_t BDCR;
//	volatile uint32_t CSR;
//	volatile uint32_t Reserved_7;
//	volatile uint32_t SSCG;
//	volatile uint32_t PLLI2SCFG;
//	volatile uint32_t PLLSAICFG;
//	volatile uint32_t DCKCFG;
//}RCC_RegDef_t;

typedef struct{
	volatile uint32_t IMR;		// Interrupt Mask
	volatile uint32_t EMR;		// Event Mask
	volatile uint32_t RTSR;		// Rising Trigger Selection
	volatile uint32_t FTSR;		// Falling Trigger Selection
	volatile uint32_t SWIER;	// Software Interrupt Event Register
	volatile uint32_t PR;		// Pending Register
}EXTI_RegDef_t;

typedef struct{
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4];
	volatile uint32_t Reserved[2];
	volatile uint32_t CMPCR;
}SYSCFG_RegDef_t;

typedef struct{
	volatile uint32_t CR[2];		//
	volatile uint32_t SMCR;		//
	volatile uint32_t DIER;		//
	volatile uint32_t SR;		//
	volatile uint32_t EGR;;			//
//	volatile uint32_t reserved1;		//
	volatile uint32_t CCMR[2];	//
	volatile uint32_t CCER;		//
	volatile uint32_t CNT;		// Counter
	volatile uint32_t PSC;		// Prescaler
	volatile uint32_t ARR;		// Auto-Reset
	volatile uint32_t reserved1;
	volatile uint32_t CCR[4];	// Capture / Compare Registers
	volatile uint32_t reserved2;		//
	volatile uint32_t DCR;		//
	volatile uint32_t DMAR;		//
	volatile uint32_t OR;		// Option Register
}GPTIMR_RegDef_t;

#endif /* INC_STM32_H_ */
