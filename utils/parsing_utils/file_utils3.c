/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:50:22 by dmuller           #+#    #+#             */
/*   Updated: 2023/12/14 13:26:24 by dmuller          ###   ########.fr       */
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