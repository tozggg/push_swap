/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:57:35 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/28 17:18:54 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*top;
	t_node	*top_next;
	t_node	*bottom;

	if (stack->size == 0 || stack->size == 1)
		return ;
	top = stack->head;
	top_next = top->next;
	bottom = top;
	while (bottom->next)
		bottom = bottom->next;
	top->prev = bottom;
	bottom->next = top;
	top_next->prev = NULL;
	top->next = NULL;
	stack->head = top_next;
}

int			ra(t_stack *a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
	return (1);
}

int			rb(t_stack *b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
	return (1);
}

void		rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
