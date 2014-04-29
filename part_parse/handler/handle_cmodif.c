/*
** handle_cmodif.c for raytracer in /home/lang_m/code/c/RT/part_parse
** 
** Made by Mathias
** Login   <lang_m@epitech.net>
** 
** Started on  Sat Apr 30 13:17:05 2011 Mathias
** Last update Fri Jun  3 19:38:42 2011 Mathias Lang
*/
#include	<stdio.h>
#include	"rt.h"

# define CMODIF_NEEDS	!RT_FLAG || (!UNIVERSE_FLAG && !SCENE_FLAG)	\
  || (!UNIVERSE_FLAG && !OBJECT_FLAG)
# define CMODIF_ERR	(!RT_FLAG) ? (OUT_RT)				\
  : ((!UNIVERSE_FLAG && !SCENE_FLAG) ? (UNI_XOR_SCENE) : (OUT_OBJ))

int	handle_pos(t_glob *glob, char *file, int *count)
{
  if (CMODIF_NEEDS)
    {
      printf(CMODIF_ERR, "<pos>");
      free_and_quit(glob, file, count);
    }
  META_FLAG += IN_F_POS;
  return (1);
}

int	handle_rotation(t_glob *glob, char *file, int *count)
{
  if (CMODIF_NEEDS)
    {
      printf(CMODIF_ERR, "<rotation>");
      free_and_quit(glob, file, count);
    }
  META_FLAG += IN_F_ROTATION;
  return (1);
}
