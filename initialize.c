/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize_draw(t_coord *coord, t_map *init, t_grid *map)
{
	t_vars vars;

	vars.i = -1;
	vars.j = 1;
	vars.k = 0;
	while (vars.i++ < ((init->row * init->col) - 2))
	{
		if (vars.j != init->row)
			draw_row(coord, init, map, vars.k);
		else
			vars.j = 0;
		vars.k++;
		vars.j++;
	}
	vars.i = -1;
	vars.j = 0;
	while (vars.i++ < ((init->row * init->col) - init->row) - 1)
	{
		draw_col(coord, init, map, vars.j);
		vars.j++;
	}
}

int		start_initialize(t_coord *coord, t_map *init, t_grid *map)
{
	map->mlx = mlx_init();
	init_coord(init, map);
	if (((coord->x = ft_memalloc(sizeof(int)
		* (init->row * init->col) + 1)) == NULL)
		|| ((coord->y = ft_memalloc(sizeof(int)
			* (init->row * init->col) + 1)) == NULL)
		|| ((coord->z = ft_memalloc(sizeof(int)
			* (init->row * init->col) + 1)) == NULL)
		|| ((coord->color = ft_memalloc(sizeof(int)
			* (init->row * init->col) + 1)) == NULL))
	{
		ft_putstr("Error initializing map. Try a different map.");
		return (0);
	}
	return (1);
}
