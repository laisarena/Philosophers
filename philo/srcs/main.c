/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:25:04 by lfrasson          #+#    #+#             */
/*   Updated: 2021/09/07 18:34:43 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = 0;
}

void	free_null(void *pointer)
{
	if (pointer)
		free(pointer);
	pointer = NULL;
}

void	free_double_pointer(void **pointer)
{
	int		i;
	void	**next;

	i = 0;
	if (!pointer)
		return ;
	next = pointer;
	while (*next)
	{
		free_null(*next);
		next++;
	}
	free_null(pointer);
}

void	destroy_mutex(t_mutex **forks)
{
	while (*forks)
	{
		pthread_mutex_destroy(*forks);
		forks++;
	}
}

void	free_structures(t_philo	**philos, t_mutex **forks)
{
	destroy_mutex(forks);
	free_double_pointer((void **)philos);
	free_double_pointer((void **)forks);
}

int	main(int argc, char **argv)
{
	t_param	param;
	t_philo	**philos;
	t_mutex	**forks;
	int		status;

	ft_bzero(&param, sizeof(t_param));
	philos = NULL;
	forks = NULL;
	status = parse_input(argc, argv, &param);
	if (status == FAIL)
		return (status);
	initialize_structures(&philos, &forks, &param, param.number_of_philo);
	start_routines(philos, &param.time.init);
	free_structures(philos, forks);
	return (SUCCESS);
}
