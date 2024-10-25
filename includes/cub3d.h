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

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define ceiling_color 0x1b4f08
# define floor_color 0x096a09

typedef struct s_texture {
	void	*img;
	int	*data;
	int	width;
	int	height;
}		t_texture;

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
	t_texture        north_texture;
	t_texture        south_texture;
	t_texture        west_texture;
	t_texture        east_texture;
}				t_data;

void			init_game(t_data *data);
int				close_window(t_data *data);

// parsing
int				check_namefile(char *str);

#endif
