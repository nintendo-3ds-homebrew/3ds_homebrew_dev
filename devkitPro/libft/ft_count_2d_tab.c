/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_2d_tab                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:57:59 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/06 22:08:32 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

void	ft_count_2d_tab(char **tab)
{
	int		k;
	int		j;
	size_t	len;

	k = 0;
	j = 0;
	while (tab[k])
	{
		j++;
		if (tab[k][j])
		{
			len = ft_strlen(tab[k]);
			k++;
			j = 0;
			ft_putnbr(len);
			ft_putchar('\n');
		}
	}
}
