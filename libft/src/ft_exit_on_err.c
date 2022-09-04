/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_on_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:29:45 by rkassouf          #+#    #+#             */
/*   Updated: 2022/08/31 23:41:55 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	exit_on_err(int fd, char *err_msg)
{
	write(fd, err_msg, ft_strlen(err_msg));
	exit(EXIT_FAILURE);
}
