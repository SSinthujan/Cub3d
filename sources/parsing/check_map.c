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
			return (free(line), printf("Error\nMemory allocation failed\n"),
				NULL);
		free(line);
	}
	return (str);
}

int	check_map(t_data *cub)
{
	char *map_str;
	// char **map;

	map_str = read_map(&cub->config.fd);
	if (!map_str)
		return (1);
	// map = ft_split(map_str, '\n');
	printf("%s", map_str);
	free(map_str);
	return (0);
}