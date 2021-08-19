/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:25:04 by lfrasson          #+#    #+#             */
/*   Updated: 2021/08/19 19:14:02 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_number_of_arguments(int argc)
{
	if (argc == 6)
		return (0);
	if (argc == 5)
		return (0);
	printf("Incorrect number of arguments\n");
	printf("Usage: philo number_of_philosophers time_to_die time_to_eat ");
	printf("time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	return (-1);
}

int	parse_arguments(int argc, char **argv)
{
	int	status;
	(void)argv;
	status = check_number_of_arguments(argc);
	if (status)
		return (status);
	return (0);
}

int	main(int argc, char **argv)
{
	int	status;

	status = parse_arguments(argc, argv);
	if (!status)
		return (status);
	return (0);
}
