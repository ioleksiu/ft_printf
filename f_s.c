/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_s.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:19:39 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/28 19:47:16 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			f_s2(char *s, t_pf *a, int c_prec, int c_s)
{
	if (a->minus == 1)
	{
		if (a->dot_val != -1)
			ft_put_strn(s, c_prec, a);
		put_nchar(' ', c_s, a);
	}
	if (a->minus == 0)
	{
		a->zero == 0 ? put_nchar(' ', c_s, a) : put_nchar('0', c_s, a);
		if (a->dot_val != -1)
			ft_put_strn(s, c_prec, a);
	}
}

void			f_s(t_pf *a, va_list ap)
{
	int			c_s;
	int			c_prec;
	char		*s;
	int			i;
	int			flag;

	flag = 0;
	s = va_arg(ap, char *);
	i = ft_strlen(s);
	c_s = 0;
	c_prec = 0;
	(a->dot_val == -1) ? c_s = a->width : 0;
	if (!s)
	{
		s = ft_strdup("(null)");
		i = ft_strlen(s);
		flag++;
	}
	if (a->dot && a->dot_val != -1)
		c_prec = (a->dot_val > i ? i : a->dot_val);
	else if (a->dot_val != -1)
		c_prec = i;
	c_s = a->width - c_prec;
	f_s2(s, a, c_prec, c_s);
	(flag) ? free(s) : 0;
}
