/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_order_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:43 by lhafsi            #+#    #+#             */
/*   Updated: 2022/11/23 07:02:19 by lhafsi           ###   ########.fr       */
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
		if (num < ber)
			i++;
		else
			return (0);
	}
	return (1);
}

void    sort_two(t_stack **stack)
{
	int first;
	int second;
	
	first = (*stack)->val;
	second = (*stack)->next->val;
	if (first > second)
		sa(stack);
	else
		return ;
}

void    sort_three(t_stack **stack)
{
	int    first;
	int    second;
	int    third;

	first = (*stack)->val;
	second = (*stack)->next->val;
	third = (*stack)->next->next->val;
	if ((first > second) && (second < third) && (first < third))
		sa(stack);
	else if ((first > second) && (second > third) && (first > third))
	{
		sa(stack);
		rra(stack);
	}
	else if ((first > second) && (second < third) && (first > third))
		ra(stack);
	else if ((first < second) && (second > third) && (first < third))
	{
		sa(stack);
		ra(stack);
	}
	else if ((first < second) && (second > third) && (first > third))
		rra(stack);
}

void    sort_five(t_stack **stacka, t_stack **stackb)
{
	int     i;

	i = find_min_index(*stacka);
	while (stack_size(*stacka) > 3)
	{
		// printf("Size stack B = %i\n", stack_size(*stackb));
		while (i > 1)
		{
			i = find_min_index(*stacka);
			if (i == 2)
				ra(stacka);
			if (i >= 3 && i <= 5)
				rra(stacka);
		}
		pb(stacka, stackb);
		if (stack_size(*stacka) >= 3)
			sort_five(stacka, stackb);
		return ;
	}
	sort_three(stacka);
	while (stack_size(*stackb) != 0)
	{
		printf("size stack A = %i // stack b = %i\n", stack_size(*stacka), stack_size(*stackb));
		pa(stackb, stacka);
		// display_both(*stacka, *stackb);
	}
	// display_list(*stacka);
}

// void	display_both(t_stack *stacka, t_stack *stackb)
// {
// 	printf("----Stack a ------\n");
// 	display_list(stacka);
// 	printf("----Stack b ------\n");
// 	display_list(stackb);
// }