/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:45:50 by dmuller           #+#    #+#             */
/*   Updated: 2024/02/08 17:53:24 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int check_map_format(char *path, t_pars *file)
{
    int fd;
    char *line;

    fd = open(path, O_RDONLY);
    line = get_next_line(fd);
    skip_no_map(&line, file, fd);
    int i = 0;
    while(line)
    {
        file->map[i] = ft_substr(line, 0, ft_strlen(line));
        free(line);
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
    while(*line && *line[i] && *line[i] != '0' && *line[i] != '1')
    {
        free(*line);
        *line = get_next_line(fd);
        i = skip_spaces(0, *line);
    }
}

