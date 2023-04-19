/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatianasofiagomeslima <tatianasofiagome    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:34:38 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/04/19 18:31:52 by tatianasofi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Checks if there are any invalid characters in the input string
int	char_in_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 32
			&& str[i] != '-' && str[i] != '+'
			&& (str[i] <= 47 || str[i] >= 58))
			return (1);
		if ((str[i] == '+' || str[i] == '-')
			&& ((i > 0 && str[i - 1] != ' ') || str[i + 1] == ' '))
			return (1);
		i++;
	}
	return (0);
}

// Checks if any number in the input array exceeds the range of a 32-bit integer
int	int_max(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		if (ft_atol(a[i]) > 2147483647 || ft_atol(a[i]) < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

// Checks if there are any duplicate numbers in the input array
int	isdup(char **a)
{
	int	i;
	int	j;

	i = 0;
	while (a[i])
	{
		j = i;
		while (a[++j])
			if (ft_atol(a[j]) == ft_atol(a[i]))
				return (1);
		i++;
	}
	return (0);
}

// Checks if the input string contains any invalid characters, numbers out of range or duplicates
void	parseo(char *str, char **a)
{	
	if (char_in_str(str))
	{
		ft_putstr("Parsing error!\n");
		ft_putstr("There is a char on your args!\n");
		exit(0);
	}
	if (int_max(a))
	{
		ft_putstr("Parsing error!\n");
		ft_putstr("Your args needs to be between 2147483647 and -2147483648!\n");
		exit(0);
	}
	if (isdup(a))
	{
		ft_putstr("Parsing error!\n");
		ft_putstr("There is a duplicated int!\n");
		exit(0);
	}
}
