# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 14:10:40 by jperez            #+#    #+#              #
#    Updated: 2022/11/14 18:52:29 by jperez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S = srcs/
O = objs/

NAME = so_long

CC = gcc
CFLAGS = -Wall -Werror -Wextra

RM = -rm -rf


SRCS = $Smain.c $Sft_new.c $Sft_end_game.c $Sft_get_next_line.c $Sft_aux.c $Sft_check_map.c $Sft_save_map.c

OBJS = $Omain.o $Oft_new.o $Oft_end_game.o $Oft_get_next_line.o $Oft_aux.o $Oft_check_map.o $Oft_save_map.o

F = -fsanitize=address

all: $(NAME)

$O:
	@echo "Creating Objects Folder...."
	mkdir $@
	@echo "Folder created."

$(OBJS): | $O

$(OBJS): $O%.o: $S%.c
#	$(CC) $(CFLAGS) -Imlx_linux -O3 -c $< -o $@
	$(CC) $(CFLAGS) -Imlx -O3 -c $< -o $@

$(NAME): $(OBJS)
#	$(CC) $(CFLAGS)  $^ -o $(NAME) -Lmlx_linux -lmlx_linux -Imlx_linux -lXext -lX11 -lm -lz
	$(CC) $(CFLAGS) -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $O

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean all
