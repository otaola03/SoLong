/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:38:42 by jperez            #+#    #+#             */
/*   Updated: 2022/11/19 13:59:40 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

void	ft_get_images(t_game *game)
{
	int	width;
	int	height;

	game->imgs[0] = mlx_xpm_file_to_image(game->mlx, "/Users/jperez/Desktop/SoLong/sprites/black_background.xpm", &width, &height);
	game->imgs[1] = mlx_xpm_file_to_image(game->mlx, "/Users/jperez/Desktop/SoLong/sprites/wall.xpm", &width, &height);
	game->imgs[2] = mlx_xpm_file_to_image(game->mlx, "/Users/jperez/Desktop/SoLong/sprites/ghost.xpm", &width, &height);
	game->imgs[3] = mlx_xpm_file_to_image(game->mlx, "/Users/jperez/Desktop/SoLong/sprites/portal.xpm", &width, &height);
	game->imgs[4] = mlx_xpm_file_to_image(game->mlx, "/Users/jperez/Desktop/SoLong/sprites/pac-man/pac_right.xpm", &width, &height);
	game->imgs[5] = mlx_xpm_file_to_image(game->mlx, "/Users/jperez/Desktop/SoLong/sprites/pac-man/pac_left.xpm", &width, &height);
	game->imgs[6] = mlx_xpm_file_to_image(game->mlx, "/Users/jperez/Desktop/SoLong/sprites/pac-man/pac_up.xpm", &width, &height);
	game->imgs[7] = mlx_xpm_file_to_image(game->mlx, "/Users/jperez/Desktop/SoLong/sprites/pac-man/pac_down.xpm", &width, &height);
}

int	ft_set_images(t_game *game, char **map)
{
	int	x;
	int	y;

	ft_get_images(game);
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '0' || map[y][x] == '2')
				mlx_put_image_to_window(game->mlx, game->win, game->imgs[0], x * 32, y * 32);
			else if (map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->imgs[1], x * 32, y * 32);
			else if (map[y][x] == 'c')
				mlx_put_image_to_window(game->mlx, game->win, game->imgs[2], x * 32, y * 32);
			else if (map[y][x] == 'e')
				mlx_put_image_to_window(game->mlx, game->win, game->imgs[3], x * 32, y * 32);
			else if (map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->imgs[4], x * 32, y * 32);
		}
	}
	return (0);
}
