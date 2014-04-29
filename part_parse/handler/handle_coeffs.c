/*
** handle_coeffs.c for TraceMyRay in /home/lang_m/code/c/RT/part_parse
** 
** Made by Mathias Lang
** Login   <lang_m@epitech.net>
** 
** Started on  Tue May 24 13:14:59 2011 Mathias Lang
** Last update Fri Jun  3 19:29:03 2011 Mathias Lang
*/
#include	<stdio.h>
#include	"rt.h"

# define OUT_COEFF	"Error: %s tag outside a <coeffs> one.\n"

int	handle_brillance(t_glob *glob, char *file,
			  int *count)
{
  if (!COEFFS_FLAG)
    {
      printf(OUT_COEFF, "<brillance>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  glob->obj->typdef.coeff.brill = get_bal_val(file, count);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<brillance>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}

int	handle_transparence(t_glob *glob, char *file,
			      int *count)
{
  if (!COEFFS_FLAG)
    {
      printf(OUT_COEFF, "<transparence>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  glob->obj->typdef.coeff.trans = get_bal_val_double(file, count);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<transparence>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}

int	handle_reflection(t_glob *glob, char *file, int *count)
{
  if (!COEFFS_FLAG)
    {
      printf(OUT_COEFF, "<reflection>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  glob->obj->typdef.coeff.reflc = get_bal_val_double(file, count);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<reflection>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}
