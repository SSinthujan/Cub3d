NAME            = cub3D

DIR_SRCS        = sources

DIR_OBJS        = objects

SRCS_NAMES      = main.c \
                  exec/init_game.c

OBJS_NAMES      = ${SRCS_NAMES:.c=.o}

DEPS            = ${SRCS_NAMES:.c=.d}

SRCS            = $(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

OBJS            = $(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

INC             = -Iincludes

LIB             = -Llibft -lft

LIBFT           = libft.a

PRINTF          = libftprintf.a

CC              = cc

CDFLAGS         = -MMD -MP

MLX_FLAGS       = -lm -lmlx -lXext -lX11

CFLAGS          = -Wall -Werror -Wextra

all:    ${NAME}

$(NAME): $(DIR_OBJS) $(OBJS)
	make -C libft
	make -C mlx
	$(CC) -g3 ${INC} $(OBJS) $(LIB) mlx/libmlx.a mlx/libmlx_Linux.a -L. -lXext -L. -lm -lX11 -o $(NAME)
	@echo "\033[31;5mcub3d\033[0m"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p $(dir $@)
	$(CC) -g3 $(CFLAGS) $(CDFLAGS) $(INC) -c $< -o $@

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

norm:
	norminette srcs/ includes/

clean:
	make clean -C mlx
	make clean -C libft
	rm -rf ${DIR_OBJS}

fclean: clean
	make fclean -C libft
	rm -rf ${LIBFT}
	rm -rf ${NAME}

re: fclean all

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re
