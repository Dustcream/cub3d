/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:33:38 by dmuller           #+#    #+#             */
/*   Updated: 2023/12/09 21:24:03 by dmuller          ###   ########.fr       */
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
