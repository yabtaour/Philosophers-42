#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));	
	if (argc != 5 && argc != 6)
		return (1);
	data->argc = argc;
	data->argv = argv;
	ft_parsing(data);
	ft_initialize_data(data);
	ft_start_mutex(data);
	ft_initialize_philosophers(data);
	ft_create_philosophers(data);
}