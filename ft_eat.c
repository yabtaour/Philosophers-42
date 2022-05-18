#include "philosophers.h"

void	ft_eat(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->right_fork);
	ft_output(philosopher->data, philosopher->philo_id, "has taken the right fork");
	pthread_mutex_lock(philosopher->left_fork);
	ft_output(philosopher->data, philosopher->philo_id, "has taken the left fork");
	ft_output(philosopher->data, philosopher->philo_id, "is eating");
	philosopher->last_meal = ft_timestamp();
	ft_sleep(philosopher->data->time_to_eat, philosopher->data);
	philosopher->data->total++;
	pthread_mutex_lock(&philosopher->data->eat);
	philosopher->eat++;
	pthread_mutex_unlock(&philosopher->data->eat);
	pthread_mutex_unlock(philosopher->right_fork);
	pthread_mutex_unlock(philosopher->left_fork);
}