NAME = cub3d

CC = @gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = cub3d.c

OBJS = ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -g3 -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "cub3d compiled!"

debug: $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address $(OBJS) -o $(NAME)
	@echo "cub3d compiled!"

all: $(NAME)

bonus: all

clean:
	@rm -rf $(OBJS)
	@echo "cub3d cleaned!"

fclean: clean
	@rm -rf $(NAME)
	@echo "cub3d fcleaned!"

re: fclean all

.PHONY: all clean fclean