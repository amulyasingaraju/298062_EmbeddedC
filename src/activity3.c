/**
 * @file activity3.c
 * @author SingarajuAmulya
 * @brief PWM assignment as per ADC values read
 * @version 0.1
 * @date 2021-08-01
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <avr/io.h>
#include <util/delay.h> //delay function
#include "activity3.h"
/**
 * @brief Initialization of PWM ports and registers
 *
 */
void PWM_init(void) //initialization of PWM
{

    TCCR1A|=(1<<COM1B1)|(1<<WGM10)|(1<<WGM11);  //COM1B1->1 = NON-INVERTING MODE; FAST PWM (table 15-3)
                                                //From Table15-5 waveform gen mode bit
                                                //PWM Phase Correct 10 bit ->11
                                                //0X3FF is TOP->***1024 IS MAX VALUE***
    TCCR1B =(1<<WGM12)|(1<<CS11)|(1<<CS10);//Clock bit Select=CS11 CS10-> 1 1->64 PRESCALAR -> MORE PRESCALAR VALUE -> MORE RESOLUTION OF MOTOR
    DDRB|=(1<<PWM_port);//Direction of o/p for PWM; PWM_port=PB2(OC1B-> Output Compare Timer 1 Channel B)

}
/**
 * @brief Assigning PWM as per Temp Table given in assignment
 *
 * @param temp_value
 * @return char
 */
char PWM(uint16_t temp_value)
{
    char temp_over_protocol;
    PWM_init(); // calling Initialization parameters

    if(temp_value>=0 && temp_value<=200)//20% Value from ADC Potentiometer
    {
       OCR1B=205;// 20%of 1024; Output Compare Register 1B (PORT PB2-> OC1B)
       temp_over_protocol=20;
      _delay_ms(200);
    }
    else if(temp_value>=201 && temp_value<=500)//40% of 1024
    {
       OCR1B=410;
       temp_over_protocol=25;
      _delay_ms(200);
    }
    else if(temp_value>=501 && temp_value<=700)//70%
    {
       OCR1B=716;
       temp_over_protocol=29;
      _delay_ms(200);
    }
    else if(temp_value>=701 && temp_value<=1024)//90%
    {
       OCR1B=972;
       temp_over_protocol=33;
      _delay_ms(200);
    }
    /**
     * @brief else condition if temperature read from ADC is not in range
     *
     */
    else
    {
        OCR1B=0;
        temp_over_protocol=0;
    }
    return temp_over_protocol;



}
