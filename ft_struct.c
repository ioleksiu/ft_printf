/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 15:05:48 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/24 13:52:39 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf		*ft_struct(void)
{
	t_pf	*a;

	a = (t_pf*)malloc(sizeof(t_pf));
	a->minus = 0;
	a->zero = 0;
	a->plus = 0;
	a->space = 0;
	a->hash = 0;
	a->dot = 0;
	a->dot_val = 0;
	a->width = 0;
	a->size = 0;
	a->conversion = '0';
	a->i = 0;
	return (a);
}
