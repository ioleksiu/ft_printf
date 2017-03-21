/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_U.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:27:28 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/21 16:27:56 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void f_U(t_pf *a, va_list ap)
{
    long i = (long)va_arg(ap,void*);
    int n = count_unum(i);
    int c_s = 0;
    int c_z = 0;

    c_s = a->dot_val > n ? a->dot_val : n;
    c_s = a->width - c_s;
    c_z = a->dot_val - n;
    if (a->minus == 1)
    {
        //if (a->plus == 1 && i > 0)
		//  put_nchar('+', 1, a);
        put_nchar('0', c_z, a);
        ft_put_unbr(i, a);
        put_nchar(' ', c_s, a);

    }
    else
    {
        if (i < 0 || a->plus == 1)
            c_s--;
		// if (a->plus == 1 && i > 0)
		// put_nchar('+', 1, a);
        if (a->space == 1 && c_s <= 0 && i > 0) // i > 0 xz
            put_nchar(' ', 1, a);
        if (a->dot == 0)// shob rabotal zero
            a->zero == 0 ? put_nchar(' ', c_s, a) : put_nchar('0', c_s, a);
        else // shob rabotal dot_val
            put_nchar(' ', c_s, a);
        put_nchar('0', c_z, a);
        ft_put_unbr(i, a);
    }
}
