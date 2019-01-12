#include "minishell.h"

int     ft_len_double(char **arr)
{
	int i;

	i = 1;
	while (arr[i])
		i++;
	return (i);
}

void    ft_get_path(t_my_shell *my_shell, char *env)
{
	int     len;
	char    **arr;

	arr = ft_strsplit(ft_strchr(env, '=') + 1, ':');
	len = ft_len_double(arr);
	while (arr[--len])
    {
        ft_lstadd(&my_shell->path, ft_lstnew((void *) (arr[len]), ft_strlen(arr[len])));
    }
}
