/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:28:38 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/17 07:47:53 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		initialize_struct(t_main *main)
{
	main->stack_a = NULL;
	main->stack_b = NULL;
	main->size = 0;
	main->count = 0;
}

int			store_value_in_stack_a(t_stack **stack_a, int num)
{
	t_stack *new;
	t_stack *current;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
	{
		return (ERROR);
	}
	new->value = num;
	if (*stack_a == NULL)
	{
		*stack_a = new;
		new->prev = NULL;
		new->next = NULL;
		return (SUCCESS);
	}
	current = *stack_a;
	while (current->next)
	{
		current = current->next;
	}
	current->next = new;
	new->prev = current;
	new->next = NULL;
	return (SUCCESS);
}

int			initialize_stack_a(t_main *main, char **argv)
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
		if (store_value_in_stack_a(&(main->stack_a), num) == ERROR)
		{
			return (ERROR);
		}
		main->size++;
		argv++;
	}
	return (SUCCESS);
}
