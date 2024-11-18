/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:33:04 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/11/18 19:09:36 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	read_cub(t_data *cube)
{
	char	*line;
	int		c;

	c = 0;
	// int		i;
	// int		j;
	if (!check_extension(cube->av[2]))
		return (ft_putstr_fd("Error\nWrong file extension\n", 1), 0);
	// i = 0;
	// j = nb_ligne(cube->av[2]);
	cube->fd = open(cube->av[2], O_RDONLY, 0664);
	// cube->map = ft_calloc(j + 1, sizeof(char *));
	while (1)
	{
		line = get_next_line(cube->fd);
		c++;
		if (!line)
			break ;
		if (!get_info(cube, line))
			return (0);
		if (c < 8)
		{
			free(line);
			continue ;
		}
		if (strchr(line, '1') == 0)
			break ;
		free(line);
		c++;
	}
	// if (!init_init(cube))
	// 	return (0);
	return (1);
}
