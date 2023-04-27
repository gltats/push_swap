/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:34:38 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/04/27 13:06:46 by tgomes-l         ###   ########.fr       */
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

int			list_len(t_list *list);
int			isorded(t_list *list, int i);

void		sort_three(t_data *data);
void		sort_four(t_data *data);
void		sort_five(t_data *data);
void		sort_two(t_data *data);
void		radix_sort(t_data *data);

t_list		*new_node(int numb);

#endif
