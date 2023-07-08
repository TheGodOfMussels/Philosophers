# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 17:56:14 by dimolin2          #+#    #+#              #
#    Updated: 2023/07/04 18:04:29 by dimolin2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####### NAME #########

SRCS	= main.c

SRCS	+= error.c init.c utils.c starter.c

OBJS	= $(SRCS:.c=.o)

NAME	= philo

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

INCLUDE	= -lpthread

HEADER	= philo.h

###### COLORS ########

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

####### RULES ########

all:	$(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)- Program Name: $(WHITE)${NAME}$(DEF_COLOR)"
	@echo "$(YELLOW)- Compiler: $(WHITE)${CC}$(DEF_COLOR)"
	@echo "$(YELLOW)- Flags: $(WHITE)${CFLAGS}$(DEF_COLOR)"
	@$(CC) $(INCLUDE) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS) $(B_OBJS)
	@echo "$(RED)All $(CYAN)$(NAME)$(RED)'s objects removed with $(WHITE)${RM}$(DEF_COLOR) 🧹"

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@echo "$(RED)..and $(CYAN)${NAME} $(RED)as been removed$(DEF_COLOR) 🚮"

re: fclean all

%.o: %.c $(HEADER)
	@echo "$(GREEN)Compiling:$(BLUE) $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $<  -o $(<:.c=.o)

.PHONY:	clean fclean re bonus bench bclean