CC					= cc
RM					= rm -f
CFLAGS				= -Wextra -Wall -Werror -g3
LDFLAGS				= -L./libft/printf/ -L./libft/ -lreadline -lncurses -lftprintf -lft
INCLUDE_PATH 		= ./includes/
CUB3DNAME 		= minishell
CUB3DSRCS		= ./parsing/check_map.c\
					./exec/init_game.c\
					main.c
CUB3DOBJS 		= $(CUB3DSRCS:.c=.o)

LIBFT_PATH = ./libft/

LIBFT = $(LIBFT_PATH)libft.a
MAKEFLAGS += --no-print-directory

all:			$(CUB3DNAME)

.c.o:
	@$(CC) $(CFLAGS) -I$(INCLUDE_PATH) -c $< -o $(<:.c=.o)

$(CUB3DNAME):	$(CUB3DOBJS) $(LIBFT) 
					@$(CC) -o $(CUB3DNAME) $(CUB3DOBJS) $(CFLAGS) $(LDFLAGS) -I$(INCLUDE_PATH)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(LIBFTPRINTF):
	@$(MAKE) -C $(LIBFTPRINTF_PATH)

clean:
				@$(RM) $(CUB3DOBJS)
				@$(MAKE) -C $(LIBFT_PATH) clean
				@echo "Object files cleaned"

fclean:	 		clean
				@$(RM) $(CUB3DNAME)
				@$(MAKE) -C $(LIBFT_PATH) fclean
				@echo "Executable $(NAME) removed"

re:				fclean 
				@$(MAKE) all

.PHONY:			all clean fclean re