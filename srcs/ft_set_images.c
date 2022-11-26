/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:38:42 by jperez            #+#    #+#             */
/*   Updated: 2022/11/26 17:32:40 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

void	ft_get_images(t_game *game)
{
	int	width;
	int	height;

	game->imgs[0] = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/black_background.xpm", &width, &height);
	game->imgs[1] = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/wall.xpm", &width, &height);
	game->imgs[2] = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/ghost.xpm", &width, &height);
	game->imgs[3] = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/portal.xpm", &width, &height);
	game->imgs[4] = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/pac-man/pac_right.xpm", &width, &height);
	game->imgs[5] = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/pac-man/pac_left.xpm", &width, &height);
	game->imgs[6] = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/pac-man/pac_up.xpm", &width, &height);
	game->imgs[7] = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/pac-man/pac_down.xpm", &width, &height);
}

void	ft_print_images(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 32, y * 32);
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
				ft_print_images(game, game->imgs[0], x, y);
			else if (map[y][x] == '1')
				ft_print_images(game, game->imgs[1], x, y);
			else if (map[y][x] == 'c')
				ft_print_images(game, game->imgs[2], x, y);
			else if (map[y][x] == 'e')
				ft_print_images(game, game->imgs[3], x, y);
			else if (map[y][x] == 'P')
				ft_print_images(game, game->imgs[4], x, y);
		}
	}
	return (0);
}
