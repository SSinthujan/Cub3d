/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:14:22 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/11/30 23:23:58 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	todo fonction init structure , init t_config rgb a -1 (look check_rgb)

	ETAPE 0
	verifier nom de map si il se termine bien par .cub --> check_mapname

	ETAPE 1
	ouvrir le fichier de la map 						}
	prendre les 6 premieres lignes non vides avec gnl	} ---> read_config
	si moins de 6 lignes -----> erreur					}
	check si il y a F C (pas d'ordre precis),
									pas de doublons --> erreur							}
	check si il y a NO SO WE EA (pas d'ordre precis),
							pas de doublons --> erreur 					}--> check.texture
	check si le rgb est composer de 3 nombres compris entre 0 et 255 separe par 2 virgules si oui   }
	check si le mpx file to img a fonctionner correctement si oui
						-> continue				}  pas sur
																non free tout et return 1 }  pas sur
		-> continue ETAPE 2
																non free tout et return 1

	ETAPE 2
	prendre la map avec gnl et la stocker
	gerer les espaces vides
	check map fermer
	check caractere valide : 1, 0, et N S E W pour le player mais pas de doublon

*/


int	plen(char **map)
{
	int	i;

	if (!map || !(*map))
		return (0);
	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	**join_tab(char **map, char *str)
{
	char	**res;
	int		i;

	res = malloc(sizeof(char *) * (plen(map) + 2));
	if (!res)
		return (NULL);
	if (!map || !(*map))
	{
		res[0] = str;
		res[1] = NULL;
		return (res);
	}
	i = 0;
	while (map[i])
	{
		res[i] = map[i];
		i++;
	}
	res[i++] = str;
	res[i] = NULL;
	return (res);
}

int	check_mapname(char *str)
{
	return (ft_strcmp(ft_strrchr(str, '.'), ".cub"));
}

int	read_map(t_data *cub, char *line)
{
	while (line)
	{
		if (!*line)
			return (1);
		cub->config.map = join_tab(cub->config.map, line);
		cub->config.length++;
		cub->config.map_width = max(cub->config.map_width, ft_strlen(line));
		line = get_next_line(cub->config.fd);
	}
	if (!cub->config.map_width)
		return (1);
	return (0);
}

//int check_map(t_dat)

