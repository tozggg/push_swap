/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:49:12 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/28 17:19:29 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*top;
	t_node	*second;
	t_node	*third;

	if (stack->size == 0 || stack->size == 1)
		return ;
	top = stack->head;
	second = top->next;
	third = second->next;
	top->next = second->next;
	top->prev = second;
	second->next = top;
	second->prev = NULL;
	if (third)
		third->prev = top;
	stack->head = second;
}

void		sa(t_stack *a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void		sb(t_stack *b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void		ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}
