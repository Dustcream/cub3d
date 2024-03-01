/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:20:45 by dmuller           #+#    #+#             */
/*   Updated: 2024/03/01 11:35:26 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_rgb_args1(int *rgb_verif, t_pars *file)
{
	char	**rgb;
	int		i;

	i = 0;
	if (!check_comma1(file))
		return (0);
	if (!check_rgb_value1(file))
		return (0);
	rgb = ft_split(file->f, ',');
	if (rgb[0] && rgb[1] && rgb[2])
	{
		if ((ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[0]) > 255)
			|| (ft_atoi(rgb[1]) < 0 || ft_atoi(rgb[1]) > 255)
			|| (ft_atoi(rgb[2]) < 0 || ft_atoi(rgb[2]) > 255))
			return (0);
		*rgb_verif += 1;
	}
	while (rgb[i])
		free(rgb[i++]);
	free(rgb);
	return (*rgb_verif);
}

int	check_rgb_args2(int *rgb_verif, t_pars *file)
{
	char	**rgb;
	int		i;

	i = 0;
	if (!check_comma2(file))
		return (0);
	if (!check_rgb_value2(file))
		return (0);
	rgb = ft_split(file->c, ',');
	if ((ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[0]) > 255)
		|| (ft_atoi(rgb[1]) < 0 || ft_atoi(rgb[1]) > 255)
		|| (ft_atoi(rgb[2]) < 0 || ft_atoi(rgb[2]) > 255))
		return (0);
	*rgb_verif += 1;
	while (rgb[i])
		free(rgb[i++]);
	free(rgb);
	return (*rgb_verif);
}

int	check_comma2(t_pars *file)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (file->c[i])
	{
		if (file->c[i] == ',')
			comma++;
		i++;
	}
	if (comma == 2)
		return (1);
	return (0);
}

int	check_comma1(t_pars *file)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (file->f[i])
	{
		if (file->f[i] == ',')
			comma++;
		i++;
	}
	if (comma == 2)
		return (1);
	return (0);
}
