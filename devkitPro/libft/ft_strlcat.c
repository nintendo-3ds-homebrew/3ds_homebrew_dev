/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:31:57 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/04 09:17:41 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		j;
	size_t	len_d;
	size_t	len_s;
	int		stop;

	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	stop = size - len_d - 1;
	i = len_d;
	j = 0;
	while (src[j] && j < stop)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	if (size <= len_d)
		return (len_s + size);
	return (len_s + len_d);
}
