/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:51:27 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/28 20:16:54 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_stack *in, t_stack *out)
{
	t_node	*node;
	
	if (out->size == 0)
		return (0);
	node = out->head;
	out->head = node->next;
	if (out->head)
		out->head->prev = NULL;
	node->next = in->head;
	if (in->head)
		in->head->prev = node;
	in->head = node;
	return (1);
}

int			pa(t_stack *a, t_stack *b)
{
	int		res;

	res = push(a, b);
	++(a->size);
	--(b->size);
	ft_putstr_fd("pa\n", 1);
	return (res);
}

int			pb(t_stack *a, t_stack *b)
{
	int		res;

	res = push(b, a);
	++(b->size);
	--(a->size);
	ft_putstr_fd("pb\n", 1);
	return (res);
}
