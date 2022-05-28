/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:49 by lhafsi            #+#    #+#             */
/*   Updated: 2022/05/25 20:40:53 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_stack 
{
	int				val;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef	struct s_struct
{
	char	**argv;
	t_stack *stack_a;
	t_stack	*stack_b;
} t_struct;

/* ARG CHECK UTILS */
int		ft_is_space(char c);
long	ft_atol(char *str);

/* ARG CHECK 1 */
int     ft_strcmp(char *s1,char *s2);
int 	ft_check_doubles(int ac, char **av);
int 	ft_check_digit(int ac, char **av);
int 	ft_check_minmax(int ac, char **av);

/* OPERATIONS */
void	push(t_stack **stack1, t_stack **stack2);
t_stack	*rotate(t_stack *stack);
t_stack	*reverse(t_stack *stack);
void	swap(t_stack *stack);

/* OPERATIONS UTILS */
int	ft_atoi(const char *str);
t_stack	*create_elem(int num);
t_stack	*generate_list(char **av);
int	*stack_size(t_stack *stack);

/* OPERATION CALLERS */
/* OP CALL SWAP */
void    sa(t_stack *stacka);
void    sb(t_stack *stackb);
void    ss(t_stack *stacka, t_stack *stackb);

/* OP CALL PUSH */
void    pa(t_stack **stackb, t_stack **stacka);
void    pb(t_stack **stacka, t_stack **stackb);

/* OP CALL ROTATE */
void    ra(t_stack *stacka);
void    rb(t_stack *stackb);
void    rr(t_stack *stacka, t_stack *stackb);

/* OP CALL REVERSE */
void    rra(t_stack *stacka);
void    rrb(t_stack *stackb);
void    rrr(t_stack *stacka, t_stack *stackb);


/* PUSH_SWAP */
// int 	arg_check(int ac, char **av);
int		is_sorted(int ac, char **av);