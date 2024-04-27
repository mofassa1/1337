/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:17:08 by afadouac          #+#    #+#             */
/*   Updated: 2024/01/15 13:47:35 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_c_path(t_data *data, int n)
{
	int	i;

	i = -1;
	if (n == 0 && !data->fpath)
		data->splited_cmd = data->splited_cmd1;
	else if (n == 1 && !data->spath)
		data->splited_cmd = data->splited_cmd2;
	while (data->paths[++i])
	{
		data->c_path = ft_strjoin(data->paths[i], data->splited_cmd[0]);
		if (access(data->c_path, F_OK | X_OK) == -1)
			free(data->c_path);
		else
			break ;
	}
}

void	free_data2(int n, t_data *data)
{
	if (n == 0)
	{
		free(data->splited_cmd2[0]);
		if (data->splited_cmd2[1])
			free(data->splited_cmd2[1]);
		free(data->splited_cmd2);
	}
	else if (n == 1)
	{
		free(data->splited_cmd1[0]);
		if (data->splited_cmd1[1])
			free(data->splited_cmd1[1]);
		free(data->splited_cmd1);
	}
}

void	for_execve(t_data *data, char **env, int n)
{
	int		i;

	i = -1;
	if (n == 0 && data->fpath)
		data->c_path = (data->splited_cmd1[0]);
	else if ((n == 0 && !data->fpath) || (n == 1 && !data->spath))
		get_c_path(data, n);
	else if (n == 1 && data->spath)
		data->c_path = (data->splited_cmd2[0]);
	if (access(data->c_path, F_OK | X_OK) == -1)
		errors(INVALID_COMMAND, data);
	free_data2(n, data);
	if (n == 0)
		execve(data->c_path, data->splited_cmd1, env);
	else if (n == 1)
		execve(data->c_path, data->splited_cmd2, env);
}
