/*
** events.c for events in /home/schmer_x//igraph/rt
** 
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
** 
** Started on  Fri Jun  3 21:28:56 2011 xavier schmerber
** Last update Fri Jun  3 21:59:34 2011 xavier schmerber
*/
#include	<stdlib.h>
#include	<mlx.h>
#include	"rt.h"

int	key_hook(int button, t_glob *glob)
{
    if (button == 65451 || button == 65453 ||
        button == 65362 || button == 65364)
        resize_window(glob, button);
    if (button == 65307) {
        /*mlx_destroy_image(glob->graph->mlx_ptr, glob->graph->aff_img.img);*/
        mlx_destroy_window(glob->graph->mlx_ptr, glob->graph->win_ptr);
        free_glob(glob);
        exit(EXIT_SUCCESS);
    }
    if (button == 112)
        fill_bmp(&(glob->graph->aff_img));
    return (0);
}

int	expose(t_glob *glob)
{
    mlx_put_image_to_window(glob->graph->mlx_ptr, glob->graph->win_ptr,
                            glob->graph->aff_img.img, 0, 0);
    return (0);
}
