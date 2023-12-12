/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:10:09 by dmuller           #+#    #+#             */
/*   Updated: 2022/12/07 14:24:14 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);

int		found_newline(t_list *stash);
int		ft_strlen(const char *str);

t_list	*pointeur_stash(t_list *stash);

void	separateur(int fd, t_list **stash);
void	stockeur(t_list **stash, char *buf, int readed);
void	extracteur(t_list *stash, char **line);
void	len_stash(char **line, t_list *stash);
void	nettoyage(t_list **stash);
void	free_stash(t_list *stash);

#endif
