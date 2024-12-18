/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:59:20 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/12/18 03:05:59 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int another_word_after(char *str, int j)
{
	while (str[j])
	{
		if (!(str[j] == ' ' || (str[j] >= 9 && str[j] <= 13)))
			return (1);
		j++;
	}
	return (0);
}

char	*get_word(char *str, char *dest, int size)
{
	int	i;
	int	j;
	int	k;

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
	if (another_word_after(str, j))
		return (NULL);
	k = 0;
	while (i < j && k < size)
		dest[k++] = str[i++];
	dest[k] = '\0';
	if (i < j)
		return (NULL);
	return (dest);
}

int	is_comma(char c, int *comma, int *current, int *color)
{
	if (c == ',')
	{
		if (*comma)
			return (1);
		*comma = 1;
		(*current)++;
		if (*current > 2)
			return (1);
		color[*current] = 0;
	}
	return (0);
}

int	check_rgb(int *color, char *rgb)
{
	int	current;
	int	comma;

	current = 0;
	comma = 1;
	while (*rgb != '\0')
	{
		if (is_comma(*rgb, &comma, &current, color))
			return (1);
		if (*rgb == ',')
			rgb++;
		if (*rgb < '0' || *rgb > '9')
			return (1);
		else
		{
			color[current] = color[current] * 10 + (*rgb - '0');
			if (color[current] > 255)
				return (1);
			comma = 0;
		}
		rgb++;
	}
	return (current != 2 || comma);
}
