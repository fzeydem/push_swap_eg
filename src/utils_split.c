/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmdemi <fatmdemi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:57:50 by fatmdemi          #+#    #+#             */
/*   Updated: 2025/12/10 20:57:52 by fatmdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_count(const char *s)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != ' ' && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == ' ')
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*word_dup(const char *s, int len)
{
	int		i;
	char	*word;

	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	*next_word(const char **s)
{
	const char	*start;
	int			len;

	while (**s == ' ')
		(*s)++;
	if (!**s)
		return (NULL);
	start = *s;
	len = 0;
	while (**s && **s != ' ')
	{
		len++;
		(*s)++;
	}
	return (word_dup(start, len));
}

char	**ps_split(const char *s)
{
	char	**arr;
	int		i;
	int		wc;

	wc = word_count(s);
	arr = (char **)ps_calloc(wc + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (1)
	{
		arr[i] = next_word(&s);
		if (!arr[i])
			break ;
		i++;
	}
	return (arr);
}

void	ps_free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
