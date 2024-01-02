/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:33:35 by guortun-          #+#    #+#             */
/*   Updated: 2024/01/02 02:04:58 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define STDIN 0
#define STDOUT 1

void	child_process(char **argv, char **envp, int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		error("Infile not found");
	if (dup2(fd[1], STDOUT) < 0)
		error("Dup STDOUT to PIPE at Child process");
	if (dup2(infile, STDIN) < 0)
		error("Dup INFILE to STDIN");
	close(fd[0]);
	execute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0774);
	if (outfile == -1)
		error("Can't create or open outfile");
	if (dup2(fd[0], STDIN) < 0)
		error("Dup PIPE to STDIN");
	if (dup2(outfile, STDOUT) < 0)
		error("Dup STDOUT to OUTFILE");
	close(fd[1]);
	execute(argv[3], envp);
}

int	is_path_in_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!(ft_strnstr(envp[i], "PATH", 4) == 0))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid_1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error("Pipe error");
		pid_1 = fork();
		if (pid_1 == -1)
			error("Fork error");
		if (pid_1 == 0)
			child_process(argv, envp, fd);
		if (pid_1 > 0)
		{
			parent_process(argv, envp, fd);
		}
	}
	else
		error("Wrong number of arguments.");
	return (0);
}
// Unit tests
// ./pipex infile "ls -l" "wc -l" outfile
// ./pipex infile "grep a1" "wc -w" outfile
// ./pipex infile "sleep 5" "ls -l" outfile
// waitpid(pid_1, NULL, 0);
// Para poder probar AWK -> export a='$1'.