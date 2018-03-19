# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmonnier <gmonnier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/02 08:23:52 by gmonnier          #+#    #+#              #
#    Updated: 2018/03/19 15:25:54 by gmonnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fractol

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
OBJDIR = obj
INCDIR = includes \
		 ./libft/includes

SRC = \
	main.c \
	utils.c \
	draw.c \
	events.c \
	init.c \
	colors.c \
	display.c \
	events2.c

LIB = ./libft/libft.a \

MLXFLAGS_MAC = -lmlx -L minilibx_macos -lmlx -framework AppKit -framework OpenGL
MATHFLAG = -lm

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(basename $(SRC))))
INCS = $(addprefix -I, $(addsuffix /, $(INCDIR)))

#Colors
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(OBJS) $(FLAGS) $(LIB) $(MLXFLAGS) $(MLXFLAGS_MAC) $(MATHFLAG) -o $@
	@echo "\rCompiling project $(NAME)... $(_GREEN)DONE$(_END)"

clean:
	@echo "Removed objects (.o) files."
	@make clean -C ./libft
	@make clean -C ./minilibx_macos/
	@/bin/rm -f $(OBJS)

fclean: clean
	@echo "Removed project ($(NAME))."
	@make fclean -C ./libft
	@/bin/rm -f $(NAME)

re: fclean all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "                                                          \r"
	@printf " $(_CYAN)Compiling $@$(_END)\r"
	@mkdir -p $(OBJDIR) || true
	@$(CC) -o $@ -c $(FLAGS) $< $(INCS)

$(LIB):
	make -C $(@D)
	make -C ./minilibx_macos
