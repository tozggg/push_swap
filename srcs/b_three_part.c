/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_three_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:06:51 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/28 20:16:54 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void b_part_123(t_stack *b)
{
	sb(b);
	rb(b);
	sb(b);
	rrb(b);
	sb(b);
}

static void	b_part_132(t_stack *b)
{
	sb(b);
	rb(b);
	sb(b);
	rrb(b);
}

static void	b_part_213(t_stack *b)
{
	rb(b);
	sb(b);
	rrb(b);
	sb(b);
}

static void	b_part_312(t_stack *b)
{
	rb(b);
	sb(b);
	rrb(b);
}

void		work_b_three_part(t_stack *b)
{
	int		d1;
	int		d2;
	int		d3;

	d1 = b->head->data;
	d2 = b->head->next->data;
	d3 = b->head->next->next->data;
	if (d1 <d2 && d2 < d3 && d1 < d3)
		b_part_123(b);
	if (d1 < d2 && d2 > d3 && d1 < d3)
		b_part_132(b);
	if (d1 > d2 && d2 < d3 && d1 < d3)
		b_part_213(b);
	if (d1 < d2 && d2 > d3 && d1 > d3)
		sb(b);
	if (d1 > d2 && d2 < d3 && d1 < d3)
		b_part_312(b);
}
