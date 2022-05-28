/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:43 by lhafsi            #+#    #+#             */
/*   Updated: 2022/05/23 17:26:52 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_check_order(int ac, char **av)
{
    int i;
    long num;
    long ber;

    i = 1;
    while (av[i] && i <= ac - 2)
    {
        num = ft_atol(av[i]);
        ber = ft_atol(av[i + 1]);
        printf("num = %ld\nber = %ld\n", num, ber);
        if (num < ber)
            i++;
        else
            return (0);
    }
    return (1);
}