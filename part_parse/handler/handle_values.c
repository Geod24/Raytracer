/*
** handle_simple_obj_values.c for raytracer in /home/lang_m/code/c/RT/part_parse
** 
** Made by Mathias Lang
** Login   <lang_m@epitech.net>
** 
** Started on  Sun May  1 00:27:36 2011 Mathias Lang
** Last update Fri Jun  3 19:28:36 2011 Mathias Lang
*/
#include	<stdio.h>
#include	"rt.h"

int	handle_radius(t_glob *glob, char *file, int *count)
{
  if (!OBJECT_FLAG)
    {
      printf(ERR_IN_OBJ, "<radius>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  glob->obj->typdef.size = get_bal_val(file, count);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<radius>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}

int	handle_rtore(t_glob *glob, char *file, int *count)
{
  if (!OBJECT_FLAG)
    {
      printf(ERR_IN_OBJ, "<torox\n");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  glob->obj->typdef.rayon_tore = get_bal_val(file, count);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<torox>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}

int	handle_type(t_glob *glob, char *file, int *count)
{
  if (!OBJECT_FLAG)
    {
      printf("Error: %s\n", "<type>");
      printf(ERR_IN_OBJ, "<type>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  glob->obj->type = get_bal_val(file, count);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<type>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}

int	handle_power(t_glob *glob, char *file, int *count)
{
  if (!OBJECT_FLAG)
    {
      printf(ERR_IN_OBJ, "<power>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  glob->obj->typdef.power = get_bal_val_double(file, count);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<power>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}

int	handle_size(t_glob *glob, char *file, int *count)
{
  if (!OBJECT_FLAG)
    {
      printf(ERR_IN_OBJ, "<size>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  glob->obj->typdef.size = get_bal_val(file, count);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<size>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}
