#include "philosophers_bonus.h"

void	ft_output(t_data *data, int philo_id, char *str)
{
	sem_wait(data->output);
	if (!(data->is_dead))
	{
		printf("[%lld] ", ft_timestamp() - data->birth);
		printf("Philosopher %d %s\n", philo_id, str);
	}
	sem_post(data->output);
}
