/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:03:31 by rkassouf          #+#    #+#             */
/*   Updated: 2022/08/31 23:44:47 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*buf;

	buf = malloc(sizeof(t_list));
	if (buf == NULL)
		return (NULL);
	buf->content = content;
	buf->next = NULL;
	return (buf);
}
