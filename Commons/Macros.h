/********************************************************************/
/*      SWC     : Macros.c	                                    */
/*      Date    : 8/26/2023                                         */
/*      Authors : MetaWare LLC                                      */
/*		  Mahmoud Sayed Mahmoud Helmy (1285)                */
/*		  Mohamed Mahmoud Masoud (200)                      */
/*		  Mark Ehab Tawfik (201)                            */
/*		  Hazzem Mohamed Ezzeldin (1297)                    */
/*		  Yousef Khaled Ahmed (558)                         */
/********************************************************************/

/* =============================================================
 * 							File Guard
 * =============================================================*/
#ifndef MACROS_H_
#define MACROS_H_

/* =============================================================
 * 				 Function Like Macros
 * =============================================================*/

#define SET_BIT(REG,BIT)    (((REG)|= (1 << BIT)))
#define CLEAR_BIT(REG,BIT)  (((REG)&= ~(1 << BIT)))
#define TOGGLE_BIT(REG,BIT) (((REG) ^= (1 << BIT)))
#define GET_BIT(REG,BIT)    ((((REG & (1<<BIT)) >> BIT)))

#endif /* MACROS_H_ */
