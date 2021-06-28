/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rrotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:58:22 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/28 20:16:54 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*top;
	t_node	*bottom;
	t_node	*bottom_prev;

	if (stack->size == 0 || stack->size == 1)
		return ;
	top = stack->head;
	bottom = top;
	while (bottom->next)
		bottom = bottom->next;
	bottom_prev = bottom->prev;
	top->prev = bottom;
	bottom->next = top;
	bottom->prev = NULL;
	bottom_prev->next = NULL;
	stack->head = bottom;
}

void		rra(t_stack *a)
{
	reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void		rrb(t_stack *b)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void		rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
