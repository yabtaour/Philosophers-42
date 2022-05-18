#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));	
	if (argc != 5 && argc != 6)
		return (1);
	data->argc = argc;
	data->argv = argv;
	if (!ft_parsing(data))
		return (1);
	ft_initialize_data(data);
	if (!ft_start_mutex(data))
		return (1);
	ft_initialize_philosophers(data);
	if (!ft_create_philosophers(data))
		return (1);
	return (0);
}