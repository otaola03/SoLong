/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:05:21 by jperez            #+#    #+#             */
/*   Updated: 2022/11/24 18:15:30 by jperez           ###   ########.fr       */
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
	ft_print_map(mem->map);
	ft_init_game(mem);
	mem->game->cont = 0;
	mem->game->exit = 0;
	mem->game->movements = 0;
	ft_set_images(mem->game, mem->map);
	mlx_key_hook(mem->game->win, ft_key_hook, mem);
	mlx_loop(mem->game->mlx);
	ft_general_free(mem, 0);
	return (0);
}
