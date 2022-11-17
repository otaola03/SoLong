/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:27:56 by jperez            #+#    #+#             */
/*   Updated: 2022/11/17 21:19:25 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

t_node	*ft_check_neighbour(int i, int j, t_mem *mem, int k)
{
	int	cont;

	cont = 0;
	if (k == 0 && mem->map[i - 1][j] != '1' && mem->map[i - 1][j] != '2' && mem->map[i - 1][j] != 'P')
		return (ft_create_node(i - 1, j));
	else if (k == 1 && mem->map[i][j + 1] != '1' && mem->map[i][j + 1] != '2' && mem->map[i][j + 1] != 'P')
		return (ft_create_node(i, j + 1));
	else if (k == 2 && mem->map[i + 1][j] != '1' && mem->map[i + 1][j] != '2' && mem->map[i + 1][j] != 'P')
		return (ft_create_node(i + 1, j));
	else if (k == 2 && mem->map[i][j - 1] != '1' && mem->map[i][j - 1] != '2' && mem->map[i][j - 1] != 'P')
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
		neighbour = ft_check_neighbour(queue->first->i, queue->first->j, mem, k);
		if (neighbour)
		{
			printf("K: %d\ni: %d\nj: %d\n\n", k, neighbour->i, neighbour->j);
			ft_enqueue(queue, neighbour);
			if (mem->map[neighbour->i][neighbour->j] == 'C' || mem->map[neighbour->i][neighbour->j] == 'E')
				(*cont)++;
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
	return (0);
}


//Pon las letras en minusculas
