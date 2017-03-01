/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:59:20 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/02/21 18:59:22 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_printf(char *format, ... )
{
    t_pf	*a;
    va_list ap;

    va_start(ap, format);

    a = struct_fill(ap,format,ft_struct());
    return(a->i);
}