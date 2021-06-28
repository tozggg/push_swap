/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 06:46:30 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/29 06:49:47 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define ASC 1
# define DESC 0

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

void				error_out(void);
void				free_stack(t_stack *stack);
void				free_and_error(t_stack *stack, char **split);

void				init_stack(t_stack *stack);
void				init_node(t_node *node);

int					pa(t_stack *a, t_stack *b);
int					pb(t_stack *a, t_stack *b);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
int					ra(t_stack *a);
int					rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

void				make_pivot(int len, t_stack *stack, t_part *part);
t_part				*make_part();
void				undo_part(t_stack *a, t_stack *b, t_part *part);
void				pa_part(int len, t_stack *a, t_stack *b);

int					is_sorted(t_stack *stack, int len, int order);

void				work_a_three_part(t_stack *a);
void				work_b_three_part(t_stack *b);
void				work_a_three_stack(t_stack *a);
void				work_a_five_stack(t_stack *a, t_stack *b);

void				work_a(int len, t_stack *a, t_stack *b);
void				work_b(int len, t_stack *a, t_stack *b);

t_stack				*make_stack_a(int ac, char *av[]);

void				push_swap(t_stack *a, t_stack *b);

#endif
