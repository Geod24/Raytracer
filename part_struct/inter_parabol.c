/*
** inter_parabol.c for rt in /home/oliver_f//Teck/Igraph/RT/raytracer/SVN/TraceMyRay
** 
** Made by florian oliver
** Login   <oliver_f@epitech.net>
** 
** Started on  Sat May 28 18:58:34 2011 florian oliver
** Last update Sat May 28 19:17:12 2011 florian oliver
*/
#include "rt.h"
#define CONSTANTE obj->typdef.size

double		inter_parabol(t_obj *obj, t_calc *calc)
{
  t_coord	tmp_eye, tmp_view, abc;
  double	delta;

  init_view(&tmp_eye, &tmp_view, obj, calc);

  abc.x = SQ(tmp_view.x) + SQ(tmp_view.y);
  abc.y = 2.0 * ((EYE_X * VIEW_X) + (EYE_Y * VIEW_Y) - (CONSTANTE * VIEW_Z));
  abc.z = (SQ(EYE_X) + SQ(EYE_Y) - (CONSTANTE * EYE_Z));
  delta = SQ(abc.y) - (4 * abc.x * abc.z);
  return (calc_delta(&abc, delta));
}
