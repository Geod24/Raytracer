/*
** normale2.c for normale2 in /home/schmer_x//igraph/rt
** 
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
** 
** Started on  Fri Jun  3 22:44:21 2011 xavier schmerber
** Last update Sat Jun  4 23:56:28 2011 xavier schmerber
*/
#include	<math.h>
#include	"rt.h"

#define RAYON_N		calc->obj->typdef.size
#define RAYON_TORE	calc->obj->typdef.rayon_tore
#define INTER_X		calc->inter.x
#define INTER_Y		calc->inter.y
#define INTER_Z		calc->inter.z

void	normale_plan(t_calc *calc)
{
  calc->normale.x = 0;
  calc->normale.y = 0;
  calc->normale.z = 1;
  rotate_3d(&(calc->normale), &(calc->obj->typdef.rot), 1);
  if ((scalaire(&(calc->normale), &(calc->view))) >= 0)
    {
      calc->normale.x = -calc->normale.x;
      calc->normale.y = -calc->normale.y;
      calc->normale.z = -calc->normale.z;
      if ((scalaire(&(calc->normale), &(calc->view))) >= 0)
        put_error("Object normal error !\n", 0);
    }
}

void		normale_cone(t_calc *calc)
{
  t_coord	tmp;

  tmp.x = INTER_X;
  tmp.y = INTER_Y;
  tmp.z = INTER_Z;
  rotate_3d(&(tmp), &(calc->obj->typdef.rot), -1);
  calc->normale.x = tmp.x - calc->obj->stddef.pos.x;
  calc->normale.y = tmp.y - calc->obj->stddef.pos.y;
  calc->normale.z = -(1.0 / calc->obj->typdef.size *
                      (tmp.z - calc->obj->stddef.pos.z));
  rotate_3d(&(calc->normale), &(calc->obj->typdef.rot), 1);
  if ((scalaire(&(calc->normale), &(calc->view))) >= 0)
    {
      calc->normale.x = -calc->normale.x;
      calc->normale.y = -calc->normale.y;
      calc->normale.z = -calc->normale.z;
      if ((scalaire(&(calc->normale), &(calc->view))) >= 0)
        put_error("Object normal error !\n", 0);
    }
}

void		normale_sphere(t_calc *calc)
{
  t_coord	tmp;

  tmp.x = INTER_X;
  tmp.y = INTER_Y;
  tmp.z = INTER_Z;
  rotate_3d(&(tmp), &(calc->obj->typdef.rot), -1);
  calc->normale.x = tmp.x - calc->obj->stddef.pos.x;
  calc->normale.y = tmp.y - calc->obj->stddef.pos.y;
  calc->normale.z = tmp.z - calc->obj->stddef.pos.z;
  rotate_3d(&(calc->normale), &(calc->obj->typdef.rot), 1);
  if ((scalaire(&(calc->normale), &(calc->view))) >= 0)
    {
      calc->normale.x = -calc->normale.x;
      calc->normale.y = -calc->normale.y;
      calc->normale.z = -calc->normale.z;
      if ((scalaire(&(calc->normale), &(calc->view))) >= 0)
	put_error("Object normal error !\n", 0);
    }
}

void		normale_tore(t_calc *calc)
{
  double	k;
  t_coord	tmp;

  tmp.x = INTER_X;
  tmp.y = INTER_Y;
  tmp.z = INTER_Z;
  rotate_3d(&(tmp), &(calc->obj->typdef.rot), -1);
  k = 4.0 * (pow(tmp.x, 2.0) + pow(tmp.y, 2.0) + pow(tmp.z, 2.0))
    + pow(RAYON_N, 2.0) - pow(RAYON_TORE, 2.0);
  calc->normale.x = tmp.x * k - 8.0 * pow(RAYON_N, 2.0) * tmp.x;
  calc->normale.y = tmp.y * k;
  calc->normale.z = tmp.z * k - 8.0 * pow(RAYON_N, 2.0) * tmp.z;
  rotate_3d(&(calc->normale), &(calc->obj->typdef.rot), 1);
  if ((scalaire(&(calc->normale), &(calc->view))) >= 0)
    {
      calc->normale.x = -calc->normale.x;
      calc->normale.y = -calc->normale.y;
      calc->normale.z = -calc->normale.z;
      if ((scalaire(&(calc->normale), &(calc->view))) >= 0)
	put_error("Object normal error !\n", 0);
    }
}
