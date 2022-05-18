NAME = philo

CC = CC -Wall  -Wextra

SRC = ft_calloc.c main.c ft_timestamp.c\
		ft_join_args.c ft_split.c \
		ft_substr.c ft_atoi.c ft_routine.c \
		ft_output.c ft_eat.c ft_check_dead.c\
		ft_parsing.c ft_initialize_data.c\
		ft_start_mutex.c ft_initialize_philosophers.c \
		ft_create_philosophers.c ft_sleep.c\

OBJ = ${SRC:.c=.o}

%.o: %.c philosophers.h
	$(CC) -c $< -o $@

all: ${NAME}

${NAME}: $(OBJ)
	CC $(OBJ) -o ${NAME}

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf ${NAME}

re: fclean all