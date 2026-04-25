# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ervillca <ervillca@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/25 20:27:53 by ervillca          #+#    #+#              #
#    Updated: 2026/04/25 20:28:05 by ervillca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== BASIC SETUP =====

NAME = push_swap
CC = cc
AR = ar
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rcs
SRC_DIR = srcs/
OBJ_DIR = obj/

# ===== FILE LISTS ====

SRCS = srcs/ft_algorithm_complex_utils.c \
	   srcs/ft_algorithm_complex_utils2.c \
	   srcs/ft_algorithm_complex_utils3.c \
	   srcs/ft_algorithm_medium_utils.c \
	   srcs/ft_algorithm_medium_utils2.c \
	   srcs/ft_algorithm.c \
	   srcs/ft_bench.c \
	   srcs/ft_bench2.c \
	   srcs/ft_math.c \
	   srcs/ft_operation.c \
	   srcs/ft_parse_check.c \
	   srcs/ft_parse_free.c \
	   srcs/ft_parse_split.c \
	   srcs/ft_parse_utils2.c \
	   srcs/ft_parse_utils.c \
	   srcs/ft_push_swap.c \
	   srcs/ft_push_swap_utils.c \
	   srcs/ft_stack_utils.c \
	   srcs/ft_stack_utils2.c \
	   srcs/ft_utils.c \

OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# ===== BUILD RULES =====
# Default command: just type 'make' to build everything
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c push_swap.h Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I. -c $< -o $@

# ===== CLEANUP RULES =====
# Remove all compiled .o files (type 'make clean')
clean:
	rm -rf $(OBJ_DIR)

# Remove both .o files AND the final program (type 'make fclean')
fclean: clean
	rm -f $(NAME)

# Completely rebuild from scratch (clean + build)
re: fclean all

.PHONY: all clean fclean re bonus

# ===== COMMANDS =====
# - Make		builds the program creating .o files (all)
# - Make clean		cleans the program removing .o files
# - Make fclean		cleans the program removing .o & libft.a
# - Make re		builds + cleans
