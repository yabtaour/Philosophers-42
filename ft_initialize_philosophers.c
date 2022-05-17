#include "philosophers.h"

void	ft_initialize_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos_num)
	{
		data->philosopher[i].eat = 0;
		data->philosopher[i].philo_id = i + 1;
		data->philosopher[i].data = data;
		data->philosopher[i].right_fork = &data->fork[i];
		if (i == (data->philos_num - 1))
			data->philosopher[i].left_fork = &data->fork[0];
		else
			data->philosopher[i].left_fork = &data->fork[i + 1];
		i++;
	}
}