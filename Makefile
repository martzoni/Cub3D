# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 14:57:14 by martinmason       #+#    #+#              #
#    Updated: 2025/03/28 13:22:38 by mmasoni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= cub3d
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
HEADER			= cub3d.h

SRC_DIR				= sources
OBJ_DIR				= objets
INC_DIR				= includes
SRCS_FILES		=	main.c\
					general_utils.c\
					parser.c\
					parser_txtr.c\
					parser_txtr_valid.c\
					parser_map.c\
					parser_map_valid.c\
					init.c\
					launcher.c\
					render.c\
					movements.c\

# Liste des fichiers sources
SRCS				= ${addprefix ${SRC_DIR}/, ${SRCS_FILES}}
OBJS 				= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

GETNEXTLINE		= libraries/get_next_line/*c
LIBRARY			= -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX		= minilibx/

# Ft_printf
FT_PRINTF_DIR	= libraries/ft_printf
FT_PRINTF		= -L$(FT_PRINTF_DIR) -lftprintf

# Libft
LIBFT_DIR		= libraries/libft
LIBFT			= -L$(LIBFT_DIR) -lft

all: $(NAME)
	@echo "\n\033[1;102m[Completed : $(NAME) !]\033[0m\n"

$(NAME):		$(OBJS) $(HEADER)
# Libft
	@echo "\033[1;37mCompiling libft...\033[0;33m"
	@make -C $(LIBFT_DIR)
	@echo "\033[1;32m+++++ Done compiling libft! +++++\033[0m\n"
# Ft_printf
	@echo "\033[1;37mCompiling printf...\033[0;33m"
	@make -C $(FT_PRINTF_DIR)
	@echo "\033[1;32m+++++ Done compiling printf! +++++\033[0m\n"
# Minilibx
	@echo "\033[1;37mCompiling Minilibx...\033[0;33m"
	@make -C $(MINILIBX)
	@echo "\033[1;32m~~~~~~ Done compiling Minilibx! ~~~~~~\033[0m\n"
# PROGRAMME
	@echo "\033[1;37mCompiling $(NAME)...\033[0;33m"
	$(CC) $(CFLAGS) -I $(HEADER) $(OBJS) $(FT_PRINTF) $(LIBFT) $(GETNEXTLINE) $(LIBRARY) -o $(NAME)
	@echo "\033[1;32m~~~~~~ Done compiling $(NAME)! ~~~~~~\033[0m\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "\033[1;37mCompiling $(NAME)...\033[0;33m"
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INC_DIR)
	@echo "\033[1;32m+++++ Done compiling $(NAME)! +++++\033[0m\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJS)

fclean: clean
	@echo "\n\033[1;37mDeleting...\033[0;33m"
	make clean -C $(MINILIBX)
	make fclean -C $(FT_PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)
	@echo "\033[1;32m~~~~~~ Done deleting : $(NAME)! ~~~~~~\033[0m\n"

re: fclean all

.PHONY: all clean fclean re
