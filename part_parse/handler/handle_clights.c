/*
** handle_coeffs_lights.c for TraceMyRay in /home/lang_m/code/c/RT
** 
** Made by Mathias Lang
** Login   <lang_m@epitech.net>
** 
** Started on  Mon May 30 17:23:47 2011 Mathias Lang
** Last update Fri Jun  3 19:28:07 2011 Mathias Lang
*/
#include	<stdio.h>
#include	"rt.h"

# define OUT_COEFF	"Error: %s tag outside a <coeffs> one.\n"

int	handle_ambiant_light(t_glob *glob, char *file, int *count)
{
  if (!COEFFS_FLAG)
    {
      printf(OUT_COEFF, "<ambiant_light>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  glob->obj->typdef.coeff.k_amb = get_bal_val_double(file, count);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<ambiant_light>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}

int	handle_diff_light(t_glob *glob, char *file, int *count)
{
  if (!COEFFS_FLAG)
    {
      printf(OUT_COEFF, "<diff_light>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  glob->obj->typdef.coeff.k_dif = get_bal_val_double(file, count);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<diff_light>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}

int	handle_specular_light(t_glob *glob, char *file, int *count)
{
  if (!COEFFS_FLAG)
    {
      printf(OUT_COEFF, "<specular_light>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  glob->obj->typdef.coeff.k_spe = get_bal_val_double(file, count);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<specular_light>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}
