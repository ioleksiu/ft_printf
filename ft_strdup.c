/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:06:56 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/03/24 20:39:18 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1) + 1;
	copy = (char*)malloc(len);
	if (!copy)
		return (0);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int				pr_f(t_pf *a, int c_pr, int c_s, intmax_t i)
{
	if (a->space == 1 && a->zero == 1 && i == 0)
	{
		(a->plus) ? put_nchar('+', 1, a) : put_nchar(' ', 1, a);
		put_nchar('0', a->width - 1, a);
	}
	else
		return (0);
	return (1);
}
