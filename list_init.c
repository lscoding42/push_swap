/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:49 by lhafsi            #+#    #+#             */
/*   Updated: 2022/11/23 07:18:59 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int  ft_strlen(char *str)
{
        int     i;

        i = 0;
        while (str[i])
                i++;
        return (i);
}

t_stack	*create_elem(int num)
{
	t_stack	*elem;

	elem = malloc(sizeof(*elem));
	if (!elem)
		return (NULL);
	elem->val = num;
	elem->index = -1;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

t_stack	*generate_list(char **av)
{
	t_stack	*head;
	t_stack	*next_copy;
	t_stack	*current;
	int		i;

	head = create_elem(ft_atoi(av[1]));
	current = head;
	i = 2;
	while (av[i])
	{
		next_copy = create_elem(ft_atoi(av[i]));
		next_copy->prev = current;
		current->next = next_copy;
		current = next_copy;
		i++;
	}
	return (head);
}

int	stack_size(t_stack *stack)
{
	int		i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	clear_stack(t_stack **stack)
{
	t_stack	*copy;
	t_stack	*tmp;

	copy = *stack;
	while (copy)
	{
		tmp = copy;
		copy = copy->next;
		free(tmp);
	}
}

// void	clear_stack(t_stack **lst, void (*del)(void *))
// {
// 	t_stack	*elem;

// 	if (!del)
// 		return ;
// 	while (*lst)
// 	{
// 		del((*lst)->val);
// 		del((*lst)->index);
// 		del((*lst)->max);
// 		del((*lst)->max_ind);
// 		elem = *lst;
// 		*lst = elem->next;
// 		free(elem);
// 	}
// 	*lst = NULL;
// }

// void    display_reverse(t_stack *st)
// {
// 	t_stack *stack;

// 	stack = st;
//     while (stack)
//     {
// 		if(stack->next == NULL)
// 			break;
// 		stack = stack->next;
//     }
// 	// printf("dans lautre sens mtn\n");
// 	 while (stack)
//     {
//         // printf("Num = %d\n", stack->val);
//         stack = stack->prev;
//     }
// }

// void	display_list(t_stack *st)
// {
// 	t_stack *stack;

// 	stack = st;
//     while (stack)
//     {
// 		printf("Num = %d\n", stack->val);
// 		if(stack->next == NULL)
// 			break;
// 		stack = stack->next;
//     }
// }
