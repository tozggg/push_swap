/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:40:31 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/28 16:02:16 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	work_b_small_part(int len, t_stack *a, t_stack *b)
{
	if (len == 2)
		sb(b);
	if (len == 3)
		work_b_three_part(b);
	pa_part(len, a, b);
}

void		work_b(int len, t_stack *a, t_stack *b)
{
	t_part *part;

	if (len == 0 || len == 1 || is_sorted(b, len, DESC))
		return (pa_part(len, a, b));
	if (len == 2 || len == 3)
		return (work_b_small_part(len, a, b));
	part = make_part();
	make_pivot(len, a, part);
	while (--len >= 0)
	{
		if (b->head->data < part->one_third_pivot)
			part->rb_count += rb(b);
		else
		{
			part->pa_count += pa(a, b);
			if (a->head->data < part->two_third_pivot)
				part->ra_count += ra(a);
		}
	}
	work_a(part->pa_count - part->ra_count, a, b);
	undo_part(a, b, part);
	work_a(part->ra_count, a, b);
	work_b(part->rb_count, a, b);
	free(part);
}

static void	work_a_small_part(int len , t_stack *a)
{
	if (len == 2)
		sa(a);
	if (len == 3)
		work_a_three_part(a);
}

void		work_a(int len, t_stack *a, t_stack *b)
{
	t_part *part;
	
	if (len == 0 || len == 1 || is_sorted(a, len, ASC))
		return ;
	if (len == 2 || len == 3)
		return (work_a_small_part(len, a));
	part = make_part();
	make_pivot(len, a, part);
	while (--len >= 0)
	{
		if (a->head->data >= part->two_third_pivot)
			part->ra_count += ra(a);
		else
		{
			part->pb_count += pb(a, b);
			if (b->head->data >= part->one_third_pivot)
				part->rb_count += rb(b);
		}
	}
	undo_part(a, b, part);
	work_a(part->ra_count, a, b);
	work_b(part->rb_count, a, b);
	work_b(part->pb_count - part->rb_count, a, b);
	free(part);
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->size == 3)
		work_a_three_stack(a);
	else if (a->size == 5)
		work_a_five_stack(a, b);
	else
		work_a(a->size, a, b);
}
