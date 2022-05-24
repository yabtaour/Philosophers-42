/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philos_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 00:08:10 by yabtaour          #+#    #+#             */
/*   Updated: 2022/05/23 11:43:41 by yabtaour         ###   ########.fr       */
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

void	ft_routine(t_philo *philo)
{
	while (!(philo->is_dead) && philo->eat != philo->data->must_eat)
	{
		ft_eat(philo);
		ft_output(philo->data, philo->philo_id, "is sleeping");
		ft_sleep(philo->data->time_to_sleep, philo->data);
		ft_output(philo->data, philo->philo_id, "is thinking");
	}
}

void	*ft_start_philosophers(t_data *data, int i)
{
	t_philo	philo;

	philo.data = data;
	philo.philo_id = i + 1;
	philo.is_dead = 0;
	philo.eat = 0;
	philo.last_meal = ft_timestamp();
	pthread_create(philo.thread_id, NULL, (void *)ft_check_dead, &philo);
	ft_routine(&philo);
	pthread_detach(*philo.thread_id);
	return (NULL);
}
