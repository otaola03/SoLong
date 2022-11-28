/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:34:51 by jperez            #+#    #+#             */
/*   Updated: 2022/11/28 18:26:03 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

#include <mlx.h>
# include<fcntl.h>
# include<unistd.h>
# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include"structs.h"

/*----------- END-GAME -----------*/
void	ft_end_game(t_game *game);
int		ft_close_window(int keycode, void *param);

/*----------- CHECK_GAME -----------*/
void	ft_check_game(t_game *game);

/*----------- NEW -----------*/
void	ft_new_game(t_game *game);
void	ft_new_window(t_game *game, int	width, int height);
void	ft_init_game(t_mem *mem);

/*----------- AUX -----------*/
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	ft_print_map(char **map);
void	ft_putnbr(int n);
int		ft_strnstr(char *haystack, char *needle, size_t len);

/*----------- CHECK-MAP -----------*/
int		ft_check_map(t_mem *mem);
int		ft_save_map(char *map_addr, t_mem *mem);

/*----------- CHECK-MAP -----------*/
char	*get_next_line(int fd);

/*----------- CHECK-PATH -----------*/
int		ft_check_path(t_mem *mem, int i, int j);

/*----------- MANAGE-QUEUE -----------*/
t_queue	*ft_create_queue(void);
t_node	*ft_create_node(int i, int j);
void	ft_enqueue(t_queue *queue, t_node *node);
void	ft_dequeue(t_queue *queue);
void	ft_free_queue(t_queue *queue);

/*----------- GENERAL-FREE -----------*/
void	ft_general_free(t_mem *mem, int on_off);
int		ft_press_x(t_mem *mem);

/*----------- SET-IMAGES -----------*/
int		ft_set_images(t_game *game, char **map);

/*----------- KEY-HOOK  -----------*/
int		ft_key_hook(int keycode, void *param);




#endif

