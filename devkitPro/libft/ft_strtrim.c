/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:34:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/04 09:19:49 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

static void	skip_blank(const char *s, int *i, int *len)
{
	while (s[*i] != '\0')
	{
		if (s[*i] != ' ' && s[*i] != '\n' && s[*i] != '\t')
		{
			*i += 1;
			*len = *i;
		}
		else
			*i += 1;
	}
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		start;
	int		len;
	int		i;

	if (s == NULL)
		return (0);
	start = 0;
	len = 0;
	i = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	skip_blank(s, &i, &len);
	if (i == 0 || ft_strsub(s, start, len - start) == NULL)
	{
		str = ft_strdup("");
		return (str);
	}
	return (ft_strsub(s, start, len - start));
}
