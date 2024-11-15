# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 11:23:33 by ffornes-          #+#    #+#              #
#    Updated: 2024/10/21 11:47:24 by ffornes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

SRC_DIR = src/
SRC_FILES = PmergeMe.cpp \
			parse.cpp \
			main.cpp
			
OBJ_DIR = objs/
OBJ_FILES = $(SRC_FILES:.cpp=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

DEP_FILES = $(SRC_FILES:.cpp=.d)
DEPS = $(addprefix $(OBJ_DIR), $(DEP_FILES))

CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror -MMD -g3
RM = rm -f
INCLUDE = -I include/

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $@

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp Makefile
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	rmdir $(OBJ_DIR)
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
