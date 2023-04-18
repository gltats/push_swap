/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:36:45 by gltats            #+#    #+#             */
/*   Updated: 2023/04/18 11:42:27 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Returns the maximum value in the given list
static int max_value(t_list *list)
{
    int max_val;

    max_val = list->numb;
    while (list)
    {
        if (list->numb > max_val)
        {
            max_val = list->numb;
        }
        list = list->next;
    }
    return max_val;
}

// Returns the number of bits required to represent the given integer in binary
static int numb_bits(int n)
{
    int bits;

    bits = 0;
    while (n)
    {
        n >>= 1;
        bits++;
    }
    return bits;
}

//calculates the number of iterations needed based on the maximum 
// value in the list and loops through all the bits of the maximum value. 
// In each iteration, it checks the current bit of the element at the 
// head of stack A and pushes it to stack B if the bit is 0 or rotates 
// stack A if the bit is 1. After all elements are checked, it pushes
//  all elements back from stack B to stack A. 
 
//  The process continues until the list is sorted or 
//  all the bits have been checked.
void radix_sort(t_data *data, int len)
{
    int max_val = max_value(data->a);
    int numb_iterations = numb_bits(max_val);
    int bit_position;
    int listlen;

    while (--numb_iterations >= 0 && !isorded(data->a, 0))
    {
        bit_position = 1 << numb_iterations;
        listlen = len;
        while (listlen-- > 0)
        {
            if ((data->a->numb & bit_position) == 0)
                push(&(data->a), &(data->b), "pb\n");
            else
                rotate(&(data->a), "ra\n");
        }

        while (data->b)
            push(&(data->b), &(data->a), "pa\n");
    }
}
