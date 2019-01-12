#ifndef MINISHELL_H
# define MINISHELL_H

# define GREEN "\033[0;32m"
# define COLOR_END "\033[0m"

#include "libft/libft.h"

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <dirent.h>

typedef struct		s_serv
{
	DIR				*dir;
	struct dirent	*read;
	pid_t           new_proc;
}					t_serv;

typedef struct      s_my_shell
{
	t_list          *path;
}                   t_my_shell;

void    ft_get_path(t_my_shell *my_shell, char *env);
void    ft_enviroment(char **env);
void    ft_exit(char *str);

#endif
