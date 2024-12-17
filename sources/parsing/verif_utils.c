/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:29:05 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/12/17 20:01:23 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**get_copymap(int height, int width)
{
	char	**copy_map;
	int		i;
	int		j;

	copy_map = malloc(sizeof(char *) * (height + 3));
	if (!copy_map)
		return (NULL);
	i = 0;
	while (i < height + 2)
	{
		copy_map[i] = malloc(sizeof(char) * (width + 3));
		if (!copy_map[i])
		{
			while (--i >= 0)
				free(copy_map[i]);
			free(copy_map);
			return (NULL);
		}
		j = 0;
		while (j < width + 1)
			copy_map[i][j++] = '2';
		copy_map[i][j] = 0;
		i++;
	}
	return (copy_map[i] = 0, copy_map);
}

char	**mapcopymap(t_config *config, char **copy_map)
{
	int		i;
	int		j;
	int		k;
	bool	cant_read;

	i = 0;
	k = 1;
	while (i < config->map_height)
	{
		j = 0;
		cant_read = false;
		while (j < config->map_width)
		{
			if (!cant_read && !config->map[i][j])
				cant_read = true;
			if (!cant_read && config->map[i][j] != ' ' && config->map[i][j] != '\t' && config->map[i][j] != '\v' && config->map[i][j] != '	')
				copy_map[k][j] = config->map[i][j];
			else if (cant_read || (config->map[i][j] == ' ' || config->map[i][j] == '\t' || config->map[i][j] == '\v' || config->map[i][j] == '	'))
				copy_map[k][j] = '2';
			++j;
		}
		++k;
		++i;
	}
	return (free_map(config->map),copy_map);
}
