/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:08:44 by yaboukir          #+#    #+#             */
/*   Updated: 2024/12/29 17:11:40 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		n *= -1;
		count = count + write(1, "-", 1);
	}
	if (n > 9)
	{
		count = count + ft_putnbr(n / 10);
		count = count + ft_putnbr(n % 10);
	}
	if (n >= 0 && n <= 9)
	{
		n = n + '0';
		count = count + write(1, &n, 1);
	}
	return (count);
}

