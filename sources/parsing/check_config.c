/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:20:15 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/11/10 21:05:09 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//TODO: check si les parametre des fonctions *read_config/check_config sont les bonnes, elles doivent avoir en entree le fichier de la map 

int	check_emptyline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == ' ' || (line[i] >= 9 && line[i] <= 13)))
			return (1);
		i++;
	}
	return (0);
}

char *check_str(int i, char *str)
{
	if (i != 6)
	{
		free(str);
		printf("Error\nConfiguration incorrect\n");
		return (NULL);
	}
	return (str);
}

char	*read_config(char *map)
{
	int		fd;
	int		i;
	char	*str;
	char	*line;

	str = NULL;
	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (printf("Error\nCannot open the file\n"), NULL);
	while (i < 6)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (check_emptyline(line))
		{
			str = ft_strjoin2(str, line, ft_strlen(line));
			i++;
		}
		free(line);
	}
	close(fd);
	return (check_str(i, str));
}
void	free_tab(char **tab)
{
	int	i;

	i = 0;

	while (tab[i])
		free(tab[i++]);
	free(tab);
}

// split la str dans un tableau de 6 pour check NO etc..
int	check_config(char *map)
{
	char **elements;
	char *elements_str;
	int i;
	t_config config;

	i = 0;
	elements_str = read_config(map);
	if (!elements_str)
		return (1);
	elements = ft_split(elements_str, '\n');
	free(elements_str);
	//check chaque str du tableau et l'allouer dans une structure config
	while(i < 6)
	{
		// int isok = check_texture(config, elements[i]);
		// printf("is ok = %i\n", isok);
		// if (!isok)
		// 	break;
		// i++;
		if ()
		i++;
	}
	// check que i est bien 
	free_tab(elements);
	return (0);
}
