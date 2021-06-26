/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:40:31 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/26 09:59:13 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define ASC 1
#define DESC 0

typedef struct		s_stack
{
	struct s_node	*head;
	int				size;
}					t_stack;

typedef struct		s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_part
{
	int				half_pivot;
	int				one_third_pivot;
	int				two_third_pivot;
	int				pa_count;
	int				pb_count;
	int				ra_count;
	int				rb_count;
}					t_part;


//---------------------------------------------------------------------------libft

int		ft_isdigit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

void	ft_putstr(char *str)
{
	int		len;

	len = ft_strlen(str);
	write(1, str, len);
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

void	print_error(void)
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
	print_error();
}

//---------------------------------------------------------------------------command

void	do_swap(t_stack *stack)
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

void	do_sa(t_stack *a)
{
	do_swap(a);
	ft_putstr("sa\n");
}

void	do_sb(t_stack *b)
{
	do_swap(b);
	ft_putstr("sb\n");
}

void	do_ss(t_stack *a, t_stack *b)
{
	do_swap(a);
	do_swap(b);
	ft_putstr("ss\n");
}

int		do_pa(t_stack *a, t_stack *b)
{
	t_node *node;
	
	if (b->size == 0)
		return ;
	node = b->head;
	b->head = node->next;
	if (b->head)
		b->head->prev = NULL;
	node->next = a->head;
	if (a->head)
		a->head->prev = node;
	a->head = node;
	++(a->size);
	--(b->size);
	ft_putstr("pa\n");
	return (1);
}

int		do_pb(t_stack *a, t_stack *b)
{
	t_node *node;

	if (a->size == 0)
		return ;
	node = a->head;
	a->head = node->next;
	if (a->head)
		a->head->prev = NULL;
	node->next = b->head;
	if (b->head)
		b->head->prev = node;
	b->head = node;
	++(b->size);
	--(a->size);
	ft_putstr("pb\n");
	return (1);
}

void	do_rotate(t_stack *stack)
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

int		do_ra(t_stack *a)
{
	do_rotate(a);
	ft_putstr("ra\n");
	return (1);
}

int		do_rb(t_stack *b)
{
	do_rotate(b);
	ft_putstr("rb\n");
	return (1);
}

void	do_rr(t_stack *a, t_stack *b)
{
	do_rotate(a);
	do_rotate(b);
	ft_putstr("rr\n");
}

void	do_reverse_rotate(t_stack *stack)
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

void	do_rra(t_stack *a)
{
	do_reverse_rotate(a);
	ft_putstr("rra\n");
}

void	do_rrb(t_stack *b)
{
	do_reverse_rotate(b);
	ft_putstr("rrb\n");
}

void	do_rrr(t_stack *a, t_stack *b)
{
	do_reverse_rotate(a);
	do_reverse_rotate(b);
	ft_putstr("rrr\n");
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

void	init_part(t_part *part)
{
	part->half_pivot = 0;
	part->one_third_pivot = 0;
	part->two_third_pivot = 0;
	part->pa_count = 0;
	part->pb_count = 0;
	part->ra_count = 0;
	part->rb_count = 0;
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
	return ((int)(res * pos));
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
		print_error();
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

static int	partition(int arr[], int left, int right)
{
	int		pivot;
	int		tmp;

	pivot = arr[(left + right) / 2];
	while (left < right)
	{
		while ((arr[left] < pivot) && (left < right))
			++left;
		while ((arr[right] > pivot) && (left < right))
			--right;
		if (left < right)
		{
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
	return (left);
}

static void	quicksort(int arr[], int left, int right)
{
	int 	pivot;
	
	if (left < right)
	{
		pivot = partition(arr, left, right);
		quicksort(arr, left, pivot - 1);
		quicksort(arr, pivot + 1, right);
	}
}

void		make_pivot(int len, t_stack *stack, t_part *part)
{
	t_node	*node;
	int		arr[len];
	int		i;

	node = stack->head;
	i = 0;
	while (i < len)
	{
		arr[i++] = node->data;
		node = node->next;
	}
	quicksort(arr, 0, len - 1);
	part->half_pivot = arr[len / 2];
	part->one_third_pivot = arr[len / 3];
	part->two_third_pivot = arr[len / 3 * 2];
}

void	work_b(int len, t_stack *a, t_stack *b, t_part *part)
{
	
}

void	work_a(int len, t_stack *a, t_stack *b, t_part *part)
{
	if (len == 1 || is_sorted(a, len, ASC))
		return ;
	else if (len == 2)
		do_sa(a);
	/*
	else if (len == 3)
	else if (len == 5)
	*/
	else
	{
		init_part(part);
		make_pivot(len, a, part);
		while (--len >= 0)
		{
			//등호와 부등호의 차이 실험해보기
			if (a->head->data >= part->two_third_pivot)
				part->ra_count += do_ra(a);
			else
			{
				part->pb_count += do_pb(a, b);
				if (a->head->data >= part->one_third_pivot)
					part->rb_count += do_rb(b);
			}
		}
		//rrr
	}
	work_a(part->ra_count, a, b, part);
	work_b(part->rb_count, a, b, part);
	work_b(part->pb_count - part->rb_count, a, b, part);
}

void	push_swap(t_stack *a, t_stack *b)
{
	t_part *part;

	if (a->size == 0)
		return ;
	if (!(part = (t_part *)malloc(sizeof(t_part))))
		print_error();
	work_a(a->size, a, b, part);
	free(part);
}


#include <stdio.h>

int		main(int ac, char *av[])
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = make_stack_a(ac, av);
	if (!(stack_b = (t_stack *)malloc(sizeof(t_stack))))
		print_error();
	init_stack(stack_b);




	//push_swap(stack_a, stack_b);

	/*
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
	*/

	free_stack(stack_a);
	free_stack(stack_b);
	//system("leaks a.out");
	return (0);
}
