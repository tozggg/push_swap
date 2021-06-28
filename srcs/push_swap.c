/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:10:52 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/28 20:26:28 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->size == 3)
		work_a_three_stack(a);
	else if (a->size == 5)
		work_a_five_stack(a, b);
	else
		work_a(a->size, a, b);
}

int		main(int ac, char *av[])
{
	t_stack *a;
	t_stack *b;

	a = make_stack_a(ac, av);
	if (!(b = (t_stack *)malloc(sizeof(t_stack))))
		error_out();
	init_stack(b);
	push_swap(a, b);
	free_stack(a);
	free_stack(b);
	//system("leaks a.out");
	return (0);
}
