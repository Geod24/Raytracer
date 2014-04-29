/*
** init_fptr.c for TraceMyRay in /partage/code/c/RT
** 
** Made by Mathias Lang
** Login   <lang_m@epitech.net>
** 
** Started on  Fri Jun  3 20:38:32 2011 Mathias Lang
** Last update Fri Jun  3 22:29:55 2011 Mathias Lang
*/
#include	<stdlib.h>
#include	"rt.h"

static void	init_fptr_begin_1(func_handler *ret)
{
  ret[0] = &handle_rt;
  ret[1] = &handle_scene;
  ret[2] = &handle_object;
  ret[3] = &handle_universe;
  ret[4] = &handle_pos;
  ret[5] = &handle_rotation;
  ret[6] = &handle_type;
  ret[7] = &handle_radius;
  ret[8] = &handle_transparence;
  ret[9] = &handle_reflection;
  ret[10] = &handle_color;
  ret[11] = &handle_xsize;
  ret[12] = &handle_ysize;
  ret[13] = &handle_camera;
  ret[14] = &handle_x;
  ret[15] = &handle_y;
  ret[16] = &handle_z;
  ret[17] = &handle_rtore;
  ret[18] = &handle_coeff;
  ret[19] = &handle_const;
  ret[20] = &handle_graph;
  ret[21] = &handle_calc_img;
  ret[22] = &handle_aff_img;
  ret[23] = &handle_ambiant_light;
  ret[24] = &handle_brillance;
}

static void	init_fptr_begin_2(func_handler *ret)
{
  ret[25] = &handle_specular_light;
  ret[26] = &handle_diff_light;
  ret[27] = &handle_power;
  ret[28] = &handle_size;
  ret[29] = &handle_angle;
  ret[30] = &handle_screen_dist;
  ret[31] = &handle_cosmic_light;
  ret[32] = &handle_transp_deep;
  ret[33] = &handle_reflec_deep;
  ret[34] = &handle_dam_color;
  ret[35] = &handle_prop;
}

static void	make_list_circ(t_glob *glob)
{
  t_obj		*end;

  if (glob && glob->obj)
    {
      end = glob->obj;
      while (glob->obj->prev)
	glob->obj = glob->obj->prev;
      while (end->next)
	end = end->next;
      glob->obj->prev = end;
      end->next = glob->obj;
    }
  else
    {
      free_glob(glob);
      put_error("Error: Cannot render an empty scene.\n", 1);
    }
}

void	clean_all(int *count, char **bal, func_handler *fptr, t_glob *glob)
{
  free(count);
  free(fptr);
  free(bal);
  make_list_circ(glob);
}

func_handler	*init_fptr()
{
  func_handler	*ret;
  int		off;

  off = B_END(0);
  ret = cx_malloc((BAL_NBR + 1) * sizeof(func_handler));
  init_fptr_begin_1(ret);
  init_fptr_begin_2(ret);
  while (off < BAL_NBR)
    ret[off++] = &handle_end;
  return (ret);
}
