#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <float.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_player
{
	double		x;
	double		y;
	double		dirX;
	double		dirY;
	double planeX; // fov du joueur
	double		planeY;
}				t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_player	player;
}				t_data;

void			init_game(t_data *data);
int				close_window(t_data *data);

// parsing
int				check_namefile(char *str);

#endif
