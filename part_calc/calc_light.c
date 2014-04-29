/*
** calc_light.c for rt in /home/schmer_x//igraph/rt/part_calc
** 
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
** 
** Started on  Fri Apr 15 08:43:04 2011 xavier schmerber
** Last update Sat Jun  4 00:43:35 2011 Mathias Lang
*/
#include	<math.h>
#include	"rt.h"

static void	calc_light_vect(t_calc *calc, t_obj *light, t_coord *light_vect)
{
  light_vect->x = light->stddef.pos.x - calc->inter.x;
  light_vect->y = light->stddef.pos.y - calc->inter.y;
  light_vect->z = light->stddef.pos.z - calc->inter.z;
}

static int	test_shadow(t_obj *light, t_coord *light_vect)
{
  t_calc	tempo;
  double	dist;

  tempo.obj = light->next;
  tempo.view.x = - light_vect->x;
  tempo.view.y = - light_vect->y;
  tempo.view.z = - light_vect->z;
  tempo.eye = light->stddef.pos;
  while (tempo.obj != light)
    {
      if (tempo.obj->type != LIGHT)
	{
	  dist = tempo.obj->methode->find_dist(tempo.obj, &tempo);
	  if (dist > 0.000001 && dist < 0.999999)
	    return (1);
	}
      tempo.obj = tempo.obj->next;
    }
  return (0);
}

static void	dif_spe_light(t_glob *glob, t_calc *calc,
			      t_obj *light, t_coord *light_vect)
{
  double	teta_diff;
  double	teta_spec;

  teta_diff = (SCALAIRE_L_N / (NORME(*light_vect) * NORME(calc->normale)));
  teta_spec = (SCALAIRE_R_L / (NORME(calc->reflect) * NORME(*light_vect)));
  if (teta_diff > 0.000001 && !(IS_OPTION(B_NO_DIFF_LIGHT)))
    {
      calc->light_dif.x += (DIFF_LIGHT) * LIGHT_POW * (GET_R(LIGHT_COLOR));
      calc->light_dif.y += (DIFF_LIGHT) * LIGHT_POW * (GET_G(LIGHT_COLOR));
      calc->light_dif.z += (DIFF_LIGHT) * LIGHT_POW * (GET_B(LIGHT_COLOR));
    }
  if (teta_spec > 0.000001 && !(IS_OPTION(B_NO_SPEC_LIGHT)))
    {
      calc->light_spe.x += (SPEC_LIGHT) * LIGHT_POW * (GET_R(LIGHT_COLOR));
      calc->light_spe.y += (SPEC_LIGHT) * LIGHT_POW * (GET_G(LIGHT_COLOR));
      calc->light_spe.z += (SPEC_LIGHT) * LIGHT_POW * (GET_B(LIGHT_COLOR));
    }
}

void	amb_light(t_glob *glob, t_calc *calc)
{
  if (!(IS_OPTION(B_NO_AMB_LIGHT)))
    {
      calc->light_dif.x += GET_R(COSMIC_LIGHT) * COEFF_AMB;
      calc->light_dif.y += GET_G(COSMIC_LIGHT) * COEFF_AMB;
      calc->light_dif.z += GET_B(COSMIC_LIGHT) * COEFF_AMB;
    }
}

void		calc_light(t_glob *glob, t_calc *calc)
{
  t_obj		*tmp;
  t_coord	light_vect;

  calc->light_dif.x = 0;
  calc->light_dif.y = 0;
  calc->light_dif.z = 0;
  calc->light_spe.x = 0;
  calc->light_spe.y = 0;
  calc->light_spe.z = 0;
  tmp = calc->obj->next;
  while (tmp != calc->obj)
    {
      if (tmp->type == LIGHT)
	{
	  calc_light_vect(calc, tmp, &light_vect);
	  rotate_3d(&(calc->inter), &(calc->obj->typdef.rot), -1);
	  if (!(test_shadow(tmp, &(light_vect))))
	    dif_spe_light(glob, calc, tmp, &light_vect);
	  rotate_3d(&(calc->inter), &(calc->obj->typdef.rot), 1);
	}
      tmp = tmp->next;
    }
  amb_light(glob, calc);
}
