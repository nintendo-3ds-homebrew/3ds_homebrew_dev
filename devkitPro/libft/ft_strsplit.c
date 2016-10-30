/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:39:24 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/06 22:09:36 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

static void	ft_split_count(char const *s, char c, int *j)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			*j = *j + 1;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
}

static void	ft_split_tab(char const *s, char **str, char c, int *j)
{
	int len;
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		len = 0;
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i + len] != c && s[i + len] != '\0')
				len++;
			str[*j] = ft_strsub(s, i, len);
			*j = *j + 1;
		}
		i = i + len;
	}
	str[*j] = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		j;

	j = 1;
	if (s == NULL)
		return (NULL);
	ft_split_count(s, c, &j);
	str = (char **)malloc(sizeof(char *) * j);
	if (str != NULL)
	{
		j = 0;
		ft_split_tab(s, str, c, &j);
	}
	return (str);
}
