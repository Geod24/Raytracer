/*
** exit_functions.c for TraceMyRay in /home/lang_m/code/c/RT/part_parse
** 
** Made by Mathias Lang
** Login   <lang_m@epitech.net>
** 
** Started on  Mon May 30 12:28:21 2011 Mathias Lang
** Last update Fri Jun  3 19:47:17 2011 Mathias Lang
*/
#include	<stdlib.h>
#include	"rt.h"

static void	free_glob_parseur(t_glob *glob)
{
  if (glob != NULL)
    {
      while (glob->obj && glob->obj->next)
	{
	  glob->obj = glob->obj->next;
	  free(glob->obj->prev);
	}
      my_free(glob->obj, glob, NULL);
    }
}

void	free_and_quit(t_glob *glob, char *file, int *count)
{
  my_free(file, count, NULL);
  free_glob_parseur(glob);
  exit(EXIT_FAILURE);
}
