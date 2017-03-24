/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:09:03 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/24 13:55:11 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_cast(t_pf *a, va_list ap)
{
	if (a->conversion == 's' || a->conversion == 'S')
		a->conversion == 's' ? f_s(a, ap) : f_ss(a, ap);
	if (a->conversion == 'p' || a->conversion == 'd')
		a->conversion == 'p' ? f_p(a, ap) : f_d(a, ap);
	if (a->conversion == 'D' || a->conversion == 'i')
		a->conversion == 'D' ? f_dd(a, ap) : f_i(a, ap);
	if (a->conversion == 'o' || a->conversion == 'O')
		a->conversion == 'o' ? f_o(a, ap) : f_oo(a, ap);
	if (a->conversion == 'u' || a->conversion == 'U')
		a->conversion == 'u' ? f_u(a, ap) : f_uu(a, ap);
	if (a->conversion == 'x' || a->conversion == 'X')
		a->conversion == 'x' ? f_x(a, ap) : f_xx(a, ap);
	if (a->conversion == 'c' || a->conversion == 'C')
		a->conversion == 'c' ? f_c(a, ap) : f_cc(a, ap);
}
