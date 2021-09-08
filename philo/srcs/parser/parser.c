/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:09:41 by lfrasson          #+#    #+#             */
/*   Updated: 2021/09/08 13:51:40 by lfrasson         ###   ########.fr       */
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
	if (lnumber < 0)
		return (FALSE);
	return (is_integer(lnumber));
}

int	parse_arguments(char **argv, t_param *param)
{
	if (!parse_number(*argv++, &param->number_of_philo))
		return (FAIL);
	if (!parse_number(*argv++, &param->time.to_die))
		return (FAIL);
	if (!parse_number(*argv++, &param->time.to_eat))
		return (FAIL);
	if (!parse_number(*argv++, &param->time.to_sleep))
		return (FAIL);
	param->must_eat = 0;
	if (!*argv)
		return (SUCCESS);
	if (!parse_number(*argv, &param->must_eat))
		return (FAIL);
	return (SUCCESS);
}

static int	check_number_of_arguments(int argc)
{
	if (argc == 6)
		return (SUCCESS);
	if (argc == 5)
		return (SUCCESS);
	printf("Incorrect number of arguments\n");
	printf("Usage: philo number_of_philosophers time_to_die time_to_eat ");
	printf("time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	return (FAIL);
}

int	parse_input(int argc, char **argv, t_param *param)
{
	int	status;

	status = check_number_of_arguments(argc);
	if (status == FAIL)
		return (status);
	status = parse_arguments(argv + 1, param);
	if (status == FAIL)
	{
		printf("xxxxx\n");
		return (status);
	}
	return (SUCCESS);
}
