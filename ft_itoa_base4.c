/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:51:45 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/21 16:53:46 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f4(uintmax_t value, uintmax_t base, char *str, int *i)
{
    char    *tmp;

    tmp = "0123456789abcdef";
    if (value >= base || -value <= -base)
        f4(value / base, base, str, i);
    str[(*i)++] = tmp[(value % base)];
}

char	*ft_itoa_base4(uintmax_t value, uintmax_t base)
{
    int     i;
    char    *str;
    char    *res;

    i = 0;
    if (base < 2 || base > 16 || !(str = (char*)malloc(32)))
        return (0);
    //if (base == 10 && value < 0)
	// str[i++] = '-';
    f4(value, base, str, &i);
    str[i] = '\0';
    res = str;
    //free(str);
    return (res);
}
