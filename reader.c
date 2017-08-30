/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	store_positive(t_coord *coord, t_map *init, t_grid *map, t_parse *parse)
{
	if (ft_isdigit(map->map[parse->i + 1]))
	{
		positive_double(coord, init, map, *parse);
		parse->i = parse->i + 2;
		parse->x_axis++;
		parse->a++;
	}
	else
	{
		positive_single(coord, init, map, *parse);
		parse->x_axis++;
		parse->a++;
	}
}

void	store_negative(t_coord *coord, t_map *init, t_grid *map, t_parse *parse)
{
	if (ft_isdigit(map->map[parse->i + 1]))
	{
		if (ft_isdigit(map->map[parse->i + 2]))
		{
			negative_double(coord, init, map, *parse);
			parse->i = parse->i + 3;
			parse->x_axis++;
			parse->a++;
		}
		else
		{
			negative_single(coord, init, map, *parse);
			parse->i = parse->i + 2;
			parse->x_axis++;
			parse->a++;
		}
	}
}

void	store_coord(t_coord *coord, t_map *init, t_grid *map)
{
	t_parse parse;

	parse.i = 0;
	parse.x_axis = 0;
	parse.y_axis = 0;
	parse.a = 0;
	while (map->map[parse.i] != '\0')
	{
		if (ft_isdigit(map->map[parse.i]))
			store_positive(coord, init, map, &parse);
		if (map->map[parse.i] == '-')
			store_negative(coord, init, map, &parse);
		if (map->map[parse.i] == '\n')
		{
			parse.x_axis = 0;
			parse.y_axis++;
			parse.i = parse.i + 1;
		}
		else
			parse.i = parse.i + 1;
	}
}
