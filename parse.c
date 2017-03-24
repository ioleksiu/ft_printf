/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:04:11 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/24 13:54:13 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*parse(char *s, t_pf *a)
{
	s = ft_flags(a, s);
	s = ft_width(a, s);
	s = ft_dot(a, s);
	s = ft_size(a, s);
	if (ft_strchr("pisoSdDOuUxXcC", *s) && *s)
	{
		a->conversion = *s;
		s++;
	}
	return (s);
}
