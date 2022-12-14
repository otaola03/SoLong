# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 14:10:40 by jperez            #+#    #+#              #
#    Updated: 2022/11/28 19:39:44 by jperez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


define HEADER
░░░░░██╗██████╗░███████╗██████╗░███████╗███████╗
░░░░░██║██╔══██╗██╔════╝██╔══██╗██╔════╝╚════██║
░░░░░██║██████╔╝█████╗░░██████╔╝█████╗░░░░███╔═╝
██╗░░██║██╔═══╝░██╔══╝░░██╔══██╗██╔══╝░░██╔══╝░░
╚█████╔╝██║░░░░░███████╗██║░░██║███████╗███████╗
░╚════╝░╚═╝░░░░░╚══════╝╚═╝░░╚═╝╚══════╝╚══════╝

endef
export HEADER

S = srcs/
O = objs/

NAME = so_long

#F = -fsanitize=address -g3

CC = gcc -O3$(F) 
CFLAGS = -Wall -Werror -Wextra

RM = -rm -rf


SRCS = $Smain.c $Sft_init_map.c $Sft_end_game.c $Sft_get_next_line.c $Sft_aux.c $Sft_check_map.c $Sft_save_map.c $Sft_check_path.c $Sft_manage_queue.c $Sft_general_free.c $Sft_set_images.c $Sft_key_hook.c $Sft_print_map.c

OBJS = $Omain.o $Oft_init_map.o $Oft_end_game.o $Oft_get_next_line.o $Oft_aux.o $Oft_check_map.o $Oft_save_map.o $Oft_check_path.o $Oft_manage_queue.o $Oft_general_free.o $Oft_set_images.o $Oft_key_hook.o $Oft_print_map.o

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
	$(MAKE) -C mlx 2> logs
	rm -f logs
#	$(CC) $(CFLAGS)  $^ -o $(NAME) -Lmlx_linux -lmlx_linux -Imlx_linux -lXext -lX11 -lm -lz
	$(CC) $(CFLAGS) -I mlx/libmlx.a -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)
#	$(CC) $(CFLAGS) -I mlx/libmlx.dylib -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)
	@echo "\033[0;33m"
	@echo "$$HEADER"

clean:
	$(RM) $(OBJS) $O
	$(RM) mlx/*.o

fclean: clean
	$(RM) $(NAME)
	$(RM) mlx/libmlx.a
#	$(RM) mlx/libmlx.dylib

re: fclean all

.PHONY: fclean clean all
