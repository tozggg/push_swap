/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:26:46 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/28 20:50:53 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_next_line(char **line)
{
	char	buf[2];
	char	*tmp;
	int		r;
	
	if (line == NULL)
		return (-1);
	if (!(*line = (char *)malloc(sizeof(char))))
		return (-1);
	*line = 0;
	while ((r = read(0, buf, 1)) > 0)
	{
		buf[1] = 0;
		if (buf[0] == '\n')
			return (1);
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(*line);
	}
	return (r == 0 ? 0 : -1);
}

void	checker(t_stack *a, t_stack *b)
{
	int		r;
	char	*line;

	while ((r = get_next_line(&line)) > 0)
	{
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
}


int		main(int ac, char *av[])
{
	t_stack *a;
	t_stack *b;
	
	a = make_stack_a(ac, av);
	if (!(b = (t_stack *)malloc(sizeof(t_stack))))
		error_out();
	init_stack(b);
	checker(a, b);
	free_stack(a);
	free_stack(b);
	return (0);	
}
