/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:36:06 by jperez            #+#    #+#             */
/*   Updated: 2022/11/16 13:17:14 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"


int	ft_check_walls(t_mem *mem)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	len = ft_strlen(mem->map[0]);
	while (mem->map[++i])
	{
		j = -1;
		while (mem->map[i][++j])
		{
			if (i == 0 && !(mem->map[i][j] == '1' || mem->map[i][j] == '\n'))
				return (1);
			else if (i == (mem->map_len -1) &&  !(mem->map[i][j] == '1' || mem->map[i][j] == '\n'))
				return (2);
			else if ((j == 0 || j == len - 2) && mem->map[i][j] != '1')
				return (3);
		}
		if (j != len)
			exit(-1);
		len = j;
	}
	return (0);
}


int	ft_check_objects(t_mem *mem, int i)
{
	int	j;
	int	exit;
	int	entry;
	int	collect;

	exit = 0;
	entry = 0;
	collect = 0;
	while (mem->map[++i])
	{
		j = -1;
		while (mem->map[i][++j])
		{
			if (mem->map[i][j] == 'C')
				collect++;
			else if (mem->map[i][j] == 'E')
				exit++;
			else if (mem->map[i][j] == 'P')
				entry++;
		}
	}
	if (collect == 0 || exit != 1 || entry != 1)
		return (1);
	return (0);
}


int	ft_check_map(t_mem *mem)
{
	printf("walls: %d\n", ft_check_walls(mem));
	printf("walls: %d\n", ft_check_objects(mem, -1));
	return (0);
}
