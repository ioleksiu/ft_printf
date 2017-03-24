/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:59:20 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/24 13:42:42 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(char *format, ...)
{
	t_pf		*a;
	va_list		ap;
	int			i;

	va_start(ap, format);
	a = struct_fill(ap, format, ft_struct());
	i = a->i;
	free(a);
	va_end(ap);
	return (i);
}
