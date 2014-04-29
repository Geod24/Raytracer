/*
** check_values.c for rt in /home/oliver_f//Teck/Igraph/RT/raytracer/SVN/TraceMyRay
**
** Made by florian oliver
** Login   <oliver_f@epitech.net>
**
** Started on  Thu Jun  2 21:29:41 2011 florian oliver
** Last update Fri Jun  3 20:32:08 2011 sylvain fischer
*/
#include	<string.h>
#include	"rt.h"

void		check_reflc(t_error *error, t_obj *obj)
{
  if (obj->typdef.coeff.reflc < 0.0 || obj->typdef.coeff.reflc > 1.0)
    {
      error->nb += 1;
      error->type_errors[error->nb] = obj->typdef.coeff.reflc;
      if (obj->typdef.coeff.reflc < 0.0)
        {
          error->fatal = 1;
          error->errors[error->nb] =
	    strdup("Error: invalid assignment reflection");
        }
      else
        error->errors[error->nb] =
	  strdup("Warning: invalid assignment reflection");
    }
}

void		check_rtore(t_error *error, t_obj *obj)
{
  if (obj->typdef.rayon_tore <= 0.0)
    {
      error->nb += 1;
      error->type_errors[error->nb] = obj->typdef.rayon_tore;
      if (obj->typdef.rayon_tore < -0.0)
        {
          error->errors[error->nb] =
	    strdup("Error: invalid assignment torox");
          error->fatal = 1;
        }
      else
        error->errors[error->nb] =
	  strdup("Warning: invalid assignment torox");
    }
}

void		check_satur(t_error *error, t_obj *obj)
{
  double	res;

  res = obj->typdef.coeff.k_amb + obj->typdef.coeff.k_dif
 + obj->typdef.coeff.k_spe;
  if (res > 1.0)
    {
      error->nb += 1;
      error->type_errors[error->nb] = res;
      error->errors[error->nb] = strdup("Warning: saturation is possible");
    }
}
