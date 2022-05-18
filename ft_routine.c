#include "philosophers.h"

void	*ft_routine(void *ptr)
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