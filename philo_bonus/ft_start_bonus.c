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

void	ft_create_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos_num)
	{
		data->pid[i] = fork();
		if (data->pid[i] == 0)
			ft_start_philosophers(data, i);
		i++;
	}
}

void	ft_start(t_data *data)
{
	int	i;

	i = 0;
	ft_create_philos(data);
	while (i < data->philos_num)
	{
		waitpid(data->pid[i], 0, 0);
		i++;
	}
	free(data);
}
