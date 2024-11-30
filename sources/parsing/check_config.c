/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:20:15 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/11/26 23:41:27 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_emptyline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == ' ' || (line[i] >= 9 && line[i] <= 13)))
			return (0);
		i++;
	}
	return (1);
}

char	*count_elements(int i, char *str)
{
	if (i != 6)
	{
		free(str);
		printf("Error\nConfiguration incorrect\n");
		return (NULL);
	}
	return (str);
}

char	*read_config(char *map, int *fd)
{
	int		i;
	char	*str;
	char	*line;

	str = NULL;
	i = 0;
	*fd = open(map, O_RDONLY);
	if (*fd == -1)
		return (printf("Error\nCannot open the file\n"), NULL);
	while (i < 6)
	{
		line = get_next_line(*fd);
		if (!line)
			break ;
		if (!check_emptyline(line))
		{
			str = ft_strjoin2(str, line, ft_strlen(line));
			if (!str)
				return (free(line), printf("Error\nMemory allocation failed\n"),
					NULL);
			i++;
		}
		free(line);
	}
	return (count_elements(i, str));
}

// split la str dans un tableau de 6 pour check NO etc..
int	check_config(char *map, t_data *cub)
{
	char	**elements;
	char	*elements_str;
	int		i;

	i = 0;
	elements_str = read_config(map, &cub->config.fd);
	if (!elements_str)
	{
		if (cub->config.fd > 0)
			close(cub->config.fd);
		return (1);
	}
	elements = ft_split(elements_str, '\n');
	free(elements_str);
	while (i < 6)
	{
		if (check_texture(&cub->config, elements[i])
			&& check_color(&cub->config, elements[i]))
			return (close(cub->config.fd), free_tab(elements), 1);
				// free structure config
		else
			i++;
	}
	free_tab(elements);
	return (0);
}
