# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 13:44:31 by ghanquer          #+#    #+#              #
#    Updated: 2022/01/13 15:49:29 by ghanquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INC_DIR =		inc
OBJ_DIR = 		obj
SRC_DIR	= 		.

SRC =			$(SRC_FT:%=$(SRC_DIR)/%.c)

OBJ =			$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

OBJ_DIRS =		$(OBJ_DIR)

CC = clang

RM = rm -fr

CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

#HOW TO LIST .c 
#	ls -l | awk '{print $9}' | grep -E ".c$"| sed "s/\.c/ \\\/g" | sed '$s/\\$//g'

SRC_FT = instr_push\
		instr_revrot\
		instr_rot\
		instr_swap\
		lstfunc\
		main\
		push_swap

all: $(NAME)

$(OBJ_DIRS): inc/push_swap.h
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $< -o $@

$(NAME): $(OBJ_DIRS) $(SRC)
	@$(MAKE) -j -s $(OBJ)
	@$(CC) $(OBJ) -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

define print_aligned_coffee
    @t=$(NAME); \
	l=$${#t};\
	i=$$((8 - l / 2));\
	echo "             \0033[1;32m\033[3C\033[$${i}CAnd Your program \"$(NAME)\" "
endef

coffee: all clean
	@echo ""
	@echo "                                {"
	@echo "                             {   }"
	@echo "                              }\0033[1;34m_\0033[1;37m{ \0033[1;34m__\0033[1;37m{"
	@echo "                           \0033[1;34m.-\0033[1;37m{   }   }\0033[1;34m-."
	@echo "                          \0033[1;34m(   \0033[1;37m}     {   \0033[1;34m)"
	@echo "                          \0033[1;34m| -.._____..- |"
	@echo "                          |             ;--."
	@echo "                          |            (__  \ "
	@echo "                          |             | )  )"
	@echo "                          |   \0033[1;96mCOFFEE \0033[1;34m   |/  / "
	@echo "                          |             /  / "
	@echo "                          |            (  / "
	@echo "                          \             | "
	@echo "                            -.._____..- "
	@echo ""
	@echo ""
	@echo "\0033[1;32m\033[3C                    Take Your Coffee"
	$(call print_aligned_coffee)

.SECONDARY: $(OBJ_DIR)
.PHONY: all clean fclean re coffee
