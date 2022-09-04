/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:54:57 by rkassouf          #+#    #+#             */
/*   Updated: 2022/08/31 23:44:42 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*buf;
	int		size;

	if (!lst)
		return (0);
	buf = lst;
	size = 1;
	while (buf->next != NULL)
	{
		size++;
		buf = buf->next;
	}
	return (size);
}
