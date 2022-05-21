#include "philosophers_bonus.h"

void	ft_kill(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos_num)
	{
		kill (data->pid[i], SIGINT);
		i++;
	}
}

void	*ft_check_dead(void *ptr)
{
	t_philo		*philosopher;
	long long	now;
	philosopher = (t_philo *)ptr;
	while (1)
	{
		now = ft_timestamp();
		if (philosopher->eat == philosopher->data->must_eat)
			return (NULL);
		if (now - philosopher->last_meal >= philosopher->data->time_to_die)
		{
			philosopher->is_dead = 1;
			sem_wait(philosopher->data->output);
			printf("[%lld] philosopher %d died\n", now - philosopher->data->birth, philosopher->philo_id);
			ft_kill(philosopher->data);
			exit(1);
		}
	}
	return (NULL);
}