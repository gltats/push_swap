# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tatianasofiagomeslima <tatianasofiagome    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 23:34:38 by tgomes-l          #+#    #+#              #
#    Updated: 2023/04/17 18:31:35 by tatianasofi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors------------------------------------------------------------
#\033[38;2;255;0;0m 38;2 indicates 24-bit color mode.
#                   255;0;0 amount of red, green, and blue
CYAN = \033[0;96m
ORANGE = \033[38;2;255;146;3m
RED = \033[38;2;255;0;0m
GREEN = \033[38;2;0;255;0m
PINK = \033[38;2;255;55;255m
L_VIOLET = \033[38;2;171;0;205m
VIOLET = \033[38;2;154;0;255m
RESET = \033[0m
#------------------------------------------------------------------

#Emojis-------------------------
EMOJI_HAPPY := \xF0\x9F\x98\x83
EMOJI_SAD := \xF0\x9F\x98\xA2
EMOJI_CELEBRATE := \xF0\x9F\x8E\x89
EMOJI_CLOCK := \xE2\x8F\xB0
EMOJI_ROBOT := \xF0\x9F\xA4\x96
SPARKS := \xE2\x9C\xA8
CLEANING_TOOL := \xF0\x9F\xA7\xBD
#--------------------------------


SRC = 	Main.c	Movements.c	Parseo.c Push_swap.c\
		Utils.c big_sort.c three_five_sort.c
OBJS = $(SRC:.c=.o)
LIB = ./libft/libft.a
HEADERS = Push_swap.h
NAME = push_swap
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g

all: header $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(NAME):
	@make -C ./libft
	gcc $(FLAGS) -o $(NAME) $(SRC) $(LIB)

header:	
		@echo "                                                    "
		@echo " $(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)"
		@echo " $(SPARKS)                                                        $(SPARKS)"
		@echo "$(PINK) $(SPARKS)    ∞∞∞∞∞  ∞∞∞          ∞                 ∞             $(SPARKS) $(RESET)"
		@echo "$(PINK) $(SPARKS)   ∞∞   ∞   ∞           ∞       ∞∞∞       ∞     ∞∞∞∞    $(SPARKS) $(RESET)"
		@echo "$(PINK) $(SPARKS)   ∞    ∞   ∞          ∞∞∞∞∞   ∞   ∞    ∞∞∞∞∞   ∞   ∞   $(SPARKS) $(RESET)"
		@echo "$(L_VIOLET) $(SPARKS)   ∞        ∞           ∞          ∞      ∞    ∞∞       $(SPARKS) $(RESET)"
		@echo "$(L_VIOLET) $(SPARKS)   ∞  ∞∞∞   ∞           ∞          ∞      ∞    ∞∞       $(SPARKS) $(RESET)"
		@echo "$(L_VIOLET) $(SPARKS)   ∞    ∞   ∞           ∞     ∞∞∞∞∞∞∞     ∞     ∞∞∞∞    $(SPARKS) $(RESET)"
		@echo "$(VIOLET) $(SPARKS)   ∞∞   ∞   ∞           ∞     ∞     ∞     ∞         ∞∞  $(SPARKS) $(RESET)"
		@echo "$(VIOLET) $(SPARKS)    ∞   ∞   ∞     ∞∞    ∞  ∞  ∞∞    ∞     ∞  ∞      ∞∞  $(SPARKS) $(RESET)"
		@echo "$(VIOLET) $(SPARKS)     ∞∞∞∞ ∞∞∞∞∞∞  ∞∞    ∞∞∞∞   ∞∞∞∞∞∞∞    ∞∞∞∞  ∞∞∞∞∞   $(SPARKS) $(RESET)"
		@echo " $(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)"
		@echo " $(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(SPARKS)$(RESET)$(CYAN)PIPEX PROJECT!$(RESET)$(CYAN)$(SPARKS)$(SPARKS)$(RESET)"

clean:
	/bin/rm -f $(OBJS)
	@make clean -C ./libft

fclean: clean
	/bin/rm -f $(NAME)
	@make fclean -C ./libft
	
re: fclean all

#valgrind:
#	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --trace-children=yes -s -q ./push_swap 6 5 1 60 76 3 7589 234 1235 46

norm:
	@echo "$(CYAN)\nChecking norm for Pipex...$(RESET)\n"
	@norminette $(SRC) includes/ && echo "$(EMOJI_HAPPY)$(GREEN)Norm check passed!$(RESET)$(EMOJI_CELEBRATE)" || echo "$(EMOJI_SAD)$(RED)Norm check failed!$(RESET)$(EMOJI_SAD)"