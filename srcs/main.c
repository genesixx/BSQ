/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweeks <nweeks@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 09:51:08 by nweeks            #+#    #+#             */
/*   Updated: 2017/08/18 13:33:51 by nweeks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

void	ft_start_bsq(char *file)
{
	int		fd;
	t_map	*map;
	char	**grid;

	fd = ft_get_fd(file);
	if (fd == -1)
		return ;
	map = get_first_line(fd);
	if (map->valid_map == 0)
	{
		ft_putstr("map error\n", 2);
		return ;
	}
	grid = ft_parse(fd, map);
	if (!grid)
	{
		ft_putstr("map error\n", 2);
		return ;
	}
	ft_find_bsq(grid, map);
	ft_destroy(grid, map->height);
	free(map);
	close(fd);
}

int		main(int argc, char **argv)
{
	int		cur_file;

	cur_file = 0;
	while (++cur_file < argc)
	{
		if (cur_file != 1)
			ft_putstr("\n", 1);
		ft_start_bsq(argv[cur_file]);
	}
}
