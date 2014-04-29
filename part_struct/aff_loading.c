/*
** aff_loading.c for aff_loading in /home/schmer_x//igraph/rt
** 
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
** 
** Started on  Fri Jun  3 20:06:38 2011 xavier schmerber
** Last update Fri Jun  3 22:40:51 2011 xavier schmerber
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
#define CHARG_COLOR	0xED7F10
#define AFF_COLOR	0x34C924

static void	clean_percent(t_glob *glob)
{
  static int	create = 0;
  int   x;

  if (create == 0)
    {
      x = 0;
      while (x < 60 * 60 * 4)
        {
          glob->graph->loader.data[x] = 0;
          x++;
        }
      create = 42;
    }
  mlx_put_image_to_window(glob->graph->mlx_ptr, glob->graph->win_ptr,
                          glob->graph->loader.img, AFF_SIZEX / 2 - 15,
                          AFF_SIZEY / 2 + 5);
}

static	void	aff_kikoo(t_glob *glob, int count_part)
{
  if (count_part == 0)
    mlx_string_put(glob->graph->mlx_ptr, glob->graph->win_ptr,
		   5, 15, AFF_COLOR, "Raytracing de la scene en cours...");
  if (count_part == 42)
    mlx_string_put(glob->graph->mlx_ptr, glob->graph->win_ptr,
		   5, 30, AFF_COLOR, "Just take a break to enjoy the 42 !");
  if (count_part == 69)
    mlx_string_put(glob->graph->mlx_ptr, glob->graph->win_ptr,
		   5, 45, AFF_COLOR, "Just take another to enjoy the 69 !");
  if (count_part == 90)
    mlx_string_put(glob->graph->mlx_ptr, glob->graph->win_ptr,
		   5, 60, AFF_COLOR, "Bientot fini ! ;)");
}

void		advance_indice(t_glob *glob, int y)
{
  static int    count_part = 0;
  char		*tmp;

  if (CALC_SIZEY / 100 * count_part == y)
    {
      aff_kikoo(glob, count_part);
      if (count_part <= 100 &&
	  !(count_part > 42 && count_part < 48) &&
	  !(count_part > 69 && count_part < 75))
        {
	  clean_percent(glob);
          mlx_string_put(glob->graph->mlx_ptr, glob->graph->win_ptr,
                         AFF_SIZEX / 2 - 10, AFF_SIZEY / 2 + 15, AFF_COLOR,
                         (tmp = my_putnbr_in_str((count_part))));
          free(tmp);
        }
      mlx_string_put(glob->graph->mlx_ptr, glob->graph->win_ptr,
                     AFF_SIZEX / 2 + 10, AFF_SIZEY / 2 + 15, AFF_COLOR, "%");
      mlx_string_put(glob->graph->mlx_ptr, glob->graph->win_ptr,
		     AFF_SIZEX * count_part / 100, AFF_SIZEY / 2,
                     CHARG_COLOR, "|");
      count_part++;
    }
}
