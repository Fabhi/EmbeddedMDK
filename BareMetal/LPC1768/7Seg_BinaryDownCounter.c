#include <LPC17xx.h>

unsigned int seven_seg[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
unsigned int rounds, i, one_second_over = 1, start;
unsigned int value1, value2, value3, value4;
void delay(void);
void display(int, int);
void refresh(void);


// Not checked
int main(){
    // Initialization
    SystemInit();
    SystemCoreClockUpdate();
    LPC_GPIO0 -> FIODIR = 0xFF0;
    LPC_GPIO0 -> FIODIR = 0x07800000;


    start = 0xF;
    while(1){
        delay();
        if(one_second_over){
            one_second_over = 0;

            // Update value1, value2, value3, value4
            start -= 1 ;
            value1 = start & 0x1;
            value2 = start & 0x2;
            value3 = start & 0x3;
            value4 = start & 0x4;
        }
        refresh();
    }
}


// Checked
void refresh(void){
    display(value1, 1);
    display(value2, 2);
    display(value3, 3);
    display(value4, 4);
}

// Not checked
void display(int value, int displayNumber){
    LPC_GPIO1->FIOPIN = displayNumber << 23 ; //TODO : Check if its active low
    LPC_GPIO0->FIOPIN = seven_seg[value]<<4;
}


// Checked
void delay(void){
    for ( i=0 ; i<1000 ; i++);
    rounds++;
    if (rounds == 100){
        one_second_over=1;
        rounds = 0;
    }
}
