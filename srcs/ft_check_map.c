/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:36:06 by jperez            #+#    #+#             */
/*   Updated: 2022/11/25 19:49:27 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

int	ft_check_walls(int	i, int j, int line_len, t_mem *mem)
{
	if (i == 0 && !(mem->map[i][j] == '1' || mem->map[i][j] == '\n'))
		return (1);
	else if (i == (mem->map_len) &&  !(mem->map[i][j] == '1' || mem->map[i][j] == '\n'))
		return (2);
	else if ((j == 0 || j == line_len - 2) && mem->map[i][j] != '1')
		return (3);
	else if (!(mem->map[i][j] == '0' || mem->map[i][j] == '1' || mem->map[i][j] == 'C' || mem->map[i][j] == 'E' || mem->map[i][j] == 'P' || mem->map[i][j] == '\n'))
		return (4);
	return (0);
}

void	ft_update_objects(int i, int j, t_mem *mem)
{
	if (mem->map[i][j] == 'C')
		mem->collect++;
	else if (mem->map[i][j] == 'E')
		mem->exit++;
	else if (mem->map[i][j] == 'P')
	{
		mem->p_pos[0] = i;
		mem->p_pos[1] = j;
		mem->entry++;
	}
}

int	ft_check_line(t_mem *mem, int line_len, int i, int j)
{
	if (i != mem->map_len - 1 && line_len != j)
		return (1);
	else if (i == mem->map_len - 1 && mem->map[i][j - 1] == '\n' && line_len != j)
		return (1);
	else if (i == mem->map_len - 1 && mem->map[i][j - 1] == '\0' && line_len != j - 1)
		return (1);
	return (0);
}

int	ft_check_map(t_mem *mem)
{
	int	i;
	int	j;
	int	line_len;

	mem->exit = 0;
	mem->entry = 0;
	mem->collect = 0;
	line_len = ft_strlen(mem->map[0]);
	i = -1;
	while (mem->map[++i])
	{
		j = -1;
		while (mem->map[i][++j])
		{
			if (ft_check_walls(i, j, line_len, mem))
				return (1);
			ft_update_objects(i, j, mem);
		}
//		if ((i != mem->map_len - 1 && j != line_len) || (i == mem->map_len - 1 && ))
		if (ft_check_line(mem, line_len, i, j))
			return (1);
	}
	if (mem->collect == 0 || mem->exit != 1 || mem->entry != 1)
		return (1);
	return (0);
}
