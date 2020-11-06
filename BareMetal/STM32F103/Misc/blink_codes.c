#include <stm32f10x.h>
void loop_delay(void){
    // Keep Delay>20,00,000
  //20,00,000 is perfect.
  //2,00,000 is very quick.
  //20,000 is imperceptable(always on)
  for (volatile unsigned int i = 0; i < 2000000; i++);
}

_Noreturn void blink_PC13(){
  /*WORKING! TESTED ON 04-11-20*/
  RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
  // Set PC_13 to output 
  GPIOC->CRH &= ~(GPIO_CRH_MODE13 | GPIO_CRH_CNF13);
  GPIOC->CRH |= GPIO_CRH_MODE13;

  while(1)
  {
    GPIOC->BSRR = (1<<13);
    delay();
    GPIOC->BRR = (1<<13);
    delay();
  }
}

_Noreturn void blink_PA0(){
   /*WORKING! TESTED ON 04-11-20*/
   RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
  // Set PA0 to output 
  GPIOA->CRL &= ~(GPIO_CRL_MODE0 | GPIO_CRL_CNF0);
  GPIOA->CRL |= GPIO_CRL_MODE0;

  while(1)
  {
    GPIOA->BSRR = (1);
    delay();
    GPIOA->BRR = (1);
    delay();
  }
}
