/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 23:52:39 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/01 23:52:42 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_itoa(int n)
{
    int len = (n <= 0) ? 1 : 0;
    int tmp = n;

    while (tmp)
    {
        len++;
        tmp /= 10;
    }
    char *str = malloc(len + 1);
    if (!str)
        return (NULL);
    str[len] = '\0';
    if (n == 0)
        str[0] = '0';
    else if (n < 0)
    {
        str[0] = '-';
        n = -n;
    }
    while (n)
    {
        str[--len] = (n % 10) + '0';
        n /= 10;
    }
    return (str);
}
