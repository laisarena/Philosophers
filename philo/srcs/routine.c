/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:14:45 by lfrasson          #+#    #+#             */
/*   Updated: 2021/09/08 14:59:00 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(char *message, t_philo *philo)
{
	if (philo->param->died.index != 0)
		return ;
	printf("%d %d %s",
			delta_time(philo->param->time.init),
			philo->index,
			message);
}

void	take_forks(t_philo *philo)
{
	t_mutex	*first;
	t_mutex	*second;

	first = philo->hand.left;
	second = philo->hand.right;
	/*if ((philo->index % 2 == 0))
	{
		first = philo->hand.right;
		second = philo->hand.left;
	}*/
	pthread_mutex_lock(first);
	print("has taken a fork\n", philo);
	pthread_mutex_lock(second);
	print("has taken a fork\n", philo);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->hand.left);
	pthread_mutex_unlock(philo->hand.right);
}

int	eating(t_philo *philo)
{
	if (philo->param->died.index != 0)
		return (FALSE);
	take_forks(philo);

	philo->last_meal = get_time();
	print("is eating\n", philo);
	sleeep_ms(philo->param->time.to_eat);
	drop_forks(philo);
	return (TRUE);
}

int	thinking(t_philo *philo)
{
	if (philo->param->died.index != 0)
		return (FALSE);
	print("is thinking\n", philo);
	return (TRUE);
}

int	sleeping(t_philo *philo)
{
	if (philo->param->died.index != 0)
		return (FALSE);
	print("is sleeping\n", philo);
	sleeep_ms(philo->param->time.to_sleep);
	return (TRUE);
}

void	*death_control(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (delta_time(philo->last_meal) < philo->param->time.to_die)
		continue ;
	if (philo->param->died.index == 0)
	{
		pthread_mutex_lock(&philo->param->died.mutex);
		philo->param->died.index = philo->index;
		printf("%d %d died\n",
			delta_time(philo->param->time.init),
			philo->index);
		pthread_mutex_unlock(&philo->param->died.mutex);
		pthread_mutex_unlock(philo->hand.left);
	}
	return (SUCCESS);
}

void	create_control_thread(t_philo *philo)
{
	t_pthread	thread;

	pthread_create(&thread, NULL, death_control, philo);
	pthread_detach(thread);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = philo->param->time.init;
	create_control_thread(philo);
	if (philo->index % 2 == 0)
		sleeep_ms(5);
	//if (philo->index == philo->param->number_of_philo)
	//	sleeep_ms(20);
	while (eating(philo) && sleeping(philo) && thinking(philo))
		continue ;
	return (SUCCESS);
}

int	create_philo_threads(t_philo **philo)
{
	t_pthread	thread;

	while (*philo)
	{
		if (pthread_create(&thread, NULL, routine, *philo))
			return (FAIL);
		(*philo)->thread = thread;
		philo++;
	}
	return (SUCCESS);
}

int	join_philo_threads(t_philo **philo)
{
	while (*philo)
	{
		if (pthread_join((*philo)->thread, NULL))
			return (FAIL);
		philo++;
	}
	return (SUCCESS);
}

int	start_routines(t_philo **philos, t_microsec *init)
{
	*init = get_time();
	if (create_philo_threads(philos))
		return (FAIL);
	if (join_philo_threads(philos))
		return (FAIL);
	return (SUCCESS);
}
