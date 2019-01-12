cmake_minimum_required(VERSION 3.9)
project(minishell C)

include_directories(includes libft) # headers

link_directories(libft) # libraries

set(CMAKE_C_STANDARD 99)

add_executable(minishell main.c minishell.h ft_get_path.c ft_enviroment.c ft_exit.c)

target_link_libraries(minishell libft.a) # linkage