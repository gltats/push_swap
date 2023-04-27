/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_four_five_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:28:50 by tatianasofi       #+#    #+#             */
/*   Updated: 2023/04/27 12:54:46 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Find the index of the smallest element in the list
int	find_smallest_index(t_list *list)
{
	int	index;
	int	smallest_index;
	int	smallest_value;

	index = 0;
	smallest_index = 0;
	smallest_value = list->numb;
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
	return (smallest_index);
}

// Move the smallest element from stack A to stack B
//l48 Decide whether to use rotate or reverse rotate
// to reach the smallest element
void	move_smallest_to_b(t_data *data)
{
	int	smallest_index;
	int	len;

	smallest_index = find_smallest_index(data->a);
	len = list_len(data->a);
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
void	sort_three(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->a->numb;
	b = data->a->next->numb;
	c = data->a->next->next->numb;
	if (a > b && a < c)
		swap(&(data->a), "sa\n");
	else if (a > b && b > c)
	{
		swap(&(data->a), "sa\n");
		reverse_rotate(&(data->a), "rra\n");
	}
	else if (a > c && b < c)
		rotate(&(data->a), "ra\n");
	else if (a < b && b > c && a < c)
	{
		swap(&(data->a), "sa\n");
		rotate(&(data->a), "ra\n");
	}
	else if (a < b && b > c && a > c)
		reverse_rotate(&(data->a), "rra\n");
}

// Sorts a list with 4 elements
//l101 Move the smallest element to stack B
//l102 Sort the remaining 3 elements in stack A
//l103 Move the smallest element back from B to A
void	sort_four(t_data *data)
{
	move_smallest_to_b(data);
	sort_three(data);
	push(&(data->b), &(data->a), "pa\n");
}

// Sorts a list with 5 elements
//l111 Move the two smallest elements to stack B
//l114 Sort the remaining three elements in stack A
//l117 Move the two elements back from stack B to stack A
void	sort_five(t_data *data)
{
	move_smallest_to_b(data);
	move_smallest_to_b(data);
	sort_three(data);
	if (data->b->numb < data->b->next->numb)
		swap(&(data->b), "sb\n");
	push(&(data->b), &(data->a), "pa\n");
	push(&(data->b), &(data->a), "pa\n");
}
