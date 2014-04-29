/*
** reflection.c for rt in /home/schmer_x//igraph/rt/part_calc
** 
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
** 
** Started on  Tue Apr 19 00:07:24 2011 xavier schmerber
** Last update Sun Jun  5 00:44:06 2011 xavier schmerber
*/
#include	<math.h>
#include	"rt.h"

void	calc_reflect_vect(t_calc *calc, t_coord *view)
{
  double	tmp;
  t_coord	tmp_view;

  tmp_view.x = - view->x;
  tmp_view.y = - view->y;
  tmp_view.z = - view->z;
  tmp = (scalaire(&(calc->normale), &(tmp_view))) / (NORME(calc->normale));
  calc->reflect.x = view->x + (2 * tmp * calc->normale.x);
  calc->reflect.y = view->y + (2 * tmp * calc->normale.y);
  calc->reflect.z = view->z + (2 * tmp * calc->normale.z);
}
