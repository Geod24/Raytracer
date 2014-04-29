/*
** rotate_3d.c for rt in /home/schmer_x//igraph/rt
** 
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
** 
** Started on  Tue Feb 15 09:01:37 2011 xavier schmerber
** Last update Fri Jun  3 13:31:42 2011 xavier schmerber
*/
#include	<math.h>
#include	"rt.h"

static void	rotate_x(t_coord *vect, double teta)
{
  double	b_tmp;
  double	c_tmp;

  b_tmp = vect->y * cos(RAD(teta)) - vect->z * sin(RAD(teta));
  c_tmp = vect->y * sin(RAD(teta)) + vect->z * cos(RAD(teta));
  vect->y = b_tmp;
  vect->z = c_tmp;
}

static void	rotate_y(t_coord *vect, double teta)
{
  double	a_tmp;
  double	c_tmp;

  a_tmp = vect->x * cos(RAD(teta)) + vect->z * sin(RAD(teta));
  c_tmp = - vect->x * sin(RAD(teta)) + vect->z * cos(RAD(teta));
  vect->x = a_tmp;
  vect->z = c_tmp;
}

static void	rotate_z(t_coord *vect, double teta)
{
  double	a_tmp;
  double	b_tmp;

  a_tmp = vect->x * cos(RAD(teta)) - vect->y * sin(RAD(teta));
  b_tmp = vect->x * sin(RAD(teta)) + vect->y * cos(RAD(teta));
  vect->x = a_tmp;
  vect->y = b_tmp;
}

void	rotate_3d(t_coord *vect, t_coord *rot, int inverse)
{
  if (inverse == 1)
    {
      rotate_x(vect, rot->x * inverse);
      rotate_y(vect, rot->y * inverse);
      rotate_z(vect, rot->z * inverse);
    }
  else if (inverse == -1)
    {
      rotate_z(vect, rot->z * inverse);
      rotate_y(vect, rot->y * inverse);
      rotate_x(vect, rot->x * inverse);
    }
}
