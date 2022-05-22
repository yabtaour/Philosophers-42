#include "philosophers_bonus.h"

int	ft_start_semaphores(t_data *data)
{
	sem_unlink("philo_forks");
	sem_unlink("philo_output");
	sem_unlink("philo_eat");
	data->fork = sem_open("philo_forks", O_CREAT, 0700, data->philos_num);
	data->eat = sem_open("philo_eat", O_CREAT, 0700, 1);
	data->output = sem_open("philo_output", O_CREAT, 0700, 1);
	if (data->fork == SEM_FAILED
		|| data->eat == SEM_FAILED || data->output == SEM_FAILED)
	{
		ft_destroy_sem(data);
		free(data);
		exit (1);
	}
	return (1);
}
