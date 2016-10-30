/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 23:35:22 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/06 08:44:57 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

static char	*cpy(long stock, char *str)
{
	char	*cpystr;

	if (stock == 1)
	{
		str[0] = '-';
		cpystr = str + 1;
	}
	else
		cpystr = str;
	return (cpystr);
}

static void	incr(unsigned long *i, unsigned long *res)
{
	while (*res != 0)
	{
		*res = *res / 10;
		*i = *i + 1;
	}
}

char		*ft_ultoa(unsigned long n)
{
	unsigned long		i;
	unsigned long		stock;
	unsigned long		res;
	char				*str;
	char				*cpystr;

	i = 0;
	stock = 0;
	res = n;
	if (res == 0)
		i = 1;
	incr(&i, &res);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	cpystr = cpy(stock, str);
	cpystr[i] = '\0';
	while (i--)
	{
		cpystr[i] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
