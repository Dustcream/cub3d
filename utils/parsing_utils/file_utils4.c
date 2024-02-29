/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:24:35 by dmuller           #+#    #+#             */
/*   Updated: 2024/02/29 18:51:42 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void stock_WE(t_pars *file, int i, char *line, int *verif)
{
    i = skip_spaces(i + 3, line);
	file->WE = ft_substr(line, i, skip_end_spaces(line) - i);
	*verif += 1;
}

void stock_EA(t_pars *file, int i, char *line, int *verif)
{
    i = skip_spaces(i + 3, line);
	file->EA = ft_substr(line, i, skip_end_spaces(line) - i);
	*verif += 1;
}

int	verif_line2(char *line, int *verif, int *rgb_verif, t_pars *file)
{
    int i;
    
	i = skip_spaces(0, line);
    if(line[i] == 'F' && (line[i + 1]== ' ' 
        || line[i + 1] == '\t') && file->F == NULL)
    {
	    i = skip_spaces(i + 2, line);
	    file->F = ft_substr(line, i, skip_end_spaces(line) - i);
	    check_F_rgb_args(rgb_verif, file);
	    *verif += 1;
    }
	else if(line[i] == 'C' && (line[i + 1]== ' ' 
        || line[i + 1] == '\t') && file->C == NULL)
    {
        i = skip_spaces(i + 2, line);
	    file->C = ft_substr(line, i, skip_end_spaces(line) - i);
	    check_C_rgb_args(rgb_verif, file);
	    *verif += 1;
    }
	return(*verif);
}