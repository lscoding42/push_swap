/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_call_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:49 by lhafsi            #+#    #+#             */
/*   Updated: 2022/05/25 23:14:11 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    pa(t_stack **stackb, t_stack **stacka)
{
    push(stackb, stacka);
    write(1,"pa\n", 3);
}

void    pb(t_stack **stacka, t_stack **stackb)
{
    push(stacka, stackb);
    write(1,"pb\n", 3);
}

