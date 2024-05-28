#include "../pipex.h"
int	token_length(const char *str, int start, int str_length, char delimiter)
{
	int	token_length;
	int	in_quotes;
	int	j;
	j = start;
	in_quotes = 0;
	token_length = 0;
	while (j < str_length)
	{
		if (str[j] == delimiter && !in_quotes)
			break ;
		else if (str[j] == '\'')
			in_quotes = !in_quotes;
		token_length++;
		j++;
	}
	return (token_length);
}
char	**split_string(const char *str, char delimiter)
{
	int		i;
	int		k;
	int		token_len;
	char	**tokens;
	i = 0;
	k = 0;
	tokens = allocate_memory(count_tokens(str, delimiter) + 1);
	while (i < (int)ft_strlen(str))
	{
		token_len = token_length(str, i, strlen(str), delimiter);
		tokens[k] = copy_token(str, i, token_len);
		i += token_len;
		if (str[i] == delimiter)
			i++;
		k++;
	}
	tokens[k] = NULL;
	return (tokens);
}