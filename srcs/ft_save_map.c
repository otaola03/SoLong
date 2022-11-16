/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:51:29 by jperez            #+#    #+#             */
/*   Updated: 2022/11/16 13:12:01 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/so_long.h"

int	ft_cont_lines(char *addr)
{
	int		fd;
	int		cont;
	int		read_len;
	char	buff[2];

	fd = open(addr, O_RDONLY);
	if (fd <= 0)
	{
		perror("");
		exit(-1);
	}
	cont = 0;
	read_len = 1;
	while (read_len)
	{
		read_len = read(fd, buff, 1);
		buff[read_len] = '\0';
		if (buff[0] == '\n')	
			cont++;
	}
	close(fd);
	return (cont);
}

void	ft_save_map(char *map_addr, t_mem *mem)
{
	int		fd;
	int		i;
	char	*str;

	mem->map_len = ft_cont_lines(map_addr);
	mem->map = (char **)malloc(sizeof(char *) * (mem->map_len + 1));
	if (!mem->map)
		exit(-1);
	fd = open(map_addr, O_RDONLY);
	i = 0;
	str = get_next_line(fd);
	mem->map[i++] = str;
	while(str)
	{
		str = get_next_line(fd);
		mem->map[i++] = str;
	}
	close(fd);
}
