/*
** reflection.c for reflection in /home/schmer_x//igraph/rt
** 
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
** 
** Started on  Tue May 31 01:44:23 2011 xavier schmerber
** Last update Sun Jun  5 00:49:23 2011 xavier schmerber
*/
#include	"rt.h"

static void	make_new_pixel_color(t_glob *glob, t_calc *new)
{
  if (new->dist > 0.000001)
    calc_pixel(glob, new);
  else if (!(IS_OPTION(B_NO_STARS)) && background_color(glob))
    {
      new->light_dif.x = (COSMIC_LIGHT) % 0x100;
      new->light_dif.y = (COSMIC_LIGHT >> 8) % 0x100;
      new->light_dif.z = (COSMIC_LIGHT >> 16) % 0x100;
    }
  else
    {
      new->light_dif.x = 0x00;
      new->light_dif.y = 0x00;
      new->light_dif.z = 0x00;
    }
}

void		calc_reflection(t_glob *glob, t_calc *calc)
{
  t_calc	new;

  if (calc->reflect_deep < glob->universe->reflec_deep)
    {
      new.eye = calc->inter;
      new.view = calc->reflect;
      new.reflect_deep = calc->reflect_deep + 1;
      new.transp_deep = calc->transp_deep;
      intersections(glob, &new);
      make_new_pixel_color(glob, &new);
      calc->light_dif.x = (((1.0 - COEFF_REFLC) * calc->light_dif.x)
			   + (COEFF_REFLC * new.light_dif.x));
      calc->light_dif.y = (((1.0 - COEFF_REFLC) * calc->light_dif.y)
			   + (COEFF_REFLC * new.light_dif.y));
      calc->light_dif.z = (((1.0 - COEFF_REFLC) * calc->light_dif.z)
			   + (COEFF_REFLC * new.light_dif.z));
    }
}

void		calc_transparency(t_glob *glob, t_calc *calc)
{
  t_calc        new;

  if (calc->transp_deep < glob->universe->transp_deep)
    {
      new.eye = calc->inter;
      new.view = calc->view;
      new.reflect_deep = calc->reflect_deep;
      new.transp_deep = calc->transp_deep + 1;
      intersections(glob, &new);
      make_new_pixel_color(glob, &new);
      calc->light_dif.x = (((1.0 - COEFF_TRANS) * calc->light_dif.x)
			   + (COEFF_TRANS * new.light_dif.x));
      calc->light_dif.y = (((1.0 - COEFF_TRANS) * calc->light_dif.y)
			   + (COEFF_TRANS * new.light_dif.y));
      calc->light_dif.z = (((1.0 - COEFF_TRANS) * calc->light_dif.z)
			   + (COEFF_TRANS * new.light_dif.z));
    }
}
