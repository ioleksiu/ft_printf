/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 17:48:04 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/02/19 17:48:05 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void f_S(t_pf *a, va_list ap)
{

}

void f_p(t_pf *a, va_list ap)
{

}
/*
void f_d(t_pf *a, va_list ap)
{
    int i = va_arg(ap, int);
    ft_putnbr(i);
}
*/
void f_D(t_pf *a, va_list ap)
{

}

void f_i(t_pf *a, va_list ap)
{
    int i = cast_d(a,ap);
    ft_putnbr(i);
}

void f_o(t_pf *a, va_list ap)
{

}

void f_O(t_pf *a, va_list ap)
{

}

void f_u(t_pf *a, va_list ap)
{

}

void f_U(t_pf *a, va_list ap)
{

}

void f_x(t_pf *a, va_list ap)
{

}

void f_X(t_pf *a, va_list ap)
{

}

void f_proc(char c, t_pf *a)
{
    int l;
    char sp;

    l = a->width;
    sp = (char) ((a->zero == 1 && a->minus != 1) ? '0' : ' ');
    if (a->minus == 0)
        while (l-- > 1)
        {
            write(1, &sp, 1);
           // a->i++;//
        }
    write(1, &c, 1);
    if (a->minus != 0)
        while (l-- > 1)
        {
            write(1, &sp, 1);
           // a->i++;
        }
    a->width > 0 ?  (a->i = a->i + a->width) : (a->i = a->i + 1) ;
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
        {
            write(1, &sp, 1);
         //   a->i++;
        }
    c = va_arg(ap, int);
    write(1, &c, 1);
    if (a->minus != 0)
        while (l-- > 1)
        {
            write(1, &sp, 1);
          //  a->i++;
        }
    a->width > 0 ?  (a->i = a->i + a->width) : (a->i = a->i + 1) ;
}

/* ========================================================= */

void ft_put_strn(char *s, int i, t_pf *a)
{
    while (i--)
    {
        write(1, s, 1);
        a->i++;
        s++;
    }
}
void f_s(t_pf *a, va_list ap)
{
    int i;
    char *s;
    char sp;

    s = va_arg(ap, char *);
    if (a->width == 0 && a->dot == 0)
    {
        a->width = ft_strlen(s);
        a->dot_val = a->width;
        a->dot = 1;
    }
    if (a->dot_val >= ft_strlen(s))
        a->dot_val = ft_strlen(s);
    if (a->width <= a->dot_val)
        a->width = ft_strlen(s);
    i = a->width - a->dot_val;
    if (a->width != 0 && a->width > ft_strlen(s)
        && !(a->dot == 1 && a->dot_val == 0))
    {
        a->dot_val = ft_strlen(s);
        i = a->width - ft_strlen(s);
    }
    sp = ' ';
    if (a->zero == 1 && a->minus != 1)
        sp = '0';
    if (a->minus == 0)
        while (i-- >= 1)
        {
            write(1, &sp, 1);
            a->i++;
        }
    ft_put_strn(s, a->dot_val,a);
    if (a->minus != 0)
        while (i-- >= 1)
        {
            write(1, &sp, 1);
            a->i++;
        }
   }

void f_C(t_pf *a, va_list ap)
{

}

intmax_t cast_d(t_pf *a, va_list ap)
{
    intmax_t i;

    i = va_arg(ap, intmax_t);
    if(a->size == 3)
        return  (long)i;
    if(a->size == 2)
        return  (short)i;
    if(a->size == 1)
        return  (signed char)i;
    if(a->size == 4)
        return  (long long)i;
    return (int)i;
}

void f_d(t_pf *a, va_list ap)
{
    int i = cast_d(a,ap);
    ft_putnbr(i);
}
void    pf_cast(t_pf *a, va_list ap)
{
    if (a->conversion == 's' || a->conversion == 'S')
        a->conversion == 's' ? f_s(a, ap) : f_S(a, ap);
    if (a->conversion == 'p' || a->conversion == 'd' )
        a->conversion == 'p' ? f_p(a, ap) : f_d(a, ap);
    if (a->conversion == 'D' || a->conversion == 'i' )
        a->conversion == 'D' ? f_D(a, ap) : f_i(a, ap);
    if (a->conversion == 'o' || a->conversion == 'O' )
        a->conversion == 'o' ? f_o(a, ap) : f_O(a, ap);
    if (a->conversion == 'u' || a->conversion == 'U' )
        a->conversion == 'u' ? f_u(a, ap) : f_U(a, ap);
    if (a->conversion == 'x' || a->conversion == 'X' )
        a->conversion == 'x' ? f_x(a, ap) : f_X(a, ap);
    if (a->conversion == 'c' || a->conversion == 'C' )
        a->conversion == 'c' ? f_c(a, ap) : f_C(a, ap);
 }
