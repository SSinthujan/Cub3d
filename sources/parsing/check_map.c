/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:14:22 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/12/18 03:32:33 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_map(int *fd)
{
	char	*str;
	char	*line;
	int		i;

	i = 0;
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
	while (str[i++])
	{
		if (!ft_strchr2(" 012NSWE\n", str[i]))
			return (free(str),
				printf("Error\nMap incorrect (undesired char)\n"), NULL);
	}
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

	i = 0;
	while (map[++i])
	{
		j = 1;
		while (map[i][j])
		{
			if (!is_player(map[i][j]))
			{
				if (config->player_orientation)
					return (printf("Error\nMap incorrect (player)\n"), 1);
				get_playerpos(config, i, j, map[i][j]);
			}
			if (map[i][j] == '0' || !is_player(map[i][j]))
			{
				if (map[i - 1][j] == '2' || map[i + 1][j] == '2' || map[i][j
					- 1] == '2' || map[i][j + 1] == '2')
					return (printf("Error\nMap incorrect (map open)\n"), 1);
			}
			++j;
		}
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
	if (check_format(config, copy_map))
		return (free_map(copy_map), 1);
	if (!config->player_orientation)
		return (free_map(copy_map),
			printf("Error\nMap incorrect (no player)\n"), 1);
	config->map = copy_map;
	return (0);
}

int more_than_one_nl(char *map)
{
	int i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			return (printf("Error\nEmpty lines in map\n"), 1);
		i++;
	}
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
	if (more_than_one_nl(map_str))
		return (free(map_str), 1);
	cub->config.map = ft_split(map_str, '\n');
	free(map_str);
	if (!cub->config.map)
		return (printf("Error\nMemory allocation failed (map)\n"), 1);
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
