/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:50:51 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/10/28 17:44:17 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
    t_data data;
    if (argc != 2)
        return (printf("Error\nFormat must be: ./cub3D <map_file.cub>\n"), 1);
    if (check_namefile(argv[2]))
        return (1);
    // if (parsing(&data, argv))
    //     return (1);
    init_game(&data);
    mlx_loop(data.mlx_ptr);
}
