/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 18:51:16 by kkamashi          #+#    #+#             */
/*   Updated: 2020/12/13 18:57:31 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bubblesort(int *array, int upto)
{
	int		i;
	int		j;

	i = 0;
	while (i < upto - 1)
	{
		j = 0;
		while (j < upto - 1 - i)
		{
			if (array[j] > array[j + 1])
			{
				ft_swap(&array[j], &array[j + 1]);
			}
			j++;
		}
		i++;
	}
}
