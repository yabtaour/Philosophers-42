#include "philosophers_bonus.h"

int	ft_initialize_data(t_data *data)
{
	data->philos_num = ft_atoi(data->argv[1]);
	data->time_to_die = ft_atoi(data->argv[2]);
	data->time_to_eat = ft_atoi(data->argv[3]);
	data->time_to_sleep = ft_atoi(data->argv[4]);
	if (data->argv[5])
	{
		data->must_eat = ft_atoi(data->argv[5]);
		if (data->must_eat <= 0)
			return (0);
	}
	else
		data->must_eat = -1;
	data->birth = ft_timestamp();
	data->is_dead = 0;
	data->all_ate = 0;
	if (data->philos_num < 1)
		return (0);
	return (1);
}
