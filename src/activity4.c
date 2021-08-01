/**
 * @file activity4.c
 * @author SingarajuAmulya
 * @brief USART for displaying temperature values over protocol
 * @version 0.1
 * @date 2021-08-01
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <avr/io.h>
#include <util/delay.h>
#include "activity4.h"
/**
 * @brief USART Initialization of Registers and Ports
 *
 * @param ubrr_value
 */
void USARTInit(uint16_t ubrr_value) //ubrr_value=103 calculated
{
    //Set Baud Rate
    UBRR0L=ubrr_value;
    UBRR0H=(ubrr_value>>8)&0x00ff;
    UCSR0C=(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);

    //Enable rec and trans
    UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);

}
/**
 * @brief Read Character Initialization of USART
 *
 * @return char
 */
char USARTReadChar()
{
    //Wait till data is available
    while(!(UCSR0A &(1<<RXC0)))
    {
        //Do Nothing
    }
    return UDR0;
}
/**
 * @brief Write Character Function Definition of USART
 *
 * @param data
 */
void USARTWriteChar(char data)
{
    //Wait till Transmitter is ready
    while(!(UCSR0A &(1<<UDRE0)))//Writing to UDR Register that acts as a buffer
    {
        //Do Nothing
    }
    UDR0=data;
}
