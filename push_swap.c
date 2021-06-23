/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:40:31 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/23 20:11:07 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define INT_MAX 2147483647
#define INT_MIN -2147473648

typedef struct		s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_stack
{
	struct s_node	*head;
	int				size;
}					t_stack;

//---------------------------------------------------------------------------isdigit

int		ft_isdigit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

//---------------------------------------------------------------------------split

static int	get_split_size(char const *s, char c)
{
	int res;
	int check;
	int i;

	res = 0;
	check = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (check == 0)
				++res;
			check = 1;
		}
		else
			check = 0;
		++i;
	}
	return (res);
}

static char	*get_split_child(char const *s, char c, int i)
{
	char	*res;
	int		start;
	int		end;
	int		j;

	start = i;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		++i;
	}
	end = i;
	res = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (start < end)
		res[j++] = s[start++];
	res[j] = 0;
	return (res);
}

static void	get_split_parent(char **ptr, char const *s, char c)
{
	int index;
	int check;
	int i;

	index = 0;
	check = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (check == 0)
				ptr[index++] = get_split_child(s, c, i);
			check = 1;
		}
		else
			check = 0;
		++i;
	}
	ptr[index] = 0;
}

void		free_split(char **ptr)
{
	int i;

	i = 0;
	if (ptr == NULL)
		return ;
	while (ptr[i])
	{
		free(ptr[i]);
		++i;
	}
	free(ptr);
}

char		**ft_split(char const *s, char c)
{
	char	**ptr;
	int		size;
	int		i;

	if (s == NULL)
		return (NULL);
	size = get_split_size(s, c);
	ptr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ptr)
		return (NULL);
	get_split_parent(ptr, s, c);
	i = 0;
	while (i < size)
	{
		if (ptr[i] == NULL)
		{
			free_split(ptr);
			return (NULL);
		}
		++i;
	}
	return (ptr);
}

// --------------------------------------------------------------------------utils

void	error(void)
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
	error();
}

//---------------------------------------------------------------------------command

void	command_swap(t_stack *stack)
{
	t_node	*top;
	t_node	*second;

	if (stack->size == 0 || stack->size == 1)
		return ;
	top = stack->head;
	second = top->next;
	top->next = second->next;
	top->prev = second;
	second->next = top;
	second->prev = NULL;
	stack->head = second;
}

void	command_ss(t_stack *stack_a, t_stack *stack_b)
{
	command_swap(stack_a);
	command_swap(stack_b);
}

void	command_pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node *node;
	
	if (stack_b->size == 0)
		return ;
	node = stack_b->head;
	stack_b->head = node->next;
	if (stack_b->head)
		stack_b->head->prev = NULL;
	node->next = stack_a->head;
	if (stack_a->head)
		stack_a->head->prev = node;
	stack_a->head = node;
	++(stack_a->size);
	--(stack_b->size);
}

void	command_pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node *node;

	if (stack_a->size == 0)
		return ;
	node = stack_a->head;
	stack_a->head = node->next;
	if (stack_a->head)
		stack_a->head->prev = NULL;
	node->next = stack_b->head;
	if (stack_b->head)
		stack_b->head->prev = node;
	stack_b->head = node;
	++(stack_b->size);
	--(stack_a->size);
}

void	command_rotate(t_stack *stack)
{
	t_node	*top;
	t_node	*tmp;

	if (stack->size == 0 || stack->size == 1)
		return ;
	top = stack->head;
	stack->head = top->next;
	stack->head->prev = NULL;
	tmp = stack->head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = top;
	top->prev = tmp;
	top->next = NULL;
}

void	command_rr(t_stack *stack_a, t_stack *stack_b)
{
	command_rotate(stack_a);
	command_rotate(stack_b);
}

void	command_reverse_rotate(t_stack *stack)
{
	t_node *top;
	t_node *tmp;

	if (stack->size == 0 || stack->size == 1)
		return ;
	top = stack->head;
	tmp = stack->head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->next = top;
	tmp->prev = NULL;
	stack->head = tmp;
}

void	command_rrr(t_stack *stack_a, t_stack *stack_b)
{
	command_reverse_rotate(stack_a);
	command_reverse_rotate(stack_b);
}

//---------------------------------------------------------------------------function

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

int		is_duplicated_data(t_stack *stack, int data)
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

int		ft_atoi(char *str, t_stack *stack, char **split)
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
	return ((int)res);
}

void	add_split_to_stack(t_stack *stack, char **split)
{
	t_node	*node;
	t_node	*tmp;
	int		data;
	int		i;

	i = 0;
	while (split[i])
	{
		data = ft_atoi(split[i++], stack, split);
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

t_stack	*make_stack_a(int ac, char *av[])
{
	t_stack *stack;
	char	**split;
	int		i;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		error();
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

#include <stdio.h>

int		main(int ac, char *av[])
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = make_stack_a(ac, av);
	if (!(stack_b = (t_stack *)malloc(sizeof(t_stack))))
		error();
	init_stack(stack_b);

	
	//-------------------------------------
	command_reverse_rotate(stack_a);
	
	

	//--
	printf("a\tb\n");
	printf("_\t_\n");
	
	t_node *node1 = stack_a->head;
	t_node *node2 = stack_b->head;
	
	while (node1 || node2)
	{
		if (node1 != NULL)
		{	
			printf("%d", node1->data);
			node1 = node1->next;
		}
		printf("\t");
		if (node2 != NULL)
		{
			printf("%d", node2->data);
			node2 = node2->next;
		}
		printf("\n");
		
	}
	//-----------------------------------

	free_stack(stack_a);
	free_stack(stack_b);
	//system("leaks a.out");
	return (0);
}
