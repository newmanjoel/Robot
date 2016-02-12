/* 
 * File:   main.cpp
 * Author: joell
 *
 * Created on February 11, 2016, 8:00 PM
 */

#include <cstdlib>
#include "wiringPi.h"
#include "softPwm.h"
#include <iostream>
#include <cmath>
#define PWM0 1
#define PWM1 13
#define pwmClock 10
#define pwmRange 100

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    if(wiringPiSetup()==-1){
        cout<<"Wiring Pi was not set up properly try sudo?"<<endl;
        return -1;
    }
    double temp = 19.2*pow(10,6)/pwmClock/pwmRange;
    cout<<"The hardware PWM is on wiringPi pin 1 which is System pin 12"<<endl;
    pinMode(PWM0,PWM_OUTPUT);
    //pinMode(PWM1,PWM_OUTPUT);
    softPwmCreate(PWM1,0,10);
    softPwmWrite(PWM1,5);
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(pwmClock);
    pwmSetRange(pwmRange);
    pwmWrite(PWM0,50);
    //pwmWrite(PWM1,50);
    cout<<"I get here"<<endl;
    for(;;){
        int dutyCycle;
        cin >> dutyCycle;
        pwmWrite(PWM0,dutyCycle);
        softPwmWrite(PWM1,int((100-dutyCycle)/10));
        
    }
    
    return 0;
}

