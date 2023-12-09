/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:09:44 by dmuller           #+#    #+#             */
/*   Updated: 2023/12/09 21:31:52 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

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

size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* ---- [ parsing utils ] ---- */

/* ---- [ file_utils.c ] ---- */

int		check_cub(char *path);

/* ================== */

/* ---- [ cub3d.c ] ---- */

int		main(int argc, char **argv);

/* ================== */

#endif