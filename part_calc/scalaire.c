/*
** scalaire.c for rt in /home/schmer_x//igraph/rt
** 
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
** 
** Started on  Sat Apr 16 16:05:38 2011 xavier schmerber
** Last update Fri Jun  3 13:32:16 2011 xavier schmerber
*/
#include	"rt.h"

double	scalaire(t_coord *v1, t_coord *v2)
{
  return ((v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z));
}
