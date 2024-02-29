NAME = cub3d

CC = @gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = cub3d.c \
		srcs/error/error_manager.c \
		srcs/parsing/file_parsing.c \
		utils/little_func/little_func.c \
		utils/little_func/little_func2.c \
		utils/little_func/little_func3.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		utils/parsing_utils/file_utils.c \
		utils/parsing_utils/file_utils2.c \
		utils/parsing_utils/file_utils3.c \
		utils/parsing_utils/file_utils4.c \
		utils/parsing_utils/map_utils.c

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