#include "../pipex.h"
char	**allocate_memory(int count)
{
	char	**tokens;
	tokens = (char **)malloc(count * sizeof(char *));
	if (tokens == NULL)
	{
		perror("Error en la asignación de memoria");
		exit(EXIT_FAILURE);
	}
	return (tokens);
}
char	*copy_token(const char *str, int start_index, int token_len)
{
	char	*token;
	int		i;
	char	*tmp;
	token = (char *)malloc((token_len + 1) * sizeof(char));
	if (token == NULL)
	{
		perror("Error en la asignación de memoria");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < token_len)
	{
		token[i] = str[start_index + i];
		i++;
	}
	token[token_len] = '\0';
	tmp = ft_strtrim(token, "\'");
	free(token);
	return (tmp);
}
int	char_compare(char c, int i, int j)
{
	if (c == '\'')
		return (j);
	else
		return (i);
}
int	delimiter_compare(char c, char delimiter, int count)
{
	if (c == delimiter)
		return (count + 1);
	else
		return (count);
}
int	count_tokens(const char *str, char delimiter)
{
	int	str_length;
	int	count;
	int	i;
	int	j;
	i = 0;
	count = 1;
	str_length = strlen(str);
	while (i < str_length)
	{
		count = delimiter_compare(str[i], delimiter, count);
		if (str[i] == '\'')
		{
			j = i + 1;
			while (j < str_length)
			{
				i = char_compare(str[j], i, j);
				if (i == j)
					break ;
				j++;
			}
		}
		i++;
	}
	return (count);
}