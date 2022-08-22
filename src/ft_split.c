/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:52:07 by rkassouf          #+#    #+#             */
/*   Updated: 2022/08/22 13:02:28 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	ft_issep(char c, char sep)
{
	if (c == sep || c == '\0')
		return (1);
	return (0);
}

static size_t	ft_wordcount(char *s, char sep)
{
	int		i;
	size_t	wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		if (ft_issep(s[i + 1], sep) && (ft_issep(s[i], sep) == 0))
			wc++;
		i++;
	}
	return (wc);
}

static char	*ft_strdup_len(char const *src, size_t len)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	size;
	size_t	words;
	char	**split;

	if (s == NULL)
		return (NULL);
	words = ft_wordcount((char *)s, c);
	split = malloc(sizeof(char *) * (words + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < words)
	{
		size = 0;
		while (ft_issep(s[j], c))
			j++;
		while (ft_issep(s[j++], c) == 0)
			size++;
		split[i++] = ft_strdup_len(&s[j - size - 1], size);
	}
	split[i] = NULL;
	return (split);
}
