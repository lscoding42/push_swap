/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_order_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:43 by lhafsi            #+#    #+#             */
/*   Updated: 2022/11/23 04:16:01 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	assign_index(t_stack *stack)
{
	t_stack *cp1;
	t_stack *cp2;
	
	cp1 = stack;
	while (cp1)
	{
		cp2 = stack;
		while (cp2)
		{
			if(cp1->val >= cp2->val)
				cp1->index += 1;
			cp2 = cp2->next;
		}
		cp1 = cp1->next;
	}
}

int	find_max_bits(t_stack **stack)
{
	t_stack	*cp;
	int		index_max;
	int		max_bits;

	cp = *stack;
	index_max = cp->index;
	max_bits = 0;
	while (cp)
	{
		if (cp->index > index_max)
			index_max = cp->index;
		cp = cp->next;
	}
	while ((index_max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		j;
	int		size_a;
	int		max_bits;
	t_stack	*copy_a;

	copy_a = *stack_a;
	size_a = stack_size(copy_a);
	max_bits = find_max_bits(stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size_a)
		{
			// printf("Size stack B = %i\n", stack_size(*stack_b));
			copy_a = *stack_a;
			if (((copy_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (stack_size(*stack_b) != 0)
		{
			pa(stack_b, stack_a);
			// printf("Size_a stack B = %i\n", stack_size(*stack_b));
		}
		i++;
	}
	// display_list(*stack_a);
}
