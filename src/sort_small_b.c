/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:57:36 by fatmdemi          #+#    #+#             */
/*   Updated: 2025/12/14 21:47:45 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two_b(t_stack *a, t_stack *b)
{
	if (b->top->index < b->top->next->index)
		op_sb(b);
	op_pa(a, b);
	op_pa(a, b);
}

void	sort_small_b(t_stack *a, t_stack *b, int len)
{
	if (len == 1)
		op_pa(a, b);
	else if (len == 2)
		sort_two_b(a, b);
}
