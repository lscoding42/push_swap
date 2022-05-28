/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:43 by lhafsi            #+#    #+#             */
/*   Updated: 2022/05/19 16:30:33 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int     ft_strcmp(char *s1,char *s2)
{
        int  i;

        i = 0;
        while (s1[i] || s2[i])
        {
                if (s1[i] != s2[i])
                        return (1);
                i++;
        }
        return (0);
}

int ft_check_doubles(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    while (av[i])
    {
        j = i + 1;
        while (av[j] && j < ac)
        {
            if (ft_strcmp(av[i],av[j]) == 0)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int ft_check_digit(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    if (ac < 2 || !av)
        return (1);
    while (av[i] && i <= ac)
    {
        j = 0;
        while (av[i][j])
        {
            printf("HERE j = %c\n", av[i][j]);
            
            if (av[i][j] == ' ')
                j++; 
            if (av[i][j] == '+' || av[i][j] == '-')
                j++;    
            if (!(av[i][j] >= '0' && av[i][j] <= '9'))
                return (1);
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