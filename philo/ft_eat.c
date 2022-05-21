/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:25:59 by yabtaour          #+#    #+#             */
/*   Updated: 2022/05/19 15:26:02 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	ft_eat(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->right_fork);
	ft_output(philosopher->data, philosopher->philo_id, "has taken a fork");
	pthread_mutex_lock(philosopher->left_fork);
	ft_output(philosopher->data, philosopher->philo_id, "has taken a fork");
	ft_output(philosopher->data, philosopher->philo_id, "is eating");
	philosopher->last_meal = ft_timestamp();
	ft_sleep(philosopher->data->time_to_eat, philosopher->data);
	philosopher->data->total++;
	pthread_mutex_lock(&philosopher->data->eat);
	philosopher->eat++;
	pthread_mutex_unlock(&philosopher->data->eat);
	pthread_mutex_unlock(philosopher->right_fork);
	pthread_mutex_unlock(philosopher->left_fork);
}
