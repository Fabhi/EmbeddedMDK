#include "LPC17xx.h"

//Connect CNA to 7 Segment
//Connect CNC to BCD Decoder
//Connect CNB to Keyboard
unsigned int segment = 1, i=0;
int main(){
    SystemInit();
    SystemCoreClockUpdate();

    LPC_GPIO0->FIODIR = 0xFFFFFFFF; // 7 Segment + Decoder in Output Mode
    LPC_GPIO0->FIOMASK = 0xF<<15; //Mask Decoder so it's not modified(0 is default output of decoder)
    LPC_GPIO2->FIODIR = 1<<11; // Row 1 Output Mode
    LPC_GPIO2->FIOPIN = 1<<11; // Send Logic 1 to Row 1

    while(1){
        if((LPC_GPIO1->FIOPIN >> 25 & 0x1) == 1){
            for(i = 0; i<10000; i++); // Delay so that multiple keypress aren't mistakenly registered
            segment <<= 1;
            if(segment == 0x80)
                segment = 1;
        }
        LPC_GPIO0->FIOPIN = segment<<4;
    }
}
