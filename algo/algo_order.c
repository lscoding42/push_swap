/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Louisa <Louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:43 by lhafsi            #+#    #+#             */
/*   Updated: 2022/05/28 12:32:48 by Louisa           ###   ########.fr       */
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

int main(int ac, char **av)
{
    if (ac == 1)
        printf("NO ARGS\n");
    else if (ac == 2)
        printf("Only 1 = sorted\n");
    else if (ft_check_order(ac, av) == 1)
        printf("Already sorted\n");
    else
        printf("NOT sorted\n");
    return(0);
}