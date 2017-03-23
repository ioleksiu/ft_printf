/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_proc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:25:09 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/23 18:16:33 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		f_proc(char c, t_pf *a)
{
	int		l;
	char	sp;

	l = a->width;
	sp = (char)((a->zero == 1 && a->minus != 1) ? '0' : ' ');
	if (a->minus == 0)
		while (l-- > 1)
			write(1, &sp, 1);
	write(1, &c, 1);
	if (a->minus != 0)
		while (l-- > 1)
			write(1, &sp, 1);
	a->i = (a->width > 0) ? (a->i + a->width) : (a->i + 1);
}
