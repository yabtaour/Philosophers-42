#include "philosophers.h"

void	ft_output(t_data *data, int philo_id, char *str)
{
	pthread_mutex_lock(&data->output);
	if (!(data->is_dead))
	{
		printf("[%lld] ", ft_timestamp() - data->birth);
		printf("Philosopher %d %s\n", philo_id, str);
	}
	pthread_mutex_unlock(&data->output);
}