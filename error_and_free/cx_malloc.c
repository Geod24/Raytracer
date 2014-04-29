/*
** cx_malloc.c for cx_malloc in /home/schmer_x//unix/minishell2
** 
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
** 
** Started on  Wed Mar  2 19:27:09 2011 xavier schmerber
** Last update Thu Jun  2 20:16:49 2011 florian oliver
*/

#include <stdlib.h>
#include <unistd.h>

void	*cx_malloc(int size)
{
  char	*mem;

  if ((mem = malloc(size)) == 0)
    {
      if ((write(2, "Malloc error\n", 13)) == -1)
	exit(1);
      exit(1);
    }
  while (size > 0)
    {
      mem[size - 1] = 0;
      size = size - 1;
    }
  return (mem);
}
