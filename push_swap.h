/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gltats <gltats@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:34:38 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/04/16 19:22:44 by gltats           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				numb;
	char			bin[33];
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	t_list			*a;
	t_list			*b;
}	t_data;

long int	ft_atol(char *str);

char		*args_to_str(char **argv);
char		*itobin(unsigned int numb, char *aux, int neg);

void		clean_list(t_list *list);
void		parseo(char *str, char **a);
void		push_swap(t_data *data);

void		rotate(t_list **list, char *str);
void		reverse_rotate(t_list **list, char *str);
void		swap(t_list **list, char *str);
void		push(t_list **src, t_list **dst, char *str);

t_list		*new_node(int numb);

#endif
