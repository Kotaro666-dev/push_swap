/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_with_more_than_four_numbers.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:54:19 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/19 16:55:19 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int			find_perfect_position(t_main *main, int target)
{
	t_stack *current;
	int		position;

	current = main->stack_a->next;
	position = 0;
	while (current)
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
	t_stack *tail;

	current = main->stack_a;
	head = main->stack_a;
	while (current)
	{
		if (current->value == target)
		{
			break ;
		}
		current = current->next;
	}
	if (!current->prev)
	{
		tail = current;
		while (tail->next)
		{
			tail = tail->next;
		}
		if (current->value > tail->value &&
		current->value < current->next->value)
		{
			return (TRUE);
		}
		else
		{
			return (FALSE);
		}
	}
	if (!current->next)
	{
		if (current->value > current->prev->value &&
			current->value > head->value)
		{
			return (TRUE);
		}
		else
		{
			return (FALSE);
		}
	}
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

void		sort_stack_with_more_than_four_numbers(t_main *main)
{
	int	position;
	int	target;

	while (main->size > 3)
	{
		push_b(main);
		main->size--;
	}
	while (!is_stack_empty(main->stack_b))
	{
		push_a(main);
		main->size++;
		target = main->stack_a->value;
		position = find_perfect_position(main, target);
		if (position < main->size / 2)
		{
			while (!is_target_right_position(main, target))
			{
				if (is_stack_sorted(main->stack_a))
				{
					return ;
				}
				// 無限ループに陥る。双方向循環リストにしたほうがいい。
				swap_a(main);
				rotate_a(main);
				// print_out_stack(main->stack_a, main->stack_b);
				// return ;
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
				if (is_stack_sorted(main->stack_a))
				{
					return ;
				}
				// 無限ループに陥る。双方向循環リストにしたほうがいい。
				reverse_rotate_a(main);
				swap_a(main);
				// print_out_stack(main->stack_a, main->stack_b);
				// return ;
			}
			while (!is_stack_sorted(main->stack_a))
			{
				rotate_a(main);
			}
		}
	}
}
