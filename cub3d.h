/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:09:44 by dmuller           #+#    #+#             */
/*   Updated: 2024/02/29 18:45:54 by dmuller          ###   ########.fr       */
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
    char *NO;
    char *SO;
    char *WE;
    char *EA;
    char *F;
    char *C;
    char **map;
}   t_pars;

/* ================== */

/* ---- [ srcs ] ---- */

/* ---- [ error ] ---- */

/* ---- [ error_manager.c ] ----*/

/* ---- [ parsing ] ---- */

/* ---- [ file_parsing.c ] ---- */

int		check_args(int argc);
int		check_map(char *path, t_pars *file);

/* ================== */

/* ---- [ utils ] ---- */

/* ---- [ little_func ] ---- */

/* ---- [ little_func.c ] ---- */

int		ft_strcmp(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int     skip_spaces(int i, char *line);
int     skip_end_spaces(char *line);
int     ft_atoi(const char *str);

/* ---- [ little_func2.c] ---- */

int	    wordcount(const char *s, char c, int opt, char **strs);
int	    wordlen(const char *s, char c, int i);
char	*putword(const char *str, char charset, int i);
char	**split2(const char *str, char charset, int j, int i);
char	**ft_split(const char *str, char charset);

/* ---- [ little_func3.c] ---- */

int	    ft_isdigit(int c);
char	*ft_strdup(char *s1);

/* ---- [ parsing utils ] ---- */

/* ---- [ file_utils.c ] ---- */

int		check_cub(char *path);
int		check_file(char *path);
int		check_directory(char *path);
int     check_file_args(char *path, t_pars *file);
int     args_utils(char *path, int *verif, int *rgb_verif, t_pars *file);


/* ---- [ file_utils2.c ] ---- */

int     check_F_rgb_args(int *rgb_verif, t_pars *file);
int     check_C_rgb_args(int *rgb_verif, t_pars *file);
int     check_C_comma(t_pars *file);
int     check_F_comma(t_pars *file);

/* ---- [ file_utils3.c ] ---- */

int     check_F_rgb_value(t_pars *file);
int     check_C_rgb_value(t_pars *file);
int     verif_line(char *line, int *verif, t_pars *file);
void	stock_NO(t_pars *file, int i, char *line, int *verif);
void	stock_SO(t_pars *file, int i, char *line, int *verif);	

/* ---- [ file_utils4.c ] ---- */

void	stock_WE(t_pars *file, int i, char *line, int *verif);
void	stock_EA(t_pars *file, int i, char *line, int *verif);
int		verif_line2(char *line, int *verif, int *rgb_verif, t_pars *file);

/* ---- [ map_utils.c ] ---- */

int     map_copy(char *path, t_pars *file);
void    skip_no_map(char **line, t_pars *file, int fd);
int     check_map_format(t_pars *file);
int     is_valid_char(t_pars *file, int i, int x);
int		is_map_character(char c);

/* ================== */

/* ---- [ cub3d.c ] ---- */

int		main(int argc, char **argv);

/* ================== */

#endif