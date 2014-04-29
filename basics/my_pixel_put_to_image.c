/*
** my_pixel_put_to_image.c for my_pixel_put_to_image in /home/schmer_x//igraph/tp2
** 
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
** 
** Started on  Thu Nov 18 09:16:11 2010 xavier schmerber
** Last update Wed May 25 13:56:27 2011 Mathias Lang
*/

#include	<mlx.h>
#include	"struct.h"

# define IMAGE_POSITION	(y * glob->graph->calc_img.sizeline	\
			 + x * glob->graph->calc_img.bpp / 8)

void	my_pixel_put_to_image(int x, int y, t_glob *glob, int color)
{
  int	r;
  int	g;
  int	b;
  int	tmp;
  int	decal;

  r = color % 0x100;
  g = (color >> 8) % 0x100;
  b = (color >> 16) % 0x100;
  decal = 0;
  if (glob->graph->endian == 1)
    {
      decal = 1;
      tmp = r;
      r = b;
      b = tmp;
    }
  if (IMAGE_POSITION >= 0 && IMAGE_POSITION + 3 <
      (glob->graph->calc_img.sizey * glob->graph->calc_img.sizeline))
    {
      glob->graph->calc_img.data[IMAGE_POSITION + decal] = r;
      glob->graph->calc_img.data[IMAGE_POSITION + decal + 1] = g;
      glob->graph->calc_img.data[IMAGE_POSITION + decal + 2] = b;
    }
}
