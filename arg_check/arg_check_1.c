/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:43 by lhafsi            #+#    #+#             */
/*   Updated: 2022/11/18 04:16:06 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_minmax(int ac, char **av)
{
	int			i;
	long int	num;

	i = 1;
	while (av[i] && i <= ac)
	{
		if (ft_strlen(av[i]) > 11)
			return(1);
		num = ft_atol(av[i]);
		if (num < -2147483648 || num > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_doubles(int ac, char **av)
{
	int	i;
	int	j;
	int	num;
	int	ber;

	i = 1;
	while (av[i] && i < ac - 1)
	{
		if (ft_check_minmax(ac, av))
			return (1);
		j = i + 1;
		num = ft_atoi(av[i]);
		ber = ft_atoi(av[j]);
		while (av[j] && j < ac)
		{
			ber = ft_atoi(av[j]);
			if (num == ber)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_digit(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac < 2 || !av)
		return (1);
	while (av[i] && i <= ac)
	{
		j = 0;
		while (av[i][j] == ' ')
			j++;
		if (av[i][j] == '+' || av[i][j] == '-')
			j++;
		if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (1);
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
