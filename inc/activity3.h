/**
 * @file activity3.h
 * @author SingarajuAmulya
 * @brief Activity3 Header file
 * @version 0.1
 * @date 2021-08-01
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef ACTIVITY3_H_INCLUDED
#define ACTIVITY3_H_INCLUDED
/**
 * @brief macros definitions and funcion declarations
 *
 */
#define PWM_port (PORTB2)
char PWM(uint16_t temp_value);
void PWM_init(void);

#endif // ACTIVITY3_H_INCLUDED
