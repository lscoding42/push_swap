/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_minmax.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:43 by lhafsi            #+#    #+#             */
/*   Updated: 2022/11/23 03:31:04 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int         find_min_index(t_stack *stack)
{
    int     i;
    int     j;
    t_stack *current;
    t_stack *min;
    
    min = stack;
    current = stack->next;
    i = 1;
    j = 1;
    while (current)
    {
        j++;
        if ((min->val) > (current->val))
        {
            min = current;
            i = j;
        }
        current = current->next;
    }
    return (i);
}

// t_stack    *find_min(t_stack *stack)
// {
//     t_stack *min;
//     t_stack *current;
    
//     min = stack;
//     current = stack->next;
//     while (current)
//     {
//         if (min->val > (current->val))
//             min = current;
//         current = current->next;
//     }
//     return (min);
// }