/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:10:52 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/28 16:02:16 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
