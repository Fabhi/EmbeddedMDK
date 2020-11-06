#include "HelperFunctions.h"

int main(void){
    initialize();
    initPin(GPIOA, 0);  //PA0 is Active High LED
    initPin(GPIOC, 13); //PC13 is Active Low LED
    while(1){
        set(GPIOA, 0);
        clear(GPIOC, 13);
        delay(1000);
        set(GPIOC,13);
        clear(GPIOA,0);
        delay(1000);
    }
    
}
