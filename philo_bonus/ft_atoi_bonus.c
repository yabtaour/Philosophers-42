/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:45:57 by yabtaour          #+#    #+#             */
/*   Updated: 2022/05/18 17:46:07 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers_bonus.h"

int	ft_atoi(const char	*str)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v'
		|| str[i] == ' ' || str[i] == '\f')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
