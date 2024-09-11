# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 12:22:36 by ccodere           #+#    #+#              #
#    Updated: 2024/09/05 22:33:29 by ccodere          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = gcc
CFLAGS = -I lib -Wall -Wextra -Werror
NAME = minitalk
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Mandatory
MANDATORY_DIR = mandatory
SERVER_SRC = $(MANDATORY_DIR)/server.c $(MANDATORY_DIR)/server_utils.c
CLIENT_SRC = $(MANDATORY_DIR)/client.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_EXE = server
CLIENT_EXE = client

# Bonus
BONUS_DIR = bonus
BONUS_SERVER_SRC = $(BONUS_DIR)/server_bonus.c $(BONUS_DIR)/server_utils_bonus.c
BONUS_CLIENT_SRC = $(BONUS_DIR)/client_bonus.c
BONUS_SERVER_OBJ = $(BONUS_SERVER_SRC:.c=.o)
BONUS_CLIENT_OBJ = $(BONUS_CLIENT_SRC:.c=.o)
BONUS_SERVER_EXE = server_bonus
BONUS_CLIENT_EXE = client_bonus

all: $(LIBFT) $(SERVER_EXE) $(CLIENT_EXE)

bonus: $(LIBFT) $(BONUS_SERVER_EXE) $(BONUS_CLIENT_EXE)

# Rules
# TARGET: DEPENDENCIES
# 	COMMANDS

$(NAME): all

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(SERVER_EXE): $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(SERVER_EXE) $(LIBFT)

$(CLIENT_EXE): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(CLIENT_EXE) $(LIBFT)

$(BONUS_SERVER_EXE): $(BONUS_SERVER_OBJ)
	$(CC) $(CFLAGS) $(BONUS_SERVER_OBJ) -o $(BONUS_SERVER_EXE) $(LIBFT)

$(BONUS_CLIENT_EXE): $(BONUS_CLIENT_OBJ)
	$(CC) $(CFLAGS) $(BONUS_CLIENT_OBJ) -o $(BONUS_CLIENT_EXE) $(LIBFT)

# Compilation
# $< is the first dependency file name
# $@ is the current target file name
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling: $<"

clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(BONUS_SERVER_OBJ) $(BONUS_CLIENT_OBJ)

fclean: clean
	rm -f $(SERVER_EXE) $(CLIENT_EXE) $(BONUS_SERVER_EXE) $(BONUS_CLIENT_EXE)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

bonus_re: fclean bonus

.PHONY: all clean fclean re bonus bonus_re
