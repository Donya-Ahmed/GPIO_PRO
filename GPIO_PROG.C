/*
 * GPIO_PROG.C
 *
 *  Created on: Feb 11, 2020
 *      Author: SemSem
 */
#include "DATA_TYPES.h"
#include "REG_ADDRESS.h"
#include "GPIO_GONFIG.h"
#include "GPIO_PRIV.h"
#include "COMMON_MACROS.h"

/**********READPORT*/
u32 READPORT(u32 BASE)
{
if(BASE==PortAP_Base||BASE==PortBP_Base||BASE==PortCP_Base||
  BASE==PortDP_Base||BASE==PortEP_Base||BASE==PortFP_Base ||
  BASE==PortAH_Base||BASH==PortBP_Base||BASE==PortCH_Base||
  BASE==PortDH_Base||BASE==PortEH_Base||BASE==PortFH_Base)
 {
  DATA_PORT=READ_PORT(BASE+GPIO_DATA_OFFSET );
}
}
//-------------------------------------------------------------
/*****************READPIN**********/

u8 READPIN(u32 BASE,u8 PIN)
{
if(BASE==PortAP_Base||BASE==PortBP_Base||BASE==PortCP_Base||
  BASE==PortDP_Base||BASE==PortEP_Base||BASE==PortFP_Base ||
  BASE==PortAH_Base||BASH==PortBP_Base||BASE==PortCH_Base||
  BASE==PortDH_Base||BASE==PortEH_Base||BASE==PortFH_Base)
 {
  DATA_PIN=READ_PIN(BASE+GPIO_DATA_OFFSET,PIN );
}
}
//-------------------------------------------
/******************WRITEPORT*/

GPIOERROR WRITEPORT(u32 BASE,u8 VALUE)
{GPIOERROR_t state= pass;
if(BASE==PortAP_Base||BASE==PortBP_Base||BASE==PortCP_Base||
  BASE==PortDP_Base||BASE==PortEP_Base||BASE==PortFP_Base ||
  BASE==PortAH_Base||BASH==PortBP_Base||BASE==PortCH_Base||
  BASE==PortDH_Base||BASE==PortEH_Base||BASE==PortFH_Base)
 {
  WRITE_PORT(BASE+GPIO_DATA_OFFSET,VALUE );
}
else
{
state=INCORRECT_PORT;
}
return state;
}
//-------------------------------------------------
/*************WRITEPIN**************/

GPIOERROR WRITEPIN(u32 BASE,u8 PIN,u8 VALUE)
{GPIOERROR_t state= pass;
if(BASE==PortAP_Base||BASE==PortBP_Base||BASE==PortCP_Base||
  BASE==PortDP_Base||BASE==PortEP_Base||BASE==PortFP_Base ||
  BASE==PortAH_Base||BASH==PortBP_Base||BASE==PortCH_Base||
  BASE==PortDH_Base||BASE==PortEH_Base||BASE==PortFH_Base)
 {
  WRITE_PIN(BASE+GPIO_DATA_OFFSET,PIN,VALUE );
}
else
{
state=INCORRECT_PORT;
}
return state;
}




//----------------------------------------------------
/*SETPPORTDIR*/////////////////////////////
GPIOERROR SETPORT_DIR(u32 BASE,u8 VALUE){
GPIOERROR_t state= pass;
if(BASE==PortAP_Base||BASE==PortBP_Base||BASE==PortCP_Base||BASE==PortDP_Base||BASE==PortEP_Base||BASE==PortFP_Base)
{
    if(VALUE==INPUT  )
                  {
                     WRITE_PORT(BASE+GPIO_DIRECTION_OFFSET  ,INPUT);
                  }
     else if(VALUE==OUTPUT  ){


          WRITE_PORT(BASE+GPIO_DIRECTION_OFFSET  ,OUTPUT);
                      }
              else
            {
            state=INCORRECT_VALUE
                }
                }
else if(BASE==PortAH_Base||BASE==PortBH_Base||BASE==PortCH_Base||BASE==PortDH_Base||BASE==PortEH_Base||BASE==PortFH_Base)
           {
                      if(VALUE==INPUT  )
                     {
            WRITE_PORT(BASE+GPIO_DIRECTION_OFFSET  ,INPUT);
                 }
              else if(VALUE==OUTPUT  )
                  {
               WRITE_PORT(BASE+GPIO_DIRECTION_OFFSET  ,OUTPUT);
                 }
                  else
                      {
             state=INCORRECT_VALUE
                 }
                      }
             else
             {
         state=INCORRECT_PORT;
              }
return state;
               }

