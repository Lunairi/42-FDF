/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_final(t_coord *coord, t_map *init, t_grid *map, t_draw draw)
{
	if (abs(coord->color[draw.a]) > 71 && abs(coord->color[draw.a]) <= 78)
		mlx_pixel_put(map->mlx, map->win,
			(draw.x + init->center), (draw.y + init->align), BLUE);
	else if (abs(coord->color[draw.a]) > 78 && abs(coord->color[draw.a]) <= 85)
		mlx_pixel_put(map->mlx, map->win,
			(draw.x + init->center), (draw.y + init->align), NAVY);
	else if (abs(coord->color[draw.a]) > 85 && abs(coord->color[draw.a]) <= 92)
		mlx_pixel_put(map->mlx, map->win,
			(draw.x + init->center), (draw.y + init->align), FUCHSIA);
	else if (abs(coord->color[draw.a]) > 92)
		mlx_pixel_put(map->mlx, map->win,
			(draw.x + init->center), (draw.y + init->align), PURPLE);
}

void	draw_next(t_coord *coord, t_map *init, t_grid *map, t_draw draw)
{
	if (abs(coord->color[draw.a]) > 18 && abs(coord->color[draw.a]) <= 25)
		mlx_pixel_put(map->mlx, map->win,
			(draw.x + init->center), (draw.y + init->align), MAROON);
	else if (abs(coord->color[draw.a]) > 24 && abs(coord->color[draw.a]) <= 32)
		mlx_pixel_put(map->mlx, map->win,
			(draw.x + init->center), (draw.y + init->align), YELLOW);
	else if (abs(coord->color[draw.a]) > 32 && abs(coord->color[draw.a]) <= 40)
		mlx_pixel_put(map->mlx, map->win,
			(draw.x + init->center), (draw.y + init->align), OLIVE);
	else if (abs(coord->color[draw.a]) > 40 && abs(coord->color[draw.a]) <= 47)
		mlx_pixel_put(map->mlx, map->win,
			(draw.x + init->center), (draw.y + init->align), LIME);
	else if (abs(coord->color[draw.a]) > 47 && abs(coord->color[draw.a]) <= 55)
		mlx_pixel_put(map->mlx, map->win,
			(draw.x + init->center), (draw.y + init->align), GREEN);
	else if (abs(coord->color[draw.a]) > 55 && abs(coord->color[draw.a]) <= 63)
		mlx_pixel_put(map->mlx, map->win,
			(draw.x + init->center), (draw.y + init->align), AQUA);
	else if (abs(coord->color[draw.a]) > 63 && abs(coord->color[draw.a]) <= 71)
		mlx_pixel_put(map->mlx, map->win,
			(draw.x + init->center), (draw.y + init->align), TEAL);
	else
		draw_final(coord, init, map, draw);
}

void	draw_image(t_coord *coord, t_map *init, t_grid *map, t_draw draw)
{
	if (abs(coord->color[draw.a]) >= 0 && abs(coord->color[draw.a]) <= 2)
		mlx_pixel_put(map->mlx, map->win,
			(draw.x + init->center), (draw.y + init->align), WHITE);
	else if (abs(coord->color[draw.a]) > 2 && abs(coord->color[draw.a]) <= 4)
		mlx_pixel_put(map->mlx, map->win,
			(draw.x + init->center), (draw.y + init->align), LIGHTGRAY);
	else if (abs(coord->color[draw.a]) > 4 && abs(coord->color[draw.a]) <= 6)
		mlx_pixel_put(map->mlx, map->win,
			(draw.x + init->center), (draw.y + init->align), DARKGRAY);
	else if (abs(coord->color[draw.a]) > 6 && abs(coord->color[draw.a]) <= 8)
		mlx_pixel_put(map->mlx, map->win,
			(draw.x + init->center), (draw.y + init->align), LIGHTCORAL);
	else if (abs(coord->color[draw.a]) > 8 && abs(coord->color[draw.a]) <= 10)
		mlx_pixel_put(map->mlx, map->win,
			(draw.x + init->center), (draw.y + init->align), SALMON);
	else if (abs(coord->color[draw.a]) > 10 && abs(coord->color[draw.a]) <= 12)
		mlx_pixel_put(map->mlx, map->win,
			(draw.x + init->center), (draw.y + init->align), LIGHTSALMON);
	else if (abs(coord->color[draw.a]) > 12 && abs(coord->color[draw.a]) <= 18)
		mlx_pixel_put(map->mlx, map->win,
			(draw.x + init->center), (draw.y + init->align), RED);
	else
		draw_next(coord, init, map, draw);
}
