/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 23:35:22 by rabougue          #+#    #+#             */
/*   Updated: 2016/07/08 01:29:51 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

static long	checksign(long n)
{
	if (n < 0)
		return (1);
	return (0);
}

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

static void	incr(long *i, long *res)
{
	while (*res != 0)
	{
		*res = *res / 10;
		*i = *i + 1;
	}
}

char		*ft_ltoa(long n)
{
	long		i;
	long		stock;
	long		res;
	char		*str;
	char		*cpystr;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	stock = checksign(n);
	stock == 1 ? n = -n : (void)n;
	res = n;
	if (res == 0)
		i = 1;
	incr(&i, &res);
	if (!(str = (char *)malloc(sizeof(char) * (i + stock + 1))))
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
