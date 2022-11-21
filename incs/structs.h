/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:26:35 by jperez            #+#    #+#             */
/*   Updated: 2022/11/21 18:30:46 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCTS_H

# define STRUCTS_H

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*imgs[8];
	int		cont;
	int		exit;
	int		movements;
}	t_game;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mem
{
	char	**map;
	int		map_len;
	int		exit;
	int		entry;
	int		collect;
	int		*c_pos;
	int		e_pos[2];
	int		p_pos[2];
	t_game	*game;
}	t_mem;

typedef struct s_node
{
	int	i;
	int	j;
	struct s_node *prev;
	struct s_node *next;
}	t_node;

typedef struct s_queue
{
	t_node *first;
	t_node *last;
} t_queue;

#endif
