/*
** perturb_normale.c for TraceMyRay in /home/lang_m/code/c/42sh
** 
** Made by Mathias Lang
** Login   <lang_m@epitech.net>
** 
** Started on  Wed Jun  1 01:00:37 2011 Mathias Lang
** Last update Fri Jun  3 22:28:10 2011 xavier schmerber
*/
#include	<math.h>
#include	"rt.h"

void	perturb_normal(t_coord *normale, t_coord *inter)
{
  normale->x += cos(RAD(inter->x)) / PERTURB_NORMAL_COEFF;
  normale->y += cos(RAD(inter->y)) / PERTURB_NORMAL_COEFF;
  normale->z += cos(RAD(inter->z)) / PERTURB_NORMAL_COEFF;
}
