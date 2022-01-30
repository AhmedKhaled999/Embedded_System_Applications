/*
 * MTIMER_Private.h
 *
 *  Created on: Jan 17, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MCAL_MTIMER_MTIMER_PRIVATE_H_
#define MCAL_MTIMER_MTIMER_PRIVATE_H_


#define TCCR0     *((volatile u8*)0x53)
#define TIMSK     *((volatile u8*)0x59)
#define TCNT0     *((volatile u8*)0x52)
#define OCR0      *((volatile u8*)0x5C)



/*Timer Prescaler Options */

#define TIMER_STOPPED                                    0
#define TIMER_NO_PRESCALER                               1
#define TIMER_8_PRESCALER                                2
#define TIMER_64_PRESCALER                               3
#define TIMER_256_PRESCALER                              4
#define TIMER_1024_PRESCALER                             5
#define TIMER_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE         6
#define TIMER_EXTERNAL_CLOCK_SOURCE_RISING_EDGE          7


/*Timer Mode options*/

#define TIMER0_NORMAL_MODE                                1
#define TIMER0_CTC_MODE                                   2
#define TIMER0_PHASECORRECT_PWM_MODE                      3
#define TIMER0_FAST_PWM_MODE                              4


/*Timer0 CTC Interrupt Options*/

#define TIMER0_CTC_INTERRUPT_ENABLED                      0
#define TIMER0_CTC_INTERRUPT_DISABLED                     1

/*Timer0 CTC OC0 PIN Options*/

#define TIMER0_OC0_PIN_DISCONNECTED                       0
#define TIMER0_OC0_PIN_TOGGLE							  1
#define TIMER0_OC0_PIN_SET								  2
#define TIMER0_OC0_PIN_CLR							      3

#define TIMER0_NON_INVERTING_PWM						  1
#define TIMER0_INVERTING_PWM                              0

#endif /* MCAL_MTIMER_MTIMER_PRIVATE_H_ */
