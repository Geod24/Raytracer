/*
** free_exit.c for fdf in /home/schmer_x//igraph/fdf/test
** 
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
** 
** Started on  Thu Dec  2 01:33:12 2010 xavier schmerber
** Last update Fri Mar 11 10:37:45 2011 xavier schmerber
*/

#include <mlx.h>
#include <stdlib.h>
#include "../headers/rt.h"

void	free_exit(t_info *my_info)
{
  t_fig	*tmp;
  t_fig	*rep;

  my_putstr("Freeing memory...\t\t");
  rep = my_info->fig;
  my_info->fig = my_info->fig->next;
  while (my_info->fig != rep)
    {
      tmp = my_info->fig;
      my_info->fig = my_info->fig->next;
      free(tmp);
    }
  free(rep);
  mlx_destroy_image(my_info->mlx_ptr, my_info->img);
  mlx_destroy_window(my_info->mlx_ptr, my_info->win_ptr);
  free(my_info->mlx_ptr);
  free(my_info);
  my_putstr("OK\nGoodbye\n");
  exit (0);
}
