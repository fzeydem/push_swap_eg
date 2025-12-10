/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:57:36 by fatmdemi          #+#    #+#             */
/*   Updated: 2025/12/10 20:57:38 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	highest_index(t_stack *stack, int len)
{
	int		max;
	t_node	*cur;
	int		i;

	cur = stack->top;
	max = cur->index;
	i = 0;
	while (cur && i < len)
	{
		if (cur->index > max)
			max = cur->index;
		cur = cur->next;
		i++;
	}
	return (max);
}

static void	sort_two_b(t_stack *a, t_stack *b)
{
	if (b->top->index < b->top->next->index)
		op_sb(b, 1);
	op_pa(a, b);
	op_pa(a, b);
}

static void	sort_three_b(t_stack *a, t_stack *b)
{
	int	high;

	high = highest_index(b, 3);
	if (b->top->index != high)
	{
		if (b->top->next && b->top->next->index == high)
			op_sb(b, 1);
		else
			op_rrb(b, 1);
	}
	op_pa(a, b);
	sort_two_b(a, b);
}

void	sort_small_b(t_stack *a, t_stack *b, int len)
{
	if (len == 1)
		op_pa(a, b);
	else if (len == 2)
		sort_two_b(a, b);
	else if (len == 3)
		sort_three_b(a, b);
}
