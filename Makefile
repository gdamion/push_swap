# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 11:58:36 by gdamion-          #+#    #+#              #
#    Updated: 2019/04/09 11:55:05 by gdamion-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_C = checker
NAME_P = push_swap

FLAGS = -Wall -Wextra -Werror
LIB_DIR = lib/
HEADER_DIR = includes/

################ COMMON FILES ##################
SRC_COM =		common1.c \
				common2.c \
				common3.c

SRC_DIR_COM =	src/common/
################################################

################ CHECKER FILES ##################
SRC_C =			checker.c

SRC_DIR_C =		src/checker/
################################################

############# PUSH_SWAP FILES ##################
SRC_P =			push_swap.c

SRC_DIR_P =		src/push_swap/
################################################

OBJ_COM = $(patsubst %.c,%.o,$(SRC_COM))
OBJ_C = $(patsubst %.c,%.o,$(SRC_C))
OBJ_P = $(patsubst %.c,%.o,$(SRC_P))

OBJ_DIR = obj/
OBJ_DIR_COM = $(OBJ_DIR)o_common/
OBJ_DIR_C = $(OBJ_DIR)o_checker/
OBJ_DIR_P = obj/o_push_swap/

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR_COM)%.o: $(SRC_DIR_COM)%.c
	@mkdir -p $(OBJ_DIR_COM)
	@gcc -c $< -o $@ -I $(HEADER_DIR)

$(OBJ_DIR_C)%.o: $(SRC_DIR_C)%.c
	@mkdir -p $(OBJ_DIR_C)
	@gcc -c $< -o $@ -I $(HEADER_DIR)

$(OBJ_DIR_P)%.o: $(SRC_DIR_P)%.c
	@mkdir -p $(OBJ_DIR_P)
	@gcc -c $< -o $@ -I $(HEADER_DIR)

$(NAME): $(addprefix $(OBJ_DIR_COM),$(OBJ_COM)) $(addprefix $(OBJ_DIR_C),$(OBJ_C)) $(addprefix $(OBJ_DIR_P),$(OBJ_P))
	@make -C $(LIB_DIR)
	@gcc $(addprefix $(OBJ_DIR_COM),$(OBJ_COM)) $(addprefix $(OBJ_DIR_C),$(OBJ_C)) -L/Users/gdamion-/push_swap/lib -lft -o $(NAME_C)
	@gcc $(addprefix $(OBJ_DIR_COM),$(OBJ_COM)) $(addprefix $(OBJ_DIR_P),$(OBJ_P)) -L/Users/gdamion-/push_swap/lib -lft -o $(NAME_P)

clean:
	@make clean -C $(LIB_DIR)
	@rm -Rf $(OBJ_DIR)

fclean: clean
	@make fclean -C $(LIB_DIR)
	@rm -f $(NAME_C) $(NAME_P)

re: fclean all
