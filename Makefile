SRCS =	$(addprefix srcs/, pipex.c ft_utils.c)
CC =	cc -g3 #-Wall -Werror -Wextra
DIRLIB = ./libft

LIBFT = $(DIRLIB)/libft.a

NAME =	pipex
OBJS =	$(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(MLXLIB)
	$(CC) $(OBJS) $(LIBFT) $(MLXLIB)  -o $(NAME)
	@echo "done !"

$(LIBFT) :
	@make -sC $(DIRLIB)


%.o : %.c
	@$(CC) -c $< -o $@ -Imlx
	#echo "compiling: $<"

clean :
	@make fclean -sC $(DIRLIB)
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all