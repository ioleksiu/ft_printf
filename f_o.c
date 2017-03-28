/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_o.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:36:22 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/28 18:41:51 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			f_o_min(t_pf *a, int c_pr, int c_s, uintmax_t i)
{
	char		*s;

	s = ft_itoa_base(i, 8, a);
	if (a->hash && i > 0)
	{
		write(1, "0", 1);
		a->i += 1;
		c_pr -= 2;
		if (c_pr == -2)
			c_s--;
	}
	put_nchar('0', c_pr, a);
	if (((a->dot_val != -1 && i > 0) || (a->dot_val == -1 && a->hash == 1))
		|| (a->width == 0 && i > 0))
		ft_putstr(s, a);
	put_nchar(' ', c_s, a);
	free(s);
}

void			f_o_nmin(t_pf *a, int c_pr, int c_s, uintmax_t i)
{
	char		*s;
	int			len;

	len = count_unum(i);
	s = ft_itoa_base(i, 8, a);
	(a->hash && i > 0) ? c_s -= 1 : 0;
	if (a->zero == 0)
		put_nchar(' ', c_s, a);
	if (a->hash && i > 0)
	{
		write(1, "0", 1);
		a->i += 1;
		c_pr--;
	}
	if (a->zero == 1 && a->dot_val != -1)
		put_nchar('0', c_s, a);
	else if (a->zero == 1 && a->dot_val == -1)
		put_nchar(' ', c_s, a);
	put_nchar('0', c_pr, a);
	if ((a->dot_val != -1 || (a->dot_val == -1 && a->hash == 1))
		|| (a->width == 0 && i > 0))
		ft_putstr(s, a);
	else if (a->width > 0)
		put_nchar(' ', len, a);
	free(s);
}

void			f_o(t_pf *a, va_list ap)
{
	int			c_s;
	int			c_pr;
	int			len;
	char		*s;
	uintmax_t	i;

	c_s = 0;
	c_pr = 0;
	len = 0;
	i = cast_du(a, ap);
	s = ft_itoa_base(i, 8, a);
	len = count_num(i);
	if (i > 0)
		len = (int)ft_strlen(s);
	c_pr = (a->dot_val - len) > 0 ? (a->dot_val - len) : 0;
	c_s = a->width - len - c_pr;
	(a->minus == 0) ? f_o_nmin(a, c_pr, c_s, i) : f_o_min(a, c_pr, c_s, i);
	free(s);
}
