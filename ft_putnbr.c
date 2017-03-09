/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:08:03 by ioleksiu          #+#    #+#             */
/*   Updated: 2016/12/20 20:34:52 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putnbr(intmax_t n, t_pf *a);

void	ft_putnbr(intmax_t n, t_pf *a)
{
	char			p;
    intmax_t    	z;

	z = n;
	if (n < 0)
	{
		write(1, "-", 1);
		z = -z;
		a->i++;
	}
	if (z >= 10)
	{
		ft_putnbr(z / 10, a);
		ft_putnbr(z % 10, a);
	}
	else
	{
		p = z + 48;
		write(1, &p, 1);
		a->i++;
	}
}
