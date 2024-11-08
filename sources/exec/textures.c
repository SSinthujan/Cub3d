#include "cub3d.h"

t_texture *select_texture(t_data *data, t_ray *ray)
{
    if (ray->side == 1)
    {
        if (ray->ray_dir_y > 0)
            return (&data->north_texture);
        else
            return (&data->south_texture);
    }
    else
    {
        if (ray->ray_dir_x > 0)
            return (&data->west_texture);
        else
            return (&data->east_texture);
    }
}

void calculate_tex_x(t_draw *draw, t_ray *ray, t_texture *texture, double wall_x)
{
    draw->tex_x = (int)(wall_x * (double)texture->width);
    if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1 && ray->ray_dir_y < 0))
        draw->tex_x = texture->width - draw->tex_x - 1;
}

double calculate_perp_wall_dist(t_data *data, t_ray *ray)
{
    if (ray->side == 0)
        return ((ray->map_x - data->player.x + (1 - ray->step_x) / 2) / ray->ray_dir_x);
    else
        return ((ray->map_y - data->player.y + (1 - ray->step_y) / 2) / ray->ray_dir_y);
}

void calculate_draw_limits(t_draw *draw, int win_height)
{
    draw->draw_start = -draw->line_height / 2 + win_height / 2;
    if (draw->draw_start < 0)
        draw->draw_start = 0;
    draw->draw_end = draw->line_height / 2 + win_height / 2;
    if (draw->draw_end >= win_height)
        draw->draw_end = win_height - 1;
}

void draw_column(t_data *data, int x, t_draw *draw, t_texture *texture)
{
    int y;
    int tex_y;
    double tex_pos;
    double step;

    step = 1.0 * texture->height / draw->line_height;
    tex_pos = (draw->draw_start - WIN_HEIGHT / 2 + draw->line_height / 2) * step;
    y = draw->draw_start;
    while (y < draw->draw_end)
    {
        tex_y = (int)tex_pos % texture->height;
        tex_pos += step;
        int color = texture->data[tex_y * texture->width + draw->tex_x];
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
        y++;
    }
}
