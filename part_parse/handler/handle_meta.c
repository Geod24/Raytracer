/*
** handle_meta.c for raytracer in /home/lang_m/code/c/RT/part_parse
** 
** Made by Mathias Lang
** Login   <lang_m@epitech.net>
** 
** Started on  Sun May  1 00:28:14 2011 Mathias Lang
** Last update Fri Jun  3 22:30:10 2011 Mathias Lang
*/
#include	<stdio.h>
#include	"rt.h"

int	handle_rt(t_glob *glob, char *file, int *count)
{
  if (RT_FLAG || META_FLAG & F_RT_END)
    {
      printf(OUT_RT);
      free_and_quit(glob, file, count);
    }
  META_FLAG += IN_F_RT;
  return (1);
}

# define ERR_IN_SCN	((!RT_FLAG) ? (SCN_OUT_RT)			\
			 : ((SCENE_FLAG) ? (SCN_IN_SCN) : (SCN_IN_UNI)))

int	handle_scene(t_glob *glob, char *file, int *count)
{
  if (!RT_FLAG || SCENE_FLAG || UNIVERSE_FLAG || ID_FLAG)
    {
      if (ID_FLAG)
	printf(ID_EXPECTED);
      else
	printf(ERR_IN_SCN);
      free_and_quit(glob, file, count);
    }
  META_FLAG += IN_F_SCENE;
  return (1);
}

int	handle_universe(t_glob *glob, char *file, int *count)
{
  if (!RT_FLAG || SCENE_FLAG || UNIVERSE_FLAG || ID_FLAG)
    {
      printf("Universe description must be in a \"<RT>\" tag.\n");
      free_and_quit(glob, file, count);
    }
  META_FLAG += IN_F_UNI;
  return (1);
}

int	handle_camera(t_glob *glob, char *file, int *count)
{
  if (!UNIVERSE_FLAG || ID_FLAG)
    {
      printf("Error: <camera> outside <universe>\n");
      free_and_quit(glob, file, count);
    }
  META_FLAG += IN_F_CAMERA;
  return (1);
}
