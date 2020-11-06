#include "HelperFunctions.h"
static int ticks = 0;
void initialize(void){
    SystemInit();
    init_clock();
    SysTick_Config(SystemCoreClock/1000);    //Raise Interrupt every 1 millisecond
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPDEN;
}
void init_clock(void){
    // Conf clock : 72MHz using HSE 8MHz crystal w/ PLL X 9 (8MHz x 9 = 72MHz)
    FLASH->ACR      |= FLASH_ACR_LATENCY_2; // Two wait states, per datasheet
    RCC->CFGR       |= RCC_CFGR_PPRE1_2;    // prescale AHB1 = HCLK/2
    RCC->CR         |= RCC_CR_HSEON;        // enable HSE clock
    while( !(RCC->CR & RCC_CR_HSERDY) );    // wait for the HSEREADY flag

    RCC->CFGR       |= RCC_CFGR_PLLSRC;     // set PLL source to HSE
    RCC->CFGR       |= RCC_CFGR_PLLMULL9;   // multiply by 9
    RCC->CR         |= RCC_CR_PLLON;        // enable the PLL
    while( !(RCC->CR & RCC_CR_PLLRDY) );    // wait for the PLLRDY flag

    RCC->CFGR       |= RCC_CFGR_SW_PLL;     // set clock source to pll
    while( !(RCC->CFGR & RCC_CFGR_SWS_PLL) );    // wait for PLL to be CLK
    SystemCoreClockUpdate();                // calculate the SYSCLOCK value
}

void SysTick_Handler(void)  {                               /* SysTick interrupt Handler. */
    ticks++;  
}

void initPin(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin){
    if(GPIO_Pin<8){
        GPIOx->CRL &= (uint32_t) ~(0x0F<<(4*GPIO_Pin));
        GPIOx->CRL |= (uint32_t) (0x03<<(4*GPIO_Pin));
    }
    else{
        GPIOx->CRH &= (uint32_t) ~(0x0F<<(4*GPIO_Pin-32));
        GPIOx->CRH |= (uint32_t) (0x03<<(4*GPIO_Pin-32));
    }
}

void set(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin){
        GPIOx->ODR |= (1<<GPIO_Pin);
}

void clear(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin){
        GPIOx->ODR &= ~(1<<GPIO_Pin);

}



void delay(int msec){
   ticks=0;
   while(ticks<msec)
       __asm__("nop");   
}
