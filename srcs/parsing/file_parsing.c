/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:33:33 by dmuller           #+#    #+#             */
/*   Updated: 2023/12/12 11:51:03 by dmuller          ###   ########.fr       */
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

int	check_map(char *path)
{
	if (!check_cub(path))
		return (0);
	if(!check_file(path))
		return(0);
	if(!check_directory(path))
		return(0);
	if(!check_file_args(path))
		return(0);
	else
		return (1);
}
