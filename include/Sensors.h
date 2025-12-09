#include <Arduino.h>
#include <string>

using namespace std;


#define P1 A0
#define P2 A1
#define P3 A2
#define P4 A3
// Only on the nano
#define P5 A6
#define P6 A7



class Photodiode {
    public:
        int threshold; //Threshold that has to be passed to be considered 'on', has default. 
        int value_one; //most recent value
        int value_two; //Second most recent value
        int time_one; //Time of value_one reading in milliseconds
        int time_two; //Time of value_two reading in milliseconds
        bool is_on;
        int coordinates[2]; 
        Photodiode(int coordinates[2]){
            is_on = false;
        }
};

int analog_pins[6] = {P1, P2, P3, P4, P5, P6};
//! NOTE: to future self: When using a multiplexer, will need to account for its internal resistance!! Since this can vary with temperature, will likely need to calibrate it on startup each time. 
void readAllSensors(Photodiode sensor_array[]) {

   for(Photodiode diode : sensor_array){

   }


}

/*
Checks if a switch is on or not. 
*/
bool checkSwitch(int switch_pin){
    int isOn = digitalRead(switch_pin);
    if (isOn == 1){
        return true;
    }
    return false;
}


// Sensor reading that does not use multiplexing. Mostly used during testing. 
void readAllSensors_noMultiplexing(){

}

float getCurrentTimeInSeconds(){
    int time = micros();
    return 1000000 / float(time);
}



/*
    Function for testing using pre-defined sensor values. 
*/
void readAllSensors_TestFunction(int shutter_speed, string direction){

}