/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayonal <ayonal@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:55:17 by ayonal            #+#    #+#             */
/*   Updated: 2025/10/30 14:55:17 by ayonal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(const char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (*(str + i) != '\0')
	{
		if (i == 0)
		{
			if (*(str + i) != c)
				count++;
		}
		else
		{
			if ((*(str + i) != c && *(str + i - 1) == c))
				count++;
		}
		i++;
	}
	return (count);
}

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0' && *(s + i) != c)
	{
		i++;
	}
	return (i);
}

static void	free_function(char **str, int j)
{
	while (j >= 0)
	{
		free(str[j--]);
	}
	free(str);
}

static void	fill(char **str, int len, int j, char **s)
{
	int	m;

	m = 0;
	while (m < len)
	{
		str[j][m++] = **s;
		(*s)++;
	}
	str[j][m] = '\0';
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	int		j;
	int		len;

	j = 0;
	str = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (str == NULL)
		return (0);
	while (*(s) != '\0')
	{
		while (*(s) == c)
			s++;
		if (*(s) == '\0')
			break ;
		len = word_len(s, c);
		str[j] = (char *)malloc(len + 1);
		if (str[j] == NULL)
		{
			free_function(str, j);
			return (NULL);
		}
		fill(str, len, j++, (char **)&s);
	}
	str[j] = NULL;
	return (str);
}
