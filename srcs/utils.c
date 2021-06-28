/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:00:19 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/28 20:16:54 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_out(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack *stack)
{
	t_node *node;
	t_node *tmp;

	if (stack == NULL)
		return ;
	node = stack->head;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(stack);
}

void	free_and_error(t_stack *stack, char **split)
{
	free_split(split);
	free_stack(stack);
	error_out();
}


void	init_node(t_node *node)
{
	node->data = 0;
	node->next = NULL;
	node->prev = NULL;
}

void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->size = 0;
}
