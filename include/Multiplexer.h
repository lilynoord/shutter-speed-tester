#include <Arduino.h>
//Handles multiplexing of more sensors than there are pins, using a TI Multiplexer. 
//TODO: This will eventually actually handle it but for right now it'll just do direct reads. 
//Docs: https://www.ti.com/lit/ds/symlink/cd74hct4067.pdf?ts=1764927418545&ref_url=https%253A%252F%252Fwww.mouser.it%252F
int TRUTH_TABLE[16][6] = { 
    //{S0, S1, S2, S3, E, Channel}
    {0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 2},
    {1, 1, 0, 0, 0, 3},
    {0, 0, 1, 0, 0, 4},
    {1, 0, 1, 0, 0, 5},
    {0, 1, 1, 0, 0, 6},
    {1, 1, 1, 0, 0, 7}, 
    {0, 0, 0, 1, 0, 8},
    {1, 0, 0, 1, 0, 9},
    {0, 1, 0, 1, 0, 10},
    {1, 1, 0, 1, 0, 11},
    {0, 0, 1, 1, 0, 12},
    {1, 0, 1, 1, 0, 13},
    {0, 1, 1, 1, 0, 14},
    {1, 1, 1, 1, 0, 15}
};

/*
    Multiplexer class.  
*/
class Multiplexer {
    public:
        int select_pins[3]; //Pins used to select the channel of the multiplexer.
        int num_channels; //Number of channels in the multiplexer.
        int current_channel; //Current channel selected.
        Multiplexer(int s0_pin,int s1_pin,int s2_pin, int e_pin, int channel_count){
            select_pins[0] = s0_pin;
            select_pins[1] = s1_pin;
            select_pins[2] = s2_pin;
            enable_pin = e_pin;
            num_channels = channel_count;
        }
        void disable(){
            digitalWrite(enable_pin, 1);
        }
        void select_channel(int channel){
            current_channel = channel;
            digitalWrite(select_pins[0], TRUTH_TABLE[current_channel][0]);
            digitalWrite(select_pins[1], TRUTH_TABLE[current_channel][1]);
            digitalWrite(select_pins[2], TRUTH_TABLE[current_channel][2]);
            digitalWrite(select_pins[3], TRUTH_TABLE[current_channel][3]);
            digitalWrite(enable_pin, TRUTH_TABLE[current_channel][4]);
        }
        int read_input(int channel){
            select_channel(channel);
            return analogRead(analog_pin);
        }


     
};

/*
Has all the same functions as the multiplexer, but when asked for a value returns regular analog reads from the provided pin. 
*/
class DummyMultiplexer {
    int select_pins[3]; //Pins used to select the channel of the multiplexer.
        int num_channels; //Number of channels in the multiplexer.
        int current_channel; //Current channel selected.
        Multiplexer(int s0_pin,int s1_pin,int s2_pin, int e_pin, int channel_count){
            select_pins[0] = s0_pin;
            select_pins[1] = s1_pin;
            select_pins[2] = s2_pin;
            enable_pin = e_pin;
            num_channels = channel_count;
        }
        void disable(){
            digitalWrite(enable_pin, 1);
        }
        void select_channel(int channel){
            current_channel = channel;
            digitalWrite(select_pins[0], TRUTH_TABLE[current_channel][0]);
            digitalWrite(select_pins[1], TRUTH_TABLE[current_channel][1]);
            digitalWrite(select_pins[2], TRUTH_TABLE[current_channel][2]);
            digitalWrite(select_pins[3], TRUTH_TABLE[current_channel][3]);
            digitalWrite(enable_pin, TRUTH_TABLE[current_channel][4]);
        }
        int read_input(int pin){
            return analogRead(pin);
        }


};