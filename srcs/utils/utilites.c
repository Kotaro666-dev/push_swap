/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilites.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:40:33 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/21 14:55:22 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			is_arg_numeric(char *arg)
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

int			is_stack_empty(t_stack *stack)
{
	if (stack == NULL)
	{
		return (TRUE);
	}
	return (FALSE);
}

int			is_stack_sorted(t_stack *stack)
{
	t_stack *current;
	t_stack *head;

	if (stack == NULL)
	{
		return (TRUE);
	}
	current = stack;
	head = stack;
	while (current->next != head)
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
	t_stack *head;

	first = stack;
	head = stack;
	while (first->next != head)
	{
		second = first->next;
		while (second != head)
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
