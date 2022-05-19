/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:37:56 by yabtaour          #+#    #+#             */
/*   Updated: 2022/05/19 23:39:37 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo{
	int				philo_id;
	int				eat;
	long long		last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread_id;
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
	t_philo			philosopher[200];
	int				total;
	long long		time;
	long long		norm;
	long long		norm2;
	t_philo			*n;
	pthread_mutex_t	eat;
	pthread_mutex_t	fork[200];
	pthread_mutex_t	output;
}	t_data;

char		*ft_join_args(char *argv[], int argc);
void		free_split(char **arguments);
int			ft_strlen(char *str);
char		*ft_substr(char *s, int start, size_t len);
void		*ft_calloc(int count, int size);
char		**ft_split(char *s, char c);
void		ft_check_char(char **arguments);
int			ft_atoi(const char *str);
void		ft_start(t_data *data);
void		ft_output(t_data *data, int philo_id, char *str);
long long	ft_timestamp(void);
void		ft_sleep(long long time, t_data *data);
void		ft_eat(t_philo *philosopher);
int			ft_check_dead(t_data *data);
int			ft_parsing(t_data *data);
void		ft_initialize_data(t_data *data);
int			ft_start_mutex(t_data *data);
void		ft_initialize_philosophers(t_data *data);
int			ft_create_philosophers(t_data *data);
void		*routine(void *data);

#endif
