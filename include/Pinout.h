#include <Arduino.h>

void pinout(){    
    for(int i = 2; i<12; i++){
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
    };
    
}