/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 00:07:59 by yabtaour          #+#    #+#             */
/*   Updated: 2022/05/23 00:08:01 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers_bonus.h"

void	ft_create_philos(t_data *data, int *pid)
{
	int	i;

	i = 0;
	while (i < data->philos_num)
	{
		pid[i] = fork();
		if (pid[i] == 0)
			ft_start_philosophers(data, i);
		i++;
	}
}

int	ft_start(t_data *data)
{
	int	i;

	i = 0;
	data->pid = malloc(sizeof(int) * data->philos_num);
	if (!data->pid)
	{
		free(data);
		exit(1);
	}
	ft_create_philos(data, data->pid);
	while (i < data->philos_num)
		waitpid(data->pid[i++], 0, 0);
	ft_end(data);
	return (1);
}
