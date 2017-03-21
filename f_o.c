/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_o.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:36:22 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/21 16:39:35 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void f_o(t_pf *a, va_list ap)
{
    int c_s = 0;
    int c_pr = 0;
    int len = 0;
    char *s;
    uintmax_t i;

    i = cast_du(a,ap);
    s = ft_itoa_base(i, 8);
    len = count_unum(i);
    c_pr = (a->dot_val - len) > 0 ?  (a->dot_val - len) : 0;
    c_s = a->width - len - c_pr /* - 2 */;
	// if (a->width > a->dot_val && len != a->dot_val && a->dot_val != -1) commented
	//   c_s--;
    if (a->minus == 0)
    {
        if (a->hash && i > 0)
            c_s -=1;
        if (a->zero == 0)
            put_nchar(' ', c_s, a);
        if (a->hash && i > 0)
        {
            write(1, "0", 1);
            a->i += 1;
        }
        if (a->zero == 1 && a->dot_val != -1)
            put_nchar('0', c_s, a);
        else if (a->zero == 1 && a->dot_val == -1)
            put_nchar(' ', c_s, a);
        put_nchar('0', c_pr, a);
        if((a->dot_val != -1 || (a->dot_val == -1 && a->hash == 1)) || (a->width == 0 && i > 0))
            ft_putstr(s, a);
        else if (a->width > 0)//added
            put_nchar(' ', len, a);//added
    }
    else
    {
        if (a->hash && i > 0)
        {
            write(1, "0", 1);
            a->i += 1;
            c_pr -= 2;
            if (c_pr == -2)
                c_s--;
        }
        put_nchar('0', c_pr, a);
        if(((a->dot_val != -1 && i > 0)|| (a->dot_val == -1 && a->hash == 1)) || (a->width == 0 && i > 0))
            ft_putstr(s, a);
        put_nchar(' ', c_s, a);
    }
}
