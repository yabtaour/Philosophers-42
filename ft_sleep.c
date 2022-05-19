/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:06:39 by yabtaour          #+#    #+#             */
/*   Updated: 2022/05/19 22:14:15 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

long long	ft_period(long long past, long long present)
{
	return (present - past);
}

void	ft_sleep(long long time, t_data *data)
{
	long long	i;

	i = ft_timestamp();
	while (!(data->is_dead))
	{
		if (ft_period(i, ft_timestamp()) >= time)
			break ;
		usleep(500);
	}
}
