/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:12:54 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/11/14 20:27:14 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_word(char *str)
{
	int	i;
	int j;
	int k;
	char *word;

	i = 0;
	while (!(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (!str[i])
		return (NULL);
	j = i;
	while (str[j] && !(str[j] == ' ' || (str[j] >= 9 && str[j] <= 13)))
		j++;
	word = malloc(sizeof(char *) * (j - i + 1));
	k = 0;
	while (i < j)
	{
		word[k] = str[i];
		i++;
		k++;
	}
	word[k] = '\0';
	return (word);
}

int	get_color(t_config config, char *str, int nbr)
{
	if (nbr == 1)
	{
		if (config.ceiling_color)
			return (1);
		config.ceiling_color = get_word(str);
	}
	else
	{
		if (config.floor_color)
			return (1);
		config.floor_color = get_word(str);
	}
	return (0);
}

// skip le NO (etc) prendre le str suivant et l'assigner a la texture correspondante
int	get_texture(t_config config, char *str, int nbr)
{
	if (nbr == 1)
	{
		if(config.north_texture)
			return (1);
		config.north_texture = get_word(str);
	}
	if (nbr == 2)
	{
		if(config.south_texture)
			return (1);
		config.south_texture = get_word(str);
	}
	if (nbr == 3)
	{
		if(config.east_texture)
			return (1);
		config.east_texture = get_word(str);
	}
	if (nbr == 4)
	{
		if(config.west_texture)
			return (1);
		config.west_texture = get_word(str);
	}
	return (0);
}

int	check_color(t_config config, char *str)
{
	if (!ft_strncmp(str, "C ", 2))
	{
		if (!get_color(config, str, 1))
			return (printf("Error\nMap texture\n", 1));
		return (0);
	}
	if (!ft_strncmp(str, "F ", 2))
	{
		if (!get_color(config, str, 2))
			return (printf("Error\nMap texture\n", 1));
		return (0);
	}
	return (1);
}

// check str du tableau et verifier a quel NO (etc..) il correspond puis l'allouer dans la struct config
int	check_texture(t_config config, char *str)
{
	if (!ft_strncmp(str, "NO ", 3))
	{
		if (!get_texture(config, str, 1))
			return (printf("Error\nMap texture\n", 1));
		return (0);
	}
	if (!ft_strncmp(str, "SO ", 3))
	{
		if (!get_texture(config, str, 2))
			return (printf("Error\nMap texture\n", 1));
		return (0);
	}
	if (!ft_strncmp(str, "EA ", 3))
	{
		if (!get_texture(config, str, 3))
			return (printf("Error\nMap texture\n", 1));
		return (0);
	}
	if (!ft_strncmp(str, "WE ", 3))
	{
		if (!get_texture(config, str, 4))
			return (printf("Error\nMap texture\n", 1));
		return (0);
	}
	return (1);
}
