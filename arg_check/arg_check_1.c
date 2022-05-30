/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Louisa <Louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:43 by lhafsi            #+#    #+#             */
/*   Updated: 2022/05/29 20:28:40 by Louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int     ft_strcmp(char *s1,char *s2)
// {
//         int  i;

//         i = 0;
//         while (s1[i] || s2[i])
//         {
//                 if (s1[i] != s2[i])
//                         return (1);
//                 i++;
//         }
//         return (0);
// }

// int ft_check_doubles(int ac, char **av)
// {
//     int i;
//     int j;

//     i = 1;
    
//     while (av[i])
//     {
//         j = i + 1;
//         while (av[j] && j < ac)
//         {
//             if (ft_strcmp(av[i],av[j]) == 0)
//                 return (1);
//             j++;
//         }
//         i++;
//     }
//     return (0);
// }

int ft_check_0_doubles(int ac, char **av)
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
        if (num != ber)
            i++;
        else
            return (1);
    }
    return (0);
}

int ft_check_signs(char *str)
{
    int i;

    i = 1;
    while (str)
	{
        if (str[i] == '-' || str[i] == '+')
	    {
            if (str[i + 1] == '-' || str[i + 1] == '+')
			return(0);
            i++;
        }
    }
    return (1);
}

int ft_check_digit(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    if (ft_check_signs(av[i]) == 1)
        return (1);
    while (av[i] && i <= ac)
    {
        j = 0;
        while (av[i][j])
        {
            if (ft_is_space(av[i][j]) == 1)
                j++;
            else if (av[i][j] == '+' || av[i][j] == '-')
                j++;
            else if (!(av[i][j] >= '0' && av[i][j] <= '9'))
                return (1);
            else
                j++;
        }
        i++;
    }
    return (0);
}

int ft_check_minmax(int ac, char **av)
{
    int i;
    long int num;

    i = 1;
    while (av[i] && i <= ac)
    {
        num = ft_atol(av[i]);
        if (num < -2147483648 || num > 2147483647)
            return (1);
        i++;
    }
    return (0);
}

//////// MAINS DES FONCTIONS AU DESSUS DANS L ORDRE INVERSE MDR
/*
int main(int ac, char **av)
{
    if (ac < 2)
    {
        printf("missing args\n");
        return (0);
    }
    if (ac == 2)
    {
        printf("only 1 arg\n");
        return (0);
    }
    if (ft_check_order(ac, av) == 1)
        printf("Already sorted\n");
    else
        printf("Time to sort\n");
    return (0);
}*/
/*
int main(int ac, char **av)
{
    if (ft_check_digit(ac, av) == 1)
        printf("Non-digits found\n");
    else
        printf("Only digits\n");
    return (0);
}

int main(int ac, char **av)
{
    if (ft_check_doubles(ac, av) == 1)
        printf("Doubles found\n");
    else
        printf("No doubles\n");
    return (0);
}*/

int	arg_check(int ac, char **av)
{
	if (ac < 2 || !av)
		return (0);
	if (ft_check_digit(ac, av) == 1)
		return (0);
	if (ft_check_minmax(ac, av) == 1)
		return (0);
	if (ft_check_0_doubles(ac, av) == 1)
		return (0);
	return (1);
}

// MAIN ARG CHECKS
int	main(int ac, char **av)
{
	if (arg_check(ac, av) == 0)
	{
		write(1,"Error\n", 6);
		return (0);
	}
	return (0);
}

// int	main(int ac, char **av)
// {
// 	if (ft_check_signs(ac, av) == 0)
// 		write(1,"Error\n", 6);
// 	return (0);
// }