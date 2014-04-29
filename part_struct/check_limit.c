/*
** check_limit.c for rt in /home/oliver_f//Teck/Igraph/RT/raytracer/SVN/TraceMyRay
** 
** Made by florian oliver
** Login   <oliver_f@epitech.net>
** 
** Started on  Fri May 27 11:08:21 2011 florian oliver
** Last update Fri Jun  3 19:15:40 2011 xavier schmerber
*/
#include	"rt.h"

#define VIEW_X_P	tmp_view->x
#define VIEW_Y_P	tmp_view->y
#define VIEW_Z_P	tmp_view->z
#define EYE_X_P		tmp_eye->x
#define EYE_Y_P		tmp_eye->y
#define EYE_Z_P		tmp_eye->z

double		check_limit(t_obj *obj, double dist,
			    t_coord *tmp_eye, t_coord *tmp_view)
{
  t_coord	abc;

  abc.x = EYE_X_P + (dist * VIEW_X_P);
  abc.y = EYE_Y_P + (dist * VIEW_Y_P);
  abc.z = EYE_Z_P + (dist * VIEW_Z_P);
  if (obj->typdef.size_y >= 0 && obj->typdef.size_x >= 0)
    {
      if (abc.z > obj->typdef.size_x ||
	  abc.z < -obj->typdef.size_y)
	dist = -1.0;
    }
  else if (obj->typdef.size_x > 0)
    {
      if (abc.z > obj->typdef.size_x)
	dist = -1.0;
    }
  else if (obj->typdef.size_y > 0)
    if (abc.z > obj->typdef.size_y)
      dist = -1.0;
  return (dist);
}

