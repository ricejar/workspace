/*
 * task3_reg.c
 *
 *  Created on: Sep 13, 2021
 *      Author: wangy62
 */

#include "stm32f769xx.h"
#include "hello.h"

#include<stdint.h>




int main(void){

	Sys_Init();
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	GPIOD -> MODER |= 0x00000100U;
	GPIOC -> MODER &= 0xFFFF3FFFU;
	GPIOC -> PUPDR |= 0X00004000U;

	printf("\033[2J\033[;H"); // Erase screen & move cursor to home position
	    fflush(stdout); // Need to flush stdout after using printf that doesn't end in \n
	    printf("press ESC to quit.\r\n\n");

	while(1){
		printf("Pin state %d\r\n",GPIOC -> IDR & 0x00000080 );
		if (GPIOC -> IDR & 0x00000080)
			GPIOD ->BSRR = 0x00100000U;
		else
			GPIOD ->BSRR = 0x00000010U;
	}

}

