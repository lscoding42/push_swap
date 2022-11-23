/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_call_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:49 by lhafsi            #+#    #+#             */
/*   Updated: 2022/06/02 19:24:36 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **stacka)
{
	swap(stacka);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stackb)
{
	swap(stackb);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stacka, t_stack **stackb)
{
	swap(stacka);
	swap(stackb);
	write(1, "ss\n", 3);
}
