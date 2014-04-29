/*
** calc_delta.c for raytracer in /home/fische_s//dossier/projets/rt
** 
** Made by sylvain fischer
** Login   <fische_s@epitech.net>
** 
** Started on  Tue Apr 12 19:23:51 2011 sylvain fischer
** Last update Fri Jun  3 14:43:48 2011 xavier schmerber
*/
#include	<math.h>
#include	"rt.h"

double		calc_delta(t_coord *abc, double delta)
{
  double	t1;
  double	t2;

  t1 = -1.0;
  t2 = -1.0;
  if (delta > 0.000001)
    {
      t1 = (-abc->y - sqrt(delta)) / (2 * abc->x);
      t2 = (-abc->y + sqrt(delta)) / (2 * abc->x);
    }
  else if (delta >= -0.000001 && delta <= 0.000001)
    t1 = ((abc->y * -1) / (2 * abc->x));
  if ((t1 <= t2 && t1 > 0.000001) || (t2 >= -1.000001 && t2 <= -0.999999))
    return (t1);
  else if (t2 < t1 && t2 > 0.000001)
    return (t2);
  return (-1.0);
}
