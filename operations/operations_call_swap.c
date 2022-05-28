/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_call_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:49 by lhafsi            #+#    #+#             */
/*   Updated: 2022/05/28 01:01:42 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    sa(t_stack *stacka)
{
	if (!stacka || !(stacka->next))
		return ;
	swap(stacka);
	write(1,"sa\n", 3);
}

void    sb(t_stack *stackb)
{
	if (!stackb || !(stackb->next))
		return ;
	swap(stackb);
	write(1,"sb\n", 3);
}

void    ss(t_stack *stacka, t_stack *stackb)
{
	if (!stacka || !(stacka->next))
		return ;
	if (!stackb || !(stackb->next))
		return ;
	swap(stacka);
	swap(stackb);
	write(1,"ss\n", 3);
}
