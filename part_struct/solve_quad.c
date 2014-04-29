/*
** solve_quad.c for rt in /home/oliver_f//Teck/Igraph/RT/raytracer/SVN/TraceMyRay
**
** Made by florian oliver
** Login   <oliver_f@epitech.net>
**
** Started on  Thu May 26 22:07:17 2011 florian oliver
** Last update Fri Jun  3 20:21:22 2011 sylvain fischer
*/
#include <math.h>
#include <stdlib.h>
#include "struct.h"
#include "rt.h"

#define A poly->a
#define B poly->b
#define C poly->c
#define D poly->d
#define E poly->e
#define F poly->f

double          search_mino(t_poly *poly)
{
  int           i;
  double        res;

  i = -1;
  res = 99999999.0;
  while (i++ < 4)
    if (poly->res[i] > 0.0 && poly->res[i] < res)
      res = poly->res[i];
  if (res == 99999999.0)
    res = -1.0;
  free(poly->res);
  free(poly->res_done);
  return (res);
}

double          search_min(t_poly *poly)
{
  int           i;
  double        res;

  i = 0;
  res = 99999.0;
  while (i <= 3)
    {
      if (poly->res_done[i] > 0.0 && poly->res_done[i] < res)
        res = poly->res_done[i];
      i++;
    }
  if (res >= 99999.0)
    res = -1.0;
  free(poly->res);
  free(poly->res_done);
  return (res);
}

void            solve_cubic(t_poly *poly)
{
  double        q, r, d, d2, alpha, s;
  int           i = 0;

  q = ((C * C) - (3.0 * D)) / 9.0;
  r = (C * (C * C - (4.5 * D)) + 13.5 * E) / 27.0;
  d = pow(q, 3.0) - (r * r);
  if (d >= 0.0)
    {
      d2 = r / pow(q, 3.0 / 2.0);
      alpha = acos(d2) / 3.0;
      s = -2.0 * pow(q, 1.0 / 2.0);
      while (i <= 2)
	{
	  poly->res[i] = s * cos(alpha + (2.0 * PI * i) / 3.0) - (C / 3.0);
	  i++;
	}
    }
  else
    {
      s = pow((pow(-d, 0.5) + ABS(r)), 1.0/3.0);
      if (r < 0.0)
        poly->res[0] = s + (q/s) - (C / 3.0);
      else
        poly->res[0] = -s - (q/s) - (C / 3.0);
    }
}

void             solve_quad(t_poly *poly)
{
  t_coord       nbb;
  t_poly        poly2;
  int           i = -1;

  poly2.res = cx_malloc(sizeof(double) * 5);
  E = E / A;
  D = D / A;
  C = C / A;
  B = B / A;
  if (poly->e == 0.0)
    poly->res[0] = -1.0;
  else
    {
      calc_quad(&nbb, &poly2, poly);
      i = -1;
      solve_cubic(&poly2);
      while (i++ < 4)
        poly->res[i] = poly2.res[i];
      i = -1;
      while (poly->res[++i] == -1.0 && i < 4);
      if (i >= 4)
        return;
      resolve_last(poly, poly->res[i], &nbb);
      free(poly2.res);
    }
}
