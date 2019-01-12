#include "minishell.h"

int         ft_len_tab(char **tab)
{
    int     len;

    len = 0;
    while (tab[len++])
        ;
    return (len);
}

void        ft_exit(char *str)
{
//    int     status;
    char    **tab;

    tab = ft_strsplit(str, ' ');
    if (!ft_strcmp(tab[0], "exit") && ft_len_tab(tab) <= 2)
    {
        if (!tab[1])
            exit(0);
//        ELSE??????
    }
}