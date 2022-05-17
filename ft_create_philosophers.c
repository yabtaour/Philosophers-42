#include "philosophers.h"

void	ft_check_dead(t_data *data)
{
	int	i;
	int j;

	i = 0;
	while (1)
	{
		i = 0;
		while (i < data->philos_num)
		{
			if (data->argc == 6 && data->total >= data->philos_num * data->must_eat)
			{
				free(data);
				exit(1);
			}
			if ((ft_timestamp() - data->philosopher[i].last_meal) >= data->time_to_die)
			{
				data->is_dead = 1;
				pthread_mutex_lock(&data->output);
				printf("[%lld] Philosopher %d died \n", ft_timestamp() - data->birth, i + 1);
				free(data);
				exit(1);
			}
			i++;
		}
	}
}

void	ft_create_philosophers(t_data *data)
{
	int i;

	i = 0;
	data->birth = ft_timestamp();
	while (i < data->philos_num)
	{
		data->philosopher[i].last_meal = ft_timestamp();
		if (pthread_create(&data->philosopher[i].thread_id, NULL, &routine, &data->philosopher[i]) != 0)
		{
			free(data);
			exit (1);
		}
		usleep(100);
		i++;
	}
	ft_check_dead(data);
	i = 0;
	while (i < data->philos_num)
	{
		pthread_join(data->philosopher[i].thread_id, NULL);
		i++;
	}
}