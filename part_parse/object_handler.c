/*
** object_handler.c for raytracer in /home/lang_m/code/c/RT/part_parse
** 
** Made by Mathias Lang
** Login   <lang_m@epitech.net>
** 
** Started on  Sun May  1 00:28:03 2011 Mathias Lang
** Last update Fri Jun  3 19:36:17 2011 Mathias Lang
*/
#include	<stdio.h>
#include	"rt.h"

t_obj	*create_obj(t_obj *obj)
{
  t_obj *new;

  new = cx_malloc(sizeof(t_obj));
  if (obj != NULL)
    obj->next = new;
  new->prev = obj;
  return (new);
}

int	handle_object(t_glob *glob, char *file, int *count)
{
  if (!SCENE_FLAG || OBJECT_FLAG)
    {
      if (!SCENE_FLAG)
	printf(OUT_SCENE, "<object>");
      else
	printf("Error: <object> inside another one.\n");
      free_and_quit(glob, file, count);
    }
  glob->obj = create_obj(glob->obj);
  META_FLAG += IN_F_OBJ;
  return (1);
}
