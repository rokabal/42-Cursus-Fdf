/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:28:19 by rkassouf          #+#    #+#             */
/*   Updated: 2022/08/31 23:42:05 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_digits(int n)
{
	int	digits;

	digits = 0;
	if (n < 0)
	{
		digits++;
		n = -n;
	}
	while (n > 9)
	{
		digits++;
		n = n / 10;
	}
	return (++digits);
}

char	*ft_itoa(int n)
{
	int		flag;
	char	*number;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	number = malloc((ft_digits(n) + 1) * sizeof(char));
	if (number == NULL)
		return (NULL);
	number[ft_digits(n)] = '\0';
	flag = 0;
	if (n < 0)
	{
		number[0] = '-';
		n = -n;
		flag = 1;
	}
	while (n > 9)
	{
		number[ft_digits(n) + flag - 1] = (n % 10) + '0';
		n = n / 10;
	}
	number[ft_digits(n) + flag - 1] = (n % 10) + '0';
	return (number);
}
