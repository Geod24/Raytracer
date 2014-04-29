/*
** inter_cube_troue.c for rt in /home/oliver_f//Teck/Igraph/RT/raytracer/SVN/TraceMyRay
**
** Made by florian oliver
** Login   <oliver_f@epitech.net>
**
** Started on  Thu May 26 22:03:42 2011 florian oliver
** Last update Sat Jun  4 00:51:07 2011 Mathias Lang
*/
#include <math.h>
#include "rt.h"

static void	calc_trou(t_poly *poly, t_coord tmp_view, t_coord tmp_eye)
{
  poly->a = pow(VIEW_X, 4.0) + pow(VIEW_Y, 4.0) + pow(VIEW_Z, 4.0);
  poly->b = 4.0 * ((pow(VIEW_X, 3.0) * EYE_X) + (pow(VIEW_Y, 3.0) * EYE_Y)
		  + (pow(VIEW_Z, 3.0) * EYE_Z));
  poly->c = 6.0 * ((SQ(VIEW_X) * SQ(EYE_X)) + (SQ(VIEW_Y) * SQ(EYE_Y))
		  + (SQ(VIEW_Z) * SQ(EYE_Z))) -
    (5.0 * (SQ(VIEW_X) + SQ(VIEW_Y) + SQ(VIEW_Z)));
  poly->d = 4.0 * ((pow(EYE_X, 3.0) * VIEW_X) + (pow(EYE_Y, 3.0) * VIEW_Y)
		  + (pow(EYE_Z, 3.0) * VIEW_Z)) -
    (10 * (VIEW_X * EYE_X) + (VIEW_Y * EYE_Y) + (VIEW_Z * EYE_Z));
  poly->e = pow(EYE_X, 4.0) + pow(EYE_Y, 4.0) + pow(EYE_Z, 4.0) -
    (5.0 * (SQ(EYE_X) + SQ(EYE_Y) + SQ(EYE_Z))) + 11.8;
}

double		inter_cube_troue(t_obj *obj, t_calc *calc)
{
  t_coord       tmp_eye, tmp_view;
  t_poly	poly;
  int           k = 0;
  int		i = -1;

  poly.res = cx_malloc(sizeof(double) * 5);
  poly.res_done = cx_malloc(sizeof(double) * 5);
  init_view(&tmp_eye, &tmp_view, obj, calc);
  calc_trou(&poly, tmp_view, tmp_eye);
  while (i++ < 4)
    {
      poly.res[i] = -1.0;
      poly.res_done[i] = -1.0;
    }
  if (poly.a == 0.0 && poly.b != 0.0)
    {
      solve_cubic(&poly);
      k++;
    }
  else
    solve_quad(&poly);
  return ((k != 0) ? search_mino(&poly) : search_min(&poly));
}
