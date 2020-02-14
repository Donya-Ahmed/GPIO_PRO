/*
 * GPIO_CONFIG.h
 *
 *  Created on: Feb 11, 2020
 *      Author: SemSem
 */

#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_
#define HIGH 1
#define LOW 0
typedef enum GPIOERROR{
    PASS=1, INCORRECT_RESISTANCE ,INCORRECT_CURRENT ,INCORRECT_PORT ,INCORRECT_FUNCTION,INCORRECT_VALUE

}GPIOERROR_t;

 /*choise of mode(APB OR AHB)*/
#define MODE_GPIO    GPIO_Advanced_Peripheral_Bus
 //-----------------------------------------
#define VAL OUTOUT
//-----------------------------
#define FUN   GPIO
//------------------------------------
#define CUR   CURRENT8AM
//---------------------------------------
#define RES   PULLDOWN
//-----------------------------------
#define DA  DIGITAL




#endif /* GPIO_CONFIG_H_ */
