/*
** solve_second.c for rt in /home/oliver_f//Teck/Igraph/RT/raytracer/SVN/TraceMyRay
** 
** Made by florian oliver
** Login   <oliver_f@epitech.net>
** 
** Started on  Tue May 24 10:05:15 2011 florian oliver
** Last update Tue May 24 10:13:55 2011 florian oliver
*/

#include "struct.h"
#include "rt.h"
/* equation bicarre a resoudre */

void		solve_second(t_poly * poly, double a, double b, double c)
{
  double	delta;
  t_coord	abc;
  double	res;

  poly->res[0] = -1.0;
  poly->res[1] = -1.0;
  poly->res[2] = -1.0;
  poly->res[3] = -1.0;
  abc.x = 1.0;
  abc.y = a;
  abc.z = c;
  delta = (a * a) - (4.0 * 1 * c);
  res = calc_delta(&abc, delta);
  poly->res[0] = res;
}
