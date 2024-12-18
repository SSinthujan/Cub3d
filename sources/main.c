/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:22:57 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/12/18 03:21:16 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_mapname(char *str)
{
	return (ft_strcmp(ft_strrchr(str, '.'), ".cub"));
}

int	init_parse(int ac, char **av, t_data *cub)
{
	if (ac != 2)
		return (printf("Error\nFormat: ./cub3D <map_file.cub>\n"), 1);
	if (check_mapname(av[1]))
		return (printf("Error\nMap name incorrect\n"), 1);
	if (check_config(av[1], cub))
		return (1);
	if (check_map(cub))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	static t_data	cub = {0};

	if (init_parse(ac, av, &cub))
		return (1);
	if (init_game(&cub))
		return (1);
	handle_keyhook(&cub);
	mlx_loop_hook(cub.mlx_ptr, game_loop, &cub);
	mlx_loop(cub.mlx_ptr);
	return (0);
}

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
