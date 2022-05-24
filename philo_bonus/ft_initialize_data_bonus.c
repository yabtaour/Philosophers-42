/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_data_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 00:06:20 by yabtaour          #+#    #+#             */
/*   Updated: 2022/05/23 00:06:22 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers_bonus.h"

int	ft_initialize_data(t_data *data)
{
	data->philos_num = ft_atoi(data->argv[1]);
	data->time_to_die = ft_atoi(data->argv[2]);
	data->time_to_eat = ft_atoi(data->argv[3]);
	data->time_to_sleep = ft_atoi(data->argv[4]);
	data->birth = ft_timestamp();
	data->is_dead = 0;
	if (data->argv[5])
	{
		data->must_eat = ft_atoi(data->argv[5]);
		if (data->must_eat <= 0)
			return (0);
	}
	else
		data->must_eat = -1;
	if (data->philos_num < 1)
		return (0);
	return (1);
}
