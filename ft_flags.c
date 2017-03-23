/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:08:25 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/23 19:45:59 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flags(t_pf *a, char *s)
{
	if (*s == '-')
		a->minus = 1;
	else if (*s == ' ')
		a->space = 1;
	else if (*s == '+')
		a->plus = 1;
	else if (*s == '#')
		a->hash = 1;
	else if (*s == '0')
		a->zero = 1;
	else
		return (s);
	s += 1;
	return (s);
}
