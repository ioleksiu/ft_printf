/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:18:18 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/23 15:41:07 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t		cast_d(t_pf *a, va_list ap)
{
	intmax_t	j;

	if (a->size == 3)
		return (va_arg(ap, long));
	if (a->size == 2)
		return ((short)(va_arg(ap, int)));
	if (a->size == 1)
		return ((char)(va_arg(ap, int)));
	if (a->size == 4)
		return (va_arg(ap, long long));
	if (a->size == 5)
	{
		j = va_arg(ap, size_t);
		return (j);
	}
	if (a->size == 6)
		return (va_arg(ap, intmax_t));
	return (va_arg(ap, int));
}
