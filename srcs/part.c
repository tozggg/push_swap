/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:09:10 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/28 16:21:43 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		is_sorted(t_stack *stack, int len, int order)
{
	t_node	*node;
	int		prev;
	int		i;

	if (stack == NULL || stack->head == NULL)
		return (0);
	node = stack->head;
	prev = node->data;
	node = node->next;
	i = 1;
	while (i < len)
	{
		if (order == ASC && node->data < prev)
			return (0);
		if (order == DESC && node->data > prev)
			return (0);
		prev = node->data;
		node = node->next;
		++i;
	}
	return (1);
}

t_part	*make_part()
{
	t_part	*part;

	if (!(part = (t_part *)malloc(sizeof(t_part))))
		error_out();
	part->half_pivot = 0;
	part->one_third_pivot = 0;
	part->two_third_pivot = 0;
	part->pa_count = 0;
	part->pb_count = 0;
	part->ra_count = 0;
	part->rb_count = 0;
	return (part);
}

void	undo_part(t_stack *a, t_stack *b, t_part *part)
{
	int ra;
	int rb;

	ra = 0;
	rb = 0;
	while ((ra < part->ra_count) && (rb < part->rb_count))
	{
		rrr(a, b);
		++ra;
		++rb;
	}
	while (ra < part->ra_count)
	{
		rra(a);
		++ra;
	}
	while(rb < part->rb_count)
	{
		rrb(b);
		++rb;
	}
}

void	pa_part(int len, t_stack *a, t_stack *b)
{
	int i;

	i = 0;
	while (i < len)
	{
		pa(a, b);
		++i;
	}
}
