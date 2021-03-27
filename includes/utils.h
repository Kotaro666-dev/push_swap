/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:44:25 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/27 13:30:49 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "constant.h"
# include "struct.h"
# include "get_next_line.h"
# include "commands.h"

/*
** PRINT_OUT.C
*/

int			print_out_ok(void);
int			print_out_ko(t_main *main);
int			print_out_error(t_main *main);
int			print_out_null_character(t_main *main);

/*
** UTILITIES.C
*/

int			is_arg_numeric(char *arg);
int			is_stack_empty(t_stack *stack);
int			get_stack_size(t_stack *stack);
int			is_stack_sorted(t_stack *stack);
int			is_every_number_unique(t_stack *stack);

/*
**	READ_AND_OPERATE_COMMANDS.C
*/

int			read_and_operate_commands(t_main *main);

/*
** FREE_MEMORY.C
*/

void		dispose_memory(t_main *main);

/*
** INITIALIZE.C
*/

int			initialize_struct(t_main *main, int argc);
int			initialize_stack_a(t_main *main, char **argv);

/*
** COUNT_STEP.C
*/

int			count_step_from_head_to_target(t_main *main, int target);
int			count_step_from_tail_to_target(t_main *main, int target);

#endif
