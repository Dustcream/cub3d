/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:04:24 by dmuller           #+#    #+#             */
/*   Updated: 2024/03/01 11:08:00 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*rep;

	if (start < (unsigned int)ft_strlen(s))
		len = len + start;
	if (len > (unsigned int)ft_strlen(s))
		len = (unsigned int)ft_strlen(s);
	if (start < len)
		rep = malloc(sizeof(char) * (len - start + 1));
	else
		rep = malloc(sizeof(char));
	if (rep == NULL)
		return (NULL);
	i = start;
	while (i < len && s[i] != '\0')
	{
		rep[i - start] = s[i];
		i++;
	}
	rep[i - start] = '\0';
	return (rep);
}

int	skip_spaces(int i, char *line)
{
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (i);
}

int	skip_end_spaces(char *line)
{
	int	i;

	i = ft_strlen(line) - 1;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		i--;
	return (i + 1);
}

int	ft_atoi(const char *str)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 1;
	c = 0;
	while (str[a] == '\t' || str[a] == '\n' || str[a] == '\v'
		|| str[a] == '\f' || str[a] == '\r' || str[a] == ' ')
		a++;
	if (str[a] == '-')
		b = -1;
	if (str[a] == '-' || str[a] == '+')
		a++;
	while (ft_isdigit(str[a]) && str[a])
		c = (c * 10) + (str[a++] - '0');
	return (c * b);
}
