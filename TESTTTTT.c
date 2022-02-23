#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}					t_list;

/*
typedef struct s_data
{
	int			argv;
}				t_data; */

void    initialisation(char **av, int ac)
{
    t_list  *list;
    t_list  *tmp;
    t_list  *first_node;
    int     i;

    list = malloc(sizeof(t_list));
    if (list == NULL)
        return ;
    i = 1;
    list->str = av[i];
    first_node = list;
    list = list->next;
    i++;
    while (i < ac)
    {
        list = malloc(sizeof(t_list));
        if (list == NULL)
            return ;
        if (i == 2)
            first_node->next = list;
        else
            tmp->next = list;
        tmp = list;
        list->str = av[i];
        list = list->next;
        i++;
    }
    tmp->next = NULL;
    i = 1;
    while (first_node != NULL)
    {
        printf("%s\n", av[i]);
        i++;
        first_node = first_node->next;
    }
}

int main(int ac, char **av)
{
    initialisation(av, ac);
    return(0);
}

    // ft_printlst(numbers);
// void    ft_printlst(t_list *stack_a)
// {
//     if (!stack_a)
//         return ;
//     while (stack_a && stack_a->content)
//     {
//         if (stack_a && stack_a->content)
//             printf("|%i|", stack_a->content);
//         else
//             printf("| |");
//         printf(" | |\n");
//         stack_a = stack_a->next;
//     }
//     printf("  -\n");
//     printf("  A\n");
// }