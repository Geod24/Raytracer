/*
** resize_key.c for rt in /home/klein_e//Project/tek1/igraph/RT_final/TraceMyRay/part_graph
**
** Made by eric klein
** Login   <klein_e@epitech.net>
**
** Started on  Fri May 27 15:33:19 2011 eric klein
** Last update Fri Jun  3 21:27:54 2011 xavier schmerber
*/
#include	<mlx.h>
#include	<stdio.h>
#include	<ncurses.h>
#include	"rt.h"

static void		init_new_image(t_glob *glob, int h, int w)
{
    /*mlx_destroy_image(glob->graph->mlx_ptr, glob->graph->aff_img.img);*/
  glob->graph->aff_img.img = mlx_new_image(glob->graph->mlx_ptr, w, h);
  glob->graph->aff_img.data = mlx_get_data_addr(glob->graph->aff_img.img,
                                                &(glob->graph->aff_img.bpp),
                                                &(glob->graph->
						  aff_img.sizeline),
                                                &(glob->graph->endian));
  glob->graph->aff_img.sizey = h;
  glob->graph->aff_img.sizex = w;
  resize_img(&(glob->graph->calc_img), &(glob->graph->aff_img));
  mlx_put_image_to_window(glob->graph->mlx_ptr, glob->graph->win_ptr,
                          glob->graph->aff_img.img, 0, 0);
  mlx_expose_hook(glob->graph->win_ptr, &expose, glob);
  mlx_key_hook(glob->graph->win_ptr, &key_hook, glob);
  mlx_loop(glob->graph->mlx_ptr);
}

static void		scall_minus(int *h, int *w, t_glob *glob)
{
  if (*h > 100)
    *h = *h - (*h * 0.1);
  else
    *h = 100;
  if (*w > 100)
    *w = *w - (*w * 0.1);
  else
    *w = 100;
  if ((glob->graph->win_ptr = mlx_new_window(glob->graph->mlx_ptr, *w, *h
					     , "Tiny Window !")) == NULL)
    fprintf(stderr, "Invalide return from new window \n");
}

static void		scall_plus(int *h, int *w, t_glob *glob)
{
  if (*h < 840 && (*h * 1.1) < 840)
    *h = (*h * 1.1);
  else
    *h = 840;
  if (*w < 1580 && (*w * 1.1) < 1580)
    *w = (*w * 1.1);
  else
    *w = 1580;
  if ((glob->graph->win_ptr = mlx_new_window(glob->graph->mlx_ptr, *w, *h
					     , "Bigger Window !")) == NULL)
    fprintf(stderr, "Invalide return from new window \n");
}

void	resize_window(t_glob *glob, int keycode)
{
  int	h;
  int	w;

  h = glob->graph->aff_img.sizey;
  w = glob->graph->aff_img.sizex;
  mlx_destroy_window(glob->graph->mlx_ptr, glob->graph->win_ptr);
  if (keycode == 65451 || keycode == 65362)
    scall_plus(&h, &w, glob);
  if (keycode == 65453 || keycode == 65364)
    scall_minus(&h, &w, glob);
  init_new_image(glob, h, w);
}
