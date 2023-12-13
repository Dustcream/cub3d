/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:33:38 by dmuller           #+#    #+#             */
/*   Updated: 2023/12/13 16:55:09 by dmuller          ###   ########.fr       */
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

	verif = 0;
	args_utils(path, &verif, file);
	if(verif != 6)
	{
		printf("Error\nWrong number of arguments\n");
		return(0);
	}
	else if(file->C && file->EA && file->F && file->NO && file->SO && file->WE)
		return(1);
	else
		printf("Error\nArguments are not valid\n");
	return(0);
}

int args_utils(char *path, int *verif, t_pars *file)
{
	int fd;
	char *line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while(line && verif_line(line, verif, file))
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return(0);
}

int	verif_line(char *line, int *verif, t_pars *file)
{
	int i;
	i = skip_spaces(0, line);
	if(line[i] == 'N' && line[i + 1] == 'O' && (line[i+2] == ' ' || line[i + 2] == '\t') && file->NO == NULL)
	{
		i = skip_spaces(i + 3, line);
		file->NO = ft_substr(line, i, skip_end_spaces(line) - i);
		*verif += 1;
	}
	else if(line[i] == 'S' && line[i + 1] == 'O' && (line[i + 2]== ' ' || line[i + 2] == '\t') && file->SO == NULL)
	{
		i = skip_spaces(i + 3, line);
		file->SO = ft_substr(line, i, skip_end_spaces(line) - i);
		*verif += 1;
	}
	else if(line[i] == 'W' && line[i + 1] == 'E' && (line[i + 2]== ' ' || line[i + 2] == '\t') && file->WE == NULL)
	{
		i = skip_spaces(i + 3, line);
		file->WE = ft_substr(line, i, skip_end_spaces(line) - i);
		*verif += 1;
	}
	else if(line[i] == 'E' && line[i + 1] == 'A' && (line[i + 2]== ' ' || line[i + 2] == '\t') && file->EA == NULL)
	{
		i = skip_spaces(i + 3, line);
		file->EA = ft_substr(line, i, skip_end_spaces(line) - i);
		*verif += 1;
	}
	else if(line[i] == 'F' && (line[i + 1]== ' ' || line[i + 1] == '\t') && file->F == NULL)
	{
		i = skip_spaces(i + 2, line);
		file->F = ft_substr(line, i, skip_end_spaces(line) - i);
		*verif += 1;
	}
	else if(line[i] == 'C' && (line[i + 1]== ' ' || line[i + 1] == '\t') && file->C == NULL)
	{
		i = skip_spaces(i + 2, line);
		file->C = ft_substr(line, i, skip_end_spaces(line) - i);
		*verif += 1;
	}
	else if(line[i] == ' ' || line[i] == '\t' || line[i] == '\n' || line[i] == '1')
		return(*verif);
	else
		*verif += 1;
	return(*verif);
}
