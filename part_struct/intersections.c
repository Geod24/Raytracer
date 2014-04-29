/*
** intersections.c for raytracer in /home/fische_s//dossier/projets/rt
**
** Made by sylvain fischer
** Login   <fische_s@epitech.net>
**
** Started on  Tue Apr 12 15:43:17 2011 sylvain fischer
** Last update Sat Jun  4 00:52:40 2011 Mathias Lang
*/
#include	<stdlib.h>
#include	"rt.h"

static void	check_obj(t_obj *tmp, t_calc *calc)
{
  double	dist;

  if (tmp->methode->find_dist != NULL)
    {
      dist = tmp->methode->find_dist(tmp, calc);
      if ((dist < calc->dist ||
	   (calc->dist > -1.000001 && calc->dist < -0.999999)) && dist > 0.0)
	{
	  calc->dist = dist;
	  calc->obj = tmp;
	}
    }
}

void		intersections(t_glob *glob, t_calc *calc)
{
  t_obj		*tmp;
  int		dowhile;

  dowhile = 0;
  calc->dist = -1.0;
  tmp = glob->obj;
  while (tmp != glob->obj || dowhile == 0)
    {
      dowhile = 1;
      if (tmp->type != LIGHT)
	check_obj(tmp, calc);
      tmp = tmp->next;
    }
}
