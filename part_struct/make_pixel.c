/*
** make_pixel.c for rt in /home/schmer_x//igraph/rt/part_struct
**
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
**
** Started on  Thu May 12 14:14:19 2011 xavier schmerber
** Last update Fri Jun  3 19:22:12 2011 xavier schmerber
*/
#include	"rt.h"

void	add_under_pixel(t_coord *color_moy, t_calc *calc)
{
  if (calc->dist > 0.000001)
    {
      color_moy->x += calc->light_dif.x;
      color_moy->y += calc->light_dif.y;
      color_moy->z += calc->light_dif.z;
    }
  else
    {
      color_moy->x += calc->r;
      color_moy->y += calc->g;
      color_moy->z += calc->b;
    }
}

int		make_pixel(t_calc *calc1, t_calc *calc2,
			   t_calc *calc3, t_calc *calc4)
{
  int		color;
  t_coord	color_moy;

  color_moy.x = 0;
  color_moy.y = 0;
  color_moy.z = 0;
  add_under_pixel(&color_moy, calc1);
  add_under_pixel(&color_moy, calc2);
  add_under_pixel(&color_moy, calc3);
  add_under_pixel(&color_moy, calc4);
  color = ((int)(color_moy.z / 4) << 16)  + ((int)(color_moy.y / 4) << 8)
    + ((int)(color_moy.x / 4));
  return (color);
}
