/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:28:38 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/19 19:24:42 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void			initialize_struct(t_main *main)
{
	main->stack_a = NULL;
	main->stack_b = NULL;
	main->size = 0;
	main->count = 0;
	main->top = 0;
	main->middle = 0;
	main->bottom = 0;
}

static int		store_value_in_stack_a(t_main *main, int num)
{
	t_stack	**stack_a;
	t_stack	*new;

	stack_a = &(main->stack_a);
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
	{
		return (ERROR);
	}
	new->value = num;
	if (*stack_a == NULL)
	{
		*stack_a = new;
		new->prev = new;
		new->next = new;
	}
	else
	{
		new->next = *stack_a;
		new->prev = (*stack_a)->prev;
		(*stack_a)->prev->next = new;
		(*stack_a)->prev = new;
	}
	return (SUCCESS);
}

int				initialize_stack_a(t_main *main, char **argv)
{
	int num;

	while (*argv)
	{
		if (!is_arg_numeric(*argv))
		{
			return (ERROR);
		}
		if ((num = ft_atoi(*argv)) == OVERFLOW && ft_strcmp(*argv, "-1") != 0)
		{
			return (ERROR);
		}
		if (store_value_in_stack_a(main, num) == ERROR)
		{
			return (ERROR);
		}
		main->size++;
		argv++;
	}
	return (SUCCESS);
}
