#include "minishell.h"

void    ft_enviroment(char **env)
{
    while (env && *env)
        ft_putendl(*(env++));
}