/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:57:55 by fatmdemi          #+#    #+#             */
/*   Updated: 2025/12/10 20:58:07 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

void	*ps_calloc(size_t count, size_t size)
{
	size_t	total;
	size_t	i;
	char	*ptr;

	total = count * size;
	ptr = (char *)malloc(total);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total)
		ptr[i++] = 0;
	return ((void *)ptr);
}

static int	read_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

long	ps_atol(const char *str, int *ok)
{
	int		sign;
	long	res;

	*ok = 0;
	if (!str || !*str)
		return (0);
	sign = read_sign(&str);
	if (*str < '0' || *str > '9')
		return (0);
	res = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if (res * sign < -2147483648L || res * sign > 2147483647L)
			return (0);
		str++;
	}
	if (*str)
		return (0);
	*ok = 1;
	return (res * sign);
}
