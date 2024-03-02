/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:00:37 by dmuller           #+#    #+#             */
/*   Updated: 2024/03/02 15:44:15 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	map_copy2(t_pars *file, int fd, char *line)
{
	int		x;
	int		i;
	char	**copy;

	i = 0;
	while (line)
	{
		copy = malloc((i + 2) * sizeof(char *));
		if (!copy)
			return (printf("Error\nMalloc failed during parsing\n"), 0);
		x = 0;
		while (x < i)
		{
			copy[x] = file->map[x];
			x++;
		}
		copy[x] = ft_strdup(line);
		copy[x + 1] = 0;
		free(file->map);
		file->map = copy;
		line = get_next_line(fd);
		i++;
	}
	return (1);
}
