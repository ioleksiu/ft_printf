/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 15:08:50 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/02/19 15:08:51 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_print_struct(t_pf *a)
{
	char *b[7] = {"none", "hh", "h", "l", "ll", "j", "z"};
	printf("minus %d \n", a->minus);
	printf("zero %d \n", a->zero);
	printf("plus %d \n", a->plus);
	printf("space %d \n", a->space);
	printf("hash %d \n", a->hash);
	printf("dot %d \n", a->dot);
	printf("dot_val %d \n", a->dot_val);
	printf("width %d \n", a->width);
	printf("size : %s = ", b[a->size]);
	printf("%d \n", a->size);
	printf("conversion %c \n", a->conversion);
}