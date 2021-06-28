/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_three_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:07:36 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/28 16:15:54 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	a_stack_132(t_stack *a)
{
	sa(a);
	ra(a);
}

static void	a_stack_231(t_stack *a)
{
	rra(a);
}

static void	a_stack_312(t_stack *a)
{
	ra(a);
}

static void	a_stack_321(t_stack *a)
{
	sa(a);
	rra(a);
}

void		work_a_three_stack(t_stack *a)
{
	int		d1;
	int		d2;
	int		d3;

	d1 = a->head->data;
	d2 = a->head->next->data;
	d3 = a->head->next->next->data;
	if (d1 < d2 && d2 < d3 && d1 < d3)
		return ;
	if (d1 < d2 && d2 > d3 && d1 < d3)
		a_stack_132(a);
	if (d1 > d2 && d2 < d3 && d1 < d3)
		sa(a);
	if (d1 < d2 && d2 > d3 && d1 > d3)
		a_stack_231(a);
	if (d1 > d2 && d2 < d3 && d1 > d3)
		a_stack_312(a);
	if (d1 > d2 && d2 > d3 && d1 > d3)
		a_stack_321(a);
}
