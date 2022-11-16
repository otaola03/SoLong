/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:27:42 by jperez            #+#    #+#             */
/*   Updated: 2022/11/12 19:27:50 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

void	ft_new_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_end_game(game);
}

void	ft_new_window(t_game *game, int	width, int height)
{
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (game->win == NULL)
		ft_end_game(game);
}
