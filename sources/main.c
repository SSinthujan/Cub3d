/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 05:50:53 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/11/26 05:50:55 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int init_parse(int ac, char **av, t_data *cub)
{
	if (ac != 2)
		return (printf("Error\nFormat: ./cub3D <map_file.cub>\n"), 1);
	if (check_mapname(av[1]))
		return (1);
	if (check_config(av[1], cub))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data cub = {0};
	if (init_parse(ac, av, &cub))
		return (1);
	return (0);
}
