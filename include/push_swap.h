/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:23:15 by fatmdemi          #+#    #+#             */
/*   Updated: 2025/12/14 20:06:38 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

int		parse_args(t_stack *a, int argc, char **argv);
int		is_sorted(t_stack *a);
void	assign_indices(t_stack *a);
int		contains_value(t_stack *stack, int value);
t_node	*ps_new_node(int value);
void	append_node(t_stack *stack, t_node *node);
void	free_stack(t_stack *stack);
void	error_exit(t_stack *a, t_stack *b);

void	op_sa(t_stack *a);
void	op_sb(t_stack *b);
void	op_ss(t_stack *a, t_stack *b);
void	op_pa(t_stack *a, t_stack *b);
void	op_pb(t_stack *a, t_stack *b);
void	op_ra(t_stack *a);
void	op_rb(t_stack *b);
void	op_rr(t_stack *a, t_stack *b);
void	op_rra(t_stack *a);
void	op_rrb(t_stack *b);
void	op_rrr(t_stack *a, t_stack *b);

void	sort_stack(t_stack *a, t_stack *b);
void	sort_small_a(t_stack *a, int len);
void	sort_small_b(t_stack *a, t_stack *b, int len);

char	**ps_split(const char *s);
long	ft_atol(const char *str, int *ok);
void	*ps_calloc(size_t count, size_t size);
void	ps_free_split(char **arr);

#endif
