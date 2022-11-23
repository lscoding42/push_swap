/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:43 by lhafsi            #+#    #+#             */
/*   Updated: 2022/11/18 04:31:57 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}

int	error_manager(int ac, char **av)
{
	if (ac < 2 || !av)
		return (ft_putstr_fd("Error\n", 2), 0);
	if (ft_check_minmax(ac, av))
		return (ft_putstr_fd("Error\n", 2), 0);
	if (ft_check_doubles(ac, av))
		return (ft_putstr_fd("Error\n", 2), 0);
	if (ft_check_digit(ac, av))
		return (ft_putstr_fd("Error\n", 2), 0);
	return (1);
}

