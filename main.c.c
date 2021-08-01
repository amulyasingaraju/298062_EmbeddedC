/**
 * @file EmbProjectMain.c
 * @author SingarajuAmulya
 * @brief main file for EmbeddedActivity to call subsequent activities
 * @version 0.1
 * @date 2021-08-01
 *
 * @copyright Copyright (c) 2021
 *
 */


#include <avr/io.h>
#include <util/delay.h>
#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"
/**
 * @brief main function to call sub activities
 *
 * @return int
 */
int main(void)
{
char data;
USARTInit(103);//Initialize USART
uint16_t temp, ADC_value=0;//initialize 10 bit resolution for 16
/**
 * @brief while true enter loop
 *
 */
while(1)
{
    activity1();//Detecting user; calling activity1
    /**
     * @brief Construct a new if object activity 1 output holds true
     *
     */
    if(activity1()==1)//if activity1 output is true
    {
       temp=ReadADC(ADC_value);
        data=PWM(temp);
        USARTWriteChar(data);
        _delay_ms(200);
    }


}

return 0;
}
