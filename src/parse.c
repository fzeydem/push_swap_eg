/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:56:59 by fatmdemi          #+#    #+#             */
/*   Updated: 2025/12/14 18:39:11 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_value(t_stack *a, const char *str)
{
	int		ok;
	long	val;

	val = ft_atol(str, &ok);
	if (!ok || contains_value(a, (int)val))
		return (0);
	append_node(a, ps_new_node((int)val));
	return (a->top != NULL);
}

static void	load_parts(t_stack *a, char **parts)
{
	int	i;

	if (!parts || !parts[0])
	{
		ps_free_split(parts);
		error_exit(a, NULL);
	}
	i = 0;
	while (parts[i])
	{
		if (!add_value(a, parts[i]))
		{
			ps_free_split(parts);
			error_exit(a, NULL);
		}
		i++;
	}
	ps_free_split(parts);
}

static void	handle_arg(t_stack *a, const char *arg)
{
	char	**parts;

	parts = ps_split(arg);
	if (!parts)
		error_exit(a, NULL);
	load_parts(a, parts);
}

int	parse_args(t_stack *a, int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		handle_arg(a, argv[i]);
		i++;
	}
	assign_indices(a);
	return (1);
}
