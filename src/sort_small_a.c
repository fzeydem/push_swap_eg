/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:57:24 by fatmdemi          #+#    #+#             */
/*   Updated: 2025/12/10 20:57:27 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two_a(t_stack *a)
{
		if (a->top->index > a->top->next->index)
			op_sa(a);
}

static void	sort_three_a(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->index;
	second = a->top->next->index;
	third = a->top->next->next->index;
	if (first > second && second < third && first < third)
		op_sa(a);
	else if (first > second && second > third)
	{
		op_sa(a);
		op_rra(a);
	}
	else if (first > second && second < third && first > third)
		op_ra(a);
	else if (first < second && second > third && first < third)
	{
		op_sa(a);
		op_ra(a);
	}
	else if (first < second && second > third && first > third)
		op_rra(a);
}

void	sort_small_a(t_stack *a, int len)
{
	if (len < 2)
		return ;
	if (len == 2)
		return (sort_two_a(a));
	sort_three_a(a);
}
