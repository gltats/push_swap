/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:34:38 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/04/18 11:42:50 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rotates the elements of the given list by one position to the left
void	rotate(t_list **list, char *str)
{
	t_list	*aux;

	if ((*list)->next)
	{
		aux = *list;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = *list;
		*list = (*list)->next;
		aux = aux->next;
		aux->next = NULL;
		write(1, str, ft_strlen(str));
	}
}

// Rotates the elements of the given list by one position to the right
void	reverse_rotate(t_list **list, char *str)
{
	t_list	*aux;

	if ((*list)->next)
	{
		aux = *list;
		while ((*list)->next != NULL)
			(*list) = (*list)->next;
		(*list)->next = aux;
		while (aux->next != *list)
			aux = aux->next;
		aux->next = NULL;
		write(1, str, ft_strlen(str));
	}
}

// Swaps the first two elements of the given list
void	swap(t_list **list, char *str)
{
	t_list	*aux;

	if ((*list)->next)
	{
		aux = *list;
		(*list) = (*list)->next;
		aux->next = (*list)->next;
		(*list)->next = aux;
		write(1, str, ft_strlen(str));
	}
}

// Moves the first element of the source list to the destination list
void	push(t_list **src, t_list **dst, char *str)
{
	t_list	*aux;

	if (*src)
	{
		aux = *src;
		(*src) = (*src)->next;
		aux->next = *dst;
		*dst = aux;
		write(1, str, ft_strlen(str));
	}
}
 