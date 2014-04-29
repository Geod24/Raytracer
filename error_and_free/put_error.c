/*
** put_error.c for minishell in /home/schmer_x//unix/minishell2
** 
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
** 
** Started on  Fri Mar  4 13:51:01 2011 xavier schmerber
** Last update Thu May 12 12:37:13 2011 xavier schmerber
*/

#include <stdlib.h>
#include <unistd.h>
#include "../headers/rt.h"

void	put_error(char *str, int kill)
{
  if ((write(2, str, my_strlen(str))) == -1)
    exit(1);
  if (kill == 1)
    exit(1);
}
