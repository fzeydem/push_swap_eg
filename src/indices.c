/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indices.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:56:18 by fatmdemi          #+#    #+#             */
/*   Updated: 2025/12/10 20:56:21 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_values(t_stack *a)
{
	int		*arr;
	int		i;
	t_node	*cur;

	arr = (int *)malloc(sizeof(int) * a->size);
	if (!arr)
		error_exit(a, NULL);
	cur = a->top;
	i = 0;
	while (cur)
	{
		arr[i++] = cur->value;
		cur = cur->next;
	}
	return (arr);
}

static void	bubble_sort(int *arr, int size)
{
	int	i;
	int	tmp;
	int	sorted;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i + 1 < size)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				sorted = 0;
			}
			i++;
		}
	}
}

static int	find_pos(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	assign_indices(t_stack *a)
{
	int		*arr;
	t_node	*cur;

	arr = copy_values(a);
	bubble_sort(arr, a->size);
	cur = a->top;
	while (cur)
	{
		cur->index = find_pos(arr, a->size, cur->value);
		cur = cur->next;
	}
	free(arr);
}
