/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 06:58:05 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/06 06:58:43 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_strchr(const char *str, int c)
// {
// 	size_t	i;

// 	i = 0;
// 	if (str)
// 	{	
// 		while (str[i])
// 		{
// 			if (str[i] == (unsigned char)c)
// 				return (1);
// 			i++;
// 		}
// 	}
// 	return (0);
// }

char	*ft_strchr2(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

