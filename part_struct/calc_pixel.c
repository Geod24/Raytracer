/*
** calc_pixel.c for rt in /home/schmer_x//igraph/rt/part_struct
**
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
**
** Started on  Thu May 12 13:46:36 2011 xavier schmerber
** Last update Fri Jun  3 14:55:02 2011 xavier schmerber
*/
#include "rt.h"

void	find_inter_point(t_calc *calc)
{
  calc->inter.x = calc->eye.x + (calc->dist * calc->view.x);
  calc->inter.y = calc->eye.y + (calc->dist * calc->view.y);
  calc->inter.z = calc->eye.z + (calc->dist * calc->view.z);
}

void	calc_pixel(t_glob *glob, t_calc *calc)
{
  find_inter_point(calc);
  calc->obj->methode->calc_normale(calc);
  if (IS(P_NORMAL))
    perturb_normal(&(calc->normale), &(calc->inter));
  calc_reflect_vect(calc, &(calc->view));
  calc->light_dif.x = 1;
  calc->light_dif.y = 1;
  calc->light_dif.z = 1;
  calc->obj->methode->calc_color(calc);
  if (!(IS_OPTION(B_NO_LIGHT)))
    calc->obj->methode->calc_light(glob, calc);
  calc_pixel_color(calc);
  if (!(IS_OPTION(B_NO_REFLECT)))
    calc->obj->methode->calc_reflec(glob, calc);
  if (!(IS_OPTION(B_NO_TRANSP)))
    calc->obj->methode->calc_transp(glob, calc);
}
