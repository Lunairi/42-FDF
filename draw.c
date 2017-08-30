/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_segment(t_coord *coord, t_map *init, t_grid *map, t_draw draw)
{
	while (draw.i++ < draw.dx)
	{
		draw_image(coord, init, map, draw);
		while (draw.p >= 0)
		{
			draw.p = draw.p - (2 * draw.dx);
			if (draw.swap)
				draw.x += draw.s1;
			else
				draw.y += draw.s2;
		}
		draw.p = draw.p + (2 * draw.dy);
		if (draw.swap)
			draw.y += draw.s2;
		else
			draw.x += draw.s1;
	}
	draw_image(coord, init, map, draw);
}

void	draw_pixel(t_coord *coord, t_map *init, t_grid *map, t_draw draw)
{
	draw_image(coord, init, map, draw);
	if (draw.dy > draw.dx)
	{
		draw.temp = draw.dx;
		draw.dx = draw.dy;
		draw.dy = draw.temp;
		draw.swap = 1;
	}
	draw.p = 2 * draw.dy - draw.dx;
	draw.i = 0;
	draw_segment(coord, init, map, draw);
}

void	draw_col(t_coord *coord, t_map *init, t_grid *map, int a)
{
	t_draw draw;

	draw.a = a;
	draw.dx = abs(coord->x[a + init->row] - coord->x[a]);
	draw.dy = abs(coord->y[a + init->row] - coord->y[a]);
	draw.x = coord->x[a];
	draw.y = coord->y[a];
	draw.s1 = sign(coord->x[a + init->row] - coord->x[a]);
	draw.s2 = sign(coord->y[a + init->row] - coord->y[a]);
	draw.swap = 0;
	draw_pixel(coord, init, map, draw);
}

void	draw_row(t_coord *coord, t_map *init, t_grid *map, int a)
{
	t_draw draw;

	draw.a = a;
	draw.dx = abs(coord->x[a + 1] - coord->x[a]);
	draw.dy = abs(coord->y[a + 1] - coord->y[a]);
	draw.x = coord->x[a];
	draw.y = coord->y[a];
	draw.s1 = sign(coord->x[a + 1] - coord->x[a]);
	draw.s2 = sign(coord->y[a + 1] - coord->y[a]);
	draw.swap = 0;
	draw_pixel(coord, init, map, draw);
}
