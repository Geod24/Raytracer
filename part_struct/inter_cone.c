/*
** inter_cone.c for tracemyray in /home/oliver_f//Teck/Igraph/RT/raytracer/SVN/TraceMyRay
**
** Made by florian oliver
** Login   <oliver_f@epitech.net>
**
** Started on  Tue Apr 19 13:24:23 2011 florian oliver
** Last update Fri Jun  3 18:18:12 2011 xavier schmerber
*/
#include	<math.h>
#include	<stdlib.h>
#include	"rt.h"

#define ANGLE	obj->typdef.size

double		inter_cone(t_obj *obj, t_calc *calc)
{
  t_coord	abc;
  double	delta;
  t_coord	tmp_view;
  t_coord	tmp_eye;
  double	res;

  init_view(&tmp_eye, &tmp_view, obj, calc);
  abc.x = (SQ(VIEW_X) + SQ(VIEW_Y) -
	   ((SQ(VIEW_Z)) / SQ(tan(RAD(ANGLE)))));
  abc.y = ((EYE_X * 2 * VIEW_X) + (EYE_Y * 2 * VIEW_Y) -
	   ((EYE_Z * 2 * VIEW_Z) / SQ(tan(RAD(ANGLE)))));
  abc.z = (SQ(EYE_X) + SQ(EYE_Y) -
	   (SQ(EYE_Z) / SQ(tan(RAD(ANGLE)))));
  delta = SQ(abc.y) - (4 * abc.x * abc.z);
  res = calc_delta(&abc, delta);
  if (res != -1.0 && (obj->typdef.size_x != -1 || obj->typdef.size_y != -1))
    res = check_limit(obj, res, &tmp_eye, &tmp_view);
  return (res);
}
