/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:06:12 by yabtaour          #+#    #+#             */
/*   Updated: 2022/05/19 23:00:39 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	*routine(void *ptr)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)ptr;
	while (!(philosopher->data->is_dead)
		&& (philosopher->eat != philosopher->data->must_eat))
	{
		ft_eat(philosopher);
		ft_output(philosopher->data, philosopher->philo_id, "is sleeping");
		ft_sleep(philosopher->data->time_to_sleep, philosopher->data);
		ft_output(philosopher->data, philosopher->philo_id, "is thinking");
	}
	return (NULL);
}
