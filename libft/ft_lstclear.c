/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:19:27 by taejkim           #+#    #+#             */
/*   Updated: 2021/01/16 16:07:54 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	if (lst == NULL || del == NULL)
		return ;
	tmp = *lst;
	*lst = NULL;
	while (tmp)
	{
		del(tmp->content);
		free(tmp);
		tmp = tmp->next;
	}
}
