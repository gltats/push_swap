/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gltats <gltats@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:34:38 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/04/16 19:20:27 by gltats           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
