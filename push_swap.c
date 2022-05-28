/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:43 by lhafsi            #+#    #+#             */
/*   Updated: 2022/05/23 23:55:38 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int	arg_check(int ac, char **av)
{
	if (ac < 2 || !av)
		return (0);
	if (ft_check_digit(ac, av) == 1)
		return (0);
	if (ft_check_minmax(ac, av) == 1)
		return (0);
	if (ft_check_doubles(ac, av) == 1)
		return (0);
	return (1);
}

// MAIN ARG CHECKS

int	main(int ac, char **av)
{
	if (arg_check(ac, av) == 0)
	{
		printf("Error\n");
		return (0);
	}
	else
		printf("All good\n");
	return (0);
}