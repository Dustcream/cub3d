/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:24:35 by dmuller           #+#    #+#             */
/*   Updated: 2024/03/02 15:41:15 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	savepos_we(t_pars *file, int i, char *line, int *verif)
{
	i = skip_spaces(i + 3, line);
	file->we = ft_substr(line, i, skip_end_spaces(line) - i);
	*verif += 1;
}

void	savepos_ea(t_pars *file, int i, char *line, int *verif)
{
	i = skip_spaces(i + 3, line);
	file->ea = ft_substr(line, i, skip_end_spaces(line) - i);
	*verif += 1;
}

int	verif_line2(char *line, int *verif, int *rgb_verif, t_pars *file)
{
	int	i;

	i = skip_spaces(0, line);
	if (line[i] == 'F' && (line[i + 1] == ' '
			|| line[i + 1] == '\t') && file->f == NULL)
	{
		i = skip_spaces(i + 2, line);
		file->f = ft_substr(line, i, skip_end_spaces(line) - i);
		check_rgb_args1(rgb_verif, file);
		*verif += 1;
	}
	else if (line[i] == 'C' && (line[i + 1] == ' '
			|| line[i + 1] == '\t') && file->c == NULL)
	{
		i = skip_spaces(i + 2, line);
		file->c = ft_substr(line, i, skip_end_spaces(line) - i);
		check_rgb_args2(rgb_verif, file);
		*verif += 1;
	}
	return (*verif);
}
