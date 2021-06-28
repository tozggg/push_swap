/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_three_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:06:09 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/28 20:16:54 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_part_132(t_stack *a)
{
	ra(a);
	sa(a);
	rra(a);
}

static void	a_part_231(t_stack *a)
{
	ra(a);
	sa(a);
	rra(a);
	sa(a);
}

static void	a_part_312(t_stack *a)
{
	sa(a);
	ra(a);
	sa(a);
	rra(a);
}

static void	a_part_321(t_stack *a)
{
	sa(a);
	ra(a);
	sa(a);
	rra(a);
	sa(a);
}

void		work_a_three_part(t_stack *a)
{
	int		d1;
	int		d2;
	int		d3;

	d1 = a->head->data;
	d2 = a->head->next->data;
	d3 = a->head->next->next->data;
	if (d1 < d2 && d2 > d3 && d1 < d3)
		a_part_132(a);
	if (d1 > d2 && d2 < d3 && d1 < d3)
		sa(a);
	if (d1 < d2 && d2 > d3 && d1 > d3)
		a_part_231(a);
	if (d1 > d2 && d2 < d3 && d1 < d3)
		a_part_312(a);
	if (d1 > d2 && d2 > d3 && d1 > d3)
		a_part_321(a);
}
