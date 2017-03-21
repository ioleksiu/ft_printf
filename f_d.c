/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_d.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:10:18 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/21 16:40:04 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void f_i(t_pf *a, va_list ap)
{
    f_d(a, ap);
}

void f_d(t_pf *a, va_list ap)
{
    intmax_t i = cast_d(a,ap);
    int n = count_num(i);
    int c_s = 0;
    int c_pr = 0;

//    if (i > 0)
//        c_pr = a->dot_val > n ? (a->dot_val - n) : 0;
//    else
//        c_pr = a->dot_val > n - 1 ? (a->dot_val + 1 - n) : 0;
    c_pr = a->dot_val;
    c_s = a->width;
    if (c_s <= c_pr)
        c_s = 0;
    if ((a->plus == 1 || i < 0) && c_pr > n + 1)
        c_s--;
//    if (c_pr > 0 && c_pr < a->width && c_pr > n)
//        c_s = c_s - c_pr;
//    if ((a->minus == 1 && c_pr == n + 1 && (a->plus == 1 || i < 0)) ||
//            (a->minus == 1 && (a->plus == 1 || i < 0) && c_pr < 0))
//        c_s++;
    if (c_pr > 0 && c_pr > n && c_s > c_pr)
        c_s -= c_pr - n;
    if (a->minus == 1)// left align
    {
        if (a->plus == 1 && i >= 0)
        {
            put_nchar('+', 1, a);
            c_s--;
        } else if (i < 0)
            c_s--;
        if (i < 0)
            put_nchar('-', 1, a);
        put_nchar('0', c_pr - n, a);
        if((a->dot_val != -1 || (a->dot_val == -1 && a->hash == 1)) || (a->width == 0 && i > 0)) /**/
            ft_putnbr(i, a);
        if (c_pr > 0 && a->minus == 0)
            put_nchar(' ', c_s, a);
        else
            put_nchar(' ', c_s - n, a);
    }
    else// right align
    {
        if(a->plus == 1 || i < 0)
            c_s--;
        if ( i < 0 && a->width <= n + 1 + c_pr) // ADDED
            c_s = 0;
        if (a->space == 1 && c_s <= 0 && i > 0 && a->plus == 0) // i > 0 xz
            put_nchar(' ', 1, a);
		/*
        else if (a->space == 1 && i < 0) //for ("\n{% 03d}\n", 0);
        {
            put_nchar(' ', 1, a);
            if (c_pr > 0)
                c_pr--;
            else if (c_s > 0)
                c_s--;
        }
		*/
        if (a->dot_val > n)
            a->zero = 0;
        if (a->zero == 0 || a->hash == 1 ||((a->width > a->dot_val) && a->dot_val > 0) || c_pr != 0)
        {
            if (c_pr != 0 && c_pr != -1 && i != 0 && (a->plus == 1 || i < 0) && c_s <= c_pr + 1)
                put_nchar(' ', c_s, a);
            else
                put_nchar(' ', c_s - n, a);
            c_s = 0;
        }
        if (i < 0 && a->zero == 1)
			put_nchar('-', 1, a);
        if (a->plus == 1 && i >= 0)
            put_nchar('+', 1, a);
        if (i < 0 && i < 0 && a->zero == 0)
            put_nchar('-', 1, a);
        if (a->zero == 1 && a->minus != 1/*&& a->zero != 1*/)
            put_nchar('0',c_s - n,a);
        put_nchar('0', c_pr - n, a);
        if((a->dot_val != -1 || (a->dot_val == -1 && a->hash == 1)) || (a->width == 0 && i > 0))
            ft_putnbr(i, a);
        else if (a->width > 0)//added
            put_nchar(' ', n, a);//added
    }
}
