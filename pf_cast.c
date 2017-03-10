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
void put_nchar(char c, int i, t_pf *a);
void f_d(t_pf *a, va_list ap);
uintmax_t cast_du(t_pf *a, va_list ap);
void		f(uintmax_t value, uintmax_t base, char *str, int *i);

void	ft_putstr(char const *s, t_pf *a)
{
    if (s)
        while (*s)
        {
            write(1, s, 1);
            s++;
            a->i++;
        }
}

//
void		f(uintmax_t value, uintmax_t base, char *str, int *i)
{
    char	*tmp;

    tmp = "0123456789abcdef";
    if (value >= base)
        f(value / base, base, str, i);
    str[(*i)++] = tmp[(value % base) < 0 ? -(value % base) : (value % base)];
}

char		*ft_itoa_base(uintmax_t value, uintmax_t base)
{
    int		i;
    char	*str;

    i = 0;
    if (base < 2 || base > 16 || !(str = (char*)malloc(32)))
        return (0);
    if (base == 10 && value < 0)
        str[i++] = '-';
    f(value, base, str, &i);
    str[i] = '\0';
    return (str);
}
//for X
void		f1(uintmax_t value, uintmax_t base, char *str, int *i)
{
    char	*tmp;

    tmp = "0123456789ABCDEF";
    if (value >= base)
        f1(value / base, base, str, i);
    str[(*i)++] = tmp[(value % base) < 0 ? -(value % base) : (value % base)];
}

char		*ft_itoa_base_1(uintmax_t value, uintmax_t base)
{
    int		i;
    char	*str;

    i = 0;
    if (base < 2 || base > 16 || !(str = (char*)malloc(32)))
        return (0);
    if (base == 10 && value < 0)
        str[i++] = '-';
    f1(value, base, str, &i);
    str[i] = '\0';
    return (str);
}
////
void	ft_put_unbr(uintmax_t n, t_pf *a)
{
    char			p;
    uintmax_t	z;

    z = n;
    if (z >= 10)
    {
        ft_putnbr(z / 10, a);
        ft_putnbr(z % 10, a);
    }
    else
    {
        p = z + 48;
        write(1, &p, 1);
        a->i++;
    }
}
int count_unum(uintmax_t a)
{
    int i;

    i = 0;
    while (a > 0)
    {
        a /= 10;
        i++;
    }
    return (i);
}

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
    uintmax_t i = cast_du(a,ap);
    if(a->hash)
    {
        write(1,"0", 1);
        a->i++;
    }
    ft_putstr(ft_itoa_base(i,8),a);
}

void f_O(t_pf *a, va_list ap)
{

}

void f_u(t_pf *a, va_list ap)
{
    //ft_put_unbr(va_arg(ap, uintmax_t), a);


    //  write(1, "hello", 5);
   uintmax_t i = cast_du(a,ap);
    //int n = count_unum(i);
    //int c_s = 0;
    //int c_z = 0;

   // c_s = a->dot_val > n ? a->dot_val : n;
    //c_s = a->width - c_s;
    //c_z = a->dot_val - n;
   // if (a->minus == 1)
   // {
      //  if (a->plus == 1 && i > 0)
     //       put_nchar('+', 1, a);
      //  put_nchar('0', c_z, a);
     ft_put_unbr(i, a);
     //   put_nchar(' ', c_s, a);
    /*
    }
    else
    {
        if (i < 0 || a->plus == 1)
            c_s--;
        if(a->plus == 1 && i > 0)
            put_nchar('+', 1, a);
        if (a->space == 1 && c_s <= 0 && i > 0) // i > 0 xz
            put_nchar(' ', 1, a);
        if (a->dot == 0)// shob rabotal zero
            a->zero == 0 ? put_nchar(' ', c_s, a) : put_nchar('0', c_s, a);
        else // shob rabotal dot_val
            put_nchar(' ', c_s, a);
        put_nchar('0', c_z, a);
        ft_put_unbr(i, a);
    }
     */
}

void f_U(t_pf *a, va_list ap)
{

}

