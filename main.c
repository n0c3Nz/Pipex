/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:33:35 by guortun-          #+#    #+#             */
/*   Updated: 2023/09/19 18:35:47 by guortun-         ###   ########.fr       */
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
		error();
	dup2(fd[1], STDOUT);
	dup2(infile, STDIN);
	close(fd[0]);
	execute(argv[2], envp);
}
void	parent_process(char **argv, char **envp, int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0774);
	if (outfile == -1)
		error();
	dup2(fd[0], STDIN);
	dup2(outfile, STDOUT);
	close(fd[1]);
	execute(argv[3], envp);
}
int	main(int argc, char **argv, char **envp)
{
	int fd[2];
	pid_t pid_1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid_1 = fork();
		if (pid_1 == -1)
			error();
		if (pid_1 == 0)
			child_process(argv, envp, fd);
		waitpid(pid_1, NULL, 0);
		parent_process(argv, envp, fd);
	}
	else
		error();
	return (0);
}