/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:20:45 by dmuller           #+#    #+#             */
/*   Updated: 2023/12/14 13:43:15 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int check_F_rgb_args(int *rgb_verif, t_pars *file)
{
	char **rgb;
	int i;

	i = 0;
	if(!check_F_comma(file))
		return(0);
	if(!check_F_rgb_value(file))
		return(0);
	rgb = ft_split(file->F, ',');
	if(rgb[0] && rgb[1] && rgb[2])
	{
		if((ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[0]) > 255) || (ft_atoi(rgb[1]) < 0 || ft_atoi(rgb[1]) > 255) || (ft_atoi(rgb[2]) < 0 || ft_atoi(rgb[2]) > 255))
			return(0);
		*rgb_verif += 1;
	}
	while(rgb[i])
		free(rgb[i++]);
	free(rgb);
	return(*rgb_verif);
}

int check_C_rgb_args(int *rgb_verif, t_pars *file)
{
	char **rgb;
	int i;

	i = 0;
	if(!check_C_comma(file))
		return(0);
	if(!check_C_rgb_value(file))
		return(0);
	rgb = ft_split(file->C, ',');
	if((ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[0]) > 255) || (ft_atoi(rgb[1]) < 0 || ft_atoi(rgb[1]) > 255) || (ft_atoi(rgb[2]) < 0 || ft_atoi(rgb[2]) > 255))
		return(0);
	*rgb_verif += 1;
	while(rgb[i])
		free(rgb[i++]);
	free(rgb);
	return(*rgb_verif);
}

int	check_C_comma(t_pars *file)
{
	int i;
	int comma;

	i = 0;
	comma = 0;
	while(file->C[i])
	{
		if(file->C[i] == ',')
			comma++;
		i++;
	}
	if(comma == 2)
		return(1);
	return(0);
}

int	check_F_comma(t_pars *file)
{
	int i;
	int comma;

	i = 0;
	comma = 0;
	while(file->F[i])
	{
		if(file->F[i] == ',')
			comma++;
		i++;
	}
	if(comma == 2)
		return(1);
	return(0);
}