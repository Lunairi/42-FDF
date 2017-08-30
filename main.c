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

// void *
// mlx_init(); <-- allows you to connect your program to graphic server

// man mlx
// man mlx_new_window

// need to compile with these flags
// gcc main.c fdf.h -L minilibx ./libft/libft.a -lmlx -framework OpenGL -framework AppKit -I minilibx -I libft

#include "fdf.h"

int		main(int ac, char **av)
{
	t_grid *map;
	t_map *init;
	t_coord *coord;

	if (ac != 2 || ((init = ft_memalloc(sizeof(t_map))) == NULL)
		|| ((map = ft_memalloc(sizeof(t_grid))) == NULL)
		|| ((coord = ft_memalloc(sizeof(t_coord))) == NULL))
	{
		ft_putstr("You must provide one map file to be generated.");
		return (0);
	}
	map->map = ft_fdtostr(open(av[1], O_RDONLY));
	if(!(start_initialize(coord, init, map)))
		return (0);
	store_coord(coord, init, map);
	map->win = mlx_new_window(map->mlx, 1500, 1200, "Kill me please");
	initialize_draw(coord, init, map);
	mlx_key_hook(map->win, exit_map, map->mlx);
	mlx_loop(map->mlx);
	return (0);
}

