/* 
 * File:   config.h
 * Author: rgawron
 *
 * Created on 28 lipiec 2015, 22:51
 */

#ifndef CONFIG_H
#define	CONFIG_H

#ifndef __XC8
    #error "Incorrect project configuration"
#endif

#if defined(_18F25K50) || defined(_18F45K50)

    #pragma config PLLSEL = PLL3X   /* 16 Mhz * 3 = 48 Mhz */
    #pragma config CFGPLLEN = ON
    #pragma config CPUDIV = NOCLKDIV
    #pragma config LS48MHZ = SYS48X8
    #pragma config FOSC = HSH
    #pragma config nPWRTEN = ON
    #pragma config WDTEN = OFF
    #pragma config STVREN = ON
    #pragma config XINST = OFF

#else

    #error "Config flags for your device not defined"

#endif

#endif	/* CONFIG_H */

