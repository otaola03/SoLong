/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:49:54 by jperez            #+#    #+#             */
/*   Updated: 2022/11/20 20:04:01 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

int	ft_update_cont(t_mem *mem, int i, int j)
{
	if (mem->map[i][j] == 'c')
	{
		mem->map[i][j] = '2';
		mem->game->cont++;
		if (mem->game->cont == mem->collect)
			mem->game->exit = 1;
		return (1);
	}
	else if (mem->map[i][j] == 'e' && mem->game->exit != 1)
		return (2);
	else if (mem->map[i][j] == 'e' && mem->game->exit == 1)
		ft_end_game(mem->game);
	return (0);
}

void	ft_move(t_mem *mem, int i, int j, int k)
{
	int	status;

	status = ft_update_cont(mem, i, j);
	mlx_put_image_to_window(mem->game->mlx, mem->game->win, mem->game->imgs[0],\
		mem->p_pos[1] * 32, mem->p_pos[0] * 32);
	if (mem->map[mem->p_pos[0]][mem->p_pos[1]] == 'e')
		mlx_put_image_to_window(mem->game->mlx, mem->game->win, mem->game->imgs[3],\
			mem->p_pos[1] * 32, mem->p_pos[0] * 32);
	if (status == 1)
		mlx_put_image_to_window(mem->game->mlx, mem->game->win, mem->game->imgs[0], j * 32, i * 32);
	else if (status == 2)
		mlx_put_image_to_window(mem->game->mlx, mem->game->win, mem->game->imgs[3], j * 32, i * 32);
	mlx_put_image_to_window(mem->game->mlx, mem->game->win, mem->game->imgs[k], j * 32, i * 32);
	mem->p_pos[0] = i;
	mem->p_pos[1] = j;
}

int	ft_key_hook(int keycode, void *param)
{
	t_mem *mem;

	mem = param;
	printf("collect: %d\ncont: %d\n", mem->collect, mem->game->cont);
	if (keycode == 0 && mem->map[mem->p_pos[0]][mem->p_pos[1] - 1] != '1')
		ft_move(mem, mem->p_pos[0], mem->p_pos[1] - 1, 5);
	else if (keycode == 2 && mem->map[mem->p_pos[0]][mem->p_pos[1] + 1] != '1')
		ft_move(mem, mem->p_pos[0], mem->p_pos[1] + 1, 4);
	else if (keycode == 13 && mem->map[mem->p_pos[0] - 1][mem->p_pos[1]] != '1')
		ft_move(mem, mem->p_pos[0] - 1, mem->p_pos[1], 6);
	else if (keycode == 1 && mem->map[mem->p_pos[0] + 1][mem->p_pos[1]] != '1')
		ft_move(mem, mem->p_pos[0] + 1, mem->p_pos[1], 7);
	else if (keycode == 53)
		ft_end_game(mem->game);
	printf("cont: %d\n\n",mem->game->cont);
	return (0);
}
