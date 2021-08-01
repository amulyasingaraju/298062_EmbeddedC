/**
 * @file activity1.h
 * @author SingarajuAmulya
 * @brief Activity1 Header File
 * @version 0.1
 * @date 2021-08-01
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef ACTIVITY1_H_INCLUDED
#define ACTIVITY1_H_INCLUDED
/**
 * @brief definition of macros and function declarations
 *
 */
#define heater_switch_close !(PIND&(1<<PD2))
#define seat_switch_close !(PIND&(1<<PD3))
#define LED (PORTB1)
#define heater (PORTD2)
#define seat (PORTD3)

void port_assignment();
int activity1();

#endif // ACTIVITY1_H_INCLUDED
