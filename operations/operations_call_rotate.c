/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_call_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:49 by lhafsi            #+#    #+#             */
/*   Updated: 2022/05/25 23:22:53 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    ra(t_stack **stacka)
{
	
    if (stack_size(*stacka) == 2)
        swap(*stacka);
    else
	{	
		rotate(stacka);
        write(1,"ra\n", 3);
	}
}

void    rb(t_stack **stackb)
{
    if (stack_size(*stackb) == 2)
        swap(*stackb);
    else
    {
        rotate(stackb);
        write(1,"rb\n", 3); 
    }
}

void    rr(t_stack **stacka, t_stack **stackb)
{
    if (stack_size(*stacka) == 2)
        swap(*stacka);
    else
        rotate(stacka);
	if (stack_size(*stackb) == 2)
        swap(*stackb);
	else
        rotate(stackb);
    write(1,"rr\n", 3); 
}
