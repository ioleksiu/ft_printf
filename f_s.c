/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_s.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:19:39 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/21 16:20:06 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void f_s(t_pf *a, va_list ap)
{
    int c_s;
    int c_prec;
    char *s;
    int i ;

    s = va_arg(ap, char *);
    i = ft_strlen(s);
    c_s = 0;
    c_prec = 0;
    if (a->dot)
        c_prec = (a->dot_val > i ? i : a->dot_val);
    else
        c_prec = i;
    c_s = a->width - c_prec;
    if (a->minus == 1)/* left align */
    {
        ft_put_strn(s,c_prec,a);
		/* a->zero == 0 ? */put_nchar(' ',c_s, a) /*: put_nchar('0',c_s, a)*/;
    }
    if (a->minus == 0)/* right align */
    {
        a->zero == 0 ? put_nchar(' ', c_s, a) : put_nchar('0', c_s, a);
        ft_put_strn(s, c_prec, a);
    }
}
