/*
** inter_tore.c for rt in /home/oliver_f//Teck/Igraph/RT/raytracer/SVN/TraceMyRay/part_struct
** 
** Made by florian oliver
** Login   <oliver_f@epitech.net>
** 
** Started on  Mon May 16 16:15:07 2011 florian oliver
** Last update Sat Jun  4 00:50:51 2011 Mathias Lang
*/
#include	<math.h>
#include	"struct.h"
#include	"rt.h"

#define RAYON_N		obj->typdef.size
#define RAYON_TORE	obj->typdef.rayon_tore
/* equation du 4eme degre
** ((x * x) + (y * y) + (z * z) - (r * r) - (R * R)) au carre + 4R*R*Z*Z - 4*r * R * R * R;
**
*/
#define A	poly->a
#define B	poly->b
#define C	poly->c
#define D	poly->d
#define E	poly->e
#define F	poly->f
#define B0	nbb.x
#define B1	nbb.y
#define B2	nbb.z

void		search_alpha(double d, t_poly *poly, double z0, double d2)
{
  double	alpha;

  alpha = d - 4.0 * (z0 - d2);
  if (alpha == 0.0)
    poly->res_done[0] = (-pow(d, 0.5) / 2.0) + (B / 4.0);
  else if (alpha > 0.0)
    {
      poly->res_done[0] = -((pow(d, 0.5) + pow(alpha, 0.5)) / 2.0)
  	- (B / 4.0);
      poly->res_done[1] = -((pow(d, 0.5) - pow(alpha, 0.5)) / 2.0)
  	- (B / 4.0);
    }
  alpha = d - 4.0 * (z0 + d2);
  if (alpha == 0.0)
    poly->res_done[2] = (pow(d, 0.5) / 2.0) + (B / 4.0);
  else if (alpha > 0.0)
    {
      poly->res_done[2] = ((pow(d, 0.5)
			    + pow(alpha, 0.5)) / 2.0) - (B / 4.0);
      poly->res_done[3] = ((pow(d, 0.5) -
			    pow(alpha, 0.5)) / 2.0) - (B / 4.0);
    }
}

void		resolve_last(t_poly *poly, double z0, t_coord *nbb)
{
  double	d, d2, next;

  d = 2.0 * (z0 + nbb->z);
  next = 0.0;
  if (d < next)
    {
      if (d > -EPSILON)
	d = 0.0;
      else
	poly->res_done[0] = -1.0;
      return;
    }
  if (d < next)
    d2 = pow(((nbb->z * nbb->y) - nbb->x) / d,  0.5);
  else
    {
      d2 = z0 * z0 + nbb->y;
      if (d2 < 0.0)
	poly->res_done[0] = -1.0;
      else
	d2 = pow(z0 * z0 + nbb->y, 0.5);
    }
  search_alpha(d, poly, z0, d2);
}

static void	init_coeff_poly(t_poly *poly)
{
  int		i;

  i = -1;
  poly->a = poly->tmpa * poly->tmpa;
  poly->b = 2.0 * poly->tmpa * poly->tmpb;
  poly->c = 2.0 * poly->tmpa * poly->tmpc + (poly->tmpb * poly->tmpb)
    - poly->tmpd;
  poly->d = 2.0 * (poly->tmpb * poly->tmpc) - poly->tmpe;
  poly->e = (poly->tmpc * poly->tmpc) - poly->f;
  while (i++ < 4)
    {
      poly->res[i] = -1.0;
      poly->res_done[i] = -1.0;
    }
}

double		inter_tore(t_obj *obj, t_calc *calc)
{
  t_poly	poly;
  t_coord	tmp_eye, tmp_view;
  int		k = 0;

  poly.res = cx_malloc(sizeof(double) * 5);
  poly.res_done = cx_malloc(sizeof(double) * 5);
  init_view(&tmp_eye, &tmp_view, obj, calc);
  poly.tmpa = VIEW_X * VIEW_X + VIEW_Y * VIEW_Y + VIEW_Z * VIEW_Z;
  poly.tmpb = 2.0 * (VIEW_X * EYE_X + VIEW_Y * EYE_Y + VIEW_Z * EYE_Z);
  poly.tmpc = EYE_X * EYE_X + EYE_Y * EYE_Y + EYE_Z * EYE_Z
    + (RAYON_N * RAYON_N) - (RAYON_TORE * RAYON_TORE);
  poly.tmp = 4.0 * RAYON_N * RAYON_N;
  poly.tmpd = poly.tmp * (VIEW_X * VIEW_X + VIEW_Z * VIEW_Z);
  poly.tmpe = poly.tmp * 2.0 * (VIEW_X * EYE_X + VIEW_Z * EYE_Z);
  poly.f = poly.tmp * (EYE_X * EYE_X + EYE_Z * EYE_Z);
  init_coeff_poly(&poly);
  if (poly.a == 0.0 && poly.b != 0.0)
    {
      solve_cubic(&poly);
      k++;
    }
  else
    solve_quad(&poly);
  return ((k != 0) ? search_mino(&poly) : search_min(&poly));
}
