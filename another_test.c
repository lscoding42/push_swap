#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
    int             index;
}                   t_list;

t_list	*ft_lstlast(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	ft_lstadd_back(t_list **list, char *av, t_list *head, int i)
{
	t_list	*elem;
    t_list	*new;

    new = malloc(sizeof(t_list));
    if (new == NULL || !*list)
        return ;
	elem = ft_lstlast(head);
	elem->next = new;
    new->str = av;
    new->index = i;
    new->next = NULL;
}

void    displayList(t_list *lst, t_list *head)
{
    t_list *tmp = head;
    while (tmp)
    {
        printf("tmp->str = %s | index = %d\n", tmp->str, tmp->index);
        tmp = tmp->next;
    }
}

void    initialisation(char **av, int ac)
{
    t_list  *list;
    t_list  *tmp;
    t_list  *head;
    int     i;
    
    if (ac <= 1)
        return ;
    list = malloc(sizeof(t_list));
    if (list == NULL)
        return ;
    i = 1;
    head = list;
    tmp = head;
    list->str = av[i];
    list->index = i;
    list->next = NULL;
    i++;
    while (i <= ac - 1)
    {
        printf("first while : %i\n", i);
        list = malloc(sizeof(t_list));
        if (list == NULL)
           return ;
        ft_lstadd_back(&list, av[i], head, i);
        i++;
    }
    printf("head->str = %s\n", head->str);
    displayList(list, head);
}

int main(int ac, char **av)
{
    initialisation(av, ac);
    return(0);
}
