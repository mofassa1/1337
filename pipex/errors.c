/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:38:10 by afadouac          #+#    #+#             */
/*   Updated: 2024/01/15 11:59:12 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->splited_cmd1[i])
	{
		free(data->splited_cmd1[i]);
		i++;
	}
	free(data->splited_cmd1);
	i = 0;
	while (data->splited_cmd2[i])
	{
		free(data->splited_cmd2[i]);
		i++;
	}
	free(data->splited_cmd2);
	i = 0;
	while (data->paths[i])
	{
		free(data->paths[i]);
		i++;
	}
	free(data->paths);
}

void	errors(int return_value, t_data *data)
{
	if (return_value == INVALID_INPUT)
		ft_putstr("INVALID_INPUT\n");
	else if (return_value == FAILED_PIPE)
		perror("error pipe\n");
	else if (return_value == FAILED_FORK)
		perror("error fork\n");
	else if (return_value == FAILED_WRITE)
		perror("error write\n");
	else if (return_value == FAILED_READ)
		perror("error read\n");
	else if (return_value == FAILED_OPEN)
		perror("error open\n");
	else if (return_value == NO_PERMITION)
		perror("permitions incorrect\n");
	else if (return_value == INVALID_COMMAND)
		perror("command not found!\n");
	if (return_value != INVALID_INPUT)
		free_data(data);
	exit(return_value);
}
