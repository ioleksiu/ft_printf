/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_U.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:27:28 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/23 16:38:55 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		f_ub_m(t_pf *a, long i, int c_s, int c_z)
{
	put_nchar('0', c_z, a);
	ft_put_unbr(i, a);
	put_nchar(' ', c_s, a);
}

void		f_ub_nm(t_pf *a, long i, int c_s, int c_z)
{
	if (i < 0 || a->plus == 1)
		c_s--;
	if (a->space == 1 && c_s <= 0 && i > 0)
		put_nchar(' ', 1, a);
	if (a->dot == 0)
		a->zero == 0 ? put_nchar(' ', c_s, a) : put_nchar('0', c_s, a);
	else
		put_nchar(' ', c_s, a);
	put_nchar('0', c_z, a);
	ft_put_unbr(i, a);
}

void		f_uu(t_pf *a, va_list ap)
{
	long	i;
	int		n;
	int		c_s;
	int		c_z;

	i = (long)va_arg(ap, void*);
	n = count_unum(i);
	c_s = 0;
	c_z = 0;
	c_s = a->dot_val > n ? a->dot_val : n;
	c_s = a->width - c_s;
	c_z = a->dot_val - n;
	(a->minus == 1) ? f_ub_m(a, i, c_s, c_z) : f_ub_nm(a, i, c_s, c_z);
}
