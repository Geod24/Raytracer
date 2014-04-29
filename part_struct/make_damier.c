/*
** make_damier.c for make_damier in /home/schmer_x//igraph/rt
**
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
**
** Started on  Wed Jun  1 21:23:39 2011 xavier schmerber
** Last update Fri Jun  3 11:26:58 2011 eric klein
*/
#include	<math.h>
#include	"rt.h"

int	make_damier(t_calc *calc, int value, int color1, int color2)
{
  if (((int)floor(calc->inter.x / value)
       + (int)floor(calc->inter.y / value)) % 2 != 0)
    return (color1);
  return (color2);
}
