#include "philosophers_bonus.h"

void	ft_eat(t_philo *philosopher)
{
	sem_wait(philosopher->data->fork);
	ft_output(philosopher->data, philosopher->philo_id, "has taken a fork");
	sem_wait(philosopher->data->fork);
	ft_output(philosopher->data, philosopher->philo_id, "has taken a fork");
	philosopher->last_meal = ft_timestamp();
	ft_output(philosopher->data, philosopher->philo_id, "is eating");
	ft_sleep(philosopher->data->time_to_eat, philosopher->data);
	sem_post(philosopher->data->fork);
	sem_post(philosopher->data->fork);
	philosopher->eat++;
}

void	*ft_routine(t_philo *philosopher)
{
	while (!(philosopher->is_dead) && (philosopher->eat != philosopher->data->must_eat))
	{
		ft_eat(philosopher);
		ft_output(philosopher->data, philosopher->philo_id, "is sleeping");
		ft_sleep(philosopher->data->time_to_sleep, philosopher->data);
		ft_output(philosopher->data, philosopher->philo_id, "is thinking");
	}
	return (NULL);
}

void	ft_start_philosophers(t_data *data, int i)
{
	data->philosopher[i].data = data;
	data->philosopher[i].philo_id = i + 1;
	data->philosopher[i].is_dead = 0;
	data->philosopher[i].eat = 0;
	data->philosopher[i].last_meal = ft_timestamp();
	//pthread_create(&data->philosopher[i].thread_id, NULL, &ft_check_dead, &data->philosopher[i]);
	ft_routine(&data->philosopher[i]);
}