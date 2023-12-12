/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:09:44 by dmuller           #+#    #+#             */
/*   Updated: 2023/12/12 13:27:44 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "gnl/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_pars
{
    bool NO;
    bool SO;
    bool WE;
    bool EA;
    bool F;
    bool C;
}   t_pars;

/* ================== */

/* ---- [ srcs ] ---- */

/* ---- [ error ] ---- */

/* ---- [ error_manager.c ] ----*/

/* ---- [ parsing ] ---- */

/* ---- [ file_parsing.c ] ---- */

int		check_args(int argc);
int		check_map(char *path);

/* ================== */

/* ---- [ utils ] ---- */

/* ---- [ little_func ] ---- */

/* ---- [ little_func.c ] ---- */

int		ft_strcmp(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* ---- [ parsing utils ] ---- */

/* ---- [ file_utils.c ] ---- */

int		check_cub(char *path);
int		check_file(char *path);
int		check_directory(char *path);

/* ================== */

/* ---- [ cub3d.c ] ---- */

int		main(int argc, char **argv);

/* ================== */

#endif