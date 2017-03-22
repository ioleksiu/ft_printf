/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_X.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:25:52 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/21 16:26:18 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void f_X_nmin(t_pf *a, int c_s, intmax_t i, int n)
{

    if (a->hash && i > 0)
        c_s -=2;
    if (a->zero == 0)
        put_nchar(' ', c_s, a);
    if (a->hash && i > 0)
    {
        write(1, "0X", 2);
        a->i += 2;
    }
    if (i == 0 && a->dot_val != -1 )
        put_nchar('0', 1, a);
    if (a->zero == 1 && a->dot_val != -1)
        put_nchar('0', c_s, a);
    else if (a->zero == 1 && a->dot_val == -1)
        put_nchar(' ', c_s, a);
    if (a->dot_val != -1 && i != 0)
        ft_putstr(ft_itoa_base_1(i, 16), a);
    else if (a->width > 0)
        put_nchar(' ', n, a);
}

void f_X_min(t_pf *a, int c_s, intmax_t i, int n)
{
    if (a->hash)
    {
        write(1, "0X", 2);
        a->i += 2;
        c_s -= 2;
    }
    if (i == 0 && a->dot_val != -1)
        put_nchar('0', 1, a);
    if (a->dot_val != -1 && i != 0)
        ft_putstr(ft_itoa_base_1(i, 16), a);
    put_nchar(' ', c_s, a);
}

void f_X(t_pf *a, va_list ap)
{
    int c_s = 0;
    int c_z = 0;
    int n ;

    intmax_t i = cast_du(a,ap);
    n = count_num(i);
    c_s = a->dot_val > n ? a->dot_val : n;
    c_s = a->width - c_s;
    c_z = a->dot_val - n;
    (a->minus == 0) ? f_X_nmin(a, c_s, i, n) : f_X_min(a, c_s, i, n);
}
