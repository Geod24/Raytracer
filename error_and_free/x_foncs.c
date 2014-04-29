/*
** x_foncs.c for minishell in /home/schmer_x//unix/minishell2
** 
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
** 
** Started on  Sat Mar  5 16:12:05 2011 xavier schmerber
** Last update Thu May 12 12:37:47 2011 xavier schmerber
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../headers/rt.h"

void	x_close(int fd)
{
  if (close(fd) == -1)
    put_error("Can't close a file\n", 1);
}
