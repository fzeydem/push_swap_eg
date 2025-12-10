/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:56:30 by fatmdemi          #+#    #+#             */
/*   Updated: 2025/12/10 20:56:33 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_stack *dst, t_stack *src)
{
	t_node	*node;

	if (!src || src->size == 0)
		return (0);
	node = src->top;
	src->top = node->next;
	src->size--;
	node->next = dst->top;
	dst->top = node;
	dst->size++;
	return (1);
}

void	op_pa(t_stack *a, t_stack *b)
{
	if (push(a, b))
		write(1, "pa\n", 3);
}

void	op_pb(t_stack *a, t_stack *b)
{
	if (push(b, a))
		write(1, "pb\n", 3);
}
