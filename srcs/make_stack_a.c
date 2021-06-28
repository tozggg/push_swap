/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:14:47 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/28 20:16:54 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_duplicated_data(t_stack *stack, int data)
{
	t_node *node;

	node = stack->head;
	while (node)
	{
		if (node->data == data)
			return (1);
		node = node->next;
	}
	return (0);
}

static int	ft_atoi_check(char *str, t_stack *stack, char **split)
{
	unsigned long long	res;
	int					pos;
	int					i;

	res = 0;
	pos = 1;
	i = 0;
	if (str[i] == '-')
	{
		pos = -1;
		++i;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			res = (res * 10) + (str[i] - '0');
		else
			free_and_error(stack, split);
		if ((pos == 1 && res > 2147483647) \
				|| (pos == -1 && res > 2147483648))
			free_and_error(stack, split);
		++i;
	}
	if (is_duplicated_data(stack, res))
			free_and_error(stack, split);
	return ((int)(res * pos));
}

static void	add_split_to_stack(t_stack *stack, char **split)
{
	t_node	*node;
	t_node	*tmp;
	int		data;
	int		i;

	i = 0;
	while (split[i])
	{
		data = ft_atoi_check(split[i++], stack, split);
		if (!(node = (t_node *)malloc(sizeof(t_node))))
			free_and_error(stack, split);
		init_node(node);
		node->data = data;
		if (stack->head == NULL)
			stack->head = node;
		else
		{
			tmp = stack->head;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = node;
			node->prev = tmp;
		}
		++(stack->size);
	}
}

t_stack		*make_stack_a(int ac, char *av[])
{
	t_stack *stack;
	char	**split;
	int		i;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		error_out();
	init_stack(stack);
	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		add_split_to_stack(stack, split);
		free_split(split);
		++i;
	}
	
	return (stack);
}
