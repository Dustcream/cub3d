/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:33:09 by dmuller           #+#    #+#             */
/*   Updated: 2024/03/01 11:36:41 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_pars	file;

	file.c = NULL;
	file.ea = NULL;
	file.f = NULL;
	file.no = NULL;
	file.so = NULL;
	file.we = NULL;
	if (!check_args(argc) || !check_map(argv[1], &file))
		exit(-1);
	printf("CA MARCHE\n");
}
