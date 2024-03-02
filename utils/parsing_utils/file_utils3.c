/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:50:22 by dmuller           #+#    #+#             */
/*   Updated: 2024/03/02 15:39:32 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_rgb_value2(t_pars *file)
{
	int		i;
	int		j;
	char	**number;

	i = 0;
	j = 0;
	number = ft_split(file->c, ',');
	while (number[i])
	{
		while (number[i][j])
		{
			if (!ft_isdigit(number[i][j]))
				return (0);
			j++;
		}
		if (j > 3)
			return (0);
		i++;
		j = 0;
	}
	return (1);
}

int	check_rgb_value1(t_pars *file)
{
	int		i;
	int		j;
	char	**number;

	i = 0;
	j = 0;
	number = ft_split(file->f, ',');
	while (number[i])
	{
		while (number[i][j])
		{
			if (!ft_isdigit(number[i][j]))
				return (0);
			j++;
		}
		if (j > 3)
			return (0);
		i++;
		j = 0;
	}
	return (1);
}

int	verif_line(char *line, int *verif, t_pars *file)
{
	int	i;

	i = skip_spaces(0, line);
	if (line[i] == '\t' || line[i] == '\n' || line[i] == '\v'
		|| line[i] == '\f' || line[i] == '\r' || line[i] == '1')
		*verif += 0;
	else if (line[i] == 'N' && line[i + 1] == 'O' && (line[i + 2] == ' '
			|| line[i + 2] == '\t') && file->no == NULL)
		savepos_no(file, i, line, verif);
	else if (line[i] == 'S' && line[i + 1] == 'O' && (line[i + 2] == ' '
			|| line[i + 2] == '\t') && file->so == NULL)
		savepos_so(file, i, line, verif);
	else if (line[i] == 'W' && line[i + 1] == 'E' && (line[i + 2] == ' '
			|| line[i + 2] == '\t') && file->we == NULL)
		savepos_we(file, i, line, verif);
	else if (line[i] == 'E' && line[i + 1] == 'A' && (line[i + 2] == ' '
			|| line[i + 2] == '\t') && file->ea == NULL)
		savepos_ea(file, i, line, verif);
	else if ((line[i] == 'F' && (line[i + 1] == ' ' || line[i + 1] == '\t')
			&& file->f == NULL) || (line[i] == 'C' && (line[i + 1] == ' '
				|| line[i + 1] == '\t') && file->c == NULL))
		verif += 0;
	else
		*verif += 1;
	return (*verif);
}

void	savepos_no(t_pars *file, int i, char *line, int *verif)
{
	i = skip_spaces(i + 3, line);
	file->no = ft_substr(line, i, skip_end_spaces(line) - i);
	*verif += 1;
}

void	savepos_so(t_pars *file, int i, char *line, int *verif)
{
	i = skip_spaces(i + 3, line);
	file->so = ft_substr(line, i, skip_end_spaces(line) - i);
	*verif += 1;
}
