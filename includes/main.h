/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:00:14 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/21 17:55:21 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "constant.h"
# include "utils.h"
# include "debug.h"
# include "struct.h"

/*
** SORTING FUNCTION
*/

void		sort_stack_with_two_numbers(t_main *main);
void		sort_stack_with_three_numbers(t_main *main);
void		sort_stack_with_small_numbers(t_main *main);
void		sort_stack_with_many_numbers(t_main *main, int divider);

/*
** PUSH_ALL_NUMBERS_TO_STACK_B_UTILS.C
*/

int			count_step_from_top(t_stack *stack, int maximum);
int			count_step_from_tail(t_stack *stack, int maximum);
int			is_minimum_number_on_top(t_stack *stack);
int			get_stack_size(t_stack *stack);
int			find_minimum_position(t_stack *stack);
void		put_minimum_number_on_top(t_main *main);

/*
** PUSH_ALL_NUMBERS_TO_STACK_A_UTILS.C
*/

int			count_step_to_maximum_from_head(t_stack *stack, int maximum);
int			count_step_to_maximum_from_tail(t_stack *stack, int maximum);

/*
** IS_TARGET_IN_RIGHT_POSITION.C
*/

int			is_target_suitable_in_head(t_stack *current);
int			is_target_suitable_in_tail(t_stack *current);
int			is_target_suitable_in_middle(t_stack *current);
int			is_target_in_right_position(t_main *main, int target);

#endif
