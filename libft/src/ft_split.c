/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 09:03:42 by rkassouf          #+#    #+#             */
/*   Updated: 2022/08/31 23:43:57 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_separator(char a, char c)
{
	if (a == c || a == '\0')
		return (1);
	return (0);
}

static int	ft_wordcount(char const *s, char c)
{
	int	wc;
	int	i;

	wc = 0;
	i = -1;
	while (s && s[++i])
		if (!ft_separator(s[i], c) && ft_separator(s[i + 1], c))
			wc++;
	return (wc);
}

static int	ft_wordlength(char const *s, char c)
{
	int	length;

	length = 0;
	while (!ft_separator(s[length], c))
			length++;
	return (length);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		wc;
	char	**split;

	if (!s)
		return (NULL);
	wc = ft_wordcount(s, c);
	split = malloc(sizeof(*split) * (wc + 1));
	if (!split)
		return (NULL);
	i = -1;
	while (++i < wc)
	{
		while (ft_separator(*s, c) && *s != '\0')
			s++;
		split[i] = ft_substr(s, 0, ft_wordlength(s, c));
		if (!split[i])
		{
			free_split(split);
			return (NULL);
		}
		s += ft_wordlength(s, c);
	}
	split[i] = NULL;
	return (split);
}
