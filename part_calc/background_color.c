/*
** background_color.c for background_color in /home/schmer_x//igraph/rt
** 
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
** 
** Started on  Wed Jun  1 22:43:43 2011 xavier schmerber
** Last update Fri Jun  3 19:46:04 2011 Mathias Lang
*/
#include	<stdlib.h>
#include	"rt.h"

int	background_color(t_glob *glob)
{
  if (rand() % (1000 * (!(IS_OPTION(B_NO_ANTIALIASING)) * 3 + 1)) == 0)
    return (1);
  return (0);
}
