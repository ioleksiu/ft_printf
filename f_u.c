/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_u.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:28:09 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/23 18:23:59 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			f_u_min(t_pf *a, int c_z, int c_s, uintmax_t i)
{
	put_nchar('0', c_z, a);
	if (a->dot_val != -1)
		ft_put_unbr(i, a);
	put_nchar(' ', c_s, a);
}

void			f_u_nmin(t_pf *a, int c_z, int c_s, uintmax_t i)
{
	if (a->plus == 1)
		c_s--;
	if (a->dot == 0)
		a->zero == 0 ? put_nchar(' ', c_s, a) : put_nchar('0', c_s, a);
	else
		put_nchar(' ', c_s, a);
	put_nchar('0', c_z, a);
	if (a->dot_val != -1)
		ft_put_unbr(i, a);
}

void			f_u(t_pf *a, va_list ap)
{
	uintmax_t	i;
	int			n;
	int			c_s;
	int			c_z;

	i = cast_du(a, ap);
	n = count_unum(i);
	c_s = 0;
	c_z = 0;
	c_s = a->dot_val > n ? a->dot_val : n;
	c_s = a->width - c_s;
	c_z = a->dot_val - n;
	(a->minus == 1) ? f_u_min(a, c_z, c_s, i) : f_u_nmin(a, c_z, c_s, i);
}
