/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_p.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:45:32 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/23 18:13:31 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				f_p_minus(t_pf *a, int c_pr, int c_s, char *s)
{
	write(1, "0x", 2);
	a->i += 2;
	put_nchar('0', c_pr, a);
	if (a->dot_val != -1)
		ft_putstr(s, a);
	put_nchar(' ', c_s, a);
}

void				f_p_no_minus(t_pf *a, int c_pr, int c_s, char *s)
{
	put_nchar(' ', c_s, a);
	write(1, "0x", 2);
	a->i += 2;
	put_nchar('0', c_pr, a);
	if (a->dot_val != -1)
		ft_putstr(s, a);
}

void				f_p(t_pf *a, va_list ap)
{
	unsigned long	i;
	char			*s;
	int				c_s;
	int				c_pr;
	int				len;

	i = va_arg(ap, unsigned long);
	s = ft_itoa_base(i, 16, a);
	len = ft_strlen(s);
	c_pr = (a->dot_val - len) > 0 ? a->dot_val - len : 0;
	c_s = a->width - len - c_pr - 2;
	if (i == 0 && a->width < 0)
		c_s--;
	if (a->minus == 1)
		f_p_minus(a, c_pr, c_s, s);
	else
		f_p_no_minus(a, c_pr, c_s, s);
	free(s);
}
