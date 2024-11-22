/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_finish_map_validation2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:02:25 by wzielins          #+#    #+#             */
/*   Updated: 2024/11/20 16:02:39 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_visited(int **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	free_map(t_game *game)
{
	int	row;

	if (game->map)
	{
		row = 0;
		while (row < game->height)
		{
			free(game->map[row]);
			row++;
		}
		free(game->map);
	}
}

void	ft_error(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}