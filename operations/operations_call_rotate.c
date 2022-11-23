/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_call_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:49 by lhafsi            #+#    #+#             */
/*   Updated: 2022/06/02 19:50:02 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	just_ra(t_stack **stacka)
{
	if (stack_size(*stacka) == 2)
        swap(stacka);
    else
		rotate(stacka);
}

void    ra(t_stack **stacka)
{
	just_ra(stacka);
    write(1, "ra\n", 3);
}

void	just_rb(t_stack **stackb)
{
	if (stack_size(*stackb) == 2)
        swap(stackb);
    else
		rotate(stackb);
}

void    rb(t_stack **stackb)
{
	just_rb(stackb);
    write(1, "rb\n", 3);
}

void    rr(t_stack **stacka, t_stack **stackb)
{
    just_ra(stacka);
	just_rb(stackb);
    write(1, "rr\n", 3); 
}