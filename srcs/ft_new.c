/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:27:42 by jperez            #+#    #+#             */
/*   Updated: 2022/11/24 19:30:12 by jperez           ###   ########.fr       */
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

void	ft_init_game(t_mem *mem)
{
	int	width;

	width = ft_strlen(mem->map[0]) - 1;
	mem->game = (t_game *)malloc(sizeof(t_game));
	ft_new_game(mem->game);
	ft_new_window(mem->game, width *  32, mem->map_len * 32);
	mem->game->cont = 0;
	mem->game->exit = 0;
	mem->game->movements = 0;
}
