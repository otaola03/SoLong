/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:05:21 by jperez            #+#    #+#             */
/*   Updated: 2022/11/28 18:28:55 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

int	main(int argc, char **argv)
{
	t_mem	*mem;

	if (argc != 2)
		return (1);
	mem = (t_mem *)malloc(sizeof(t_mem));
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) || \
		ft_save_map(argv[1], mem) || ft_check_map(mem) || \
		ft_check_path(mem, mem->p_pos[0], mem->p_pos[1]))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	ft_init_game(mem);
	ft_set_images(mem->game, mem->map);
	mlx_key_hook(mem->game->win, ft_key_hook, mem);
	mlx_hook(mem->game->win, 17, 1L << 17, ft_press_x, mem);
	mlx_loop(mem->game->mlx);
	return (0);
}
