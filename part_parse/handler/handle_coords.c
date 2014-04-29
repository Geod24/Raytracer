/*
** handle_coords.c for raytracer in /home/lang_m/code/c/RT/part_parse
** 
** Made by Mathias Lang
** Login   <lang_m@epitech.net>
** 
** Started on  Sun May  1 00:28:40 2011 Mathias Lang
** Last update Fri Jun  3 19:31:37 2011 Mathias Lang
*/
#include	<stdio.h>
#include	"rt.h"

# define SIZE_NEEDS	!OBJECT_FLAG && !UNIVERSE_FLAG

int	handle_xsize(t_glob *glob, char *file, int *count)
{
  if (SIZE_NEEDS)
    {
      if (!UNIVERSE_FLAG)
	printf("Error: <xsize> outside <universe>\n");
      else
	printf("Error: <xsize> outside <object>\n");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  if (UNIVERSE_FLAG && CALC_IMG_FLAG)
    glob->graph->calc_img.sizex = get_bal_val(file, count);
  else if (UNIVERSE_FLAG && AFF_IMG_FLAG)
    glob->graph->aff_img.sizex = get_bal_val(file, count);
  else
    glob->obj->typdef.size_x = get_bal_val(file, count);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<xsize>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}

int	handle_ysize(t_glob *glob, char *file, int *count)
{
  if (SIZE_NEEDS)
    {
      if (!UNIVERSE_FLAG)
	printf("Error: <ysize> outside <universe>\n");
      else
	printf("Error: <ysize> outside <object>\n");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  if (UNIVERSE_FLAG && CALC_IMG_FLAG)
    glob->graph->calc_img.sizey = get_bal_val(file, count);
  else if (UNIVERSE_FLAG && AFF_IMG_FLAG)
    glob->graph->aff_img.sizey = get_bal_val(file, count);
  else
    glob->obj->typdef.size_y = get_bal_val(file, count);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<ysize>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}

# define XYZ_NEEDS	!POS_FLAG && !ROTATION_FLAG

int	handle_x(t_glob *glob, char *file, int *count)
{
  if (XYZ_NEEDS)
    {
      printf("Error: <x> tag outside a <pos> or a <rotation> tag.\n");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  if (UNIVERSE_FLAG && POS_FLAG)
    glob->universe->eye.x = get_bal_val(file, count);
  else if (UNIVERSE_FLAG && ROTATION_FLAG)
    glob->universe->view_rot.x = get_bal_val_double(file, count);
  else if (POS_FLAG)
    glob->obj->stddef.pos.x = get_bal_val_double(file, count);
  else if (ROTATION_FLAG)
    glob->obj->typdef.rot.x = get_bal_val_double(file, count);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<x>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}

int	handle_y(t_glob *glob, char *file, int *count)
{
  if (XYZ_NEEDS)
    {
      printf("Error: <x> tag outside a <pos> or a <rotation> tag.\n");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  if (UNIVERSE_FLAG && POS_FLAG)
    glob->universe->eye.y = get_bal_val_double(file, count);
  else if (UNIVERSE_FLAG && ROTATION_FLAG)
    glob->universe->view_rot.y = get_bal_val_double(file, count);
  else if (POS_FLAG)
    glob->obj->stddef.pos.y = get_bal_val_double(file, count);
  else if (ROTATION_FLAG)
    glob->obj->typdef.rot.y = get_bal_val_double(file, count);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<y>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}

int	handle_z(t_glob *glob, char *file, int *count)
{
  if (XYZ_NEEDS)
    {
      printf("Error: <x> tag outside a <pos> or a <rotation> tag.\n");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  if (UNIVERSE_FLAG && POS_FLAG)
    glob->universe->eye.z = get_bal_val_double(file, count);
  else if (UNIVERSE_FLAG && ROTATION_FLAG)
    glob->universe->view_rot.z = get_bal_val_double(file, count);
  else if (POS_FLAG)
    glob->obj->stddef.pos.z = get_bal_val_double(file, count);
  else if (ROTATION_FLAG)
    glob->obj->typdef.rot.z = get_bal_val_double(file, count);
  if (!file[count[0]] || !file[count[0] + 1] || VAL_FLAG)
    {
      printf(NO_VALUE, "<z>");
      free_and_quit(glob, file, count);
    }
  VAL_FLAG = 0;
  return (0);
}
