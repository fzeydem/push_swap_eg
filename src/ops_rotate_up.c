/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:56:43 by fatmdemi          #+#    #+#             */
/*   Updated: 2025/12/14 20:29:39 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*cur;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	cur = stack->top;
	while (cur->next)
		cur = cur->next;
	cur->next = first;
	first->next = NULL;
}

void	op_ra(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	op_rb(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	op_rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
