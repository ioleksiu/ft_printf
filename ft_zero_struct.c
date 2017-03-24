/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:05:06 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/24 13:53:29 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf	*ft_zero_struct(t_pf *a)
{
	a->minus = 0;
	a->zero = 0;
	a->plus = 0;
	a->space = 0;
	a->hash = 0;
	a->dot = 0;
	a->dot_val = 0;
	a->width = 0;
	a->size = 0;
	a->conversion = '0';
	return (a);
}
