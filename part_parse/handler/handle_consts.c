/*
** handle_consts.c for TraceMyRay in /home/lang_m/code/c/RT
** 
** Made by Mathias Lang
** Login   <lang_m@epitech.net>
** 
** Started on  Mon May 30 17:28:17 2011 Mathias Lang
** Last update Sat Jun  4 01:13:47 2011 Mathias Lang
*/
#include	<stdio.h>
#include	"rt.h"

# define OUT_CONST	"Error: %s tag outside a <constants> one.\n"

int	handle_screen_dist(t_glob *glob, char *file, int *count)
{
  if (!CONST_FLAG)
    {
      printf(OUT_CONST, "<screen_dist>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  glob->universe->screen_dist = get_bal_val(file, count);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<screen_dist>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}

int	handle_cosmic_light(t_glob *glob, char *file, int *count)
{
  if (!CONST_FLAG)
    {
      printf(OUT_CONST, "<cosmic_light>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  glob->universe->cosmic_light = get_color(file, count, 16);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<cosmic_light>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}

int	handle_transp_deep(t_glob *glob, char *file, int *count)
{
  if (!CONST_FLAG)
    {
      printf(OUT_CONST, "<transp_deep>");
      free_and_quit(glob, file,  count);
    }
  VAL_FLAG = 0;
  glob->universe->transp_deep = get_bal_val(file, count);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<transp_deep>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}

int	handle_reflec_deep(t_glob *glob, char *file, int *count)
{
  if (!CONST_FLAG)
    {
      printf(OUT_CONST, "<reflec_deep>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  glob->universe->reflec_deep = get_bal_val(file, count);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<reflec_deep>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}
