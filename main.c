#include "minishell.h"
#include <stdio.h>

void ft_write_prompt()
{
    char *str;

//    str = getcwd(NULL, 0);
	str = "HIIIIII:)";
    write(1, GREEN, ft_strlen(GREEN));
    write(1, str, ft_strlen(str));
    write(1, "> ", 2);
    write(1, COLOR_END, ft_strlen(COLOR_END));
//    free(str);
}

void ft_command_nfound(char *str)
{
    write(1, str, ft_strlen(str));
    write(1, ": command not found\n", 20);

}

void ft_go_to_cd(char *str)
{
    char *path;

    path = ft_strchr(str, ' ') + 1;
    chdir(path);
}

void ft_pwd()
{
    char *str;

    str = getcwd(NULL, 0);
    write(1, str, ft_strlen(str));
    write(1, "\n", 1);
    free(str);
}

void ft_echo(char *str)
{
    char *text;

    text = ft_strchr(str, ' ');
    if (text)
    {
        text++;
        write(1, text, ft_strlen(text));
        write(1, "\n", 1);
    }
}

int is_builtins(char *str)
{
	if (ft_strstr(str, "cd"))
		ft_go_to_cd(str);
	else if (!ft_strcmp(str, "pwd"))
		ft_pwd();
	else if (ft_strstr(str, "echo"))
		ft_echo(str);
	else
		return (0);
	return (1);
}

int ft_open_find(char *line, char *command, char *path, char **env)
{
	t_serv serv;
	int status;

	status = 1;
	serv.dir = opendir(path);
	if (serv.dir)
	{
		while ((serv.read = readdir(serv.dir)))
		{
			if (!ft_strcmp(serv.read->d_name, command))
			{
				serv.new_proc = fork();
				if (serv.new_proc == 0) {
					char *new_command = ft_strjoin(ft_strjoin(path, "/"), command);
					char **a = ft_strsplit(line, ' ');
					execve(new_command, a, env);
				}
				else if (serv.new_proc > 0)
				{
					waitpid(serv.new_proc, &status, WNOHANG & WUNTRACED);
				}
				//обработать -1!!!!!
//				break ;
                closedir(serv.dir);
                return (1);
			}
		}
		closedir(serv.dir);
	}
	return (0);
}

int is_nbuiltins(char *str, t_my_shell my_shell, char **env)
{
	char **arr;

	arr = ft_strsplit(str, ':');
	while (my_shell.path)
	{
		if (ft_open_find(str, arr[0], my_shell.path->content, env))
			return (1) ;
        my_shell.path = my_shell.path->next;
	}
	return (0);
}

//is_nbuiltins(str, my_shell, env);

int main(int ac, char **av, char **env)
{
    char *str;
	t_my_shell  my_shell;

	ft_get_path(&my_shell, env[0]);


	while (1)
    {
        ft_write_prompt();
        get_next_line(0, &str);
	    if (ft_strstr(str, "exit"))
            ft_exit(str);

        free(str);
    }
    return (0);
}