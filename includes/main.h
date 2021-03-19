/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:00:14 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/19 16:55:14 by kkamashi         ###   ########.fr       */
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
void		sort_stack_with_more_than_four_numbers(t_main *main);

#endif
