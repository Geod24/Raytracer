/*
** handle_universe.c for TraceMyRay in /home/lang_m/code/c/RT
** 
** Made by Mathias Lang
** Login   <lang_m@epitech.net>
** 
** Started on  Mon May 23 16:03:30 2011 Mathias Lang
** Last update Fri Jun  3 19:28:21 2011 Mathias Lang
*/
#include	<stdio.h>
#include	"rt.h"

int	handle_graph(t_glob *glob, char *file, int *count)
{
  if (!RT_FLAG || !UNIVERSE_FLAG || ID_FLAG || GRAPH_FLAG)
    {
      printf("Error in handle_graph\n");
      free_and_quit(glob, file, count);
    }
  META_FLAG += IN_F_GRAPH;
  return (1);
}

int	handle_const(t_glob *glob, char *file, int *count)
{
  if (!UNIVERSE_FLAG)
    {
      printf(OUT_UNI, "<constants>");
      free_and_quit(glob, file, count);
    }
  META_FLAG += IN_F_CONST;
  return (1);
}

int	handle_coeff(t_glob *glob, char *file, int *count)
{
  if (!OBJECT_FLAG)
    {
      printf(OUT_OBJ, "<coeff>");
      free_and_quit(glob, file, count);
    }
  META_FLAG += IN_F_COEFFS;
  return (1);
}

int	handle_calc_img(t_glob *glob, char *file, int *count)
{
  if (!GRAPH_FLAG)
    {
      printf(OUT_GRAPH, "<calc_img>");
      free_and_quit(glob, file, count);
    }
  META_FLAG += IN_F_CALC_IMG;
  return (1);
}

int	handle_aff_img(t_glob *glob, char *file, int *count)
{
  if (!RT_FLAG || !UNIVERSE_FLAG || !GRAPH_FLAG)
    {
      printf("Error in handle_aff_img\n");
      free_and_quit(glob, file, count);
    }
  META_FLAG += IN_F_AFF_IMG;
  return (1);
}
