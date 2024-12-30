/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:09:24 by yaboukir          #+#    #+#             */
/*   Updated: 2024/12/29 15:55:29 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	check_len_rows(char **rows)
{
	size_t	l;

	l = 0;
	while (rows[l])
		l++;
	return (l);
}

size_t	check_col_len(char *rows)
{
	size_t	n;

	n = 0;
	while (rows[n])
		n++;
	return (n);
}

void	free_function(char **rows)
{
	int	f;

	f = 0;
	while (rows[f])
	{
		free(rows[f]);
		f++;
	}
	free(rows);
}
void	checking_the_line(char **rows)
{
	size_t	n;
	size_t	l;
	size_t	j;

	n = 0;
	l = check_col_len(rows[n]);
	while (rows[n])
	{
		j = check_col_len(rows[n]);
		if (j != l)
		{
			write(2, "Error\nmap isn't a full rectangle", 33);
			free_function(rows);
			exit(0);
		}
		n++;
	}
}

