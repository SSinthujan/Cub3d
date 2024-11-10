/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:33:04 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/11/10 14:20:40 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	nb_ligne(char *file)
{
	int		fd;
	int		i;
	char	*ligne;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while (1)
	{
		ligne = get_next_line(fd);
		if (!ligne)
			break ;
		free(ligne);
		i++;
	}
	close(fd);
	return (i);
}

int	remove_space(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	return (0);
}

int	check_xpm(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (i < 5)
		return (0);
	i -= 4;
	while (line[i])
	{
		if (line[i] != ".xpm"[i])
			return (0);
		i++;
	}
	return (1);
}

int	get_path(t_cube *cube, char *line, char **way)
{
	int	x;
	int	y;

	if (!check_xpm(line))
		return (0);
	*way = mlx_xpm_file_to_image(cube->mlx, line, &x, &y);
	if (!*way)
		return (0);
	return (1);
}

int	get_info(t_cube *cube, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
	{
		if (!get_path(cube, line, &cube->texture.north))
			return (printf("Map error\n", 0));
		return (1);
	}
	if (!ft_strncmp(line, "SO ", 3))
	{
		if (!get_path(cube, line, &cube->texture.south))
			return (printf("Map error\n", 0));
		return (1);
	}
	if (!ft_strncmp(line, "EA ", 3))
	{
		if (!get_path(cube, line, &cube->texture.east))
			return (printf("Map error\n", 0));
		return (1);
	}
	if (!ft_strncmp(line, "WE ", 3))
	{
		if (!get_path(cube, line, &cube->texture.west))
			return (printf("Map error\n", 0));
		return (1);
	}
	if (!ft_strncmp(line, "C ", 2))
	{
		if (!get_path(cube, line, &cube->texture.ceiling))
			return (printf("Map error\n", 0));
		return (1);
	}
	if (!ft_strncmp(line, "F ", 2))
	{
		if (!get_path(cube, line, &cube->texture.floor))
			return (printf("Map error\n", 0));
		return (1);
	}
	return (0);
}

int	read_cub(t_cube *cube)
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
