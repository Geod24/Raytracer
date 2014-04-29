/*
** handle_end.c for raytracer in /home/lang_m/code/c/RT/part_parse
** 
** Made by Mathias
** Login   <lang_m@epitech.net>
** 
** Started on  Sat Apr 30 13:16:45 2011 Mathias
** Last update Fri Jun  3 21:08:38 2011 Mathias Lang
*/
#include	<stdio.h>
#include	<stdlib.h>
#include	"rt.h"

static int	handling_norme(int *count)
{
  if (count[1] == B_END(BAL_CONSTANTS) && CONST_FLAG)
    {
      META_FLAG ^= IN_F_CONST;
      return (42);
    }
  else if (count[1] == B_END(BAL_GRAPH) && CONST_FLAG)
    {
      META_FLAG ^= IN_F_GRAPH;
      return (42);
    }
  else if (count[1] == B_END(BAL_CALC_IMG) && CALC_IMG_FLAG)
    {
      META_FLAG ^= IN_F_CALC_IMG;
      return (42);
    }
  else if (count[1] == B_END(BAL_AFF_IMG) && AFF_IMG_FLAG)
    {
      META_FLAG ^= IN_F_AFF_IMG;
      return (42);
    }
  return (0);
}

static void	handling_end_spec(int *count, char **bal)
{
  if (count[1] == B_END(BAL_RT))
    {
      META_FLAG ^= IN_F_RT;
      META_FLAG |= F_RT_END;
    }
  else if (count[1] == B_END(BAL_SCENE) && SCENE_FLAG)
    META_FLAG ^= IN_F_SCENE;
  else if (count[1] == B_END(BAL_UNIVERSE) && UNIVERSE_FLAG)
    META_FLAG ^= IN_F_UNI;
  else if (count[1] == B_END(BAL_ROTATION) && ROTATION_FLAG)
    META_FLAG ^= IN_F_ROTATION;
  else if (count[1] == B_END(BAL_POS) && POS_FLAG)
    META_FLAG ^= IN_F_POS;
  else if (count[1] == B_END(BAL_OBJECT) && OBJECT_FLAG)
    META_FLAG ^= IN_F_OBJ;
  else if (count[1] == B_END(BAL_COEFFS) && COEFFS_FLAG)
    META_FLAG ^= IN_F_COEFFS;
  else if (count[1] == B_END(BAL_CAMERA) && CAMERA_FLAG)
      META_FLAG ^= IN_F_CAMERA;
  else if (count[1] == B_END(BAL_GRAPH) && GRAPH_FLAG)
      META_FLAG ^= IN_F_GRAPH;
  else if (handling_norme(count));
  else
    printf("Warning: Error while closing %s>\n", bal[count[1]]);
}

# define IS_META_BAL	(count[1] >= B_END(BAL_RT)			\
			 && count[1] <= B_END(BAL_ROTATION))		\
  || (count[1] >= B_END(BAL_COEFFS) && count[1] <= B_END(BAL_AFF_IMG))	\
  || count[1] == B_END(BAL_CAMERA)

int		handle_end(t_glob *glob, char *file, int *count)
{
  char	**bal;

  if (!RT_FLAG)
    {
      printf(OUT_RT);
      free_and_quit(glob, file, count);
    }
  bal = init_balises();
  if (IS_META_BAL)
    handling_end_spec(count, bal);
  else
    ID_FLAG -= (count[1] - B_END(0));
  if (ID_FLAG)
    {
      printf("Error: Collision between %s> and %d>\n", bal[count[1]],
	     ID_FLAG);
      free(bal);
      free_and_quit(glob, file, count);
    }
  free(bal);
  return (1);
}
