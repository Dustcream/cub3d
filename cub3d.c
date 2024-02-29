/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:33:09 by dmuller           #+#    #+#             */
/*   Updated: 2024/02/29 18:19:51 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_pars file;

	file.C = NULL;
	file.EA = NULL;
	file.F = NULL;
	file.NO = NULL;
	file.SO = NULL;
	file.WE = NULL; //faire une fonction pour mettre tout a NULL
	//file.map = NULL;
	if (!check_args(argc) || !check_map(argv[1], &file))
		exit(-1);
	printf("CA MARCHE\n");
	//faire une fonction pour free les char * C, EA,... (si different de nul alors free)
}
