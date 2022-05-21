NAME = philo_bonus

CC = CC -Wall -Wextra -Werror

SRC = main_bonus.c ft_parsing_bonus.c \
		ft_atoi_bonus.c ft_calloc_bonus.c \
		ft_initialize_data_bonus.c \
		ft_split_bonus.c ft_substr_bonus.c\
		ft_timestamp_bonus.c ft_is_digit_bonus.c \
		ft_join_args_bonus.c ft_start_semaphores_bonus.c \
		ft_start_bonus.c ft_output_bonus.c \
		ft_sleep_bonus.c ft_start_philos_bonus.c \


OBJ = ${SRC:.c=.o}

%.o: %.c philosophers_bonus.h
	$(CC) -c $< -o $@

all: ${NAME}

${NAME}: $(OBJ)
	CC $(OBJ) -o ${NAME}

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf ${NAME}

re: fclean all