/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_with_small_numbers.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:54:19 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/20 21:33:06 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int			find_perfect_position(t_main *main, int target)
{
	t_stack	*current;
	t_stack	*head;
	int		position;

	current = main->stack_a->next;
	head = main->stack_a;
	position = 0;
	while (current != head)
	{
		if (target < current->value)
		{
			break ;
		}
		current = current->next;
		position++;
	}
	return (position);
}

static int			is_target_right_position(t_main *main, int target)
{
	t_stack *current;
	t_stack *head;

	current = main->stack_a;
	head = main->stack_a;
	while (current->next != head)
	{
		if (current->value == target)
		{
			break ;
		}
		current = current->next;
	}
	if (current == head)
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
	else if (current->next == head)
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
	else
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
}

void			sort_stack_with_small_numbers(t_main *main)
{
	int	position;
	int	target;

	while (main->size > 3)
	{
		push_b(main);
		main->size--;
	}
	sort_stack_with_three_numbers(main);
	while (!is_stack_empty(main->stack_b))
	{
		push_a(main);
		main->size++;
		target = main->stack_a->value;
		position = find_perfect_position(main, target);
		if (position == 0)
		{
			continue;
		}
		else if (position == main->size - 1)
		{
			rotate_a(main);
		}
		else if (position < main->size / 2)
		{
			while (!is_target_right_position(main, target))
			{
				swap_a(main);
				rotate_a(main);
			}
			while (!is_stack_sorted(main->stack_a))
			{
				reverse_rotate_a(main);
			}
		}
		else
		{
			while (!is_target_right_position(main, target))
			{
				reverse_rotate_a(main);
				swap_a(main);
			}
			while (!is_stack_sorted(main->stack_a))
			{
				rotate_a(main);
			}
		}
	}
}
