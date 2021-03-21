/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_target_in_right_position.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:51:15 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/21 17:52:12 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			is_target_suitable_in_head(t_stack *current)
{
	if (current->value > current->prev->value &&
		current->value < current->next->value)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

int			is_target_suitable_in_tail(t_stack *current)
{
	if (current->value > current->prev->value &&
		current->value > current->next->value)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

int			is_target_suitable_in_middle(t_stack *current)
{
	if (current->value > current->prev->value &&
		current->value < current->next->value)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

int			is_target_in_right_position(t_main *main, int target)
{
	t_stack *current;
	t_stack *head;

	current = main->stack_a;
	head = main->stack_a;
	while (current->next != head)
	{
		if (current->value == target)
			break ;
		current = current->next;
	}
	if (current == head)
	{
		return (is_target_suitable_in_head(current));
	}
	else if (current->next == head)
	{
		return (is_target_suitable_in_tail(current));
	}
	else
	{
		return (is_target_suitable_in_middle(current));
	}
}
