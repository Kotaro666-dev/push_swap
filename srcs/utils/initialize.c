/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:28:38 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/23 12:47:20 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int				initialize_struct(t_main *main, int argc)
{
	main->stack_a = NULL;
	main->stack_b = NULL;
	main->array = (int *)malloc(sizeof(int) * (argc + 10));
	if (main->array == NULL)
	{
		return (MALLOC_ERROR);
	}
	main->len_array = 0;
	main->size = 0;
	main->count = 0;
	main->top = 0;
	main->middle = 0;
	main->bottom = 0;
	main->maximum = INT_MIN;
	main->minimum = INT_MAX;
	return (SUCCESS);
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
		insert_node_at_front(&(stack_a), new);
	}
	else
	{
		insert_node_at_end(&(stack_a), new);
	}
	return (SUCCESS);
}

static void		store_max_and_min_value(t_main *main, int num)
{
	if (main->maximum < num)
	{
		main->maximum = num;
	}
	if (main->minimum > num)
	{
		main->minimum = num;
	}
}

int				initialize_stack_a(t_main *main, char **argv)
{
	int	num;

	while (argv[main->size])
	{
		if (!is_arg_numeric(argv[main->size]))
		{
			return (ERROR);
		}
		if ((num = ft_atoi(argv[main->size])) == OVERFLOW &&
			ft_strcmp(argv[main->size], "-1") != 0)
		{
			return (ERROR);
		}
		if (store_value_in_stack_a(main, num) == ERROR)
		{
			return (ERROR);
		}
		store_max_and_min_value(main, num);
		main->array[main->size] = num;
		main->size++;
	}
	main->len_array = main->size;
	return (SUCCESS);
}
