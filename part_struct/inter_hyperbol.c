/*
** inter_hyperbol.c for rt in /home/oliver_f//Teck/Igraph/RT/raytracer/SVN/TraceMyRay
** 
** Made by florian oliver
** Login   <oliver_f@epitech.net>
** 
** Started on  Sat May 28 19:15:38 2011 florian oliver
** Last update Fri Jun  3 18:28:09 2011 xavier schmerber
*/
#include	"rt.h"

#define CONSTANTE	obj->typdef.size
#define	TOUCH		obj->typdef.angle
/* la constante correspond a l ecartement de l hyperbol */
/* l'autre contante sur z correspond au nombre de "pixels qui touche le 
**bas du haut =)
*/

double		inter_hyperbol(t_obj *obj, t_calc *calc)
{
  t_coord	tmp_eye;
  t_coord	tmp_view;
  t_coord	abc;
  double	delta;

  init_view(&tmp_eye, &tmp_view, obj, calc);
  abc.x = SQ(VIEW_X) + SQ(VIEW_Y) - (CONSTANTE * SQ(VIEW_Z));
  abc.y = 2.0 * ((EYE_X * VIEW_X) + (EYE_Y * VIEW_Y)
		 - (CONSTANTE * VIEW_Z * EYE_Z));
  abc.z = SQ(EYE_X) + SQ(EYE_Y) - (CONSTANTE * SQ(EYE_Z)) - TOUCH;
  delta = SQ(abc.y) - (4 * abc.x * abc.z);
  return (calc_delta(&abc, delta));
}
