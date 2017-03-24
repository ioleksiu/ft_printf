/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:53:52 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/23 19:50:26 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			f1(uintmax_t value, uintmax_t base, char *str, int *i)
{
	char		*tmp;

	tmp = "0123456789ABCDEF";
	if (value >= base)
		f1(value / base, base, str, i);
	str[(*i)++] = tmp[(value % base)];
}

char			*ft_itoa_base_1(uintmax_t value, uintmax_t base, t_pf *a)
{
	int			i;
	char		*str;

	i = 0;
	if (base < 2 || base > 16 || !(str = (char*)malloc(32)))
		return (0);
	f1(value, base, str, &i);
	str[i] = '\0';
	a->str = str;
	return (str);
}
