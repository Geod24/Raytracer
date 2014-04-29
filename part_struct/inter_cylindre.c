/*
** inter_cylindre.c for raytracer in /home/fische_s//dossier/projets/rt/intersections
** 
** Made by sylvain fischer
** Login   <fische_s@epitech.net>
** 
** Started on  Tue Apr 12 19:39:50 2011 sylvain fischer
** Last update Fri Jun  3 18:25:30 2011 xavier schmerber
*/
#include	<math.h>
#include	"rt.h"

#define RAYON_OBJ	obj->typdef.size

double		inter_cylindre(t_obj *obj, t_calc *calc)
{
  t_coord	abc;
  double	delta;
  t_coord	tmp_eye;
  t_coord	tmp_view;
  double	res;

  init_view(&tmp_eye, &tmp_view, obj, calc);

  abc.x = SQ(VIEW_X) + SQ(VIEW_Y);
  abc.y = 2.0 * ((EYE_X * VIEW_X) + (EYE_Y * VIEW_Y));
  abc.z = (SQ(EYE_X) + SQ(EYE_Y)) - SQ(RAYON_OBJ);
  delta = SQ(abc.y) - (4 * abc.x * abc.z);
  res = calc_delta(&abc, delta);
  if (res != -1.0 && (obj->typdef.size_x != -1 || obj->typdef.size_y != -1))
    res = check_limit(obj, res, &tmp_eye, &tmp_view);
  return (res);
}
