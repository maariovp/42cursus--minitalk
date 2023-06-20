# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 11:30:29 by mavicent          #+#    #+#              #
#    Updated: 2023/02/09 17:07:53 by mavicent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client

NAMESV = server

NAMEBC = client_bonus

NAMEBS = server_bonus

LIBFT = ./lib/libft_src/

FT_PRINTF = ./lib/ft_printf_src/

INC = inc

HEADER = -I ./includes

SRC_DIR = src/

OBJ_DIR = obj/

CC = cc

FLAGS = -Wall -Werror -Wextra

RM = rm -f

OBJF = .cache_exists

SRCCL_FILES = client

SRCSV_FILES = server

SRCBC_FILES = client_bonus

SRCBS_FILES = server_bonus

SRCCL = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCCL_FILES)))

OBJCL = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCCL_FILES)))

SRCSV = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCSV_FILES)))

OBJSV = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCSV_FILES)))

SRCBC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCBC_FILES)))

OBJBC = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCBC_FILES)))

SRCBS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCBS_FILES)))

OBJBS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCBS_FILES)))

all:    start $(NAME) $(NAMESV)

start: 
	@make bonus -C $(LIBFT)
	@make -C $(FT_PRINTF)
	@cp $(LIBFT)libft.a .
	@cp $(FT_PRINTF)libftprintf.a .

$(NAME):	$(OBJCL) $(OBJF)
	@$(CC) $(FLAGS) $(OBJCL) libft.a libftprintf.a -o $(NAME) $(HEADER)

$(NAMESV):	$(OBJSV) $(OBJF)
	@$(CC) $(FLAGS) $(OBJSV) libft.a libftprintf.a -o $(NAMESV) $(HEADER)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(OBJF)
	@$(CC) $(FLAGS) -c $< -o $@ $(HEADER)

$(OBJF):
	@mkdir -p $(OBJ_DIR)
	@touch $(OBJF)

bonus:
	@make bonus -C $(LIBFT)
	@make -C $(FT_PRINTF)
	@cp $(LIBFT)libft.a .
	@cp $(FT_PRINTF)libftprintf.a .
	@make allbonus

allbonus:	$(NAMEBC) $(NAMEBS)

$(NAMEBC): $(OBJBC) $(OBJF)
	@$(CC) $(FLAGS) $(OBJBC) libft.a libftprintf.a -o $(NAMEBC) $(HEADER)

$(NAMEBS): $(OBJBS) $(OBJF)
	@$(CC) $(FLAGS) $(OBJBS) libft.a libftprintf.a -o $(NAMEBS) $(HEADER)

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(RM) $(OBJF)
	@make clean -C $(LIBFT)
	@make clean -C $(FT_PRINTF)

fclean: clean
	@$(RM) $(NAME) $(NAMESV) $(NAMEBC) $(NAMEBS)
	@$(RM) $(LIBFT)libft.a
	@$(RM) $(FT_PRINTF)libftprintf.a
	@$(RM) libft.a libftprintf.a
	@find . -name ".DS_Store" -delete

re:	fclean all

.PHONY: start all clean fclean re bonus