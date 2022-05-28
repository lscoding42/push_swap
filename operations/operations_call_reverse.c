/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_call_reverse.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:49 by lhafsi            #+#    #+#             */
/*   Updated: 2022/05/25 23:23:13 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    rra(t_stack **stacka)
{
    if (stack_size(*stacka) == 2)
        swap(*stacka);
    else
    {
        reverse(stacka);
        write(1,"rra\n", 4);
    }
}

void    rrb(t_stack **stackb)
{
    if (stack_size(*stackb) == 2)
        swap(*stackb);
    else
    {
        reverse(stackb);
        write(1,"rrb\n", 4);
    }
}

void    rrr(t_stack **stacka, t_stack **stackb)
{
   	if (stack_size(*stacka) == 2)
        swap(*stacka);
    else
        reverse(stacka);
    if (stack_size(*stackb) == 2)
        swap(*stackb);
    else
        reverse(stackb);
    write(1,"rrr\n", 4); 
}

