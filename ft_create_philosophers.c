#include "philosophers.h"

void	ft_create_philosophers(t_data *data)
{
	int i;

	i = 0;
	data->birth = ft_timestamp();
	while (i < data->philos_num)
	{
		if (pthread_create(&data->philosopher[i].thread_id, NULL, &routine, &data->philosopher[i]) != 0)
		{
			free(data);
			exit (1);
		}
		usleep(100);
		i++;
	}
	i = 0;
	while (i < data->philos_num)
	{
		if (pthread_join(data->philosopher[i].thread_id, NULL) != 0)
		{
			free(data);
			exit (1);
		}
		i++;
	}
}