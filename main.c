#include "pico/stdlib.h"
int leds[8];
void switchSegment(int number);
int size = sizeof(leds)/sizeof(leds[0]);

int switch_leds[10][8] = {
//   F G A B E D C .
    {1,0,1,1,1,1,1,0},//0
    {0,0,0,1,0,0,1,0},//1
    {0,1,1,1,1,1,0,0},//2
    {0,1,1,1,0,1,1,0},//3
    {1,1,0,1,0,0,1,0},//4
    {1,1,1,0,0,1,1,0},//5
    {1,1,1,0,1,1,1,0},//6
    {0,0,1,1,0,0,1,0},//7
    {1,1,1,1,1,1,1,0},//8
    {1,1,1,1,0,0,1,0},//9
};
int size_switch_leds = sizeof(switch_leds)/sizeof(switch_leds[0]);

int main(){
    stdio_init_all();
    for (int i = 0; i < size; i++)
    {
        leds[i]=i;
        gpio_init(leds[i]);
        gpio_set_dir(leds[i], GPIO_OUT);
    }
    while(true){
        int i;
        for (i = 0; i < size_switch_leds; i++)
        {
            switchSegment(i);
            sleep_ms(1000);
        }
        i=0;
    }
}
void switchSegment(int number){
    for (int i = 0; i < size; i++){
        gpio_put(leds[i], switch_leds[number][i]);
    }
}
