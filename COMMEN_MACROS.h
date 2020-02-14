/*
 * COMMEN_MACROS.h
 *
 *  Created on: Feb 12, 2020
 *      Author: SemSem
 */

#ifndef COMMEN_MACROS_H_
#define COMMEN_MACROS_H_
#include "DATA_TYPES.h"
#define READ_PORT(address)  (*(volatile u32*) (address))
#define WRITE_port(address,value)   ((*(volatile u32*) (address))=value)

#define SET_PIN(address,pin)    READ_PORT(address)|=(1<<pin)
#define CLEAR_PIN(address,pin)   READ_PORT(address)&=~(1<<pin)
#define TOGGLE_PIN(address,pin)    READ_PORT(address)^=(1<<pin)

static inline void WRITE_PIN(uint32 reg, uint8 pin , uint8 val);
static inline uint8 READ_PIN(uint32 reg,uint8 pin);

static inline void WRITE_PIN(u32 address, u8 pin , u8 value){
    if(value == HIGH){
    READ_PORT(address) |= (1<<pin);
    }else if(value == LOW){
        READ_PORT(address) &= ~(1<<pin);
    }
}

static inline u8 READ_PIN(u32 address,u8 pin){

    return ((READ_PORT(address)&(1<<pin))>>pin);
}





#endif /* COMMEN_MACROS_H_ */
