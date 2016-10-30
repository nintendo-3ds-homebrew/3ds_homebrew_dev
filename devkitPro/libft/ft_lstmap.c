/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 10:57:38 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/04 09:20:53 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*compt;
	t_list	*stock;

	new = NULL;
	if (lst != NULL && f != NULL)
	{
		new = f(lst);
		compt = new;
		while (lst->next)
		{
			lst = lst->next;
			stock = f(lst);
			if (stock == NULL)
				return (0);
			compt->next = stock;
			compt = compt->next;
		}
	}
	return (new);
}
