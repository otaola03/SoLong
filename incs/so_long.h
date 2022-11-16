/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:34:51 by jperez            #+#    #+#             */
/*   Updated: 2022/11/16 19:34:44 by jperez           ###   ########.fr       */
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
int	ft_close_window(int keycode, void *param);

/*----------- CHECK_GAME -----------*/
void	ft_check_game(t_game *game);

/*----------- NEW -----------*/

void	ft_new_game(t_game *game);
void	ft_new_window(t_game *game, int	width, int height);

/*----------- NEW -----------*/

int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);

/*----------- CHECK-MAP -----------*/
int	ft_check_map(t_mem *mem);
void	ft_save_map(char *map_addr, t_mem *mem);

/*----------- CHECK-MAP -----------*/
char *get_next_line(int fd);




#endif

