/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ope.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:43 by lhafsi            #+#    #+#             */
/*   Updated: 2022/05/25 10:53:06 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void    display_list(t_stack *st)
{
	t_stack *stack;

	stack = st;
    while (stack)
    {
        printf("Num = %d\n", stack->val);
		if(stack->next == NULL)
			break;
		stack = stack->next;
    }
	printf("dans lautre sens mtn\n");
	 while (stack)
    {
        printf("Num = %d\n", stack->val);
        stack = stack->prev;
    }
}

void	display_both(t_stack *stacka, t_stack *stackb)
{
	printf("----Stack a ------\n");
	display_list(stacka);
	printf("----Stack b ------\n");
	display_list(stackb);
}

int main(int argc, char **argv)
{
	// t_struct	*general;

	// general = sizeof(t_struct);
	// if bla
	t_stack *stacka;
	t_stack *stackb;

	(void)argc;
	stacka = generate_list(argv);
	stackb = NULL;
	// printf("-----Stack a-----\n");
	// display_list(stacka);
	// // stackb = NULL;
	// pb(&stacka, &stackb);
	// // pb(&stacka, &stackb);
	// printf("----after pb------\n");
	// display_both(stacka, stackb);
	// pb(&stackb, &stacka);
	// printf("----after pa------\n");
	// display_both(stacka, stackb);
	// printf("----after swap------\n");
	// swap(stacka);
	// display_list(stacka);
	
	// printf("-----Stack a before rotate-----\n");
	// display_list(stacka);
	// stacka = rotate(stacka);
	// printf("-----Stack a after rotate-----\n");
	// display_list(stacka);
	
	// printf("-----Stack a before rev-----\n");
	// display_list(stacka);
	// stacka = reverse(stacka);
	// printf("-----Stack a after rev-----\n");
	// display_list(stacka);
	
	// printf("-----Stack before push-----\n");
	// display_both(stacka, stackb);
	// push(&stacka, &stackb);
	// display_both(stacka, stackb);
	// push(&stacka, &stackb);
	// display_both(stacka, stackb);
	// push(&stacka, &stackb);
	// display_both(stacka, stackb);
	// push(&stacka, &stackb);
	// printf("-----Stack after push-----\n");
	// display_both(stacka, stackb);		
}