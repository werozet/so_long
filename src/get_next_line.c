/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:58:02 by wzielins          #+#    #+#             */
/*   Updated: 2024/11/20 15:58:19 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*ft_transfer(char *base, char *addition)
{
	char	*new;

	new = ft_strjoin(base, addition);
	if (!new)
		return (NULL);
	free(base);
	return (new);
}

static char	*ft_readline(int fd, char *left, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(left), NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!left)
			left = ft_strdup("");
		left = ft_transfer(left, buffer);
		if (!left)
			return (free(left), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left);
}

static char	*ft_return_left(char *line)
{
	size_t	i;
	char	*left;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	left = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (left[0] == '\0')
	{
		free(left);
		left = NULL;
	}
	line[i + 1] = '\0';
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*buffer_all = NULL;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = ft_readline(fd, buffer_all, buffer);
	free(buffer);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	buffer_all = ft_return_left(line);
	return (line);
}
