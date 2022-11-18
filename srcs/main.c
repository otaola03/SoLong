/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:05:21 by jperez            #+#    #+#             */
/*   Updated: 2022/11/18 17:52:18 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

int	main(int argc, char **argv)
{
	t_mem *mem;

	if (argc != 2)
		return (1);
	mem = (t_mem *)malloc(sizeof(t_mem));
	ft_save_map(*(++argv), mem);
	if (ft_check_map(mem) || ft_check_path(mem, mem->p_pos[0], mem->p_pos[1]))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	mem->game = (t_game *)malloc(sizeof(t_game));
	ft_new_game(mem->game);
	ft_new_window(mem->game, 600, 300);
	mlx_key_hook(mem->game->win, ft_close_window, mem->game);
//	mlx_loop(mem->game->mlx);
	ft_general_free(mem);
	return (0);
}
