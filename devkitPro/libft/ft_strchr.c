/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:56:26 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/04 09:16:24 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s1;

	i = 0;
	s1 = (char*)s;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (s1 + i);
		i++;
	}
	if (s[i] == c)
		return (s1 + i);
	return (NULL);
}
