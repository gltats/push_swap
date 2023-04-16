/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gltats <gltats@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:34:38 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/04/16 19:21:01 by gltats           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isorded(t_list *list, int i)
{
	if (list && list->next)
	{
		if (list->numb > list->next->numb
			|| (i == 1 && list->numb < list->next->numb))
			return (0);
		return (isorded(list->next, i) * 1);
	}
	return (1);
}

int	list_len(t_list *list)
{
	if (list)
		return (list_len(list->next) + 1);
	return (0);
}

int	ispositioned(t_data *data)
{
	int	aux;

	reverse_rotate(&(data->a), "");
	aux = data->a->numb;
	rotate(&(data->a), "");
	return ((data->b->numb < data->a->numb && aux < data->b->numb)
		|| (data->b->numb == 1 && (data->a->numb == 2 || aux == 5))
		|| (data->b->numb == 5 && (data->a->numb == 1 || aux == 4))
		|| (data->b->numb == 2 && (data->a->numb == 3 && aux == 5))
		|| (data->b->numb == 4 && (data->a->numb == 1 && aux == 3)));
}

void	three_five(t_data *data)
{
	while (!isorded(data->a, 0))
		if (data->a->numb < data->a->next->numb
			&& data->a->numb > data->a->next->next->numb)
			reverse_rotate(&(data->a), "rra\n");
	else if (data->a->numb > data->a->next->numb
		&& data->a->numb > data->a->next->next->numb)
		rotate(&(data->a), "ra\n");
	else
		swap(&(data->a), "sa\n");
	while (data->b)
		if (ispositioned(data))
			push(&(data->b), &(data->a), "pa\n");
	else
		if ((data->a->numb == ((data->b->numb + 3) % 5) + 1))
			rotate(&(data->a), "ra\n");
	else
		reverse_rotate(&(data->a), "rra\n");
	while (!isorded(data->a, 0))
		if (data->a->numb > 3)
			rotate(&(data->a), "ra\n");
	else
		reverse_rotate(&(data->a), "rra\n");
}

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

void push_swap(t_data *data)
{
    // int i;
    int numb_iterations;
    int listlen;

    numb_iterations = numb_bits(max_value(data->a));

    if (list_len(data->a) <= 5 && !isorded(data->a, 0))
    {
        while (list_len(data->a) > 3)
            push(&(data->a), &(data->b), "pb\n");
    }
    if (list_len(data->a) == 3)
        three_five(data);

    while (--numb_iterations >= 0 && !isorded(data->a, 0))
    {
        listlen = list_len(data->a);
        while (listlen-- > 0)
        {
            if (data->a->bin[numb_iterations] == '0')
                push(&(data->a), &(data->b), "pb\n");
            else
                rotate(&(data->a), "ra\n");
        }
        while (data->b)
            push(&(data->b), &(data->a), "pa\n");
    }
}