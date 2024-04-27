/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:04:17 by afadouac          #+#    #+#             */
/*   Updated: 2024/01/14 23:46:28 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	get_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp("PATH=", env[i], 5))
			return (i);
		i++;
	}
	return (0);
}

void	check_args(int ac, char *av[], char **env, t_data *data)
{
	int		i;
	char	*tmp;

	if (ac != 5)
		errors(INVALID_INPUT, data);
	data->splited_cmd1 = ft_split(av[2], ' ');
	data->splited_cmd2 = ft_split(av[3], ' ');
	if (access(data->splited_cmd1[0], F_OK | X_OK) != -1)
		data->fpath = 1;
	if (access(data->splited_cmd2[0], F_OK | X_OK) != -1)
		data->spath = 1;
	if (data->fpath && data->spath)
		return ;
	i = -1;
	data->paths = ft_split(env[get_path(env)] + 5, ':');
	while (data->paths[++i])
	{
		tmp = ft_strjoin(data->paths[i], "/");
		free(data->paths[i]);
		data->paths[i] = tmp;
	}
}
