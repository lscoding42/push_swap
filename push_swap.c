/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:43 by lhafsi            #+#    #+#             */
/*   Updated: 2022/11/23 07:12:34 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

t_stack	*call_stack(char **av)
{
	return (generate_list(av));
}

void	call_algo(t_stack **stacka)
{
	t_stack	*stackb;

	stackb = NULL;
	assign_index(*stacka);
	if (stack_size(*stacka) == 2)
		sort_two(stacka);
	else if (stack_size(*stacka) == 3)
		sort_three(stacka);
	else if (stack_size(*stacka) <= 5)
		sort_five(stacka, &stackb);
	else
		radix_sort(stacka, &stackb);
	return ;
}

int	main(int ac, char **av)
{
	t_stack *stacka;

	if (!error_manager(ac, av))
		return (0);
	if (ft_check_order(ac, av))
		return (0);
	stacka = call_stack(av);
	call_algo(&stacka);
	clear_stack(&stacka);
	return (0);
}