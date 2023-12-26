/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:54:32 by guortun-          #+#    #+#             */
/*   Updated: 2023/12/26 16:38:40 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "src/libft/libft.h"
# include "src/printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

/* Mandatory functions */
int		is_path_in_env(char **envp);
void	error(char *str);
int		is_absolute_path(char *cmd);
char	*find_path(char *cmd, char **envp);
int		get_next_line(char **line);
void	execute(char *argv, char **envp);

char	**allocate_memory(int count);
char	*copy_token(const char *str,
			int start_index, int token_len);
int		char_compare(char c, int i, int j);
int		delimiter_compare(char c, char delimiter, int count);
int		count_tokens(const char *str, char delimiter);
int		token_length(const char *str,
			int start, int str_length, char delimiter);
char	**split_string(const char *str, char delimiter);

#endif