/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:14:45 by lfrasson          #+#    #+#             */
/*   Updated: 2021/09/11 16:47:46 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(char *message, t_philo *philo)
{
	if (someone_died(philo->param) || already_ate_enough(philo))
		return ;
	printf("%d %d %s",
		delta_time(philo->param->time.init, FALSE),
		philo->index,
		message);
}

static int	thinking(t_philo *philo)
{
	if (someone_died(philo->param) || already_ate_enough(philo))
		return (FALSE);
	print("is thinking\n", philo);
	return (TRUE);
}

static int	sleeping(t_philo *philo)
{
	if (someone_died(philo->param) || already_ate_enough(philo))
		return (FALSE);
	print("is sleeping\n", philo);
	sleeep_ms(philo->param->time.to_sleep);
	return (TRUE);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = philo->param->time.init;
	if (philo->index % 2 == 0)
		sleeep_ms(5);
	create_control_thread(philo);
	while (eating(philo) && sleeping(philo) && thinking(philo))
		continue ;
	return (SUCCESS);
}
