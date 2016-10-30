/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloci_2d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 15:34:57 by rabougue          #+#    #+#             */
/*   Updated: 2016/09/15 17:17:26 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

char	**ft_memalloc_2d(size_t size_1, size_t size_2)
{
	size_t	i;
	size_t	j;
	char	**str;

	i = 0;
	j = 0;
	str = NULL;
	str = (char **)malloc(sizeof(char *) * size_1);
	if (str == NULL)
		return (NULL);
	while (i < size_1)
	{
		while (j < size_2)
		{
			str[j] = ft_memalloc(size_2 + 1);
			++j;
		}
		++i;
	}
	return (str);
}
