/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:14:22 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/12/16 04:28:08 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_mapname(char *str)
{
	return (ft_strcmp(ft_strrchr(str, '.'), ".cub"));
}
/*
	todo:

	check config incorrect -> check texture a verifier

	fonction recup largeur max et longueur max
	creer un double tableau de la taille longueur max largeur max
	fonction qui fait une copie de la map dans le double tableau et remplace les cases vide par 0 (sol)
	fonction qui check 	-> si ferme avec des 1
						-> si il a y a qu'un seul player
							-> recup sa position (X, Y) et orientation (N, O, S,
							W)
						-> pas coupé en 2

*/

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
			j++;
			if (j > width)
				width = j;
		}
		i++;
	}
	config->map_height = i;
	config->map_width = width;
}

char	**get_copymap(int height, int width)
{
	char	**copy_map;
	int		i;
	int		j;

	copy_map = malloc(sizeof(char *) * height);
	if (!copy_map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy_map[i] = malloc(sizeof(char) * (width + 1));
		if (!copy_map[i])
		{
			while (--i >= 0)
				free(copy_map[i]);
			free(copy_map);
			return (NULL);
		}
		j = 0;
		while (j < width)
			copy_map[i][j++] = '2';
		i++;
	}
	//     while (height--)
    // {
    //     copy_map[height] = malloc(sizeof(char) * (width + 1));
    //     if (!copy_map[height])
    //     {
    //         while (height >= 0)
    //             free(copy_map[height--]);
    //         free(copy_map);
    //         return (NULL);
    //     }
    //     memset(copy_map[height], '2', width);
    //     copy_map[height][width] = '\0';
    // }
	return (copy_map);
}

int	verif_map(char **map, int height, int width)
{
	char	**copy_map;
	int		i;
	int		j;

	copy_map = get_copymap(height, width);
	if (!copy_map)
		return (printf("Error\nMemory allocation failed (copy_map)\n"), 1);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] != ' ')
				copy_map[i][j] = map[i][j];
			else
				copy_map[i][j] = '2';
			j++;
		}
		copy_map[i][j] = '\0';
		i++;
	}
	print_map(copy_map);
	return (free_map(copy_map), 0);
}

int	check_map(t_data *cub)
{
	char	*map_str;

	map_str = read_map(&cub->config.fd);
	if (!map_str)
		return (1);
	cub->config.map = ft_split(map_str, '\n');
	free(map_str);
	if (!cub->config.map)
		return (printf("Error\nMemory allocation failed (map)"), 1);
	get_dimension(&cub->config);
	if (verif_map(cub->config.map, cub->config.map_height,
			cub->config.map_width))
		return (free_map(cub->config.map), 1);
	return (0);
}
