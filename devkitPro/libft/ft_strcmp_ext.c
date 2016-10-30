/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 12:55:16 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/09 14:47:01 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

int	ft_strcmp_ext(char *str, char *ext)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(str) - ft_strlen(ext);
	while (str[i] == ext[j] && str[i] != '\0')
	{
		i++;
		j++;
	}
	if (str[i] == '\0')
		return (0);
	else
		return (1);
}
