/*
** calc_quad.c for RT in /home/fische_s//dossier/projets/SVN/TraceMyRay
** 
** Made by sylvain fischer
** Login   <fische_s@epitech.net>
** 
** Started on  Fri Jun  3 20:13:33 2011 sylvain fischer
** Last update Fri Jun  3 20:21:21 2011 sylvain fischer
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
#define B0 nbb->x
#define B1 nbb->y
#define B2 nbb->z

static void            init_poly(t_poly *poly, double b2, double b1,
				 double b0)
{
  A = 0.0;
  B = 1.0;
  C = b2;
  D = b1;
  E = b0;
  F = 0.0;
}

void	calc_quad(t_coord *nbb, t_poly *poly2, t_poly *poly)
{
  int	i;

  i = -1;
  B2 = (((3.0 * B * B) / 8.0) - C) / 2.0;
  B1 = ((3.0 * B * B * B * B) / 256.0) - ((B * B * C) / 16.0)
    + ((B * D) / 4.0) - E;
  B0 = B2 * B1 - pow((((B * B * B) / 16.0) -
		      ((B * C) / 4.0) + (D / 2.0)), 2.0);
  init_poly(poly2, B2, B1, B0);
  while (i++ < 4)
    poly2->res[i] = -1.0;
}