//---------------------------------------------------------------
/************SETPINDIR*///////////////////
GPIOERROR SETPIN_DIR(u32 BASE,u8 pin,u8 VALUE){
GPIOERROR_t state= pass;
if(BASE==PortAP_Base||BASE==PortBP_Base||BASE==PortCP_Base||BASE==PortDP_Base||BASE==PortEP_Base||BASE==PortFP_Base)
{


                     WRITE_PIN(BASE+GPIO_DIRECTION_OFFSET, pin ,VALUE);
}

else if(BASE==PortAH_Base||BASE==PortBH_Base||BASE==PortCH_Base||BASE==PortDH_Base||BASE==PortEH_Base||BASE==PortFH_Base)
           {

            WRITE_PIN(BASE+GPIO_DIRECTION_OFFSET,pin  ,VALUE);
           }


             else
             {
         state=INCORRECT_PORT;
              }
return state;
               }
//----------------------------------------------
/*FUCTIONALITY*//////////////////////////
GPIOERROR ALT_O_GPIO_PORT(u32 BASE,u8 FUNCTION){
GPIOERROR_t state= pass;
if(BASE==PortAP_Base||BASE==PortBP_Base||BASE==PortCP_Base||BASE==PortDP_Base||BASE==PortEP_Base||BASE==PortFP_Base)
{
    if(FUNCTION==GPIO )
                  {
                     WRITE_PORT( BASE+GPIO_ANALOG_MODE_SEL_OFFSET   ,GPIO);
                  }
     else if(FUNCTION==ALTERNATIVEFUN  ){


          WRITE_PORT(BASE+ GPIO_ANALOG_MODE_SEL_OFFSET  ,ALTERNATIVEFUN  );
                      }
              else
            {
            state=INCORRECT_FUNCTION;
                }
                }
else if(BASE==PortAH_Base||BASE==PortBH_Base||BASE==PortCH_Base||BASE==PortDH_Base||BASE==PortEH_Base||BASE==PortFH_Base)
           {
                      if(FUNCTION==GPIO  )
                     {
            WRITE_PORT(BASE+ GPIO_ANALOG_MODE_SEL_OFFSET   ,GPIO);
                 }
              else if(FUNCTION==ALTERNATIVEFUN  )
                  {
               WRITE_PORT(BASE+ GPIO_ANALOG_MODE_SEL_OFFSET  ,ALTERNATIVEFUN  );
                 }
                  else
                      {
             state=INCORRECT_FUNCTION;
                 }
                      }
             else
             {
         state=INCORRECT_PORT;
              }
return state;
               }
//-----------------------------------------------------------
/*************SETCURRENTFORPORT*/////////////////
GPIOERROR SETCURRENT_PORT(u32 BASE,u8 CRURRENTVALUE){
GPIOERROR_t state= pass;
if(BASE==PortAP_Base||BASE==PortBP_Base||BASE==PortCP_Base||BASE==PortDP_Base||BASE==PortEP_Base||BASE==PortFP_Base)
{
    if(CURRENTVALUE==CURRENT2AM )
                  {
                     WRITE_PORT( BASE+GPIO_2_MA_DRIVE_SEL_OFFSET   ,HIGH);
                  }
     else if(CURRENTVALUE==CURRENT4AM  ){


          WRITE_PORT(BASE+ GPIO_4_MA_DRIVE_SEL_OFFSET   ,HIGH );
                      }
   else if(CURRENTVALUE==CURRENT8AM  ){


          WRITE_PORT(BASE+ GPIO_8_MA_DRIVE_SEL_OFFSET   ,HIGH );
                      }
else
{
state=INCORRECT_CURRENT;
}

                }
else if(BASE==PortAH_Base||BASE==PortBH_Base||BASE==PortCH_Base||BASE==PortDH_Base||BASE==PortEH_Base||BASE==PortFH_Base)
{
    if(CURRENTVALUE==CURRENT2AM )
                  {
                     WRITE_PORT( BASE+GPIO_2_MA_DRIVE_SEL_OFFSET   ,HIGH);
                  }
     else if(CURRENTVALUE==CURRENT4AM  ){


          WRITE_PORT(BASE+ GPIO_4_MA_DRIVE_SEL_OFFSET   ,HIGH );
                      }
   else if(CURRENTVALUE==CURRENT8AM  ){


          WRITE_PORT(BASE+ GPIO_8_MA_DRIVE_SEL_OFFSET   ,HIGH );
                      }
else
{
state=INCORRECT_CURRENT;
}

                }
return state;
               }
