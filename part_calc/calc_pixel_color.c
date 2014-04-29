/*
** calc_pixel_color.c for calc_pixel_color in /home/schmer_x//igraph/rt
** 
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
** 
** Started on  Tue May 31 15:32:47 2011 xavier schmerber
** Last update Fri Jun  3 22:35:49 2011 xavier schmerber
*/
#include	"rt.h"

void	calc_pixel_color(t_calc *calc)
{
  calc->light_dif.x = (MAJ1(calc->light_dif.x) * calc->r
		       +  MAJ1(calc->light_spe.x) * 0xFF);
  calc->light_dif.y = (MAJ1(calc->light_dif.y) * calc->g
		       + MAJ1(calc->light_spe.y) * 0xFF);
  calc->light_dif.z = (MAJ1(calc->light_dif.z) * calc->b
		       + MAJ1(calc->light_spe.z) * 0xFF);
  if (calc->light_dif.x > 0xFF)
    calc->light_dif.x = 0xFF;
  if (calc->light_dif.y > 0xFF)
    calc->light_dif.y = 0xFF;
  if (calc->light_dif.z > 0xFF)
    calc->light_dif.z = 0xFF;
}
