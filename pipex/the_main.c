/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:59:02 by afadouac          #+#    #+#             */
/*   Updated: 2024/01/16 14:44:33 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_data *data, char *av[], char **env)
{
	data->infile = open(av[1], O_RDONLY);
	if (data->infile == -1)
		errors(FAILED_OPEN, data);
	dup2(data->infile, STDIN);
	dup2(data->pipa[WRITE], STDOUT);
	close(data->pipa[READ]);
	close(data->pipa[WRITE]);
	for_execve(data, env, 0);
}

void	second_child(t_data *data, char *av[], char **env)
{
	waitpid(data->id1, NULL, 0);
	data->outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC);
	if (data->outfile == -1)
		errors(FAILED_OPEN, data);
	dup2(data->outfile, STDOUT);
	dup2(data->pipa[READ], STDIN);
	close(data->pipa[WRITE]);
	close(data->pipa[READ]);
	for_execve(data, env, 1);
}

int	main(int ac, char *av[], char **env)
{
	t_data	data;

	data.fpath = 0;
	data.spath = 0;
	check_args(ac, av, env, &data);
	if (pipe(data.pipa) == -1)
		errors(FAILED_PIPE, &data);
	data.id1 = fork();
	if (data.id1 == -1)
		errors (FAILED_FORK, &data);
	if (!data.id1)
		first_child(&data, av, env);
	data.id2 = fork();
	if (data.id2 == -1)
		errors (FAILED_FORK, &data);
	if (!data.id2)
		second_child(&data, av, env);
	close(data.pipa[0]);
	close(data.pipa[1]);
	waitpid(data.id1, NULL, 0);
	waitpid(data.id2, NULL, 0);
	return (SUCCESS);
}
