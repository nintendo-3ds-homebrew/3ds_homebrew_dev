/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 19:50:53 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/06 22:09:00 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	a;

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
		i++;
	i--;
	while (j < i)
	{
		a = str[i];
		str[i] = str[j];
		str[j] = a;
		i--;
		j++;
	}
	return (str);
}
