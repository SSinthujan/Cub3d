/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:14:22 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/12/17 20:06:18 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_map(int *fd)
{
	char	*str;
	char	*line;

	str = NULL;
	while (1)
	{
		line = get_next_line(*fd);
		if (!line)
			break ;
		str = ft_strjoin2(str, line, ft_strlen(line));
		if (!str)
			return (free(line),
				printf("Error\nMemory allocation failed (map str)\n"), NULL);
		free(line);
	}
	close(*fd);
	return (str);
}

void	get_dimension(t_config *config)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	width = 0;
	while (config->map[i])
	{
		j = 0;
		while (config->map[i][j])
		{
			if (j > width)
				width = j;
			j++;
		}
		i++;
	}
	config->map_height = i;
	config->map_width = width + 1;
}

int	check_format(t_config *config, char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'O' || map[i][j] == 'W'
				|| map[i][j] == 'E')
			{
				if (config->player_orientation)
					return (printf("Error\nMap incorrect (player)\n"), 1);
				config->player_orientation = map[i][j];
				config->player_x = j;
				config->player_y = i;
			}
			else if (map[i][j] == '0')
			{
				if (map[i - 1][j] == '2' || map[i + 1][j] == '2' || map[i][j
					- 1] == '2' || map[i][j + 1] == '2')
					return (printf("Error\nMap incorrect (map open)\n"), 1);
			}
			++j;
		}
		i++;
	}
	return (0);
}

int	verif_map(t_config *config)
{
	char	**copy_map;

	copy_map = get_copymap(config->map_height, config->map_width);
	if (!copy_map)
		return (printf("Error\nMemory allocation failed (copy_map)\n"), 1);
	mapcopymap(config, copy_map);
	print_map(copy_map);
	if (check_format(config, copy_map))
		return (free_map(copy_map), 1);
	config->map = copy_map;
	return (0);
}

int	check_map(t_data *cub)
{
	char	*map_str;
	int		i;
	int		j;

	map_str = read_map(&cub->config.fd);
	if (!map_str)
		return (1);
	cub->config.map = ft_split(map_str, '\n');
	free(map_str);
	if (!cub->config.map)
		return (printf("Error\nMemory allocation failed (map)"), 1);
	get_dimension(&cub->config);
	if (verif_map(&cub->config))
		return (1);
	i = -1;
	while (cub->config.map[++i])
	{
		j = -1;
		while (cub->config.map[i][++j])
			if (cub->config.map[i][j] == '2')
				cub->config.map[i][j] = '1';
	}
	return (0);
}
