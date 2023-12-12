/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:33:38 by dmuller           #+#    #+#             */
/*   Updated: 2023/12/12 14:11:43 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_cub(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len > 3 && ft_strcmp(ft_substr(path, len - 4, 4), ".cub") == 0)
		return (1);
	printf ("Error\nMap is not a .cub file.\n");
	return (0);
}

int check_file(char *path)
{
	int	fd;
	
	if((fd = open(path, O_RDONLY)) == -1)
		printf("Error\nCan't open the file\n");
	else
	{
		close(fd);
		return(1);
	}
	return(0);
}

int check_directory(char *path)
{
	int fd;

	if((fd = open(path, __O_DIRECTORY)) != -1)
		printf("Error\nfile is a directory\n");
	else
	{
		close(fd);
		return(1);
	}
	return(0);
}

int check_file_args(char *path)
{
	if() == true)
	{
		
	}
}

int args_utils(char *path)
{
	
}
