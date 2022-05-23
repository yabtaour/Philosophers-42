/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 00:06:52 by yabtaour          #+#    #+#             */
/*   Updated: 2022/05/23 00:06:54 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
