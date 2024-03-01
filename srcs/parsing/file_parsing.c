/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:33:33 by dmuller           #+#    #+#             */
/*   Updated: 2024/03/01 11:08:35 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_args(int argc)
{
	if (argc < 2)
	{
		printf ("Error\nNo map has been passed.\n");
		return (0);
	}
	if (argc > 2)
	{
		printf ("Error\nToo many arguments.\n");
		return (0);
	}
	return (1);
}

int	check_map(char *path, t_pars *file)
{
	if (!check_cub(path))
		return (0);
	if (!check_file(path))
		return (0);
	if (!check_directory(path))
		return (0);
	if (!check_file_args(path, file))
		return (0);
	if (!map_copy(path, file))
		return (0);
	if (!check_map_format(file))
		return (0);
	else
		return (1);
}
