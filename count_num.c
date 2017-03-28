/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:13:52 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/23 15:55:24 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			count_num(int a)
{
	int		i;

	if (a == 0)
		return (1);
	i = 0;
	if (a < 0)
		a *= -1;
	while (a > 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}