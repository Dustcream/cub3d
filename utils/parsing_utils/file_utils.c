/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:33:38 by dmuller           #+#    #+#             */
/*   Updated: 2024/02/29 18:52:47 by dmuller          ###   ########.fr       */
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

int check_file_args(char *path, t_pars *file)
{
	int verif;
	int rgb_verif;

	verif = 0;
	rgb_verif = 0;
	args_utils(path, &verif, &rgb_verif, file);
	printf("%d\n", verif);
	if(verif != 6)
	{
		printf("Error\nWrong number of arguments\n");
		return(0);
	}
	if(rgb_verif != 2)
	{
		printf("Error\nWrong RGB colors for F or C\n");
		return(0);
	}
	else if(file->C && file->EA && file->F && file->NO && file->SO && file->WE)
		return(1);
	else
		printf("Error\nArguments are not valid\n");
	return(0);
}

int args_utils(char *path, int *verif, int *rgb_verif, t_pars *file)
{
	int fd;
	char *line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while(line)
	{
		verif_line(line, verif, file);
		verif_line2(line, verif, rgb_verif, file);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return(0);
}

