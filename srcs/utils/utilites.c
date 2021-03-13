/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilites.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:40:33 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/14 08:27:40 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		is_arg_numeric(char *arg)
{
	int i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
	{
		i++;
	}
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
		{
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int		is_stack_empty(t_stack *stack)
{
	if (stack == NULL)
	{
		return (TRUE);
	}
	return (FALSE);
}

int		is_stack_sorted(t_stack *stack)
{
	t_stack *current;

	if (stack == NULL)
	{
		return (TRUE);
	}
	current = stack;
	while (current->next)
	{
		if (current->value > current->next->value)
		{
			return (FALSE);
		}
		current = current->next;
	}
	return (TRUE);
}
