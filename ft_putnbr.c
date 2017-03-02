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

#include <unistd.h>

void	ft_putnbr(int n);

void	ft_putnbr(int n)
{
	char			p;
	unsigned int	z;

	z = n;
	if (n < 0)
	{
		write(1, "-", 1);
		z = -z;
	}
	if (z >= 10)
	{
		ft_putnbr(z / 10);
		ft_putnbr(z % 10);
	}
	else
	{
		p = z + 48;
		write(1, &p, 1);
	}
}
