/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:48:55 by jperez            #+#    #+#             */
/*   Updated: 2022/11/14 17:05:44 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

void	ft_end_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
//	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit(-1);
}

int	ft_close_window(int keycode, void *param)
{
	t_game *game;

	game = param;
	if (keycode == 53)
		ft_end_game(game);
	return (0);
}
