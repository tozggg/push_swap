/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_five_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:08:05 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/28 16:02:16 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	work_a_five_stack(t_stack *a, t_stack *b)
{
	t_part *part;
	int		mid;
	int		i;

	if (is_sorted(a, 5, ASC))
		return ;
	part = make_part();
	make_pivot(5, a, part);
	mid = part->half_pivot;
	i = 0;
	while (i < 5)
	{
		if (a->head->data < mid)
			pb(a, b);
		else
			ra(a);
		++i;
	}
	work_a_three_stack(a);
	if (!is_sorted(b, 2, DESC))
		sb(b);
	pa_part(2, a, b);
	free(part);
}
