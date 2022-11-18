/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:27:56 by jperez            #+#    #+#             */
/*   Updated: 2022/11/18 13:45:54 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

int	ft_check_pos(int i, int j, char **map)
{
	if (map[i][j] == '1')
		return (1);
	else if (map[i][j] == '2')
		return (1);
	else if (map[i][j] == 'P' || map[i][j] == 'c' || map[i][j] == 'e')
		return (1);
	return (0);
}

t_node	*ft_check_neighbour(int i, int j, t_mem *mem)
{
	int	cont;

	cont = 0;
	if (!ft_check_pos(i - 1, j, mem->map))
		return (ft_create_node(i - 1, j));
	else if (!ft_check_pos(i, j + 1, mem->map))
		return (ft_create_node(i, j + 1));
	else if (!ft_check_pos(i + 1, j, mem->map))
		return (ft_create_node(i + 1, j));
	else if (!ft_check_pos(i, j - 1, mem->map))
		return (ft_create_node(i, j - 1));
	else
		return (NULL);
}

void	ft_update_neighbours(t_queue *queue, t_mem *mem, int *cont)
{
	int	k;
	t_node	*neighbour;

	k = -1;
	printf("I: %d\nJ: %d\n------------\n", queue->first->i, queue->first->j);
	while (++k < 4)
	{
		neighbour = ft_check_neighbour(queue->first->i, queue->first->j, mem);
		if (neighbour)
		{
			printf("K: %d\ni: %d\nj: %d\n\n", k, neighbour->i, neighbour->j);
			ft_enqueue(queue, neighbour);
			if (mem->map[neighbour->i][neighbour->j] == 'C' || mem->map[neighbour->i][neighbour->j] == 'E')
			{
				mem->map[neighbour->i][neighbour->j] += ('a' - 'A');
				(*cont)++;
			}
			else
				mem->map[neighbour->i][neighbour->j] = '2';
		}
	}
}

int	ft_check_path(t_mem *mem, int i, int j)
{
	t_queue	*queue;
	int		cont;
	int		k;

	queue = ft_create_queue();
	ft_enqueue(queue, ft_create_node(i, j));
	cont = 0;
	k = 0;
	while (queue->first && cont < mem->collect + 1)
	{
		ft_update_neighbours(queue, mem, &cont);
		ft_dequeue(queue);
		printf("cont: %d\n\n", cont);
		ft_print_map(mem->map);

		printf("====================\n\n");
	}
	if (cont == mem->collect + 1)
		return (0);
	return (1);
}
