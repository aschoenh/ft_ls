#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 19:03:44 by rmarracc          #+#    #+#              #
#    Updated: 2018/12/05 15:23:50 by aschoenh         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls

SRCS_PATH = srcs/
OBJ_PATH = obj/
LIBFT_PATH = libft/

CFLAGS = -Wall -Wextra -Werror
INC = -I ./includes/ -I ./$(LIBFT_PATH)
CC = @gcc

SRCS_NAME = main.c \


SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) $(OBJ) $(INC) -L $(LIBFT_PATH) -lft -o $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	$(CC) -c $(FLAGS) $(INC) $< -o $@
	@echo "\033[34m\033[1mCompilation of \033[0m\033[36m$(notdir $<)\033[1m\033[34m done.\033[0m"

clean :
	@make -C $(LIBFT_PATH)/ clean
	@rm -f $(OBJ_PATH)
	@echo "\033[31mObjects files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31m removed.\033[0m"

fclean : clean
	@make -C $(LIBFT_PATH)/ clean
	@rm -f $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"
re : fclean all

.PHONY : all clean fclean re