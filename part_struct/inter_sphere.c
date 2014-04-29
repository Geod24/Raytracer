/*
** inter_sphere.c for raytracer in /home/fische_s//dossier/projets/rt/intersections
**
** Made by sylvain fischer
** Login   <fische_s@epitech.net>
**
** Started on  Tue Apr 12 17:19:51 2011 sylvain fischer
** Last update Fri Jun  3 19:18:33 2011 xavier schmerber
*/
#include	"rt.h"

#define RAYON_OBJ	obj->typdef.size

double		inter_sphere(t_obj *obj, t_calc *calc)
{
  t_coord	abc;
  t_coord	tmp_eye;
  t_coord	tmp_view;
  double	delta;

  init_view(&tmp_eye, &tmp_view, obj, calc);
  abc.x = SQ(tmp_view.x) + SQ(tmp_view.y) + SQ(tmp_view.z);
  abc.y = 2 * ((tmp_eye.x * tmp_view.x) + (tmp_eye.y * tmp_view.y)
	       + (tmp_eye.z * tmp_view.z));
  abc.z = (SQ(tmp_eye.x) + SQ(tmp_eye.y) + SQ(tmp_eye.z)) - SQ(RAYON_OBJ);
  delta = SQ(abc.y) - (4 * abc.x * abc.z);
  return (calc_delta(&abc, delta));
}
