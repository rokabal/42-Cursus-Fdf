/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:52:20 by rkassouf          #+#    #+#             */
/*   Updated: 2022/08/31 23:43:30 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s;
	size_t	d;
	size_t	i;

	d = 0;
	while (dst[d] != '\0' && d < size)
		d++;
	s = 0;
	while (src[s] != '\0')
		s++;
	if (size <= d)
		return (size + s);
	i = 0;
	while (src[i] != '\0' && (i < size - d - 1))
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (s + d);
}
