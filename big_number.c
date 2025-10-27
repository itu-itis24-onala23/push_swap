#include "push_swap.h"
 static void debug_pb(t_list **a, t_list **b)
{
    pb(a, b);  // Elemanı B'ye gönder

    printf("---- Debug after pb ----\n");
    printf("Stack A: ");
    t_list *tmp = *a;
    while (tmp)
    {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");

    printf("Stack B: ");
    tmp = *b;
    while (tmp)
    {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n------------------------\n");
}

static void set_index(t_list **stack_a)
{
    t_list *temp;
    t_list *first;
    int     index;

    first = *stack_a;
    while(first)
    {
        index = 0;
        temp = *stack_a;
        while(temp)
        {
            if(temp->value < first->value)
                index++;
            temp = temp->next;
        }
        first->index = index;
        first = first->next;
    }
}

static int find_bit(int number)
{
    int i;

    i = 0;
    if(number == 0)
        return (1);
    while(number >> i != 0)
        i++;
    return (i);
}
void big_number(t_list **a, t_list **b, int size)
{
    int max_bits;
    int i;
    int j;

    i = 0;
    max_bits = find_bit(size - 1);
    set_index(a);
    while(i < max_bits)
    {
        j = 0;
        printf("kac tane nodeun var %d\n",size);
        size = count_nodes(*a);
        while(j < size)
        {
            printf("kacinci döngü %d\n",j);
            if((((*a)->index >> i) & 1 ) == 0)
            {
                printf("b ye gidecek olan deger %d\n",(*a)->value);
                pb(a,b);
                printf("b stacki :");
                print_stack(*b);
                printf("a stacki: ");
                print_stack(*a);
                debug_pb(a,b);
            }
            else
                ra(a);
            j++;
        }
        printf("b stacki boşalmadan önce\n ");
        print_stack(*b);
        print_stack(*a);
        while(*b)
        {
            pa(b,a);

        }
        i++;
        printf("buraya geldi mi\n");
    }
}