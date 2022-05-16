#include "philosophers.h"

void	ft_start_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos_num)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
		{
			free(data);
			exit (1);
		}
		i++;
	}
	pthread_mutex_init(&data->output, NULL);
}