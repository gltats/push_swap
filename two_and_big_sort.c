/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_and_big_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:36:45 by gltats            #+#    #+#             */
/*   Updated: 2023/04/27 13:18:13 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sorts a list with 2 elements
void	sort_two(t_data *data)
{
	while (isorded(data->a, 0))
	{
		ft_putstr("The list is sorted already!\n");
		return ;
	}
	swap(&(data->a), "sa\n");
}

//l43 Iterate through each element in the list
//l47 If the current bit is set (1), perform 
//a rotate operation
//l51 If the current bit is not set (0), 
//perform a push operation to move the element to stack B
//l55 Move all elements back from stack B to stack A
void	radix_sort(t_data *data)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = list_len(data->a);
	while (isorded(data->a, 0))
	{
		ft_putstr("The list is sorted already!\n");
		return ;
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
