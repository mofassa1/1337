/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:56:25 by afadouac          #+#    #+#             */
/*   Updated: 2024/01/16 15:32:58 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_data
{
	int		pipa[2];
	pid_t	id1;
	pid_t	id2;
	char	**paths;
	int		fpath;
	int		spath;
	int		infile;
	int		outfile;
	char	**splited_cmd;
	char	**splited_cmd1;
	char	**splited_cmd2;
	char	*c_path;
}			t_data;

# define ERROR -1
# define READ 0
# define STDIN 0
# define STDOUT 1
# define WRITE 1
# define SUCCESS 0
# define FAILED_PIPE 3
# define FAILED_READ 4
# define FAILED_WRITE 5
# define FAILED_FORK 6
# define FAILED_OPEN 7
# define INVALID_INPUT 8
# define NO_PERMITION 9
# define INVALID_COMMAND 10

void	errors(int return_value, t_data *data);
char	*ft_strdup(const char *s1);
void	check_args(int ac, char *av[], char **env, t_data *data);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	for_execve(t_data *data, char **env, int n);
void	ft_putstr(char *str);

#endif
