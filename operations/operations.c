/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:49 by lhafsi            #+#    #+#             */
/*   Updated: 2022/06/06 06:38:57 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stack)
{
	int temp;

	if (!(*stack) || !((*stack)->next) || stack_size(*stack) < 2)
		return ;
	temp = (*stack)->val;
	(*stack)->val = (*stack)->next->val;
	(*stack)->next->val = temp;
}

// void	swap(t_stack **stack)
// {
// 	t_stack *current;
// 	t_stack *temp;
	
// 	current = *stack;
// 	temp = current->next;
// 	temp->prev = NULL;
// 	current->next = temp->next;
// 	current->next->prev = current;
// 	current->prev = temp;
// 	temp->next = current;
// 	*stack = temp;
// }

void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*first_1;
	t_stack	*head;

	if (!*stack1)
		return ;
	first_1 = *stack1;
	if ((*stack1)->next)
	{
		head = first_1->next;
		head->prev = NULL;
	}
	else
		head = NULL;
	if (*stack2)
		(*stack2)->prev = first_1;
	first_1->next = (*stack2);
	first_1->prev = NULL;
	*stack2 = first_1;
	*stack1 = head;
}

void	rotate(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;

	if (!(*stack) || !((*stack)->next))
		return ;
	(*stack)->next->prev = NULL;
	current = *stack;
	temp = *stack;
	*stack = (*stack)->next;
	while (current->next)
		current = current->next;
	current->next = temp;
	temp->prev = current;
	temp->next = NULL;
}

void	reverse(t_stack **stack)
{
	t_stack	*current;
	t_stack	*second;
	t_stack	*last;

	if (!(*stack) || !((*stack)->next))
		return ;
	current = *stack;
	second = *stack;
	while (current->next)
		current = current->next;
	last = current->prev;
	last->next = NULL;
	second->prev = current;
	current->next = second;
	current->prev = NULL;
	*stack = current;
}