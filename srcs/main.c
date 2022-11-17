/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:05:21 by jperez            #+#    #+#             */
/*   Updated: 2022/11/17 21:09:23 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

int	main(int argc, char **argv)
{
//	t_game *game;
	t_mem *mem;
//	int	height, width;
//	void	*img;

	if (argc != 2)
		return (1);
	mem = (t_mem *)malloc(sizeof(t_mem));
	ft_save_map(*(++argv), mem);
	printf("%d\n", ft_check_map(mem));
	printf("p_pos[0]: %d\np_pos[1]: %d\n\n", mem->p_pos[0], mem->p_pos[1]);
	printf("%d\n", ft_check_path(mem, mem->p_pos[0], mem->p_pos[1]));


	/*
	game = (t_game *)malloc(sizeof(game));
	ft_new_game(game);
	ft_new_window(game, 600, 300);
//	img = mlx_xpm_file_to_image(game->mlx, "/Users/jperez/Desktop/SoLong/sprites/ghost_right_red.xpm", &width, &height);
//	mlx_put_image_to_window(game->mlx, game->win, img, 0, 0);
	mlx_key_hook(game->win, ft_close_window, game);
	mlx_loop(game->mlx);
	*/
	return (0);
}
