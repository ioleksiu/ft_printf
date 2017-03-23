/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_d_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:14:59 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/23 15:44:54 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		cast_d_u(t_pf *a, va_list ap)
{
	void		*i;

	i = va_arg(ap, void *);
	if (a->size == 3)
		return ((unsigned long)i);
	if (a->size == 2)
		return ((unsigned short)i);
	if (a->size == 1)
		return ((unsigned char)i);
	if (a->size == 4)
		return ((unsigned long long)i);
	if (a->size == 6)
		return ((uintmax_t)i);
	return ((unsigned long)i);
}
