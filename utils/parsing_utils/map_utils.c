/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:45:50 by dmuller           #+#    #+#             */
/*   Updated: 2024/02/29 17:44:37 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int map_copy(char *path, t_pars *file)
{
    int fd;
    char *line;
    char **copy;

    fd = open(path, O_RDONLY);
    line = get_next_line(fd);
    skip_no_map(&line, file, fd);
    int i = 0;
    int x;
    file->map = malloc(sizeof(char *));
    file->map[0] = 0;    
    while(line)
    {
        copy = malloc((i + 2) * sizeof(char *));
        if(!copy)
        {
            printf("Error\nMalloc failed during parsing\n");
            return(0);
        }
        x = 0;
        while(x < i)
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
    return(1);
}

void skip_no_map(char **line, t_pars *file, int fd)
{
    (void)file;
    int i;
    i = skip_spaces(0, *line);
    while(*line && (*line)[i] && (*line)[i] != '0' && (*line)[i] != '1')
    {
        free(*line);
        *line = get_next_line(fd);
        i = skip_spaces(0, *line);
    }
}

int check_map_format(t_pars *file)
{
    int     i;
    int     x;

	i = -1;
    while(file->map[++i])
    {
        x = 0;
        while(file->map[i][x])
        {
            if(!is_valid_char(file, i, x))
            {
                printf("Error\nInvalid map\n");
                return(0);
            }
            //INSERER SPAWN INIT
        	x++;
		}
    }
	return(1);
}

int	is_valid_char(t_pars *file, int i, int x)
{
	if (!is_map_character(file->map[i][x]))
		return (0);
	if (file->map[i][x] != '0'
		&& file->map[i][x] != 'N'
		&& file->map[i][x] != 'E'
		&& file->map[i][x] != 'S'
		&& file->map[i][x] != 'W')
		return (1);
	if (i == 0
		|| x == 0
		||!file->map[i - 1][x]
		||file->map[i - 1][x] == ' '
		||file->map[i - 1][x] == '\n'
		||!file->map[i][x - 1]
		||file->map[i][x - 1] == ' '
		||file->map[i][x - 1] == '\n'
		||!file->map[i + 1]
		||!file->map[i + 1][x]
		||file->map[i + 1][x] == ' '
		||file->map[i + 1][x] == '\n'
		||!file->map[i][x + 1]
		||file->map[i][x + 1] == ' '
		||file->map[i][x + 1] == '\n')
		return (0);
	return (1);
}

int	is_map_character(char c)
{
	return (c == '0'
		|| c == ' '
		|| c == '1'
		|| c == 'N'
		|| c == 'S'
		|| c == 'E'
		|| c == 'W'
		|| c == '\n');
}
