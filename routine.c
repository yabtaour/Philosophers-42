#include "philosophers.h"

void	ft_eat(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->right_fork);
	ft_output(philosopher->data, philosopher->philo_id, "has taken the right fork");
	pthread_mutex_lock(philosopher->left_fork);
	ft_output(philosopher->data, philosopher->philo_id, "has taken the left fork");
	ft_output(philosopher->data, philosopher->philo_id, "is eating");
	philosopher->eat++;
	philosopher->last_meal = ft_timestamp();
	ft_sleep(philosopher->data->time_to_eat, philosopher->data);
	pthread_mutex_unlock(philosopher->right_fork);
	pthread_mutex_unlock(philosopher->left_fork);
}

void	*routine(void *ptr)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)ptr;
	while (!(philosopher->data->is_dead) && (philosopher->eat != philosopher->data->must_eat))
	{
		ft_eat(philosopher);
		ft_output(philosopher->data, philosopher->philo_id, "is sleeping");
		ft_sleep(philosopher->data->time_to_sleep, philosopher->data);
		ft_output(philosopher->data, philosopher->philo_id, "is thinking");
	}
	return (NULL);
}