/*
** init_view.c for rt in /home/oliver_f//Teck/Igraph/RT/raytracer/SVN/TraceMyRay
**
** Made by florian oliver
** Login   <oliver_f@epitech.net>
**
** Started on  Thu May 26 22:24:33 2011 florian oliver
** Last update Fri Jun  3 18:15:04 2011 xavier schmerber
*/
#include	"rt.h"

void	init_view(t_coord *tmp_eye, t_coord *tmp_view,
		  t_obj *obj, t_calc *calc)
{
  tmp_eye->x = calc->eye.x - obj->stddef.pos.x;
  tmp_eye->y = calc->eye.y - obj->stddef.pos.y;
  tmp_eye->z = calc->eye.z - obj->stddef.pos.z;
  tmp_view->x = calc->view.x;
  tmp_view->y = calc->view.y;
  tmp_view->z = calc->view.z;
  rotate_3d(tmp_eye, &(obj->typdef.rot), -1);
  rotate_3d(tmp_view, &(obj->typdef.rot), -1);
}
