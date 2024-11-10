/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:12:54 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/11/10 21:17:40 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void

// skip le NO (etc) prendre le str suivant et l'assigner a la texture correspondante
void	get_texture(t_config config, char *str)
{
}

void check_color(t_config, char *str)
{
	static	char *var[2] = {"F ", "C "};

}


// check str du tableau et verifier a quel NO (etc..) il correspond puis l'allouer dans la struct config
void	check_texture(t_config config, char *str)
{
	static char *wall[4] = {"NO ", "SE ", "WE ", "EA "};
	int i = 0;
	while (wall[i])
	{
		if (!ft_strncmp(str, wall[i], ft_strlen(wall[i])) && config.texture[i])
		{
			config.texture[i] = ft_split(str, ' ');
			if (ft_strlen(config.texture[i]) != 2)
				return (1);
			
		}
		else
			return (2);
		i++;
	}
	return (0);
}
