/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatianasofiagomeslima <tatianasofiagome    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:28:58 by tatianasofi       #+#    #+#             */
/*   Updated: 2023/04/17 19:10:35 by tatianasofi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int median_of_three(int a, int b, int c)
{
    if ((a <= b && b <= c) || (c <= b && b <= a))
        return b;
    if ((b <= a && a <= c) || (c <= a && a <= b))
        return a;
    return c;
}

int get_median_pivot(t_data *data, int len)
{
    int first = data->a->numb;
    int middle;
    int last;
    t_list *middle_node;
    t_list *last_node;
    int i;

    middle_node = data->a;
    for (i = 0; i < len / 2; i++)
        middle_node = middle_node->next;
    middle = middle_node->numb;

    last_node = middle_node;
    while (last_node->next)
        last_node = last_node->next;
    last = last_node->numb;

    return median_of_three(first, middle, last);
}

void partition(t_data *data, int pivot, int len, int *left_len, int *right_len)
{
    int processed = 0;
    int left_count = 0;

    *left_len = 0;
    *right_len = 0;

    while (processed < len)
    {
        if (data->a->numb <= pivot)
        {
            push(&(data->a), &(data->b), "pb\n");
            left_count++;
        }
        else
        {
            rotate(&(data->a), "ra\n");
            (*right_len)++;
        }
        processed++;
    }

    while (left_count--)
    {
        push(&(data->b), &(data->a), "pa\n");
        (*left_len)++;
    }
}

void quick_sort(t_data *data, int len)
{
    int pivot;
    int left_len;
    int right_len;

    if (len <= 1)
    {
        return;
    }

    pivot = get_median_pivot(data, len);
    partition(data, pivot, len, &left_len, &right_len);

    quick_sort(data, left_len);
    quick_sort(data, right_len);
}