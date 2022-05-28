/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:49 by lhafsi            #+#    #+#             */
/*   Updated: 2022/05/24 20:28:34 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(const char *str)
{
	int			sign;
	long int	result;
	int			i;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

t_stack	*create_elem(int num)
{
	t_stack	*elem;

	elem = malloc(sizeof(elem));
	elem->val = num;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

t_stack	*generate_list(char **av)
{
	t_stack	*head;
	t_stack	*next_node;
	t_stack	*current;
	int		i;

	head = create_elem(ft_atoi(av[1]));
	current = head;
	i = 2;
	while (av[i])
	{
		next_node = create_elem(ft_atoi(av[i]));
		next_node->prev = current;
		current->next = next_node;
		current = next_node;
		i++;
	}
	return (head);
}

int	*stack_size(t_stack *stack)
{
	int		i;

	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

// DISPLAY & MAIN

void    display_list(t_stack *stack)
{
    while (stack)
    {
        printf("Num = %d\n", stack->val);
        stack = stack->next;
    }
}
/*
int main(int argc, char **argv)
{
	t_stack *stacka;
	t_stack *stackb;

	(void)argc;
	stacka = generate_list(argv);
	display_list(stacka);
	stackb = NULL;
} */

// main STACK SIZE