void f_x(t_pf *a, va_list ap)
{
    uintmax_t i = cast_du(a,ap);
    if (a->hash)
    {
        write(1, "0x", 2);
        a->i+=2;
    }
    ft_putstr(ft_itoa_base(i,16),a);
}

void f_X(t_pf *a, va_list ap)
{
    uintmax_t i = cast_du(a,ap);
    if (a->hash)
    {
        write(1, "0X", 2);
        a->i+=2;
    }
    ft_putstr(ft_itoa_base_1(i,16),a);
}

void f_proc(char c, t_pf *a)
{
    int l;
    char sp;

    l = a->width;
    sp = (char) ((a->zero == 1 && a->minus != 1) ? '0' : ' ');
    if (a->minus == 0)
        while (l-- > 1)
            write(1, &sp, 1);
    write(1, &c, 1);
    if (a->minus != 0)
        while (l-- > 1)
            write(1, &sp, 1);
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
            write(1, &sp, 1);
    c = va_arg(ap, int);
    write(1, &c, 1);
    if (a->minus != 0)
        while (l-- > 1)
            write(1, &sp, 1);
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
    int c_s;
    int c_prec;
    char *s;

    s = va_arg(ap, char *);
    c_s = 0;
    c_prec = 0;
    if (a->dot)
        c_prec = (a->dot_val > ft_strlen(s) ? ft_strlen(s) : a->dot_val);
    else
        c_prec = ft_strlen(s);
    c_s = a->width - c_prec;
    if (a->minus == 1)/* left align */
    {
        ft_put_strn(s,c_prec,a);
        a->zero == 0 ? put_nchar(' ',c_s, a) : put_nchar('0',c_s, a);
    }
    if (a->minus == 0)/* right align */
    {
        a->zero == 0 ? put_nchar(' ', c_s, a) : put_nchar('0', c_s, a);
        ft_put_strn(s, c_prec, a);
    }
}

void f_C(t_pf *a, va_list ap)
{
    f_c(a, ap);
}

intmax_t cast_d(t_pf *a, va_list ap)
{
    if(a->size == 3)
        return  va_arg(ap, long);
    if(a->size == 2)
        return  va_arg(ap, short);
    if(a->size == 1)
        return  va_arg(ap, signed char);
    if(a->size == 4)
        return  va_arg(ap, long long);
    return va_arg(ap, int);
}

//{"none"0, "hh"1, "h"2, "l"3, "ll"4, "j"5, "z"6};
uintmax_t cast_du(t_pf *a, va_list ap)
{
    void * i;

    i = va_arg(ap, void *);
    if(a->size == 3)
        return  (unsigned long) i;
    if(a->size == 2)
        return  (unsigned short) i;
    if(a->size == 1)
        return  (unsigned char) i;
    if(a->size == 4)
        return  (unsigned long long) i;
    if(a->size == 5)
        return  (uintmax_t) i;
    return (size_t) i;
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

void put_nchar(char c, int i, t_pf *a)
{
    while (i > 0)
    {
        write(1, &c, 1);
        i--;
        a->i++;
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
    intmax_t i = cast_d(a,ap);
    int n = count_num(i);
    int c_s = 0;
    int c_z = 0;

    c_s = a->dot_val > n ? a->dot_val : n;
    c_s = a->width - c_s;
    c_z = a->dot_val - n;
    if (a->minus == 1)/* left align */
    {
        if (a->plus == 1 && i > 0)
            put_nchar('+', 1, a);
        put_nchar('0', c_z, a);
        ft_putnbr(i, a);
        put_nchar(' ', c_s, a);
    }
    else/* right align */
    {
        if (i < 0 || a->plus == 1)
            c_s--;
        if(a->plus == 1 && i > 0)
            put_nchar('+', 1, a);
        if (a->space == 1 && c_s <= 0 && i > 0) // i > 0 xz
            put_nchar(' ', 1, a);
        if (a->dot == 0)// shob rabotal zero
            a->zero == 0 ? put_nchar(' ', c_s, a) : put_nchar('0', c_s, a);
        else // shob rabotal dot_val
            put_nchar(' ', c_s, a);
        put_nchar('0', c_z, a);
        ft_putnbr(i, a);
    }
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
