/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:12:54 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/11/26 23:12:57 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color(t_config *config, char *str, int nbr)
{
	char	*rgb_str;

	rgb_str = get_word(str);
	if (!rgb_str)
		return (1);
	if (nbr == 1 && !config->ceiling_set)
	{
		if (check_rgb(config->ceiling_color, rgb_str))
			return (free(rgb_str), 1);
		config->ceiling_set = 1;
	}
	if (nbr == 2 && !config->floor_set)
	{
		if (check_rgb(config->floor_color, rgb_str))
			return (free(rgb_str), 1);
		config->floor_set = 1;
	}
	free(rgb_str);
	return (0);
}

// skip le NO (etc) prendre le str suivant et l'assigner a la texture correspondante
int	get_texture(t_config *config, char *str, int nbr)
{
	if (nbr == 1)
	{
		if (config->north_texture)
			return (1);
		config->north_texture = get_word(str);
	}
	if (nbr == 2)
	{
		if (config->south_texture)
			return (1);
		config->south_texture = get_word(str);
	}
	if (nbr == 3)
	{
		if (config->east_texture)
			return (1);
		config->east_texture = get_word(str);
	}
	if (nbr == 4)
	{
		if (config->west_texture)
			return (1);
		config->west_texture = get_word(str);
	}
	return (0);
}

int	check_color(t_config *config, char *str)
{
	if (!ft_strncmp(str, "C ", 2))
	{
		if (!get_color(config, str, 1))
			return (printf("Error\nMap texture 1\n"), 1);
		return (0);
	}
	if (!ft_strncmp(str, "F ", 2))
	{
		if (!get_color(config, str, 2))
			return (printf("Error\nMap texture 2\n"), 1);
		return (0);
	}
	return ((printf("Error\nMap texture 3\n")), 1);
}

// check str du tableau et verifier a quel NO (etc..) il correspond puis l'allouer dans la struct config
int	check_texture(t_config *config, char *str)
{
	if (!ft_strncmp(str, "NO ", 3))
	{
		if (!get_texture(config, str, 1))
			return (printf("Error\nMap texture 4\n"), 1);
		return (0);
	}
	if (!ft_strncmp(str, "SO ", 3))
	{
		if (!get_texture(config, str, 2))
			return (printf("Error\nMap texture 5\n"), 1);
		return (0);
	}
	if (!ft_strncmp(str, "EA ", 3))
	{
		if (!get_texture(config, str, 3))
			return (printf("Error\nMap texture 6\n"), 1);
		return (0);
	}
	if (!ft_strncmp(str, "WE ", 3))
	{
		if (!get_texture(config, str, 4))
			return (printf("Error\nMap texture 7\n"), 1);
		return (0);
	}
	return (printf("Error\nMap texture 8\n"), 1);
}
