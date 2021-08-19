/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:09:41 by lfrasson          #+#    #+#             */
/*   Updated: 2021/08/28 17:56:58 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_string_number(char *string)
{
	if (*string == '-')
		string++;
	while (*string)
		if (!ft_isdigit(*string++))
			return (FALSE);
	return (TRUE);
}

static int	is_integer(long number)
{
	if (number > INT_MAX)
		return (FALSE);
	if (number < INT_MIN)
		return (FALSE);
	return (TRUE);
}

static int	parse_number(char *str_number, int *number)
{
	long	lnumber;

	if (!is_string_number(str_number))
		return (FALSE);
	lnumber = ft_atol(str_number);
	*number = (int)lnumber;
	return (is_integer(lnumber));
}

int	parse_arguments(char **argv, t_param *param)
{
	if (!parse_number(*argv++, &param->number_of_philosophers))
		return (-1);
	if (parse_number(*argv++, &param->time.to_die))
		return (-1);
	if (parse_number(*argv++, &param->time.to_eat))
		return (-1);
	if (parse_number(*argv++, &param->time.to_sleep))
		return (-1);
	param->must_eat = 0;
	if (!argv)
		return (0);
	if (!parse_number(*argv, &param->must_eat))
		return (-1);
	return (0);
}

static int	check_number_of_arguments(int argc)
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

int	parse_input(int argc, char **argv, t_param *param)
{
	int	status;

	status = check_number_of_arguments(argc);
	if (status)
		return (status);
	status = parse_arguments(argv + 1, param);
	if (status)
	{
		printf("xxxxx\n");
		return (status);
	}
	return (0);
}
