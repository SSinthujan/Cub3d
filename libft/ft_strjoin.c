/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 06:36:18 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/06 08:30:00 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	int		len;
// 	int		i;
// 	int		j;
// 	char	*str;

// 	if (s1 == NULL || s2 == NULL)
// 		return (NULL);
// 	len = ft_strlen(s1) + ft_strlen(s2);
// 	str = malloc(sizeof(char) * (len + 1));
// 	if (str == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i] != '\0')
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j] != '\0')
// 		str[i++] = s2[j++];
// 	str[i] = '\0';
// 	return (str);
// }

char	*ft_strjoin2(char *s1, char *s2, int len)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (ft_strdup(s2));
	i = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(sizeof(char) * (i + 1));
	if (!(s3))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] && j < (size_t)len)
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (free(s1), s3);
}