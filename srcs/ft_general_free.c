/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:51:49 by jperez            #+#    #+#             */
/*   Updated: 2022/11/24 19:36:28 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

void	ft_free_2d_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

/*
void	ft_general_free(t_mem *mem)
{
	ft_free_2d_arr(mem->map);
	free(mem);
}
*/

void	ft_general_free(t_mem *mem, int on_off)
{
	ft_free_2d_arr(mem->map);
	free(mem->c_pos);
	if (on_off == 1 || on_off == 2)
		ft_end_game(mem->game);
	free(mem);
	if (on_off == 1)
		exit(-1);
}

int	ft_press_x(t_mem *mem)
{
	ft_general_free(mem, 2);
	return (0);
}
