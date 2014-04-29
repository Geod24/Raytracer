/*
** calc_color.c for rt in /home/schmer_x//igra0..0ph/rt/part_calc
** 
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
** 
** Started on  Tue Apr 12 15:55:10 2011 xavier schmerber
** Last update Fri Jun  3 10:52:00 2011 xavier schmerber
*/
#include	"rt.h"

void	calc_color(t_calc *calc)
{
  int	color;

  if (IS(P_DAMIER))
    {
      color = make_damier(calc, (int)(OBJ_POWER * 100),
			  OBJ_COLOR, OBJ_DAM_COLOR);
      calc->r = ((color) % 0x100);
      calc->g = (((color) >> 8) % 0x100);
      calc->b = (((color) >> 16) % 0x100);
    }
  else
    {
      calc->r = ((OBJ_COLOR) % 0x100);
      calc->g = (((OBJ_COLOR) >> 8) % 0x100);
      calc->b = (((OBJ_COLOR) >> 16) % 0x100);
    }
}
