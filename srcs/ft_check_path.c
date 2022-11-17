/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:27:56 by jperez            #+#    #+#             */
/*   Updated: 2022/11/17 15:59:21 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

t_node	*ft_check_neighbour(int i, int j, t_mem *mem, int k)
{
	int	cont;

	cont = 0;
	if (k == 0 && mem->map[i - 1][j] != '1' && mem->map[i - 1][j] == '2')
		return (ft_create_node(i - 1, j));
	else if (k == 1 && mem->map[i][j + 1] != '1' && mem->map[i][j + 1] == '2')
		return (ft_create_node(i, j + 1));
	else if (k == 2 && mem->map[i + 1][j] != '1' && mem->map[i + 1][j] == '2')
		return (ft_create_node(i + 1, j));
	else if (k == 2 && mem->map[i][j - 1] != '1' && mem->map[i][j - 1] == '2')
		return (ft_create_node(i, j - 1));
	else
		return (NULL);
}

void	ft_update_cont(t_mem, int i, int j, int *cont)
{
	if (mem->map[i][j] == 'C' || mem->maap[i][j] == 'E')
		(*cont)++;
}

void	ft_update_neighbours(t_queue *queue, t_mem *mem, int *cont)
{
	int	k;
	t_node	*neighbour;

	k = -1;
	while (++k < 4)
	{
		neighbour = ft_check_neighbour(queue->first->i, queue->first->j, mem, k);
		if (neighbour)
		{
			ft_enqueue(queue, neighbour);
			mem->map[neighbour->i][neighbour->j] = 2;
		}
	}
}

int	ft_check_path(t_mem *mem, int i, int j)
{
	t_queue	*queue;
	int		cont;

	queue = ft_create_queue();
	ft_enqueue(queue, ft_create_node(i, j));
	cont = 0;
	while (queue->first && cont < mem->collect + 1)
	{
		ft_update_neighbours(queue, mem, &cont);
	}
	return (0);
}
