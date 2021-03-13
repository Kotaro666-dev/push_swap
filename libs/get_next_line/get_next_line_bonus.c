/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:10:42 by kkamashi          #+#    #+#             */
/*   Updated: 2020/07/20 13:11:38 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	free_memory_and_output_error(char **memory, int fd)
{
	free(memory[fd]);
	memory[fd] = NULL;
	return (GNL_ERROR);
}

static char	*get_ready_for_buffer(void)
{
	char	*buffer;

	if (!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
	{
		return (NULL);
	}
	return (buffer);
}

/*
** if ((next_line_pointer = ft_strchr(memory[fd], '\n')) != NULL)
**
** これまでに読み込んで、静的領域memoryに格納してきた中に改行文字がある場合には、
** 改行文字までの文字列をlineに格納してあげる。改行文字以降の文字列はremainderに格納し、
** memoryをfreeした後に、remainderの中身を格納して、次の読み込みへの準備をさせる
**
** else
**
** 改行文字が見当たらない場合 == EOFに到達 -> プログラムの終了準備
*/

static int	store_in_line(char **memory, int fd, char **line)
{
	char		*next_line_pointer;
	char		*remainder;
	int			length;

	if ((next_line_pointer = ft_strchr(memory[fd], '\n')) != NULL)
	{
		*next_line_pointer = '\0';
		length = ft_strlen(memory[fd]) - ft_strlen(next_line_pointer);
		if ((*line = ft_substr(memory[fd], 0, length)) == NULL)
			return (free_memory_and_output_error(memory, fd));
		if ((remainder = ft_strdup(next_line_pointer + 1)) == NULL)
			return (free_memory_and_output_error(memory, fd));
		free(memory[fd]);
		memory[fd] = remainder;
	}
	else
	{
		if ((*line = ft_strdup(memory[fd])) == NULL)
			return (free_memory_and_output_error(memory, fd));
		free(memory[fd]);
		memory[fd] = NULL;
		return (GNL_EOF);
	}
	return (GNL_READ);
}

static int	return_value(ssize_t bytes, char **memory, int fd, char **line)
{
	int	i;

	if (bytes == -1)
	{
		i = 0;
		while (i < OPEN_MAX)
		{
			if (memory[i] != NULL)
			{
				free(memory[i]);
				memory[i] = NULL;
			}
			i++;
		}
		return (GNL_ERROR);
	}
	else if (bytes == 0 && (memory[fd] == NULL || memory[fd][0] == '\0'))
	{
		if ((*line = ft_strdup("")) == NULL)
			return (GNL_ERROR);
		return (GNL_EOF);
	}
	else
		return (store_in_line(memory, fd, line));
}

/*
** 一連の流れ
** 1. BUFFER＿SIZE分読み込んでbufferに格納した中身を静的領域memoryにどんどん格納
** 2. memory内に改行があったら、読み込みを一旦中止して、改行文字までをlineに格納する作業へ
** 3. 関数return_valueを中継して、lineに格納するstore_in_line関数へと移る
**
** if (memory[fd] == NULL) == プログラムが起動されたとき
** -> ローカル変数に static をつけた静的変数＆明示的に初期化しないとき
** -> 自動的に NULL(or (void *)0) で初期化される
*/

int			get_next_line(int fd, char **line)
{
	static char		*memory[OPEN_MAX];
	char			*buffer;
	char			*temp;
	ssize_t			bytes;

	if (fd < 0 || OPEN_MAX <= fd || BUFFER_SIZE <= 0 || line == NULL)
		return (GNL_ERROR);
	if ((buffer = get_ready_for_buffer()) == NULL)
		return (free_memory_and_output_error(memory, fd));
	while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes] = '\0';
		if (memory[fd] == NULL)
			memory[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(memory[fd], buffer);
			free(memory[fd]);
			memory[fd] = temp;
		}
		if (ft_strchr(memory[fd], '\n') != NULL)
			break ;
	}
	free(buffer);
	return (return_value(bytes, memory, fd, line));
}
