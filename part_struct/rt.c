/*
** main.c for raytracer in /home/fische_s//dossier/projets/rt
**
** Made by sylvain fischer
** Login   <fische_s@epitech.net>
**
** Started on  Tue Apr 12 09:55:29 2011 sylvain fischer
** Last update Sat Jun  4 06:55:45 2011 xavier schmerber
*/
#include	<mlx.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"rt.h"

# define AFF_SIZEX	glob->graph->aff_img.sizex
# define AFF_SIZEY	glob->graph->aff_img.sizey
# define CALC_SIZEX	glob->graph->calc_img.sizex
# define CALC_SIZEY	glob->graph->calc_img.sizey

void	free_glob(t_glob *glob)
{
  t_obj	*start;

  start = glob->obj;
  my_free(glob->option->author, glob->option->desc, NULL);
  my_free(glob->option, glob->graph->mlx_ptr, glob->graph, NULL);
  my_free(glob->universe, NULL);
  if (start != NULL)
    {
      start->prev->next = NULL;
      while (start->next != NULL)
	{
	  start = start->next;
	  free(start->prev);
	}
      free(start);
    }
}

static void	init_img(t_glob *glob, t_img *image, int sizex, int sizey)
{
  if ((image->img = mlx_new_image(glob->graph->mlx_ptr, sizex, sizey)) == 0)
    put_error("Cannot create image\n", 1);
  image->data = mlx_get_data_addr(image->img, &(image->bpp),
				  &(image->sizeline), &(glob->graph->endian));
  if (image->data == NULL)
    put_error("Cannot create image container\n", 1);
}

static void	init(t_glob *glob)
{
  if ((glob->graph->mlx_ptr = mlx_init()) == 0)
    put_error("Cannot init mlx\n", 1);
  init_img(glob, &(glob->graph->aff_img), AFF_SIZEX, AFF_SIZEY);
  init_img(glob, &(glob->graph->calc_img), CALC_SIZEX, CALC_SIZEY);
  init_img(glob, &(glob->graph->loader), 60, 60);
  if ((glob->graph->win_ptr = mlx_new_window(glob->graph->mlx_ptr,
					     AFF_SIZEX, AFF_SIZEY,
					     "Raytracer")) == 0)
    put_error("Cannot create window\n", 1);
}

int		main(int ac, char **av)
{
  t_glob	*glob;

  glob = cx_malloc(1 * sizeof(*glob));
  glob->graph = cx_malloc(1 * sizeof(t_graph));
  glob->universe = cx_malloc(1 * sizeof(t_uni));
  glob->option = cx_malloc(1 * sizeof(t_option));
  if (ac < 2)
    {
      fprintf(stderr, "Usage: ./%s [file.xml] [flags]\n", av[0]);
      put_error(USAGE_FLAG, 1);
    }
  parse_conf(av[1], glob);
  get_args(glob, ac, av);
  check_parse(glob);
  init_methodes(glob);
  init(glob);
  tracemyray(glob);
  mlx_expose_hook(glob->graph->win_ptr, &expose, glob);
  mlx_key_hook(glob->graph->win_ptr, &key_hook, glob);
  mlx_loop(glob->graph->mlx_ptr);
  return (EXIT_SUCCESS);
}
