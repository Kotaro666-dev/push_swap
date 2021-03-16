/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilites.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:40:33 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/16 22:27:07 by kkamashi         ###   ########.fr       */
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

int			is_every_number_unique(t_stack *stack)
{
	t_stack	*first;
	t_stack	*second;

	first = stack;
	while (first->next)
	{
		second = first->next;
		while (second)
		{
			if (first->value == second->value)
			{
				return (FALSE);
			}
			second = second->next;
		}
		first = first->next;
	}
	return (TRUE);
}
