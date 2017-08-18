/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweeks <nweeks@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 10:10:56 by nweeks            #+#    #+#             */
/*   Updated: 2017/08/18 13:32:23 by nweeks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	ft_read_int(int fd, int *number)
{
	char	c;

	while ((read(fd, &c, 1)) && c >= '0' && c <= '9')
		*number = *number * 10 + c - 48;
	return (c);
}

void	ft_putstr(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

void	ft_destroy(char **to_free, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
		free(to_free[i++]);
	free(to_free);
}

char	*ft_strdup(char *str, int len)
{
	char	*ret;
	int		cur;

	if (!(ret = malloc((len + 1) * sizeof(char))))
		return (NULL);
	cur = -1;
	while (++cur < len)
		ret[cur] = str[cur];
	ret[cur] = 0;
	return (ret);
}

void	ft_memset(char **grid, int *line, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (grid[0][i] == map->vide)
			line[i] = 1;
		else
			line[i] = 0;
		++i;
	}
}
