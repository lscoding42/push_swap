/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:49 by lhafsi            #+#    #+#             */
/*   Updated: 2022/11/23 10:37:23 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/****************************************************************************/
/******************               STRUCTS              **********************/
/****************************************************************************/

typedef struct s_stack 
{
	int				val;
	int				max;
	int				index;
	int				max_ind;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef	struct s_struct
{
	char	**argv;
	t_stack *stack_a;
	t_stack	*stack_b;
} t_struct;

/****************************************************************************/
/******************               MAIN                 **********************/
/****************************************************************************/

/* PUSH_SWAP */
void	display_both(t_stack *stacka, t_stack *stackb);
int 	arg_check(int ac, char **av);
int		is_sorted(int ac, char **av);
t_stack	*call_stack(char **av);
void	call_algo(t_stack **stacka);

/****************************************************************************/
/******************                ARGS                **********************/
/****************************************************************************/

/* ARG CHECK UTILS */
int		ft_is_digit(int c);
int		ft_is_space(char c);
long	ft_atol(char *str);
int		ft_atoi(char *str);

/* ARG CHECK 1 */
int 	ft_check_doubles(int ac, char **av);
int 	ft_check_digit(int ac, char **av);
int 	ft_check_minmax(int ac, char **av);

/* ERROR_MANAGER */
void	ft_putstr_fd(char *s, int fd);
int		error_manager(int ac, char **av);

/****************************************************************************/
/******************             LIST INIT              **********************/
/****************************************************************************/

/* LIST_INIT */
int  	ft_strlen(char *str);
t_stack	*create_elem(int num);
t_stack	*generate_list(char **av);
int		stack_size(t_stack *stack);
void	clear_stack(t_stack **stack);
// void	display_list(t_stack *stack);
// void    display_reverse(t_stack *st);

/****************************************************************************/
/******************             OPERATIONS             **********************/
/****************************************************************************/

/* OPERATIONS */
void	push(t_stack **stack1, t_stack **stack2);
void	rotate(t_stack **stack);
void	reverse(t_stack **stack);
void	swap(t_stack **stack);


/* OPERATION CALLERS */
/* OP CALL SWAP */
void    sa(t_stack **stacka);
void    sb(t_stack **stackb);
void    ss(t_stack **stacka, t_stack **stackb);

/* OP CALL PUSH */
void    pa(t_stack **stackb, t_stack **stacka);
void    pb(t_stack **stacka, t_stack **stackb);

/* OP CALL ROTATE */
void	just_ra(t_stack **stacka);
void	just_rb(t_stack **stackb);
void    ra(t_stack **stacka);
void    rb(t_stack **stackb);
void    rr(t_stack **stacka, t_stack **stackb);

/* OP CALL REVERSE */
void	just_rra(t_stack **stacka);
void	just_rrb(t_stack **stackb);
void    rra(t_stack **stacka);
void    rrb(t_stack **stackb);
void    rrr(t_stack **stacka, t_stack **stackb);

/****************************************************************************/
/******************                ALGO                **********************/
/****************************************************************************/

/* SMALL ALGO */
int		ft_check_order(int ac, char **av);
void    sort_two(t_stack **stack);
void    sort_three(t_stack **stack);
void    sort_five(t_stack **stacka, t_stack **stackb);

/* BIG ALGO*/
void	assign_index(t_stack *stack);
int		find_max_bits(t_stack **stack);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

/* ALGO UTILS*/
// t_stack	*find_min(t_stack *stack);
// t_stack	*find_max(t_stack *stack);
int     find_min_index(t_stack *stack);
// int     find_max_index(t_stack *stack);