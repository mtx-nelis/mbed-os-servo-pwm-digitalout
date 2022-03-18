#include "mbed.h"

/* 
*  PWM on DigitalOut pins 
*  20220318 - NA
*/



/* 
*  See https://www.nxp.com/docs/en/data-sheet/K66P144M180SF5V2.pdf for pin functions (page 74..81)
*  
*  (LQFP_# is the number in the first column in the table)
*  
*  Label    PinName     LQFP_#      Mux             Available timer for PWM
*  -----------------------------------------------------------------------------------------------
*  Dout0    PTA8        60          GPIO            FTM1_CH0
*  Dout1    PTA9        61          GPIO            FTM1_CH1
*  Dout2    PTB18       97          GPIO            FTM2_CH0
*  Dout3    PTC7        112         GPIO            none
*  Dout4    PTB11       92          GPIO            none
*  Dout5    PTE24       45          GPIO            none
*  Dout6    PTC12       117         GPIO            none
*  
*  PWM0     PTC2        105         FTM0_CH1        
*  PWM1     PTC5        110         FTM0_CH2
*  PWM2     PTA6        58          FTM0_CH3
*  PWM3     PTA7        59          FTM0_CH4
*  
*  - All dedicated PWM pins on the freedom controller make use of the FlexTimer0 module and output a PWM signal of 19V at high current. 
*    These outputs can directly drive loads such as power resistors, heater foils, incandescent lamps and so on.
*  
*  - On the DigitalOut pins, the first three pins also capable of outputting a PWM signal.
*    These outputs can be used as a control signal for i.e. servo's and other devices with a digital input.
*    
*  - The MBED compiler doesn't seem to care that the other DigitalOut pins aren't capable of generating PWM signals. 
*    Why is that? Does it generate them in software instead or is hardware PWM not used on the other pins as well?
*    As usual, the documentation or internet isn't providing an answer here. Probably have to dig into the MBED OS code to see what's happening.
*
*    TODO: Check every output with a scope to see if there's a PWM signal.
*/


#define DOUT0_PIN   PTA8
#define DOUT1_PIN   PTA9
#define DOUT2_PIN   PTB18
#define DOUT3_PIN   PTC7
#define DOUT4_PIN   PTB11
#define DOUT5_PIN   PTE24
#define DOUT6_PIN   PTC12

#define PWM0_PIN    PTC2    
#define PWM1_PIN    PTC5
#define PWM2_PIN    PTA6
#define PWM3_PIN    PTA7


// main() runs in its own thread in the OS
int main()
{
    // Setup pins as PWM outputs
    PwmOut dout0_pwm(DOUT0_PIN);
    PwmOut dout1_pwm(DOUT1_PIN);
    PwmOut dout2_pwm(DOUT2_PIN);
    PwmOut dout3_pwm(DOUT3_PIN);
    PwmOut dout4_pwm(DOUT4_PIN);
    PwmOut dout5_pwm(DOUT5_PIN);
    PwmOut dout6_pwm(DOUT6_PIN);

    PwmOut pwm0(PWM0_PIN);
    PwmOut pwm1(PWM1_PIN);
    PwmOut pwm2(PWM2_PIN);
    PwmOut pwm3(PWM3_PIN);
    
    // Set period to 20ms
    dout0_pwm.period_ms(20);
    dout1_pwm.period_ms(20);
    dout2_pwm.period_ms(20);
    dout3_pwm.period_ms(20);
    dout4_pwm.period_ms(20);
    dout5_pwm.period_ms(20);
    dout6_pwm.period_ms(20);

    pwm0.period_ms(20);
    pwm1.period_ms(20);
    pwm2.period_ms(20);
    pwm3.period_ms(20);
    
    // Set pulse width to 1ms 
    // For servo control, it's easier to use the pulsewidth in microseconds than to use a percentage (like DOUT0.write(0.075) ).
    // Set different values so we can see the difference on a scope
    dout0_pwm.pulsewidth_us( 250);
    dout1_pwm.pulsewidth_us( 500);
    dout2_pwm.pulsewidth_us( 750);
    dout3_pwm.pulsewidth_us(1000);
    dout4_pwm.pulsewidth_us(1250);
    dout5_pwm.pulsewidth_us(1500);
    dout6_pwm.pulsewidth_us(1750);
    
    pwm0.pulsewidth_us(500);
    pwm1.pulsewidth_us(1000);
    pwm2.pulsewidth_us(1500);
    pwm3.pulsewidth_us(2000);

    const bool did_i_leave_my_cookies_at_work = true;
    while (true) {
        if (!did_i_leave_my_cookies_at_work) {
            printf("Let's grab a cookie\n");
        } else {
            printf("I left my cookies at work\n");
        }
    }
}

