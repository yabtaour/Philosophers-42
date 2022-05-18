#include "philosophers.h"

int	ft_check_dead(t_data *data)
{
	int			i;
	long long	time;

	while (1)
	{
		i = 1;
		while (i <= data->philos_num)
		{
			if (data->argc == 6
				&& data->total >= data->philos_num * data->must_eat)
			{
				free(data);
				return (1);
			}
			time = ft_timestamp();
			if ((time - data->philosopher[i - 1].last_meal) >= data->time_to_die)
			{
				data->is_dead = 1;
				pthread_mutex_lock(&data->output);
				printf("[%lld] Philosopher %d died \n", time - data->birth, i);
				return (1);
			}
		}
	}
	return (0);
}
