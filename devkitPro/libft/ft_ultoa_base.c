/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 05:55:47 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/06 08:59:07 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

static int	ft_len(unsigned long nb, int base)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		len++;
	}
	return (len);
}

static char	ft_char(unsigned long nb)
{
	if (nb < 10)
		return (nb + '0');
	return (nb + 'a' - 10);
}

char		*ft_ultoa_base(unsigned long value, int base)
{
	unsigned long	nb;
	char			*str;
	int				len;

	nb = value;
	len = ft_len(nb, base);
	str = (char*)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (--len >= 0)
	{
		str[len] = ft_char(nb % base);
		nb /= base;
	}
	return (str);
}
