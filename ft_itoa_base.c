/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:54:52 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/21 16:55:56 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f(uintmax_t value, uintmax_t base, char *str, int *i)
{
    char    *tmp;

    tmp = "0123456789abcdef";
    if (value >= base)
        f(value / base, base, str, i);
    str[(*i)++] = tmp[(value % base)];
}

char	*ft_itoa_base(uintmax_t value, uintmax_t base)
{
    int     i;
    char    *str;
    char    *res;

    i = 0;
    if (base < 2 || base > 16 || !(str = (char*)malloc(32)))
        return (0);
    f(value, base, str, &i);
    str[i] = '\0';
    res = str;
    return (res);
}
