/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:03:19 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/24 13:58:20 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*struct_fill_1(char *s, t_pf *a)
{
	while (*s && a->conversion == '0')
	{
		if (ft_strchr("hljz -+#01234567.89tsSpdDioOuUxXcC", *s) == NULL
			&& a->conversion == '0')
		{
			a->conversion = 'c';
			f_proc(*s, a);
			ft_zero_struct(a);
			s++;
			return (s);
		}
		s = parse(s, a);
	}
	return (s);
}

t_pf	*struct_fill(va_list ap, char *s, t_pf *a)
{
	while (*s != '\0')
	{
		s = ft_print_text(a, s);
		if (!(*s))
			break ;
		if (*s == 'n')
		{
			b_n(a, ap);
			s++;
		}
		s = struct_fill_1(s, a);
		if (!(*s) && a->conversion == '0')
			return (a);
		pf_cast(a, ap);
		(ft_strchr("sSpdDioOuUxXcC", *s) && *(s - 1) == '%') ? s++ : 0;
		ft_zero_struct(a);
	}
	return (a);
}
