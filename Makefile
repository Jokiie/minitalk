# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 12:22:36 by ccodere           #+#    #+#              #
#    Updated: 2024/08/01 13:12:36 by ccodere          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -I lib -Wall -Wextra -Werror

MTLIB_DIR = lib
MTLIB = $(MTLIB_DIR)/minitalk.a

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

SERVER_EXE = server
CLIENT_EXE = client

all: $(MTLIB) $(SERVER_EXE) $(CLIENT_EXE)

$(MTLIB):
	$(MAKE) -C $(MTLIB_DIR)

$(SERVER_EXE): $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(SERVER_EXE) $(MTLIB)

$(CLIENT_EXE): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(CLIENT_EXE) $(MTLIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling: $<"

clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	rm -f $(SERVER_EXE) $(CLIENT_EXE)
	$(MAKE) -C $(MTLIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re