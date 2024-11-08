/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:14:22 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/11/09 00:13:32 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	ETAPE 0
	verifier nom de map si il se termine bien par .cub

	ETAPE 1
	ouvrir le fichier de la map
	prendre les 6 premieres lignes non vides avec gnl
	si moins de 6 lignes -----> erreur
	check si il y a NO SO WE EA (pas d'ordre precis), pas de doublons --> erreur
	check si le mpx file to img a fonctionner correctement si oui -> continue
																non free tout et return 1
	check si il y a F C (pas d'ordre precis), pas de doublons --> erreur
	check si le rgb est composer de 3 nombres compris entre 0 et 255 separe par 2 virgules si oui
		-> continue ETAPE 2
																non free tout et return 1

	ETAPE 2
	prendre la map avec gnl et la stocker
	gerer les espaces vides
	check map fermer
	check caractere valide : 1, 0, et N S E W pour le player mais pas de doublon

*/

int	check_namefile(char *str)
{
	int	c;

	c = ft_strcmp(ft_strchr(str, '.'), ".cub");
	if (c)
	{
		printf("Error\nMap name incorrect\n");
		return (c);
	}
	return (0);
}

char	check_config(char *config)
{
	int		fd;
	int		i;
	char	*str;
	char	*line;

	str = NULL;
	i = 0;
	fd = open(config, O_RDONLY);
	if (fd == -1)
		return (printf("Error\nMap non-existent\n"), NULL);
	while (i < 6)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		str = ft_strjoin(str, line);
		free(line);
		if (!fonction qui check si une ligne est vide)
	}
	close(fd);
	return (str);
}
