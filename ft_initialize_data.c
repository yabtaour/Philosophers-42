#include "philosophers.h"

void	ft_initialize_data(t_data *data)
{
	data->philos_num = ft_atoi(data->argv[1]);
	data->time_to_die = ft_atoi(data->argv[2]);
	data->time_to_eat = ft_atoi(data->argv[3]);
	data->time_to_sleep = ft_atoi(data->argv[4]);
	if (data->argv[5])
		data->must_eat = ft_atoi(data->argv[5]);
	else
		data->must_eat = -1;
	data->is_dead = 0;
	if (data->philos_num < 1)
		exit (1);
}