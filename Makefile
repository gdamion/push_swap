# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 11:58:36 by gdamion-          #+#    #+#              #
#    Updated: 2019/03/25 13:27:01 by gdamion-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_P = push_swap
NAME_C = checker

FLAGS = -Wall -Wextra -Werror
LIB_DIR = lib/
HEADER_DIR = includes/

################ COMMON FILES ##################
SRC_COM =	\
			\
			\

SRC_DIR_COM = src/common/
################################################

################ CHECKER FILES ##################
SRC_C =		\
			\
			\

SRC_DIR_C = src/checker/
################################################

############# PUSH_SWAP FILES ##################
SRC_P =		\
			\
			\

SRC_DIR_P = src/push_swap/
################################################

OBJ_COM = $(patsubst %.c,%.o,$(SRC_COM))
OBJ_C = $(patsubst %.c,%.o,$(SRC_C))
OBJ_P = $(patsubst %.c,%.o,$(SRC_P))

OBJ_DIR_COM = obj/o_common/
OBJ_DIR_C = obj/o_checker/
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
	@gcc $(OBJ_COM) $(OBJ_C) -o $(NAME_C)
	@gcc $(OBJ_COM) $(OBJ_P) -o $(NAME_P)

clean:
	@make clean -C $(LIB_DIR)
	@rm -Rf $(OBJ_DIR)

fclean: clean
	@make fclean -C $(LIB_DIR)
	@rm -f $(NAME);

re: fclean all
