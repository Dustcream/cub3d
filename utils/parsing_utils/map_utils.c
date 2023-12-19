/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:45:50 by dmuller           #+#    #+#             */
/*   Updated: 2023/12/19 13:08:33 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_map(char *path, t_pars *file)
{
	int fd;
    char *line;
    int i;
    
    fd = open(path, O_RDONLY);
    line = get_next_line(fd);
    i = skip_spaces(0, line);
    while(line[i] != '1' || line[i] != '0' || line[i] != 'N' || line[i] != 'W' || line[i] != 'O' || line[i] != 'E')
    {
        free(line);
        line = get_next_line(fd);
        i = skip_spaces(0, line);
    }
    copy_map(fd); 
    return(1);
}

char	**copy_map(int fd)
{
	char	**rep;
	char	*buf;
	int		j;

	j = 0;
	buf = get_next_line(fd);
	rep = malloc(sizeof(char *) * get_whpp(fd)[1] + 1);
	if (!rep)
		return (NULL);
	while (buf != NULL)
	{
		rep[j++] = ft_substr(buf, 0, ft_strlen(buf) - 1);
		buf = get_next_line(fd);
	}
	rep[j] = NULL;
	return (rep);
}


int	*get_whpp(int fd)
{
	t_stuff	a;

	a.wd = malloc(sizeof(int) * 4);
	if (!a.wd)
		return (NULL);
	mini_init(&a.h, &a.fd, fd, &a.buf);
	if (in('P', a.buf) != -1)
	{
		a.wd[2] = in('P', a.buf);
		a.wd[3] = a.h;
	}
	a.wd[0] = ft_strlen(a.buf) - 1;
	while (a.buf != NULL && a.buf[0] != '\n')
	{
		if (in('P', a.buf) != -1)
		{
			a.wd[2] = in('P', a.buf);
			a.wd[3] = a.h;
		}
		a.buf = get_next_line(a.fd);
		a.h++;
	}
	free(a.buf);
	a.wd[1] = a.h;
	return (a.wd);
}

void	mini_init(int *h, int *fdd, int fd, char **buf)
{
	char	c;
	int		fakefd;

	fakefd = s_open(fd);
	if (!read(fakefd, &c, 1))
	{
		printf("Error\nEmpty Map.\n");
		close(fakefd);
		exit(0);
	}
	close(fakefd);
	*h = 0;
	*fdd = s_open(fd);
	*buf = get_next_line(*fdd);
}

int	s_open(char *path)
{
	int	fd;

	fd = open(path, O_RDWR);
	if (fd == -1)
	{
		printf("Error\nCouldn't open the map.\n");
		exit(-1);
	}
	return (fd);
}