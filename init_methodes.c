/*
** init_methodes.c for rt.h in /home/schmer_x//igraph/rt
** 
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
** 
** Started on  Fri May  6 01:00:21 2011 xavier schmerber
** Last update Fri Jun  3 14:50:54 2011 xavier schmerber
*/
#include	"rt.h"

static void	init_find_dist(t_obj *tmp)
{
  if (tmp->type == SPHERE)
    tmp->methode->find_dist = &inter_sphere;
  else if (tmp->type == PLAN)
    tmp->methode->find_dist = &inter_plan;
  else if (tmp->type == CYLINDRE)
    tmp->methode->find_dist = &inter_cylindre;
  else if (tmp->type == CONE)
    tmp->methode->find_dist = &inter_cone;
  else if (tmp->type == TORE)
    tmp->methode->find_dist = &inter_tore;
  else if (tmp->type == CUBE)
    tmp->methode->find_dist = &inter_cube_troue;
  else if (tmp->type == PARABOL)
    tmp->methode->find_dist = &inter_parabol;
  else if (tmp->type == HYPERBOL)
    tmp->methode->find_dist = &inter_hyperbol;
}

static void	init_normale(t_obj *tmp)
{
  if (tmp->type == CYLINDRE)
    tmp->methode->calc_normale = &normale_cylindre;
  else if (tmp->type == SPHERE)
    tmp->methode->calc_normale = &normale_sphere;
  else if (tmp->type == CONE)
    tmp->methode->calc_normale = &normale_cone;
  else if (tmp->type == PLAN)
    tmp->methode->calc_normale = &normale_plan;
  else if (tmp->type == TORE)
    tmp->methode->calc_normale = &normale_tore;
  else if (tmp->type == CUBE)
    tmp->methode->calc_normale = &normale_cube_troue;
  else if (tmp->type == PARABOL)
    tmp->methode->calc_normale = &normale_parabol;
  else if (tmp->type == HYPERBOL)
    tmp->methode->calc_normale = &normale_hyperbol;
}

void		init_methodes(t_glob *glob)
{
  t_obj		*tmp;
  int		dowhile;

  dowhile = 0;
  tmp = glob->obj;
  while (tmp && (tmp != glob->obj || dowhile == 0))
    {
      tmp->methode = cx_malloc(1 *sizeof(t_methode));
      init_find_dist(tmp);
      init_normale(tmp);
      tmp->methode->calc_color = &calc_color;
      tmp->methode->calc_light = &calc_light;
      tmp->methode->calc_reflec = &calc_reflection;
      tmp->methode->calc_transp = &calc_transparency;
      tmp = tmp->next;
      dowhile++;
    }
}
