/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	positive_single(t_coord *coord, t_map *init, t_grid *map, t_parse parse)
{
	coord->x[parse.a] = parse.x_axis * init->tile;
	coord->y[parse.a] = parse.y_axis * init->tile;
	coord->x[parse.a] = (coord->x[parse.a] * cos(0.6)
		- coord->y[parse.a] * sin(0.6));
	coord->y[parse.a] = (coord->x[parse.a] * sin(0.6)
		+ coord->y[parse.a] * cos(0.6));
	coord->z[parse.a] = (map->map[parse.i] - '0');
	coord->color[parse.a] = coord->z[parse.a];
	coord->y[parse.a] = (coord->y[parse.a] * cos(0.6)
		- coord->z[parse.a] * sin(0.6));
	coord->z[parse.a] = (coord->y[parse.a] * sin(0.6)
		+ coord->z[parse.a] * cos(0.6));
	parse.i = parse.i + 1;
}

void	positive_double(t_coord *coord, t_map *init, t_grid *map, t_parse parse)
{
	coord->x[parse.a] = parse.x_axis * init->tile;
	coord->y[parse.a] = parse.y_axis * init->tile;
	coord->x[parse.a] = (coord->x[parse.a] * cos(0.6)
		- coord->y[parse.a] * sin(0.6));
	coord->y[parse.a] = (coord->x[parse.a] * sin(0.6)
		+ coord->y[parse.a] * cos(0.6));
	coord->z[parse.a] = (((map->map[parse.i] - '0') * 10)
		+ (map->map[parse.i + 1] - '0'));
	coord->color[parse.a] = coord->z[parse.a];
	coord->y[parse.a] = (coord->y[parse.a] * cos(0.6)
		- coord->z[parse.a] * sin(0.6));
	coord->z[parse.a] = (coord->y[parse.a] * sin(0.6)
		+ coord->z[parse.a] * cos(0.6));
}

void	negative_double(t_coord *coord, t_map *init, t_grid *map, t_parse parse)
{
	coord->x[parse.a] = parse.x_axis * init->tile;
	coord->y[parse.a] = parse.y_axis * init->tile;
	coord->x[parse.a] = (coord->x[parse.a] * cos(0.6)
		- coord->y[parse.a] * sin(0.6));
	coord->y[parse.a] = (coord->x[parse.a] * sin(0.6)
		+ coord->y[parse.a] * cos(0.6));
	coord->z[parse.a] = (((map->map[parse.i + 1] - '0') * 10)
		+ (map->map[parse.i + 2] - '0')) * -1;
	coord->color[parse.a] = coord->z[parse.a];
	coord->y[parse.a] = (coord->y[parse.a] * cos(0.6)
		- coord->z[parse.a] * sin(0.6));
	coord->z[parse.a] = (coord->y[parse.a] * sin(0.6)
		+ coord->z[parse.a] * cos(0.6));
}

void	negative_single(t_coord *coord, t_map *init, t_grid *map, t_parse parse)
{
	coord->x[parse.a] = parse.x_axis * init->tile;
	coord->y[parse.a] = parse.y_axis * init->tile;
	coord->x[parse.a] = (coord->x[parse.a] * cos(0.6)
		- coord->y[parse.a] * sin(0.6));
	coord->y[parse.a] = (coord->x[parse.a] * sin(0.6)
		+ coord->y[parse.a] * cos(0.6));
	coord->z[parse.a] = (map->map[parse.i + 1] - '0') * -1;
	coord->color[parse.a] = coord->z[parse.a];
	coord->y[parse.a] = (coord->y[parse.a] * cos(0.6)
		- coord->z[parse.a] * sin(0.6));
	coord->z[parse.a] = (coord->y[parse.a] * sin(0.6)
		+ coord->z[parse.a] * cos(0.6));
}
