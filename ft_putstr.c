/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:07:28 by yaboukir          #+#    #+#             */
/*   Updated: 2024/12/29 11:26:36 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write (1, "(null)", 6));
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}
