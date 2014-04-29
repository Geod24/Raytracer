/*
** normale.c for rt in /home/schmer_x//igraph/rt
** 
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
** 
** Started on  Tue Mar  8 17:24:04 2011 xavier schmerber
** Last update Fri Jun  3 22:47:03 2011 xavier schmerber
*/
#include	<math.h>
#include	"rt.h"

#define RAYON_N		calc->obj->typdef.size
#define RAYON_TORE	calc->obj->typdef.rayon_tore
#define INTER_X		calc->inter.x
#define INTER_Y		calc->inter.y
#define INTER_Z		calc->inter.z

void		normale_cube_troue(t_calc *calc)
{
  t_coord	tmp;

  tmp.x = INTER_X;
  tmp.y = INTER_Y;
  tmp.z = INTER_Z;
  rotate_3d(&(tmp), &(calc->obj->typdef.rot), -1);
  calc->normale.x = 4.0 * pow(tmp.x, 3.0) - (10 * tmp.x);
  calc->normale.y = 4.0 * pow(tmp.y, 3.0) - (10 * tmp.y);
  calc->normale.z = 4.0 * pow(tmp.z, 3.0) - (10 * tmp.z);
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

void		normale_cylindre(t_calc *calc)
{
  t_coord	tmp;

  tmp.x = INTER_X;
  tmp.y = INTER_Y;
  tmp.z = INTER_Z;
  rotate_3d(&(tmp), &(calc->obj->typdef.rot), -1);
  calc->normale.x = tmp.x - calc->obj->stddef.pos.x;
  calc->normale.y = tmp.y - calc->obj->stddef.pos.y;
  calc->normale.z = 0;
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

void		normale_parabol(t_calc *calc)
{
  t_coord	tmp;

  tmp.x = INTER_X;
  tmp.y = INTER_Y;
  tmp.z = INTER_Z;
  rotate_3d(&(tmp), &(calc->obj->typdef.rot), -1);
  calc->normale.x = tmp.x;
  calc->normale.y = tmp.y;
  calc->normale.z = - calc->obj->typdef.size;
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

void		normale_hyperbol(t_calc *calc)
{
  t_coord	tmp;

  tmp.x = INTER_X;
  tmp.y = INTER_Y;
  tmp.z = INTER_Z;
  rotate_3d(&(tmp), &(calc->obj->typdef.rot), -1);
  calc->normale.x = tmp.x;
  calc->normale.y = tmp.y;
  calc->normale.z = -calc->obj->typdef.size * tmp.z;
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
