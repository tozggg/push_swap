/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:02:47 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/28 16:02:16 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
