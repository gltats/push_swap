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
                // Iterate through each element in the list
        while (j++ < size)
        {
            // If the current bit is set (1), perform a rotate operation
            if (((data->a->numb >> i) & 1) == 1)
                rotate(&(data->a), "ra\n");
            // If the current bit is not set (0), perform a push operation to move the element to stack B
            else
                push(&(data->a), &(data->b), "pb\n");
        }

        // Move all elements back from stack B to stack A
        while (data->b)
            push(&(data->b), &(data->a), "pa\n");
        i++;
    }
}
