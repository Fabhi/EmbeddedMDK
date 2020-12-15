#include "LPC17xx.h"
#define ADC_Channel 3
void ADCInit();
void ADC_IRQHandler();
void delay(unsigned int);
unsigned int ADC_data, DAC_data;
int main(void){
    SystemInit();
    SystemCoreClockUpdate();
    LPC_PINCON->PINSEL1 |= 1<<20 | 2<<14; //Enable the ADC Channel 3(P0.26 F1) and DAC(P0.23 F2)
    ADCInit();
    while(1){
        //Keep the Pin high for 12ms
        LPC_DAC-> DACR = DAC_data;
        delay(12);
        //Keep the Pin low for 12ms
        LPC_DAC-> DACR = 0;
        delay(12);
        //Total Delay 24ms (41Hz)
    }
}

void ADCInit(void){
    LPC_ADC->ADINTEN = 1<<ADC_Channel | 1<<8; //Global DONE Flag only. ADINTEN[8]=1
    LPC_ADC->ADCR = 1<<ADC_Channel| 1<<21 | 1<<24;
    NVIC_EnableIRQ(ADC_IRQHandler);
}

void ADC_IRQHandler(void){
    ADC_data = LPC_ADC->ADGDR //Global Done flag is cleared automcatically by reading the ADGDR register
    ADC_data >>=4; //Shift result left by 4 bits since data = ADGDR[15:4]
    ADC_data &=0xFFF; //Clear the remaining bits
    DAC_data = ADC_data>>2;
    }
}

void delay(unsigned int usec){
    LPC_TIM0->TCR = 2;
    LPC_TIM0->PR = 2;
    LPC_TIM0->MR0 = usec-1;
    LPC_TIM0->EMR = 0x20;
    LPC_TIM0->TCR = 1;
    while(!(LPC_TIM0->EMR & 1));
}
