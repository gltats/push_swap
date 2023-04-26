/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:36:45 by gltats            #+#    #+#             */
/*   Updated: 2023/04/26 19:20:29 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// // Returns the maximum value in the given list
// static int max_value(t_list *list)
// {
//     int max_val;

//     max_val = list->numb;
//     while (list)
//     {
//         if (list->numb > max_val)
//         {
//             max_val = list->numb;
//         }
//         list = list->next;
//     }
//     return max_val;
// }

// // Returns the number of bits required to represent the given integer in binary
// static int numb_bits(int n)
// {
//     int bits;

//     bits = 0;
//     while (n)
//     {
//         n >>= 1;
//         bits++;
//     }
//     return bits;
// }

//calculates the number of iterations needed based on the maximum 
// value in the list and loops through all the bits of the maximum value. 
// In each iteration, it checks the current bit of the element at the 
// head of stack A and pushes it to stack B if the bit is 0 or rotates 
// stack A if the bit is 1. After all elements are checked, it pushes
//  all elements back from stack B to stack A. 
 
//  The process continues until the list is sorted or 
//  all the bits have been checked.
void radix_sort(t_data *data)
{
    int i = 0;
    int j;
    int size = list_len(data->a);

    while (isorded(data->a, 0))
    {
    	ft_putstr("The list is sorted already!\n");
        return;
    }
    while (!isorded(data->a, 0))
    {
        j = 0;
        while (j++ < size)
        {
            if (((data->a->numb >> i) & 1) == 1)
                rotate(&(data->a), "ra\n");
            else
                push(&(data->a), &(data->b), "pb\n");
        }

        while (data->b)
            push(&(data->b), &(data->a), "pa\n");

        i++;
    }
}

// // Swap two list elements
// void swap_elements(t_list *a, t_list *b)
// {
//     int temp = a->numb;
//     a->numb = b->numb;
//     b->numb = temp;
// }

// // Partition the list using a pivot element
// t_list *partition(t_list *head, t_list *end, t_list **new_head, t_list **new_end)
// {
//     t_list *pivot = end;
//     t_list *prev = NULL, *cur = head, *tail = pivot;

//     while (cur != pivot)
//     {
//         if (cur->numb < pivot->numb)
//         {
//             if (*new_head == NULL)
//                 *new_head = cur;

//             prev = cur;
//             cur = cur->next;
//         }
//         else
//         {
//             if (prev)
//                 prev->next = cur->next;

//             t_list *tmp = cur->next;
//             cur->next = NULL;
//             tail->next = cur;
//             tail = cur;
//             cur = tmp;
//         }
//     }

//     if (*new_head == NULL)
//         *new_head = pivot;

//     *new_end = tail;
//     return pivot;
// }

// // Recursive Quick Sort function
// t_list *quick_sort_recur(t_list *head, t_list *end)
// {
//     if (!head || head == end)
//         return head;

//     t_list *new_head = NULL, *new_end = NULL;
//     t_list *pivot = partition(head, end, &new_head, &new_end);

//     if (new_head != pivot)
//     {
//         t_list *tmp = new_head;
//         while (tmp->next != pivot)
//             tmp = tmp->next;
//         tmp->next = NULL;

//         new_head = quick_sort_recur(new_head, tmp);
//         tmp = get_tail(new_head);
//         tmp->next = pivot;
//     }

//     pivot->next = quick_sort_recur(pivot->next, new_end);
//     return new_head;
// }

// // Quick Sort function
// void quick_sort(t_data *data)
// {
//     data->a = quick_sort_recur(data->a, get_tail(data->a));
// }