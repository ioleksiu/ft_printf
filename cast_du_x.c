/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_du_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:16:38 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/21 16:17:03 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t cast_du_x(t_pf *a, va_list ap)
{
    //void * i;

    //i = va_arg(ap, void *);
    if(a->size == 3)
        return  va_arg(ap,unsigned long);
    if(a->size == 2)
        return   (unsigned short)va_arg(ap,unsigned int);
    if(a->size == 1)
        return  (unsigned char)va_arg(ap,unsigned int);
    if(a->size == 4)
        return  va_arg(ap,unsigned long long) ;
    if(a->size == 6)/* 5*/
        return  va_arg(ap,uintmax_t);
    if(a->size == 5)/*6*/
        return va_arg(ap,size_t);// changed
    return  va_arg(ap, unsigned int);
}
