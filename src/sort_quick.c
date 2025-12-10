#include "push_swap.h"

static void	push_chunks(t_stack *a, t_stack *b, int chunk)
{
	int	target;

	target = chunk;
	while (a->size > 0)
	{
		if (a->top->index <= target)
		{
			op_pb(a, b);
			if (b->top->index < target - (chunk / 2))
				op_rb(b, 1);
			if (b->size == target)
				target += chunk;
		}
		else
			op_ra(a, 1);
	}
}

static int	locate_extreme(t_node *node, int *len, int is_max)
{
	int	pos;
	int	best_idx;
	int	cur_pos;
	pos = 0;
	cur_pos = 0;
	*len = 0;
	if (!node)
		return (0);
	best_idx = node->index;
	while (node)
	{
		if ((is_max && node->index > best_idx)
			|| (!is_max && node->index < best_idx))
		{
			best_idx = node->index;
			pos = cur_pos;
		}
		node = node->next;
		cur_pos++;
	}
	*len = cur_pos;
	return (pos);
}

static void	push_max_to_a(t_stack *a, t_stack *b)
{
	int	pos;
	int	len;
	int	steps;
	int	up;

	pos = locate_extreme(b->top, &len, 1);
	up = (pos <= len / 2);
	steps = pos;
	if (!up)
		steps = len - pos;
	while (steps > 0)
	{
		if (up)
			op_rb(b, 1);
		else
			op_rrb(b, 1);
		steps--;
	}
	op_pa(a, b);
}

static void	sort_five(t_stack *a, t_stack *b)
{
	int	min_pos;
	int	len;
	int	steps;
	int	up;

	while (a->size > 3)
	{
		min_pos = locate_extreme(a->top, &len, 0);
		up = (min_pos <= len / 2);
		steps = min_pos;
		if (!up)
			steps = len - min_pos;
		while (steps-- > 0)
			if (up)
				op_ra(a, 1);
			else
				op_rra(a, 1);
		op_pb(a, b);
	}
	sort_small_a(a, a->size);
	if (b->size)
		sort_small_b(a, b, b->size);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	int	chunk;

	if (is_sorted(a) || a->size == 0)
		return ;
	if (a->size <= 3)
		return (sort_small_a(a, a->size));
	if (a->size <= 5)
		return (sort_five(a, b));
	if (a->size <= 100)
		chunk = 15;
	else
		chunk = 30;
	push_chunks(a, b, chunk);
	while (b->size > 0)
		push_max_to_a(a, b);
}
