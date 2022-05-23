/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philos_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 00:08:10 by yabtaour          #+#    #+#             */
/*   Updated: 2022/05/23 01:02:52 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers_bonus.h"

void	ft_eat(t_philo *philosopher)
{
	sem_wait(philosopher->data->fork);
	ft_output(philosopher->data, philosopher->philo_id, "has taken a fork");
	sem_wait(philosopher->data->fork);
	ft_output(philosopher->data, philosopher->philo_id, "has taken a fork");
	philosopher->last_meal = ft_timestamp();
	ft_output(philosopher->data, philosopher->philo_id, "is eating");
	ft_sleep(philosopher->data->time_to_eat, philosopher->data);
	sem_post(philosopher->data->fork);
	sem_post(philosopher->data->fork);
	philosopher->eat++;
}

void	ft_routine(t_philo *philosopher)
{
	while (!(philosopher->is_dead)
		&& (philosopher->eat != philosopher->data->must_eat))
	{
		ft_eat(philosopher);
		ft_output(philosopher->data, philosopher->philo_id, "is sleeping");
		ft_sleep(philosopher->data->time_to_sleep, philosopher->data);
		ft_output(philosopher->data, philosopher->philo_id, "is thinking");
	}
}

void	ft_start_philosophers(t_data *data, int i)
{
	t_philo	*philo;

	philo = &data->philosopher[i];
	data->philosopher[i].data = data;
	data->philosopher[i].philo_id = i + 1;
	data->philosopher[i].is_dead = 0;
	data->philosopher[i].eat = 0;
	data->philosopher[i].last_meal = ft_timestamp();
	ft_routine(&data->philosopher[i]);
	pthread_create(&philo->thread_id, NULL, &ft_check_dead, philo);
	pthread_join(data->philosopher[i].thread_id, NULL);
	pthread_detach(data->philosopher[i].thread_id);
}
