/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:50:22 by dmuller           #+#    #+#             */
/*   Updated: 2024/02/29 18:56:47 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int check_C_rgb_value(t_pars *file)
{
    int i;
    int j;
    char **number;

    i = 0;
    j = 0;
    number = ft_split(file->C, ',');
    while(number[i])
    {
        while(number[i][j])
        {
            if(!ft_isdigit(number[i][j]))
                return(0);
            j++;
        }
        if(j > 3)
            return(0);
        i++;
        j = 0;
    }
    return(1);
}

int check_F_rgb_value(t_pars *file)
{
    int i;
    int j;
    char **number;

    i = 0;
    j = 0;
    number = ft_split(file->F, ',');
    while(number[i])
    {
        while(number[i][j])
        {
            if(!ft_isdigit(number[i][j]))
                return(0);
            j++;
        }
        if(j > 3)
            return(0);
        i++;
        j = 0;
    }
    return(1);
}

int	verif_line(char *line, int *verif, t_pars *file)
{
	int i;
    
	i = skip_spaces(0, line);
	if (line[i] == '\t' || line[i] == '\n' || line[i] == '\v' 
        || line[i] == '\f' || line[i] == '\r' || line[i] == '1') 
        *verif += 0;
	else if(line[i] == 'N' && line[i + 1] == 'O' && (line[i+2] == ' ' 
        || line[i + 2] == '\t') && file->NO == NULL)
        stock_NO(file, i, line, verif);
	else if(line[i] == 'S' && line[i + 1] == 'O' && (line[i + 2]== ' ' 
        || line[i + 2] == '\t') && file->SO == NULL)
        stock_SO(file, i, line, verif);
	else if(line[i] == 'W' && line[i + 1] == 'E' && (line[i + 2]== ' ' 
        || line[i + 2] == '\t') && file->WE == NULL)
        stock_WE(file, i, line, verif);
	else if(line[i] == 'E' && line[i + 1] == 'A' && (line[i + 2]== ' ' 
        || line[i + 2] == '\t') && file->EA == NULL)
        stock_EA(file, i, line, verif);
	else if((line[i] == 'F' && (line[i + 1]== ' ' || line[i + 1] == '\t') 
        && file->F == NULL) || (line[i] == 'C' && (line[i + 1]== ' ' 
        || line[i + 1] == '\t') && file->C == NULL))
        verif += 0;
    else
		*verif += 1;
	return(*verif);
}

void	stock_NO(t_pars *file, int i, char *line, int *verif)
{
    i = skip_spaces(i + 3, line);
	file->NO = ft_substr(line, i, skip_end_spaces(line) - i);
	*verif += 1;
}

void	stock_SO(t_pars *file, int i, char *line, int *verif)
{
    i = skip_spaces(i + 3, line);
	file->SO = ft_substr(line, i, skip_end_spaces(line) - i);
	*verif += 1;
}
