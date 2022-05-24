/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 00:08:58 by yabtaour          #+#    #+#             */
/*   Updated: 2022/05/23 00:47:20 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <semaphore.h>
# include <pthread.h>
# include <string.h>
# include <signal.h>
# include <sys/time.h>

typedef struct s_philo{
	int				philo_id;
	int				eat;
	int				is_dead;
	long long		last_meal;
	pthread_t		*thread_id;
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
	int				*pid;
	t_philo			*philosopher;
	sem_t			*fork;
	sem_t			*eat;
	sem_t			*output;
}	t_data;

int			ft_parsing(t_data *data);
int			ft_initialize_data(t_data *data);
void		free_split(char **arguments);
int			ft_d(int c);
char		**ft_split(char *s, char c);
char		*ft_join_args(char *argv[], int argc);
int			ft_atoi(const char	*str);
void		*ft_calloc(int count, int size);
char		*ft_substr(char *s, int start, size_t len);
int			ft_strlen(char *str);
int			ft_start_semaphores(t_data *data);
int			ft_start(t_data *data);
void		ft_sleep(long long time, t_data *data);
long long	ft_timestamp(void);
void		ft_output(t_data *data, int philo_id, char *str);
void		*ft_start_philosophers(t_data *data, int i);
void		*ft_check_dead(t_philo *philo);
void		ft_destroy_sem(t_data *data);
void		ft_kill(t_data *data);
void		ft_end(t_data *data);

#endif
