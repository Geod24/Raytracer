/*
** check_value.c for rt in /home/oliver_f//Teck/Igraph/RT/raytracer/SVN/TraceMyRay
**
** Made by florian oliver
** Login   <oliver_f@epitech.net>
**
** Started on  Thu Jun  2 21:24:02 2011 florian oliver
** Last update Fri Jun  3 11:19:58 2011 eric klein
*/
#include "rt.h"

void		check_type(t_error *error, t_obj *obj)
{
  if (obj->type < -1 || obj->type > OBJ_MAX)
    {
      error->nb += 1;
      error->fatal = 1;
      error->type_errors[error->nb] = obj->type;
      error->errors[error->nb] = strdup("Error: invalid type object");
    }
}

void		check_size(t_error *error, t_obj *obj)
{
  if (obj->typdef.size < 0)
    {
      error->nb += 1;
      error->fatal = 1;
      error->type_errors[error->nb] = obj->typdef.size;
      error->errors[error->nb] = strdup("Error: invalid size object");
    }
}

void		check_power(t_error *error, t_obj *obj)
{
  if (obj->typdef.power < 0.0 || obj->typdef.power > 1.0)
    {
      error->nb +=1;
      error->type_errors[error->nb] = obj->typdef.power;
      if (obj->typdef.power < 0.0)
        {
          error->fatal = 1;
          error->errors[error->nb] =
	    strdup("Error: invalid assignment power");
        }
      else
	error->errors[error->nb] =
	  strdup("Warning: invalid assignment power");
    }
}

void		check_kamb(t_error *error, t_obj *obj)
{
  if (obj->typdef.coeff.k_amb < 0.0 || obj->typdef.coeff.k_amb > 1.0)
    {
      error->nb += 1;
      error->type_errors[error->nb] = obj->typdef.coeff.k_amb;
      if (obj->typdef.coeff.k_amb < 0.0)
        {
          error->fatal = 1;
          error->errors[error->nb] =
	    strdup("Error: invalid assignment ambiant_light");
        }
      else
        error->errors[error->nb] =
	  strdup("Warning: invalid assignment ambiant_light");
    }
}

void		check_diff(t_error *error, t_obj *obj)
{
  if (obj->typdef.coeff.k_dif < 0.0 || obj->typdef.coeff.k_dif > 1.0)
    {
      error->nb += 1;
      error->type_errors[error->nb] = obj->typdef.coeff.k_dif;
      if (obj->typdef.coeff.k_amb < 0.0)
        {
          error->fatal = 1;
          error->errors[error->nb] =
	    strdup("Error: invalid assignment diff_light");
        }
      else
        error->errors[error->nb] =
	  strdup("Warning: invalid assignment diff_light");
    }
}
