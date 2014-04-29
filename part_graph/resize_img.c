/*
** resize_img.c for rt in /home/schmer_x//igraph/rt/part_graph
**
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
**
** Started on  Fri Apr 29 20:47:48 2011 xavier schmerber
** Last update Fri Jun  3 11:54:26 2011 eric klein
*/

#include "rt.h"

#define NEW_REP         (y1 * new->sizeline + x1 * 4)
#define OLD_REP         ((int)y2 * old->sizeline + (int)x2 * 4)

void		resize_img(t_img *old, t_img *new)
{
  int		y1;
  double	y2;
  int		x1;
  double	x2;

  y1 = 0;
  y2 = 0;
  while (y2 < old->sizey && y1 < new->sizey)
    {
      x1 = 0;
      x2 = 0;
      while (x2 < old->sizex && x1 < new->sizex)
        {
          new->data[NEW_REP + 0] = old->data[OLD_REP + 0];
          new->data[NEW_REP + 1] = old->data[OLD_REP + 1];
          new->data[NEW_REP + 2] = old->data[OLD_REP + 2];
          new->data[NEW_REP + 3] = old->data[OLD_REP + 3];
	  x1++;
	  x2 = x2 + (double)(old->sizex) / (double)(new->sizex);
        }
      y1++;
      y2 = y2 + (double)(old->sizey) / (double)(new->sizey);
    }
}
