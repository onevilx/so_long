/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:54:06 by yaboukir          #+#    #+#             */
/*   Updated: 2024/12/29 11:54:29 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(char *row)
{
	int		buffer;
	char	*maps;
	char	*tmp;

	tmp = NULL;
	buffer = open(row, O_RDONLY, 0777);
	if (buffer < 0)
		return (write(1, "Error\n", 6), exit(1), NULL);
	maps = NULL;
	row = get_next_line(buffer);
	while ((row))
	{
		maps = ft_strjoin(maps, row);
		free(row);
		row = NULL;
		row = get_next_line(buffer);
	}
	return (close(buffer), maps);
}
