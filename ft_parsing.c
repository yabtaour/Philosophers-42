#include "philosophers.h"

void	ft_check_args(char **arguments)
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
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_plus(char **arguments)
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
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}

void	ft_parsing(t_data *data)
{
	data->args = ft_join_args(data->argv, data->argc);
	data->arguments = ft_split(data->args, ' ');
	free(data->args);
	ft_check_args(data->arguments);
	ft_check_plus(data->arguments);
	free_split(data->arguments);
}