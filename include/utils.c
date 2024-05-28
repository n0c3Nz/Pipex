#include "../pipex.h"
char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;
	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths[i]);
	free(paths);
	return (0);
}
void	execute(char *argv, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;
	i = 0;
	cmd = split_string(argv, ' ');
	if (is_absolute_path(cmd[0]) == 0)
		path = cmd[0];
	else if (!(is_path_in_env(envp)))
		error("Please use only absolute routes (No PATH env detected)");
	else
	{
		path = find_path(cmd[0], envp);
		if (!path)
		{
			while (cmd[i++])
				free(cmd[i]);
			free(cmd);
			error("Command not found in path");
		}
	}
	if (execve(path, cmd, envp) == -1)
		error("Error executing command");
}
void	error(char *str)
{
	char	error[256];
	ft_strlcpy(error, "\033[31mError\033[0;39m: ", 256);
	ft_strlcat(error, str, 256);
	ft_strlcat(error, "\n", 256);
	ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}
int	is_absolute_path(char *cmd)
{
	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (access(cmd, X_OK) == 0)
			return (0);
		else
			error("Command is not executable or doesn't exist");
	}
	return (1);
}