/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatianasofiagomeslima <tatianasofiagome    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:34:38 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/04/19 18:20:55 by tatianasofi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Checks if the given list is ordered according to the specified ordering (ascending or descending)
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

// Returns the length of the given list
int	list_len(t_list *list)
{
	if (list)
		return (list_len(list->next) + 1);
	return (0);
}

// Checks if the elements in data->a and data->b are correctly positioned relative to each other
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


// Sorts a list with 2 elements
void sort_two(t_data *data)
{
    while (isorded(data->a, 0))
    {
    	ft_putstr("The list is sorted already!\n");
        return;
    }
	swap(&(data->a), "sa\n");
}

// Sorts a list with 3 to 5 elements
void	three_five(t_data *data)
{
    int len = list_len(data->a);
	 if (isorded(data->a, 0))
    {
		ft_putstr("The list is sorted already!\n");
        return;
    }
	if (len == 3)
		sort_three(data);
	else if (len == 4)
		sort_four(data);
	else if (len == 5)
		sort_five(data);
        return;
}

// Main push_swap function that sorts the given list using the push_swap algorithm
void push_swap(t_data *data)
{
    int len = list_len(data->a);

    if (len == 2)
    {
        sort_two(data);
        return;
    }
    else if (len <= 5)
    {
        three_five(data);
        return;
    }
    else
        radix_sort(data, len);

}
