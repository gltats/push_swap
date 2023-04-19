/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_five_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatianasofiagomeslima <tatianasofiagome    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:28:50 by tatianasofi       #+#    #+#             */
/*   Updated: 2023/04/19 18:36:14 by tatianasofi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Find the index of the smallest element in the list
int find_smallest_index(t_list *list)
{
    int index = 0;
    int smallest_index = 0;
    int smallest_value = list->numb;

    while (list)
    {
        if (list->numb < smallest_value)
        {
            smallest_value = list->numb;
            smallest_index = index;
        }
        list = list->next;
        index++;
    }
    return smallest_index;
}

// Move the smallest element from stack A to stack B
void move_smallest_to_b(t_data *data)
{
    int smallest_index = find_smallest_index(data->a);
    int len = list_len(data->a);

    // Decide whether to use rotate or reverse rotate to reach the smallest element
    if (smallest_index <= len / 2)
    {
        while (smallest_index--)
            rotate(&(data->a), "ra\n");
    }
    else
    {
        while (smallest_index++ < len)
            reverse_rotate(&(data->a), "rra\n");
    }

    push(&(data->a), &(data->b), "pb\n");
}

// Sorts a list with 3 elements
void  sort_three(t_data *data)
{
    int a;
    int b;
    int c;

    a = data->a->numb;
    b = data->a->next->numb;
    c = data->a->next->next->numb;

    if (a > b && a < c)
    {
        swap(&(data->a), "sa\n");
    }
    else if (a > b && b > c)
    {
        swap(&(data->a), "sa\n");
        reverse_rotate(&(data->a), "rra\n");
    }
    else if (a > c && b < c)
    {
        rotate(&(data->a), "ra\n");
    }
    else if (a < b && b > c && a < c)
    {
        swap(&(data->a), "sa\n");
        rotate(&(data->a), "ra\n");
    }
    else if (a < b && b > c && a > c)
    {
        reverse_rotate(&(data->a), "rra\n");
    }
}

// Sorts a list with 4 elements
void sort_four(t_data *data)
{
    // Move the smallest element to stack B
    move_smallest_to_b(data);

    // Sort the remaining 3 elements in stack A
    sort_three(data);

    // Move the smallest element back from stack B to stack A
    push(&(data->b), &(data->a), "pa\n");
}

// Sorts a list with 5 elements
void sort_five(t_data *data)
{
    // Move the two smallest elements to stack B
    move_smallest_to_b(data);
    move_smallest_to_b(data);

    // Sort the remaining three elements in stack A
    sort_three(data);

    // Move the two elements back from stack B to stack A
    if (data->b->numb < data->b->next->numb)
        swap(&(data->b), "sb\n");

    push(&(data->b), &(data->a), "pa\n");
    push(&(data->b), &(data->a), "pa\n");
}