#ifndef __HELPERS
#define __HELPERS
#include <stm32f10x.h>
void initialize(void);
void SysTick_Handler(void);
void init_clock(void);
void initPin(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin);
void set(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin);
void clear(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin);
void delay(int);
void blink_PC13(void);
void blink_PA0(void);
void loop_delay(void);

#endif
