/*
** inter_plan.c for rt in /home/oliver_f//Teck/Igraph/RT/raytracer/SVN/TraceMyRay
** 
** Made by florian oliver
** Login   <oliver_f@epitech.net>
** 
** Started on  Wed May 18 11:47:36 2011 florian oliver
** Last update Fri Jun  3 18:34:29 2011 xavier schmerber
*/
#include	"rt.h"

#define A	norm.x
#define B	norm.y
#define C	norm.z
#define D	0

double		inter_plan(t_obj *obj, t_calc *calc)
{
  double	res;
  t_coord	norm;
  t_coord	tmp_eye;
  t_coord	tmp_view;

  init_view(&tmp_eye, &tmp_view, obj, calc);
  norm.x = 0.0;
  norm.y = 0.0;
  norm.z = 1.0;
  if ((A * VIEW_X + B * VIEW_Y + C * VIEW_Z))
    {
      res = -((A * EYE_X + B * EYE_Y + C * EYE_Z + D) /
	      (A * VIEW_X + B * VIEW_Y + C * VIEW_Z));
      if (res < 0.0)
	res = -1.0;
    }
  else
    res = -1.0;
  return (res);
}