//--------------------------------------------------------
/*SETRESISTANCEFORFORPORT*////////////////////
GPIOERROR SETRES_PORT(u32 BASE,u8 RESISTANCEVALUE){
GPIOERROR_t state= pass;
if(BASE==PortAP_Base||BASE==PortBP_Base||BASE==PortCP_Base||BASE==PortDP_Base||BASE==PortEP_Base||BASE==PortFP_Base)
{
    if(RESISTANCEVALUE==PULLDOWN )
                  {
                     WRITE_PORT( BASE+GPIO_PULL_DOWN_SEL_OFFSET   ,HIGH);
                  }
     else if(RESISTANCEVALUE==PULLUP ){


          WRITE_PORT(BASE+ GPIO_PULL_UP_SEL_OFFSET      ,HIGH );
                      }
   else if(RESISTANCEVALUE==OPENDRAIN  ){


          WRITE_PORT(BASE+ GPIO_OPEN_DRAIN_SEL_OFFSET   ,HIGH );
                      }
else
{
state=INCORRECT_RESISTANCE;
}

                }
if(BASE==PortAH_Base||BASE==PortBH_Base||BASE==PortCH_Base||BASE==PortDH_Base||BASE==PortEH_Base||BASE==PortFH_Base)
{
                 if(RESISTANCEVALUE==PULLDOWN )
                  {
                     WRITE_PORT( BASE+GPIO_PULL_DOWN_SEL_OFFSET   ,HIGH);
                  }
                  else if(RESISTANCEVALUE==PULLUP ){


                         WRITE_PORT(BASE+ GPIO_PULL_UP_SEL_OFFSET      ,HIGH );
                      }
                       else if(RESISTANCEVALUE==OPENDRAIN  ){


                          WRITE_PORT(BASE+ GPIO_OPEN_DRAIN_SEL_OFFSET   ,HIGH );
                                        }
                              else
                                    {
                         state=INCORRECT_RESISTANCE;
                               }
}

return state;
               }
//------------------------------------------------------------------------
/*DIGITAL OR ANALOG FOR PORT-*///////////////////////
GPIOERROR DIDITALEN_PORT(u32 BASE,u8 VALUE){
GPIOERROR_t state= pass;
if(BASE==PortAP_Base||BASE==PortBP_Base||BASE==PortCP_Base||BASE==PortDP_Base||BASE==PortEP_Base||BASE==PortFP_Base)
{
    if(VALUE==DIGITAL )
                  {
                     WRITE_PORT( BASE+DIGITAL_EN_OFFSET  ,HIGH);
                    WRITE_PORT( BASE+ANALOG_MODE_SEL_OFFSET  ,LOW);
                  }
     else if(VALUE==ANALOG ){


          WRITE_PORT(BASE+DIGITAL_EN_OFFSETT      ,LOW );
          WRITE_PORT( BASE+ANALOG_MODE_SEL_OFFSET  ,HIGH);
                      }

else
{
state=INCORRECT_VALUE;
}

                }

if(BASE==PortAH_Base||BASE==PortBH_Base||BASE==PortCH_Base||BASE==PortDH_Base||BASE==PortEH_Base||BASE==PortFH_Base)
{
    if(VALUE==DIGITAL )
                  {
                     WRITE_PORT( BASE+DIGITAL_EN_OFFSET  ,HIGH);
                    WRITE_PORT( BASE+ANALOG_MODE_SEL_OFFSET  ,LOW);
                  }
     else if(VALUE==ANALOG ){


          WRITE_PORT(BASE+DIGITAL_EN_OFFSETT      ,LOW );
          WRITE_PORT( BASE+ANALOG_MODE_SEL_OFFSET  ,HIGH);
                      }

else
{
state=INCORRECT_VALUE;
}

                }

return state;
               }
//-------------------------------------------------------------------
/*INTIALIZATION*/



//--------------------------------------------------------
/*UNLOCKFUNCTION*////////////////////






//--------------------------------------------------------

