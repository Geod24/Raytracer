/*
** handle_color.c for raytracer in /home/lang_m/code/c/RT/part_parse
** 
** Made by Mathias Lang
** Login   <lang_m@epitech.net>
** 
** Started on  Sun May  1 00:30:48 2011 Mathias Lang
** Last update Fri Jun  3 19:31:02 2011 Mathias Lang
*/
#include	<stdio.h>
#include	"rt.h"

int	handle_color(t_glob *glob, char *file, int *count)
{
    if (!RT_FLAG || !SCENE_FLAG || !OBJECT_FLAG)
    {
      printf((!RT_FLAG) ? (OUT_RT) : ((!SCENE_FLAG) ? (OUT_SCENE)
				      : (OUT_OBJ)), "<color>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  glob->obj->stddef.color = get_color(file, count, 16);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<color>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}

int	handle_dam_color(t_glob *glob, char *file, int *count)
{
    if (!RT_FLAG || !SCENE_FLAG || !OBJECT_FLAG)
    {
      printf((!RT_FLAG) ? (OUT_RT) : ((!SCENE_FLAG) ? (OUT_SCENE)
				      : (OUT_OBJ)), "<dam_color>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  glob->obj->typdef.dam_color = get_color(file, count, 16);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<dam_color>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}

int	handle_prop(t_glob *glob, char *file, int *count)
{
    if (!RT_FLAG || !SCENE_FLAG || !OBJECT_FLAG)
    {
      printf((!RT_FLAG) ? (OUT_RT) : ((!SCENE_FLAG) ? (OUT_SCENE)
				      : (OUT_OBJ)), "<dam_prop>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  glob->obj->typdef.properties |= get_bal_val(file, count);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<dam_prop>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}
