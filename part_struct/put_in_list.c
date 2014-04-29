/*
** put_in_list.c for rt in /home/oliver_f//Teck/Igraph/RT/raytracer/SVN/TraceMyRay
**
** Made by florian oliver
** Login   <oliver_f@epitech.net>
**
** Started on  Thu Jun  2 16:57:25 2011 florian oliver
** Last update Fri Jun  3 19:46:23 2011 Mathias Lang
*/
#include	<stddef.h>
#include	"rt.h"

t_error		*put_in_list(t_error *arg)
{
  t_error	*element;

  element = cx_malloc(sizeof(*element));
  element->next = NULL;
  element->prev = NULL;
  if (arg != NULL)
    {
      element->prev = arg;
      arg->next = element;
    }
  return (element);
}
