#include "philosophers.h"

int	ft_check_args(char **arguments)
{
	int	i;
	int	j;

	i = 0;
	while (arguments[i])
	{
		j = 0;
		while (arguments[i][j])
		{
			if ((arguments[i][j] != '+') && (arguments[i][j] > '9' || arguments[i][j] < '0'))
			{
				free_split(arguments);
				exit(0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_plus(char **arguments)
{
	int	i;
	int	j;

	i = 0;
	while (arguments[i])
	{
		j = 0;
		while (arguments[i][j])
		{
			if (arguments[i][j] == '+')
			{
				if (arguments[i][j + 1] > '9' || arguments[i][j + 1] < '0')
				{
					free_split(arguments);
					return(0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_parsing(t_data *data)
{
	data->args = ft_join_args(data->argv, data->argc);
	if (!data->args)
		return (0);
	data->arguments = ft_split(data->args, ' ');
	if (!data->arguments)
	{
		free(data->args);
		return (0);
	}
	free(data->args);
	if (!ft_check_args(data->arguments))
		return (0);
	if (!ft_check_plus(data->arguments))
		return (0);
	free_split(data->arguments);
	return (1);
}