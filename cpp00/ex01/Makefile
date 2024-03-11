# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 11:23:33 by ffornes-          #+#    #+#              #
#    Updated: 2024/03/11 08:11:17 by ffornes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook

SRC_FILES = PhoneBook.cpp \
			Contact.cpp \
			utils.cpp \
			main.cpp

OBJ_DIR = objs/
OBJ_FILES = $(SRC_FILES:.cpp=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

DEP_FILES = $(SRC_FILES:.cpp=.d)
DEPS = $(addprefix $(OBJ_DIR), $(DEP_FILES))

CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror -MMD -fsanitize=address
RM = rm -f
INCLUDE = -I ./

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $@

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) -r $(OBJ_DIR)
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
