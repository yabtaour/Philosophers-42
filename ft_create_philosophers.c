#include "philosophers.h"

void ft_destroy(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->output);
	pthread_mutex_destroy(&data->eat);
	while (i < data->philos_num)
	{
		pthread_detach(data->philosopher[i].thread_id);
		pthread_mutex_destroy(data->philosopher[i].right_fork);
		pthread_mutex_destroy(data->philosopher[i].left_fork);
		i++;
	}
}

int	ft_create_philosophers(t_data *data)
{
	int i;

	i = 0;
	data->birth = ft_timestamp();
	while (i < data->philos_num)
	{
		data->philosopher[i].last_meal = ft_timestamp();
		if (pthread_create(&data->philosopher[i].thread_id, NULL, &ft_routine, &data->philosopher[i]) != 0)
		{
			free(data);
			return (0);
		}
		usleep(100);
		i++;
	}
	if (ft_check_dead(data))
	{
		ft_destroy(data);
		return (0);
	}
	i = 0;
	while (i < data->philos_num)
	{
		if (pthread_join(data->philosopher[i].thread_id, NULL) != 0)
		{
			free(data);
			return (0);
		}
		i++;
	}
	return (1);
}