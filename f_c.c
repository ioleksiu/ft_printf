/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_c.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:21:59 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/21 16:22:44 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void f_C(t_pf *a, va_list ap)
{
    f_c(a, ap);
}

void f_c(t_pf *a, va_list ap)
{
    int l;
    char c;
    char sp;

    l = a->width;
    sp = (char) ((a->zero == 1 && a->minus != 1) ? '0' : ' ');
    if (a->minus == 0)
        while (l-- > 1)
            write(1, &sp, 1);
    c = va_arg(ap, int);
    write(1, &c, 1);
    if (a->minus != 0)
        while (l-- > 1)
            write(1, &sp, 1);
    a->width > 0 ?  (a->i = a->i + a->width) : (a->i = a->i + 1) ;
}
