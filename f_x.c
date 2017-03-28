/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_x.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:26:32 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/28 19:44:31 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			f_x_nmin(t_pf *a, int c_s, intmax_t i, int c_z)
{
	int			n;
	char		*s;

	n = count_num(i);
	if (i > 0)
	{
		s = ft_itoa_base4(i, 16, a);
		n = (int)ft_strlen(s);
		free(s);
	}
	(a->hash && i > 0) ? (c_s -= 2) : 0;
	(a->zero == 0) ? put_nchar(' ', c_s, a) : 0;
	(a->hash && i > 0) ? ft_put_strn("0x", 2, a) : 0;
	(i == 0 && a->dot_val != -1) ? put_nchar('0', 1, a) : 0;
	if (a->zero == 1 && a->dot_val != -1)
		put_nchar('0', c_s, a);
	else if (a->zero == 1 && a->dot_val == -1)
		put_nchar(' ', c_s, a);
	put_nchar('0', c_z, a);
	if (a->dot_val != -1 && i != 0)
		ft_putstr(s = ft_itoa_base4(i, 16, a), a);
	else if (a->width > 0)
		put_nchar(' ', n, a);
	(a->dot_val != -1 && i != 0) ? free(s) : 0;
}

void			f_x_min(t_pf *a, int c_s, int c_z, intmax_t i)
{
	int			n;
	char		*s;

	n = count_num(i);
	if (i > 0)
	{
		s = ft_itoa_base4(i, 16, a);
		n = (int)ft_strlen(s);
		free(s);
	}
	if (a->hash)
	{
		write(1, "0x", 2);
		a->i += 2;
		c_s -= 2;
	}
	if (i == 0 && a->dot_val != -1)
		put_nchar('0', 1, a);
	if (a->dot_val != -1 && i != 0)
	{
		ft_putstr(s = ft_itoa_base4(i, 16, a), a);
		free(s);
	}
	put_nchar(' ', c_s, a);
}

void			f_x(t_pf *a, va_list ap)
{
	int			c_s;
	int			c_z;
	int			n;
	intmax_t	i;
	char		*s;

	i = cast_du_x(a, ap);
	c_z = 0;
	c_s = 0;
	n = count_num(i);
	if (i > 0)
	{
		s = ft_itoa_base4(i, 16, a);
		n = (int)ft_strlen(s);
		free(s);
	}
	c_s = a->dot_val > n ? a->dot_val : n;
	c_s = a->width - c_s;
	c_z = a->dot_val - n;
	(a->minus == 0) ? f_x_nmin(a, c_s, i, c_z) : f_x_min(a, c_s, c_z, i);
}
