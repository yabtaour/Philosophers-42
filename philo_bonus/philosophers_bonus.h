#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_philo{
	int				philo_id;
	int				eat;
	long long		last_meal;
	struct s_data	*data;
}	t_philo;

typedef struct s_data{
	int				argc;
	char			**argv;
	int				philos_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				is_dead;
	int				all_ate;
	long long		birth;
	char			*args;
	char			**arguments;
	int				total;
	long long		time;
	long long		norm;
	long long		norm2;
}	t_data;

int		ft_parsing(t_data *data);
int		ft_initialize_data(t_data *data);
void	free_split(char **arguments);
int		ft_d(int c);
char	**ft_split(char *s, char c);
char	*ft_join_args(char *argv[], int argc);
int		ft_atoi(const char	*str);

#endif