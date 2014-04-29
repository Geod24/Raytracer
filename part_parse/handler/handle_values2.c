/*
** handle_values2.c for TraceMyRay in /home/lang_m/code/c/RT
** 
** Made by Mathias Lang
** Login   <lang_m@epitech.net>
** 
** Started on  Mon May 30 17:31:46 2011 Mathias Lang
** Last update Fri Jun  3 19:28:50 2011 Mathias Lang
*/
#include	<stdio.h>
#include	"rt.h"

int	handle_angle(t_glob *glob, char *file, int *count)
{
  if (!OBJECT_FLAG)
    {
      printf(ERR_IN_OBJ, "<angle>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  glob->obj->typdef.angle = get_bal_val(file, count);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<angle>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}
