/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatianasofiagomeslima <tatianasofiagome    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:28:58 by tatianasofi       #+#    #+#             */
/*   Updated: 2023/04/17 19:01:29 by tatianasofi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void partition(t_data *data, int pivot)
{
    int count = 0;

    while (!isorded(data->a, 0))
    {
        if (data->a->numb <= pivot)
        {
            push(&(data->a), &(data->b), "pb\n");
            count++;
        }
        else
        {
            rotate(&(data->a), "ra\n");
        }
    }

    while (count--)
    {
        push(&(data->b), &(data->a), "pa\n");
    }
}

void quick_sort(t_data *data, int len)
{
    int pivot;

    if (len <= 1)
    {
        return;
    }

    pivot = data->a->numb;
    partition(data, pivot);

    quick_sort(data, len - 1);
    rotate(&(data->a), "ra\n");
    quick_sort(data, len - 1);
}