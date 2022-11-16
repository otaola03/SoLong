/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:33:17 by jperez            #+#    #+#             */
/*   Updated: 2022/11/16 19:39:29 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H

# define STRUCTS_H

typedef struct s_mem
{
	char	**map;
	int		map_len;
	int		exit;
	int		entry;
	int		collect;
	int		p_pos[2];
}	t_mem;

typedef struct s_game
{
	void	*mlx;
	void	*win;
}	t_game;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_node
{
	int	i;
	int	j;
	int	index;
	t_node next;
}

typedef struct s_peek
{
	t_node peek;
}

#endif
