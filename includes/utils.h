/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:44:25 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/12 14:43:28 by kkamashi         ###   ########.fr       */
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

/*
** PRINT_OUT.C
*/

void		print_out_ok(void);
void		print_out_ko(void);
void		print_out_error(void);

/*
** UTILITIES.C
*/

int		is_arg_numeric(char *arg);

#endif
