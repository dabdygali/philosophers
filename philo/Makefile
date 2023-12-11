# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/15 15:43:23 by dabdygal          #+#    #+#              #
#    Updated: 2023/12/11 16:40:11 by dabdygal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *********************************INITIALIZE********************************* #

BIN_NAME = philo

INCLUDE_DIR = include

MAIN_DIR = .

SRC_DIR = src

OBJ_DIR = src

INCLUDE_FILES = philo.h

MAIN_FILE = philo.c

SRC_FILES = check_args_warn.c \
			ft_atoi.c \
			ft_checkwarn_argc.c \
			ft_isdigit.c \
			ft_putstr_fd.c \
			ft_str_is_int.c \
			init_common.c \
			terminate_common.c \
			init_seats.c \
			run_simulation.c \
			lock_warn.c \
			unlock_warn.c \
			control_write.c

OBJ_FILES = $(SRC_FILES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -I $(INCLUDE_DIR)

# ************************************RULES*********************************** #

$(BIN_NAME): $(addprefix $(MAIN_DIR)/,$(MAIN_FILE)) $(addprefix $(OBJ_DIR)/,$(OBJ_FILES)) $(addprefix $(INCLUDE_DIR)/,$(INCLUDE_FILES))
	$(CC) $(CFLAGS) $(addprefix $(MAIN_DIR)/,$(MAIN_FILE)) $(addprefix $(OBJ_DIR)/,$(OBJ_FILES)) $(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)) -o $(BIN_NAME)

$(addprefix $(OBJ_DIR)/,$(OBJ_FILES)): $(addprefix $(INCLUDE_DIR)/,$(INCLUDE_FILES))

all: $(BIN_NAME)

clean:
	rm -f $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

fclean: clean
	rm -f $(BIN_NAME)

re: fclean all

.PHONY: all clean fclean re
