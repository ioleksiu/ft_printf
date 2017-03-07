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

void f_d(t_pf *a, va_list ap);

void f_S(t_pf *a, va_list ap)
{

}

void f_p(t_pf *a, va_list ap)
{

}

void f_D(t_pf *a, va_list ap)
{

}

void f_i(t_pf *a, va_list ap)
{
    f_d(a, ap);
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
    f_c(a, ap);
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

uintmax_t cast_du(t_pf *a, va_list ap)
{
    uintmax_t i;

    i = va_arg(ap, uintmax_t);
    if(a->size == 3)
        return  (unsigned long)i;
    if(a->size == 2)
        return  (unsigned short)i;
    if(a->size == 1)
        return  (unsigned char)i;
    if(a->size == 4)
        return  (unsigned long long)i;
    return (unsigned int)i;
}

int count_num(int a)
{
    int i;

    i = 0;
    if (a < 0)
    {
        a *= -1;
        i++;
    }
    while (a > 0)
    {
        a /= 10;
        i++;
    }
    return (i);
}

void put_nchar(char c, int i)
{
    while (i > 0)
    {
        write(1, &c, 1);
        i--;
    }
}
void with_m()
{

}

void without_m()
{

}
void f_d(t_pf *a, va_list ap)
{
    int i = cast_d(a,ap);
    int n = count_num(i);
    int c_s = 0;
    int c_z = 0;

    c_s = a->dot_val > n ? a->dot_val : n;
    c_s = a->width - c_s;
    c_z = a->dot_val - n;
    if (a->minus == 1)
    {
        if (a->plus == 1 && i > 0)
            write(1, "+", 1);
        put_nchar('0', c_z);
        ft_putnbr(i, a);
        put_nchar(' ', c_s);
    }
    else
    {
        if (a->space == 1)
            write(1, " ", 1);
        a->zero == 0 ? put_nchar(' ', c_s) : put_nchar('0', c_s);
        if (a->plus == 1 && i > 0)
            write(1, "+", 1);
        put_nchar('0', c_z);
        ft_putnbr(i, a);
        //put_nchar(' ', c_s);

        /*
        if (a->plus == 1 && i > 0)
            write(1, "+", 1);
        //c_s = a->dot_val > n ? a->dot_val : n;
        //c_s = a->width - c_s;
        if (c_s > 0)
            a->space = 0;
        //if (a->space = 1)
        //  write(1,' ', 1);
        if (a->minus == 1)
            put_nchar(' ', c_s);
        //zero
       // c_z = a->dot_val - n;
        put_nchar('0', c_z);
        if (a->minus == 0)
            put_nchar(' ', c_s);
        ft_putnbr(i, a);
         */
    }


    /*n = a->width - n;
    if(a->plus == 1 && i > 0)
    {
        write(1, "+", 1);
        n--;
    }
    c = ' ';
    if (a->zero == 1 )
        c = '0';
    if (a->zero == 1 && a->dot == 1)
    {
        count = a->dot_val - n;
        while(count > 0)
        {
            write(1,"0", 1);
            count--;
            n--;
        }
    }
    while (n > 0 && (i > 0 && a->minus == 0) && !(a->space == 1 && i < 0))
    {
        write(1, &c, 1);
        n--;
    }
    if (a->space == 1 && a->width == 0 && a-> minus == 0 && !(a->space == 1 && i < 0))
        write(1," ", 1);
    ft_putnbr(i,a);
    while (n > 0 && a->minus == 1)
    {
        write(1, &c, 1);
        n--;
    }
     */
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
