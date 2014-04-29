/*
** get_pixel.c for get_pixel in /home/schmer_x//igraph/rt
** 
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
** 
** Started on  Fri Jun  3 19:55:35 2011 xavier schmerber
** Last update Fri Jun  3 22:41:34 2011 xavier schmerber
*/
#include	<stdlib.h>
#include	<pthread.h>
#include	<mlx.h>
#include	<errno.h>
#include	<string.h>
#include	"rt.h"

#define AFF_SIZEX	glob->graph->aff_img.sizex
#define AFF_SIZEY	glob->graph->aff_img.sizey
#define CALC_SIZEX	glob->graph->calc_img.sizex
#define CALC_SIZEY	glob->graph->calc_img.sizey

static void	view_vect_adjust(t_glob *glob, t_coord *vect,
				 double x, double y)
{
  vect->x = glob->universe->screen_dist;
  vect->y = (x - CALC_SIZEX / 2.0);
  vect->z = - (y - CALC_SIZEY / 2.0);
  rotate_3d(vect, &(glob->universe->view_rot), 1);
}

static void	get_one_pixel(t_glob *glob, t_calc *calc)
{
  calc->dist = -1.0;
  intersections(glob, calc);
  if (calc->dist > 0.000001)
    calc_pixel(glob, calc);
  else if (!(IS_OPTION(B_NO_STARS)) && background_color(glob))
    {
      calc->r = (COSMIC_LIGHT) % 0x100;
      calc->g = (COSMIC_LIGHT >> 8) % 0x100;
      calc->b = (COSMIC_LIGHT >> 16) % 0x100;
    }
  else
    {
      calc->r = 0x00;
      calc->g = 0x00;
      calc->b = 0x00;
    }
}

static void	init_calc_struct(t_calc *calc1, t_calc *calc2,
				 t_calc *calc3, t_calc *calc4)
{
  calc1->reflect_deep = 0;
  calc1->transp_deep = 0;
  calc2->reflect_deep = 0;
  calc2->transp_deep = 0;
  calc3->reflect_deep = 0;
  calc3->transp_deep = 0;
  calc4->reflect_deep = 0;
  calc4->transp_deep = 0;
}

int		with_antialiasing(t_glob *glob, int x, int y)
{
  t_calc	calc1;
  t_calc	calc2;
  t_calc	calc3;
  t_calc	calc4;
  int		color;

  view_vect_adjust(glob, &(calc1.view), x, y);
  calc1.eye = glob->universe->eye;
  view_vect_adjust(glob, &(calc2.view), x + 0.5, y);
  calc2.eye = glob->universe->eye;
  view_vect_adjust(glob, &(calc3.view), x, y + 0.5);
  calc3.eye = glob->universe->eye;
  view_vect_adjust(glob, &(calc4.view), x + 0.5, y + 0.5);
  calc4.eye = glob->universe->eye;
  init_calc_struct(&calc1, &calc2, &calc3, &calc4);
  get_one_pixel(glob, &calc1);
  get_one_pixel(glob, &calc2);
  get_one_pixel(glob, &calc3);
  get_one_pixel(glob, &calc4);
  color = make_pixel(&calc1, &calc2, &calc3, &calc4);
  return (color);
}

int		without_antialiasing(t_glob *glob, int x, int y)
{
  t_calc	calc;
  int		color;

  view_vect_adjust(glob, &(calc.view), x, y);
  calc.eye = glob->universe->eye;
  calc.reflect_deep = 0;
  calc.transp_deep = 0;
  get_one_pixel(glob, &calc);
  if (calc.dist > 0.000001)
    color = ((int)(calc.light_dif.z) << 16)
      + ((int)(calc.light_dif.y) << 8) + ((int)(calc.light_dif.x));
  else
    color = ((int)(calc.b) << 16)  + ((int)(calc.g) << 8)
      + ((int)(calc.r));
  return (color);
}
