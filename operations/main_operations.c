
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_stack 
{
	int				val;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int	ft_is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long int	result;
	int			i;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

t_stack	*create_elem(int num)
{
	t_stack	*elem;

	elem = malloc(sizeof(elem));
	elem->val = num;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

t_stack	*generate_list(char **av)
{
	t_stack	*head;
	t_stack	*next_node;
	t_stack	*current;
	int		i;

	head = create_elem(ft_atoi(av[1]));
	current = head;
	i = 2;
	while (av[i])
	{
		next_node = create_elem(ft_atoi(av[i]));
		next_node->prev = current;
		current->next = next_node;
		current = next_node;
		i++;
	}
	return (head);
}

int	stack_size(t_stack *stack)
{
	int		i;

    i = 1;
	if (!stack)
		return (0);
	while (stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	swap(t_stack **stack)
{
	int	temp;

	if (!(*stack) || !((*stack)->next) || stack_size(*stack) < 2)
		return ;
	temp = (*stack)->val;
	(*stack)->val = (*stack)->next->val;
	(*stack)->next->val = temp;
}

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
	first_1->next = *stack2;
	first_1->prev = NULL;
	*stack2 = first_1;
	*stack1 = head;
}

void	rotate(t_stack **stack)
{
	t_stack *current;
	t_stack *temp;

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
	temp->next= NULL;
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

void    sa(t_stack **stacka)
{
	swap(stacka);
	write(1,"sa\n", 3);
}

void    sb(t_stack **stackb)
{
	swap(stackb);
	write(1,"sb\n", 3);
}

void    ss(t_stack **stacka, t_stack **stackb)
{
	swap(stacka);
	swap(stackb);
	write(1,"ss\n", 3);
}
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

void    ra(t_stack **stacka)
{
	
    if (stack_size(*stacka) == 2)
        swap(stacka);
    else
	{	
		rotate(stacka);
        write(1,"ra\n", 3);
	}
}

void    rb(t_stack **stackb)
{
    if (stack_size(*stackb) == 2)
        swap(stackb);
    else
    {
        rotate(stackb);
        write(1,"rb\n", 3); 
    }
}

void    rr(t_stack **stacka, t_stack **stackb)
{
    if (stack_size(*stacka) == 2)
        swap(stacka);
    else
        rotate(stacka);
	if (stack_size(*stackb) == 2)
        swap(stackb);
	else
        rotate(stackb);
    write(1,"rr\n", 3); 
}

void    rra(t_stack **stacka)
{
    if (stack_size(*stacka) == 2)
        swap(stacka);
    else
    {
        reverse(stacka);
        write(1,"rra\n", 4);
    }
}

void    rrb(t_stack **stackb)
{
    if (stack_size(*stackb) == 2)
        swap(stackb);
    else
    {
        reverse(stackb);
        write(1,"rrb\n", 4);
    }
}

void    rrr(t_stack **stacka, t_stack **stackb)
{
   	if (stack_size(*stacka) == 2)
        swap(stacka);
    else
        reverse(stacka);
    if (stack_size(*stackb) == 2)
        swap(stackb);
    else
        reverse(stackb);
    write(1,"rrr\n", 4); 
}

void    display_list(t_stack *stack)
{
	int i = 0;
    while (stack)
    {
        printf("Num = %d / index= %d\n", stack->val, i);
        stack = stack->next;
		i++;
    }
}

void    display_reverse(t_stack *st)
{
	t_stack *stack;

	stack = st;
    while (stack)
    {
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
	t_stack *stacka;
	t_stack *stackb;

	if (argc < 2)
	{
		printf("Error\n");
		return (0);
	}
	(void)argc;
	stacka = generate_list(argv);
	stackb = NULL;

	//SA
	// printf("-----Stack A before SA-----\n");
	// display_list(stacka);
	// sa(&stacka);
	// printf("-----Stack A after SA-----\n");
	// display_list(stacka);
	// display_reverse(stacka);

	// SB
	// printf("-----Stack B before SB-----\n");
	// display_list(stacka);
	// sb(&stacka);
	// display_list(stacka);
	// display_reverse(stacka);

	//SS
	// pb(&stacka, &stackb);//fill stack b bc its empty
	// pb(&stacka, &stackb);//fill stack b bc its empty
	printf("-----Stack A before SS-----\n");
	display_list(stacka);
	printf("-----Stack B before SS-----\n");
	display_list(stackb);
	ss(&stacka, &stackb);
	printf("-----BOTH after SS-----\n");
	// display_both(stacka, stackb);
	// printf("-----Stack A after -in reverse-----\n");
	// display_reverse(stacka);
	// printf("-----Stack B after -in reverse-----\n");
	// display_reverse(stackb);

	// PB
	// printf("-----Stack A before PB-----\n");
	// display_list(stacka);
	// pb(&stacka, &stackb);
	// display_both(stacka, stackb);

	// PA
	// printf("-----Stack B before PA-----\n");
	// display_list(stackb);
	// pb(&stacka, &stackb);
	// pb(&stacka, &stackb);
	// pa(&stackb, &stacka);
	// display_both(stacka, stackb);

	// RA
	// printf("-----Stack A before RA-----\n");
	// display_list(stacka);
	// ra(&stacka);
	// printf("-----Stack A after RA-----\n");
	// display_list(stacka);
	// display_reverse(stacka);

	// RB
	// printf("-----Stack B before RB-----\n");
	// display_list(stacka);
	// rb(&stacka);
	// printf("-----Stack B after RB-----\n");
	// display_list(stacka);
	// display_reverse(stacka);

	// RR
	// pb(&stacka, &stackb);//fill stack b bc its empty
	// pb(&stacka, &stackb);//fill stack b bc its empty
	// printf("-----BOTH before RB-----\n");
	// display_both(stacka, stackb);
	// rr(&stacka, &stackb);
	// printf("-----BOTH B after RB-----\n");
	// display_both(stacka, stackb);
	// display_reverse(stacka);
	// display_reverse(stackb);

	// RRA
	// printf("-----Stack A before RRB-----\n");
	// display_list(stacka);
	// rra(&stacka);
	// printf("-----Stack A after RRB-----\n");
	// display_list(stacka);
	// display_reverse(stacka);

	// // RRB
	// printf("-----Stack B before RRA-----\n");
	// display_list(stacka);
	// rrb(&stacka);
	// printf("-----Stack B after RRA-----\n");
	// display_list(stacka);
	// display_reverse(stacka);

	// RRR
	// pb(&stacka, &stackb);//fill stack b bc its empty
	// pb(&stacka, &stackb);//fill stack b bc its empty
	// printf("-----BOTH before RRR-----\n");
	// display_both(stacka, stackb);
	// rrr(&stacka, &stackb);
	// printf("-----BOTH after RRR-----\n");
	// display_both(stacka, stackb);
	// display_reverse(stacka);
	// display_reverse(stackb);
}

/*
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

int main(int argc, char **argv)
{
	t_stack *stacka;

	(void)argc;
	stacka = generate_list(argv);
	display_list(stacka);
    printf("\nSTACK SIZE = %d\n", stack_size(stacka));
}*/
