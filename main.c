/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 15:43:53 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/02/19 19:10:46 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(int ac, char **av) {
    va_list va;

    if (ac > 1) {
        char *d = "work!";
        (void) ac;
        /*
       printf("\n-------------------ORIGINAL----------------------\n");
        printf("\nreturns : %d\n" ,printf("Hello %%%.0+ 40s %s","word!", "ama hero"));
        printf("\nHello%%%0+232#43-23-.34#c \n", 42);
        printf("\n-------------------FT_PRINTF---------------------\n");
        printf("\nreturns : %d\n",ft_printf("Hello %%%.0+ 40s %s","word!", "ama hero"));
        ft_printf("\nHello%%%0+232#43-23-.34#c \n", 42);
        printf("\n-------------------ORIGINAL----------------------\n");
        printf("\nreturns : %d\n" ,printf("Hello %%%.0+ 1s%s","word!", "ama hero"));
        printf("\nHello%%%0+232#43-23-.34#c \n", 42);
        printf("\n-------------------FT_PRINTF---------------------\n");
        printf("\nreturns : %d\n",ft_printf("Hello %%%.0+ 1s%s","word!", "ama hero"));
        ft_printf("\nHello%%%0+232#43-23-.34#c \n", 42);
        printf("\n-------------------ORIGINAL----------------------\n");
        printf("\nreturns : %d\n" ,printf("%.0+ 12  %Hello%%%.5+ 12  %%s%.200  23s %.0 10 - c","world!", "ama hero",'c'));
        printf("\nHello%%%0+232#43-23-.34#c \n");
        printf("\n-------------------FT_PRINTF---------------------\n");
        printf("\nreturns : %d\n",ft_printf("%.0+ 12  %Hello%%%.5+ 12  %%s%.200  23s %.0 10 - c","world!", "ama hero",'c'));
        ft_printf("\nHello%%%0+232#43-23-.34#c \n");
        printf("%.15 3s","HELLO");
        printf("\n----------\n");
        ft_printf("%.15 3s","HELLO");
        printf("\n-------------------ORIGINAL----------------------\n");
        printf("\nreturns : %d\n" ,printf("Hello%%%.+ 0 -10s %s","word!", "ama hero"));
        printf("\nHello%%%0+232#43-23-.34#c \n");
        printf("\n-------------------FT_PRINTF---------------------\n");
        printf("\nreturns : %d\n" ,printf("Hello%%%.+ 0 -10s %s","word!", "ama hero"));
        printf("\n=============\n");
        printf("original : %0100 19s","hello");
        printf("\n");
        ft_printf("nriginal : %0100 19s","hello");
        printf("\n");
        printf("%3.5 -5k");
        printf("\n");
        ft_printf("%3.5 -5k");
        printf("\n=============\n");
        printf("original : %0-100 19s","hello");
        printf("\n");
        ft_printf("nriginal : %0-100 19s","hello");
        printf("\n");
        printf("Hello%%%0+23243-234-.3434");
        printf("\n");
        ft_printf("Hello%%%0+23243-234-.3434");
*/

        printf("\n------------------\n");
        printf("%%");
        printf("\n------------------\n");
        ft_printf("%%");
        }
    return (0);
}